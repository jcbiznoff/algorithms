#include <stdio.h>
#define MAXQ 100

typedef struct _queue{
	int q[MAXQ];
	int s;
	int e;
	int n;
}queue;

void initq(queue *q);
void enqueue(queue *q, int x);
int dequeue(queue *q);
int isEmpty(queue *q);
void printq(queue *q);
int headq(queue *q);
