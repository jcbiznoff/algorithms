#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>
int maxInt(int a, int b){ return a>b ? a:b;}
int minInt(int a, int b){ return a<b ? a:b;}

void swapInts(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swapStr(char **a, char **b){ //use to swap ptrs: char * datas
    char *tmp = *a;
    *a = *b;
    *b = tmp;
}

void swapStr2(char *a, char *b){ //use to swap data: char [] data, fixed len.
    char *tmp = (char*)malloc(sizeof(char)*strlen(a) + 1);
    strcpy(tmp, a);
    strcpy(a,b);
    strcpy(b,tmp);
    free(tmp);
}

void printarray(int *a, int len){
    int i;
    printf("{ ");
    for (i=0; i<len;i++)
        printf("%d ",a[i]);
    printf("}\n");
}

void gendata(int *a, int len){
    int i,tmp;
    srand(time(NULL));
    for (i=0; i<len;i++){
        a[i] = i+1;
    }

    for (i=len-1; i>0; i--){
        tmp = rand() % i + 1;
        swapInts(&a[tmp], &a[i]);
    }
}

int intCmpr(const void *a, const void *b){ return(*(int*)a - *(int*)b);}
int strCmpr(const void *a, const void *b){ return strcmp((char const*)a, (char const*)b);}

int countWordOccurance(char *pat, char *txt){
    int i,j,count = 0;
    int plen = strlen(pat);
    int tlen = strlen(txt);

    for (i=0; i<=tlen-plen; i++){
        for(j=0; j<plen;j++){
            if(pat[j] != txt[i+j]) break;
        }
        if(j == plen) count++;
    }
    return count;
}

