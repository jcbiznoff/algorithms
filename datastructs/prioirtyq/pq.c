#include <stdio.h>
#include "pq.h"

int pq_parent(int n){
    return n/2;
}
int pq_child(int n){
    return 2*n;
}
void pq_init(pq *q){
    q->n =0;
}
void bubbleup(pq *q, int x){

    int tmp;

    if (pq_parent(x) == 0) return ;

    if (q->q[pq_parent(x)] > q->q[x]){
        tmp = q->q[pq_parent(x)];
        q->q[pq_parent(x)] = q->q[x];
        q->q[x] = tmp;
    }
    bubbleup(q, pq_parent(x));
}

void insertpq(pq *q, int x){
    if (q->n >= MAXQ) printf("QSize exceeded max");
    q->n++;
    q->q[q->n]= x;
    bubbleup(q,x);
}

void makeheap(pq *q, int *a,int len){
    pq_init(q);
    for (int i =0; i<len ;i++)
        insertpq(q, a[i]);
}

void bubbledown(pq* q, int x){

    int tmp;
    int minidx = x;

    int c1 = pq_child(x);
    int c2 = pq_child(x) + 1;

    if(q->q[c1] < q->q[x]){
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

int extractmin(pq *q){
    int min = -1;
    if (q->n <=0) printf("warning: queue size 0");
    else{
        min = q->q[1];
        q->q[1] = q->q[q->n];
        q->n--;
        bubbledown(q,1);
    }
    return min;
}

void heapsortt(int *a, int len){
    pq q;
    makeheap(&q, a, len);
    for (int i=0; i<len; i++){
        a[i] = extractmin(&q);
    }
}
