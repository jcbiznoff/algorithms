#include <stdio.h>
#include "sorttest.c"
#include <stdlib.h>
#include <time.h>

#define MAXN 20

int main(){

    srand(time(NULL));
    int a[MAXN];
    gendata(a,MAXN);

    printf("gendata result: ");
    //gendata(&a,MAXN);
    //printarray(a,MAXN);
    printf("quick sort result: ");
    quicksortt(a,0, MAXN-1);
    printarray(a,MAXN);
    /*
    printf("selection sort result: ");
    selectionSort(a,MAXN);

    printf("insertion sort result: ");
    insertionSort(a,MAXN);

    printf("insertion sort 2 result: ");
    insertionSort2(a,MAXN);

//    printf("quick sort  result: ");
//   quicksortexec(a,0,MAXN);
//
    printf("counting sort result: ");
    countingsort(a, MAXN);

    printf("merge sort result: ");
    mergesortexec(a, MAXN);
   */
    return 0;
}

