#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

typedef struct _snode{
    struct _snode *next;
    int data;
}snode;

snode * newNode(int);
int isEmpty(sndoe *);
void push(snode **, int);
int pop(snode **);
int peek(snode *);

