#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _cds{
    char *artists;
    int indexId;
    char *title;
}cd;

cd* initCds(){
    cd * myCd = (cd *)malloc(sizeof(cd));
    myCd->title = NULL;
    myCd->indexId = 0;
    myCd->title = NULL;
    return myCd;
}

void printOptions(){
    printf("*********************************************\n");
    printf("Select from the following Options\n");
    printf("1. add a cd\n");
    printf("2. delete a cd\n");
    printf("3. search a cd my artist\n");
    printf("4. print cd by artist name\n");
    printf("*********************************************\n");
}

void processNewCdIn(char *aname, int idx, char *title){
   cd* cd1 = initCds();
    // add name
    cd1->artists = (char*)malloc(sizeof(char)*50);
    strcpy(cd1->artists, aname);
    cd1->indexId = idx;
    cd1->title = (char*)malloc(sizeof(char)*100);
    strcpy(cd1->title, title);
    //add to queue
}
void printAddCdOption(){
    char aname[50];
    int idx;
    char title[100];

    printf("1. add artist name: \n");
    scanf("%s",aname);
    printf("2. add index for cd\n");
    scanf("%d",&idx);
    printf("3. add title of the song\n");
    scanf("%s",title);

    processNewCdIn(aname, idx, title);
    printf("done\n");
    printOptions();

}

void printDeleteCdOption(){

}
void printSearchCdOption(){

}
void printPrintCdOption(){

}
void readOptions(){
    int opt;
    scanf("%d", &opt);
    switch(opt){
        case 1:
           printAddCdOption();
            break;
        case 2:
            printDeleteCdOption();
            break;
        case 3:
            printSearchCdOption();
            break;
        case 4:
            printPrintCdOption();
            break;
    }
}


int main(){
    while(1){
        printOptions();
    }
    return 0;
}
