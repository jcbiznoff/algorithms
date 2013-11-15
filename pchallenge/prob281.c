#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXBIN 3000

int bin[MAXBIN];
char line[MAXBIN*4];
int arr[MAXBIN];

void initBin(){
    int i;
    for(i=0;i<MAXBIN;i++){
        bin[i]=0;
        arr[i]=0;
    }
}

int getArrLen(char *line){
    int len=0;
    char *p = strtok(line," ");
    while(p != NULL){
        len++;
        p = strtok(NULL," ");
    }
    printf("len: %d",len);
    return len;
}

void parseStr2Arr(char *line){
    int i =0,j;
    char *p = strtok(line, " ");
    while(p!=NULL){
        arr[i] = atoi(p);
        printf("[%d : %d] ", j, arr[j]);
        i++;
        p = strtok(NULL, " ");
    }
}
int fillBin(int len){
    int i,max=arr[0];
    for (i=0;i<len;i++){
        if(arr[i]>max) max = arr[i];
    }

    for (i=1;i<max;i++){
        bin[abs(arr[i-1] - arr[i])]++;
    }
    return max;
}

void detJ(int max){
    int i;
    for(i=0;i<max;i++){
        if(bin[i] == 0){
            printf("not a J\n");
            break;
        }
    }
    printf("is J\n");
}
int main(){
    int k,len;

    while(fgets(line,MAXBIN*3000,stdin)!= NULL){
        if(line[strlen(line) -1 ] == '\n')
            line[strlen(line) - 1] = '\0';
        initBin();
        len = getArrLen(line);
        parseStr2Arr(line);
        k = fillBin(len);
        detJ(k);
    }
    return 0;
}
