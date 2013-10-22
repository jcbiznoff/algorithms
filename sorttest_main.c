#include <stdio.h>
#include "sorttest.c"
#include <stdlib.h>
#include <time.h>

#define MAXN 20
void gendata(int (*ain)[], int len){
    int i,tmp,tmp2;
    int *a = *ain;
    for (i=0; i<len;i++){
        a[i] = i+1;
    }
    for (i=0; i<len; i++){
        tmp = rand() % len;
        tmp2 = a[tmp];
        a[tmp] = a[i];
        a[i] = tmp2;
    }

}

int main(){

    srand(time(NULL));
    int a[MAXN];
    gendata(&a,MAXN);

    printf("gendata result: ");
    printarray(a,MAXN);
    //gendata(&a,MAXN);
    //printarray(a,MAXN);
    printf("selection sort result: ");
    selectionSort(a,MAXN);

    printf("insertion sort result: ");
    insertionSort(a,MAXN);

    printf("insertion sort 2 result: ");
    insertionSort2(a,MAXN);

    printf("quick sort  result: ");
    quicksortexec(a,0,MAXN);

    return 0;
}
