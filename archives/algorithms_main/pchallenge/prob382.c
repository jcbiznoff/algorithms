#include <stdio.h>
#include <string.h>

#define MAXL 50
#define MAXK 20

char strMap[MAXL][MAXL];
char p[MAXK][MAXL];

int M,N,pnum;

void initArrs(){
    int i,j;
    for(i=0; i<MAXL; i++){
        for(j=0; j<MAXL; j++)
            strMap[i][j] = 0;
    }
    for (i=0; i<MAXK; i++){
        for(j=0; j<MAXL; j++)
            p[i][j] = 0;
    }
}

void convert2lower(){
    int i,j;
    for (i=0; i<M; i++){
        for(j=0; j<N; j++){
            if (strMap[i][j] >= 97)
                strMap[i][j] = strMap[i][j] - 32;
        }
    }

    for (i=0; i<pnum; i++){
        for (j=0; j<MAXL ; j++)
            if (p[i][j] >= 97) p[i][j] -= 32;
    }
}
void printArr(){
    int i,j;
    for (i=0 ;i<M ; i++){
        for(j=0; j<N ;j++){
            printf("%c ", strMap[i][j]);
        }
        printf("\n");
    }
    for (i=0 ;i<pnum ; i++){
        for(j=0; j< N;j++){
            printf("%c ", p[i][j]);
        }
        printf("\n");
    }
}
void readLine(){
    int i;
    initArrs();
    scanf("%d %d",&M, &N);
    i=0;
    while (i<M){
        scanf("%s", strMap[i]);
        i++;
    }
    scanf("%d", &pnum);
    i = 0;
    while(i<pnum){
        scanf("%s",p[i]);
        i++;
    }
    convert2lower();
    printArr();

}

int isMatch (int opt, int x, int y, int plen, char * ps){
    int i;

    switch (opt){
        case 1 :
            for (i =0; i<plen ;i++){
                if (strMap[x-i][y] != ps[i]) return 0;
            }
            return 1;
            break;
        case 2 :
            for (i =0; i<plen ;i++){
                if (strMap[x][y+i] != ps[i]) return 0;
            }
            return 1;
            break;
        case 3 :
            for (i =0; i<plen ;i++){
                if (strMap[x+i][y] != ps[i]) return 0;
            }
            return 1;
            break;
        case 4 :
            for (i =0; i<plen ;i++){
                if (strMap[x][y-i] != ps[i]) return 0;
            }
            return 1;
            break;
        case 5 :
            for (i =0; i<plen ;i++){
                if (strMap[x-i][y-i] != ps[i]) return 0;
            }
            return 1;
            break;
        case 6 :
            for (i =0; i<plen ;i++){
                if (strMap[x+i][y-i] != ps[i]) return 0;
            }
            return 1;
            break;
        case 7 :
            for (i =0; i<plen ;i++){
                if (strMap[x-i][y+i] != ps[i]) return 0;
            }
            return 1;
            break;
        case 8 :
            for (i =0; i<plen ;i++){
                if (strMap[x+i][y+i] != ps[i]) return 0;
            }
            return 1;
            break;
        default :
            break;
    }
    return 0;
}

int readMap(char *p ,int *x , int *y){
    int plen = strlen(p);
    int i, j;
    int found = 0;
    for (i=0; i<M; i++){
        for(j=0; j<N ; j++){
            if (strMap[i][j] == p[0] ){
                if (i - plen >= 0 ) {if(isMatch(1,i,j,plen,p) == 1) {found =1 ; *x = i; *y =j; return 1;}}
                if (j + plen <= N) {if(isMatch(2, i,j,plen,p) == 1) {found =1 ; *x = i; *y =j; return 1;}}
                if (i + plen <= M) {if(isMatch(3, i,j,plen,p) == 1) {found =1; *x = i; *y =j; return 1;}}
                if (j - plen >= 0) {if (isMatch(4, i,j,plen,p)== 1) {found =1; *x = i; *y =j; return 1;}}
                if ((j - plen >= 0) && (i - plen >= 0)) {if(isMatch(5,i,j,plen,p)==1) {found =1; *x = i; *y =j; return 1;}}
                if ((j - plen >= 0) && (i + plen <= N)) {if(isMatch(6,i,j,plen,p)==1) {found =1 ;*x = i; *y =j;  return 1;}}
                if ((j + plen <= N) && (i - plen >= 0)) {if(isMatch(7,i,j,plen,p)==1) {found =1 ;*x = i; *y =j;  return 1;}}
                if ((j + plen <= N) && (i + plen <= N)) {if(isMatch(8,i,j,plen,p)==1) {found =1 ;*x = i; *y =j;  return 1;}}
                }
        }
    }
    return 0;
}

int findCoords(char *p , int * x, int * y){

    int tx =0, ty =0;
    if (readMap(p,&tx,&ty) !=1) return 0;
    *x = tx;
    *y = ty;
    return 1;
}

void outputRes (int x, int y){
    printf("%d %d\n",x+1,y+1);
}

int main(){
    int x=0,y=0,i,j;
    readLine();
    for (i=0; i<pnum; i++){
        if (findCoords(p[i], &x, &y))
            outputRes(x,y);
        else
            printf("\n");
    }


    return 0;
}
