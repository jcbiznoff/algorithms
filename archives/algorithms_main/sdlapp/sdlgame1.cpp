#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include <stdio.h>
#include <limits.h>

const int FRAMES_PER_SECOND 60
const int SCREEN_WIDTH 1280
const int SCREEN_HEIGHT 720

SDL_Window *gWindow;
SDL_Renderer *gRenderer;

SDL_Event event;

enum stateTypes{
    STATE_NULL
    STATE_TITLE,
    STATE_INTRO,
    STATE_EXIT,
    STATE_PLAY,
    STATE_OVER,
};

int curState = STATE_NULL;
int nextState = STATE_NULL;

class GameState {
    public:
    virtual void handleEvents() = 0;
    virtual void doLogic() = 0;
    virtual void renderScreen() = 0;
    virtual ~GameState(){};
};

class TitleScreen : public GameState {
    private:
        SDL_Texture *background;
        SDL_Texture *title;
        TTF_Font *titleFont;
        int titleWidth, titleHeight;

    public:
        TitleScreen();
        ~TitleScreen();

        void handleEvents();
        void doLogic(){};
        void renderScreen();
        SDL_Texture *loadImgTexture(std:string path);
        int loadTextTexture(std:string path);
};
TitleScreen::TitleScreen(){
    background = loadImgTexture("titlebg.png");
    if (!loadTextTexture("Intuit Presents.. Gemini")){
        printf("text loading failed.\n");
    }
}
TitleScreen::~TitleScreen(){
    SDL_DestroyTexture(title);
    SDL_DestroyTexture(background);
}
int TitleScreen::loadImgTexture(std::string path){
    if(IMG_Init() == -1){
        printf("IMG initialization failed: %s\n", IMG_GetError());
        return 0;
    }
    SDL_Surface * imgSurf = IMG_Load(path.c_str());
    if(imgSurf == NULL)
        return 0;
    SDL_SetColorKey(imgSurf, SDL_TRUE, SDL_MapRGB(imgSurf->format, 0, 0xFF, 0xFF)); //fix here later
    background = SDL_CreateTextureFromSurface(gRenderer, imgSurf);

    if(background == NULL)
        return 0;

    SDL_FreeSurface(imgSurf);

    return background!=NULL;
}


int TitleScreen::loadTextTexture(std::string text){

    if(TTF_Init() == -1 ){
        printf("TTF initialzation failed: %s\n", TTF_GetError());
        return 0;
    }
    titleFont = TTF_OpenFont("16_true_type_fonts/lazy.ttf", 28);
    if(titleFont == NULL){
        printf("failed to load font.\n");
        return 0;
    }
    SDL_Color textColor= {0,0,0};

    SDL_Surface *textSurf = TTF_RenderText_Solid(titleFont, text.c_str(), textColor);
    if(textSurf == NULL){
        return 0;
    }
    title = SDL_CreateTextureFromSurface(gRenderer, textSurf);
    if(title == NULL)
        return 0;
    titleWidth = textSurf->w;
    titleHeight = textSurf->h;

    SDL_FreeSurface(textSurf);

    return title!=NULL;
}

void TitleScreen::handleEvents(){
    while(SDL_PollEvent(&event)!=0){
        if(e.type == SDL_QUIT)
            setNextState(SDL_EXIT);
    }
}

void TitleScreen:: renderScreen(){
    SDL_RenderClear(gRenderer);

    SDL_Rect bgCoord = {0,0,SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_Rect titleCoord = {0,0,titleWidth, titleHeight};

    SDL_RenderCopy(gRenderer, background, NULL,&bgCoord);
    SDL_RenderCopy(gRenderer, title, NULL,NULL);

    SDL_RenderPresent(gRenderer);
}

int setNextState(int newState){
    if(nextState != STATE_EXIT)
        nextState = newState;
}

int changeState(){
    //delete current state
    //create a new next state
    //change stateID
    //change nextState
}

int initGame(){
    gWindow = SDL_CreateWindow("Gemini", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(gWindow == NULL) return 0;
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if(gRenderer == NULL) return 0;

    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
}

void closeGame(){
    delete currStateObj;
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;

    IMG_Quit();
    SDL_Quit();
}

gameState * currStateObj = NULL;

int main(){

    if(!initGame()){
        printf("game failed to initialize.\n");
        return 0;
    }

    Timer fps;
    curState = STATE_TITLE;
    currStateObj = new Title();

    while(1){
        fps.start();
        currStateObj->handleEvents();
        currStateObj->doLogic();
        changeState();
        currStateObj->renderScreen();
        //update screen
        //cap frame rate
        if(fps.get_ticks() < 1000 / FRAMES_PER_SECOND)
            SDL_Delay((1000/FRAMES_PER_SECOND - fps.get_ticks()));
    }

    closeGame();

    return 0;
}
