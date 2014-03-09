#include <stdio.h>
#include <stdlib.h>
#include "queue.c"

int main(){
	queue q;
	int data;
	initq(&q);
	printq(&q);

	enqueue(&q,1);
	enqueue(&q,2);
	enqueue(&q,3);
	enqueue(&q,4);

	printq(&q);

	data = dequeue(&q);
	printf("data: %d\n", data);
	printq(&q);
	data = dequeue(&q);
	printf("data: %d\n", data);
	printq(&q);

	system("pause");
	return 0;
}