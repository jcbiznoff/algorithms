#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linkedlist.c"

#define SZ 10

void shuffleList(node **l, int n){
    int i, ridx;
    for(i = n-1; i>=0 ; i--){
        ridx = rand()%SZ;
        swapNode(l, ridx, i);
    }
}

void bubblesortList(node **l, int num){
    int i,j;
    for(i=0; i<num ; i++){
        for(j=1; j<num-i; j++){
            if(getNth(*l,j-1) > getNth(*l,j))
                swapNode(l, j,j-1);
        }
    }
}


int main(){
    printf("main started: \n");
    node *l = NULL;
    int i,j;
    srand(time(NULL));

    for(i=0; i<SZ; i++)
        appendNode(&l, i+1);
    printList(l);

    shuffleList(&l, SZ);
    printList(l);

    bubblesortList(&l, SZ);
    printList(l);

    return 0;
}
