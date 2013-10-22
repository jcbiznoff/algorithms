#include <stdio.h>
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
		printf("queue size exceeded");
	}
	q->e++;
	q->q[q->e] = x;
	q->n++;
}
int dequeue(queue *q){
	int data;
	if(q->n<= 0) {
		printf("queue size is 0");
		return 0;
	}
	data = q->q[q->s];
	q->s++;
	q->n--;
	return data;
}
bool isEmpty(queue *q){
	return (q->n == 0) ? true : false;
}
void printq(queue *q){
	int i;
	for(i=q->s; i <=q->e;i++)
		printf("%d ",q->q[i]);
	printf("\n");
}