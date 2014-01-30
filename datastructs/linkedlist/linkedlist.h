#include <stdio.h>

typedef struct _node{
	int x;
	struct _node * next;
}node;

//APIS
//note: double pointer to modify input list in-place, single pointer when returning a node*
int pop(node **);
void push(node **, int data);
int length(node *);
node* appendNode(node **, int data);
node* copyList(node *);
void printList(node *l);


void insertAt(node **, int k, int data);
void deleteList(node **);
node* build123();

int count(node*, int data);
int getNth(node*, int k);

node* sortedInsert(node **, node *);
void insertSort(node **);
void append(node **, node **);
void frontBackSplit(node *, node **, node **);
void removeDups(node *);
void moveNode(node**, node**);
void altSplit(node*, node**, node**);
node* shuffleMerge(node*, node*);
node* sortedMerge(node*, node*);
void mergeSort(node*);
node* sortedIntersect(node*, node*);
void reverseList(node **);
void recurseReverse(node **);
