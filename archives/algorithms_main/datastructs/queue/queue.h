#include <stdio.h>
#define MAXQ 100
/*queue:
 * this queue uses an array data structure on a stack.
 */
typedef struct _queue{
	int q[MAXQ];
	int s;
	int e;
	int n;
}queue;

/*queueH
 * heap allocated queue
 */
typedef struct _queueH{
    int *q;
    int cap;
    int s,e,n;
}queueH;


void initq(queue *q);
void enqueue(queue *q, int x);
int dequeue(queue *q);
int isEmpty(queue *q);
void printq(queue *q);
int headq(queue *q);
int rearq(queue *q);


queueH *createQ(int);
int isEmptyH(queueH *);
void enqueueH(queueH *, int);
int dequeueH(queueH *);
int headqH(queueH*);
int rearqH(queueH*);

