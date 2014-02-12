#include <stdio.h>

typedef struct _node{
	int x;
	struct _node * next;
}node;

node* build123();
void printList(node *l);
int length(node *);
int pop(node **);
void push(node **, int data);
node* appendNode(node **, int data);
void insertAt(node **, int k, int data);

void deleteList(node **);
int getNth(node*, int k);

int countOccurence(node*, int data);

void insertToSortedList(node **, node *);

void insertSort(node **);
void append(node **, node **);
void frontBackSplit(node *, node **, node **);
void removeDupsSortedList(node *);
void movefrontNode(node**, node**);
void altSplit(node*, node**, node**);
node* shuffleMerge(node*, node*);
node* sortedMerge(node*, node*);
void mergeSort(node*);
node* getIntersectListfromSorted(node*, node*);
void reverseList(node **);
void recurseReverse(node **);


void pairwiseSwapIter(node **l);
node* pairwiseSwapRecur(node *l);

