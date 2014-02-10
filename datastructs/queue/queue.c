#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "queue.h"

void initq(queue *q){
    int i;

    q->n = 0;
    q->s = 0;
    q->e = -1;
    for(i=0; i<MAXQ; i++) q->q[i] = 0;
}
void enqueue(queue *q, int x){
    if (q->n >= MAXQ) {
        printf("queue size exceeded\n");
        return;
    }
    q->e++;
    q->q[q->e] = x;
    q->n++;
}
int dequeue(queue *q){
    int data;
    if(q->n<= 0) {
        printf("queue size is 0 \n");
        return 0;
    }
    data = q->q[q->s];
    q->s++;
    q->n--;
    return data;
}
int isEmpty(queue *q){
    return (q->n == 0) ? 1: 0;
}
void printq(queue *q){
    int i;
    for(i=q->s; i <=q->e;i++)
        printf("%d ",q->q[i]);
    printf("\n");
}


int headq(queue *q){
    return q->q[q->s];
}
int rearq(queue *q){
    return q->q[q->e];
}


queueH *createQ(int cap){
    queueH *q = (queueH*)malloc(sizeof(queueH));
    q->q = (int*)malloc(sizeof(int)*cap);
    q->cap = cap;
    q->s = 0;
    q->n =0;
    q->e = cap-1;
    return q;
}

int isEmptyH(queueH *q){
    return (q->n == 0);
}

void enqueueH(queueH *q, int x){
    if(q->n == q->cap) return;

    q->e = (q->e + 1)%q->cap;
    q->q[q->e] = x;
    q->n++;
    printf("enqueued item: %d\n",x);
}
int dequeueH(queueH *q){
    int x;
    if(isEmptyH(q)) return INT_MIN;
    x = q->q[q->s];
    q->s = (q->s + 1)%q->cap;
    q->n = q->n - 1;
    return x;
}

int headqH(queueH *q){
    if(isEmptyH(q)) return INT_MIN;
    return q->q[q->s];
}
int rearqH(queueH *q){
    if(isEmptyH(q)) return INT_MIN;
    return q->q[q->e];
}

