#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.c"

int main(){
	node *l = build123();
	printList(l);
	appendNode(&l, 5);
	appendNode(&l, 5);
	printList(l);
	
	printf("count: %d\n", count(l,5));

	system("pause");

}