/*
 * options:
 *  1) pop front, push end
 *  2) pop end, push front
 */
#include <stdlib.h>
#include <limits.h>

typedef struct _qnode{
    int data;
    struct _qnode *next;
}qnode;

typedef struct _queue{
    qnode *front, *rear;
}queue;

qnode *newNode(int x){
    qnode *qn = (qnode*)malloc(sizeof(qnode));
    qn->data = x;
    qn->next = NULL;
    return qn;
}
queue *createQ(){
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = q->rear = NULL;
}
void enqueue(queue *q, int x){
    qnode *qn, *tmp;
    if(!(qn = newNode(x)))
        return;

    if (q->rear == NULL){
        q->front = q->rear = qn;
    }

    q->rear->next = qn;
    q->rear = qn;

}
int dequeue(queue *q){
    int data;
    if(q->front == NULL)
        return INT_MIN;

    qnode *tmp = q->front;
    q->front = q->front->next;

    if(q->front == NULL)
        q->rear=NULL;

    data = tmp->data;
    free(tmp);
    return data;
}
