#include <stdio.h>
#include "sorttest.c"
#include <stdlib.h>
#include <time.h>

#define MAXN 20

enum SortMethod{
    BUBBLE = 1,
    SELECTION,
    INSERTION,
}meth;

void printWelcomeAndIntro(){
    printf("/********************************************\n");
    printf("Test different sorting algorithms on an array\n");
    printf("/********************************************\n");
    printf("\n");
}

void printMenu(){
    printf("\n");
    printf("/********************************************\n");
    printf("Select from the following: \n");
    printf("1. bubble sort\n");
    printf("2. selection sort\n");
    printf("3. insertion sort\n");
    printf("4. insertion sort with memmove\n");
    printf("5. quick sort\n");
    printf("6. merge sort\n");
    printf("7. counting sort\n");
    printf("8. radix sort\n");
    printf("9. exit\n");
    printf("/********************************************\n");
    printf("Selection: ");
}

int * generateArray(int num){
    int *a = (int*)malloc(sizeof(int)* num);
    gendata(a,num);
    return a;
}

int doSort(int *a,int n){
    int opt;
    scanf("%d", &opt);
    switch(opt){
        case 1:
            bubblesorttInt(a,n);
            break;
        case 2:
            selectionSort(a,n);
            break;
        case 3:
            insertionSort(a,n);
            break;
        case 4:
            insertionSort2(a,n);
            break;
        case 5:
            quicksortt(a,0,n-1);
            break;
        case 6:
            mergesortexec(a,n);
            break;
        case 7:
            countingsort(a,n);
            break;
        case 8:
            radixSort(a,n);
            break;
        default:
            printf("not available\n");
            return 0;
            break;
    }
    return 1;
}

int sortResPass(int *a, int num){
    int i;
    for(i=0; i<num-1 ;i++){
        if(a[i+1]-a[i] != 1)
            return 0;
    }
    return 1;
}

int main(){
    int num,opt;
    int *a;
    srand(time(NULL));

    printWelcomeAndIntro();
    printf("Choose Size: ");
    scanf("%d",&num);

    while(1){
        a = generateArray(num);
        printf("\nGenerated Array: \n");
        printarray(a, num);

        printMenu();
        if(doSort(a, num)){
            printf("\n");
            printf("Result: ");
            if(sortResPass(a,num))
                printf("PASS\n");
            else{
                printf("FAILED\n");
            }
            printarray(a,num);
        }
        free(a);

        printf("press any key to continue...");
        getchar();
        getchar();
    }
    return 0;
}

