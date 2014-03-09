#include "minheap.h"
#include <stdlib.h>

minheap* init(minheapnode *a, int size){
    minheap *b = (minheap*)malloc(sizeof(minheap));
    b->size = size;
    b->hp = a;

    int i = (b->size - 1)/2;
    while(i>=0){
        minHeapify(b, i);
        i--;
    }
}

void minHeapify(minheap *hp, int x){

    hp* tmp;
    int minidx = x;

    int c1 = left(x);
    int c2 = right(x);

    if(hp->hp[c1]->data < hp->hp[x]->data){
        minidx = c1;
    }
    if(q->q[c2] < q->q[x]){
        minidx = c2;
    }
    if (minidx != x){
        tmp = q->q[minidx];
        q->q[minidx] = q->q[x];
        q->q[x] = tmp;
        bubbledown(q, pq_child(x));
    }
}





