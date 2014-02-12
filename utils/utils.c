#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void swapInts(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swapStr(char **a, char **b){
    char *tmp = *a;
    *a = *b;
    *b = tmp;
}
void swapStr2(char *a, char *b){
    char *tmp = (char*)malloc(sizeof(char)*strlen(a) + 1);
    strcpy(tmp, a);
    strcpy(a,b);
    strcpy(b,tmp);
    free(tmp);
}
int maxInt(int a, int b){
    return (a>b)? a:b;
}

int minInt(int a, int b){
    return(a<b)? a: b;
}

void printarray(int *a, int len){
    int i;
    printf("{ ");
    for (i=0; i<len;i++)
        printf("%d ",a[i]);
    printf("}\n");
}
