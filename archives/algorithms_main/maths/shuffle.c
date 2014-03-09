#include <stdio.h>
#include <stdlib.h>
#include "../utils/utils.c"
#include <time.h>

void shuffleArr(int arr[], int n){
    int i,j;
    srand(time(NULL));
    for(i=n-1 ; i>0 ;i--){
        j = rand()%(i+1);
        swapInts(&arr[i], &arr[j]);
    }
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    shuffleArr(arr,10);
    printarray(arr,10);
    return 0;
}
