#include <stdlib>
#include <limits.h>
#include <stdio.h>

typedef struct _stack{
    int *a;
    int top;
    int capacity;
}stack;


stack * createStack(int cap);
int isEmpty(stack *);
int pop(stack *s);
void push(stack *s, int x);
int headS(stack *);
