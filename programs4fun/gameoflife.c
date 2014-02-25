#include <stdio.h>

#define MAX 10

int a[MAX][MAX];
int b[MAX][MAX];

void initArr(){
    int i,j;
    for(i=0; i<MAX; i++){
        for(j=0; j<MAX; j++){
            a[i][j] = 0;
            b[i][j] = 0;
        }
    }
}

void fillArr(int x,int y){
    a[x][y] = 1;
}

int isBoundaryOK(int i, int j){
    if((i>=0 || i<MAX) && (j>=0 || j<MAX))
        return 1;
    return 0;
}

int getNeighbors(int x, int y){
    int i,j;
    int count = 0;

    for(i=x-1; i<=x+1; i++){
        for(j=y-1; j<=y+1; j++){
            if(!(i==x && j==y)){ //stupid mistake here. before: i!=x && j!=y. need or satisfiability.
                if(isBoundaryOK(i,j)){
                    if(a[i][j] == 1)
                        count++;
                }
            }
        }
    }
    return count;
}

void printArr2(){
    int i,j;
    for(i=0; i<MAX; i++){
        for(j=0; j<MAX; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void updateArr(){
    int i, j;
    for(i=0; i<MAX; i++){
        for(j=0; j<MAX; j++){
            a[i][j] = 0;
        }
    }
    for(i=0; i<MAX; i++){
        for(j=0; j<MAX; j++){
            a[i][j] = b[i][j];
        }
    }
}

int main(){

    int i,j;
    int num;
    int tmp;
    initArr();
    fillArr(1,2);
    fillArr(2,3);
    fillArr(3,1);
    fillArr(3,2);
    fillArr(3,3);
/*
    fillArr(2,2);
    fillArr(2,3);
    fillArr(2,4);
    fillArr(2,2);
    fillArr(2,3);
    fillArr(3,2);
    fillArr(3,3);
   */

    printArr2();
    printf("\n");
    scanf("%d",&tmp);
    int br = 0;
    while(1){
        if (br==5)break;
        for(i=0; i<MAX;i++){
            for(j=0; j<MAX; j++){
                num = getNeighbors(i,j);
                if(a[i][j] == 1){
                    if(num < 2 || num > 3)
                        b[i][j] = 0;
                    else
                        b[i][j] = 1;
                }else{
                    if(num == 3){
                        b[i][j] = 1;
                    }
                }
            }
        }
        updateArr();
        printArr2();
        printf("\n");
        br++;
    }
}


