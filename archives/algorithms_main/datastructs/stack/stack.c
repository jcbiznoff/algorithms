#include "stack.h"

stack *createStack(int cap){
    stack *s = (stack *)malloc((sizeof(stack)));
    s->a = (int*)malloc(sizeof(int)*cap);
    s->top = -1;
    s->capacity = cap;
}

int isEmpty(stack *s){
    return s->top == -1;
}

int pop(stack *s){
    int data;
    if(isEmpty(s)) return INT_MIN;

    return s->a[s->top--]; //two operation in a single line
}

void push(stack *s, int x){
    if (s->top == s->capacity) return;

    s->a[++s->top] = x;
    printf("pushed data: %d to stack", x);
}

int headS(stack *s){
    if(isEmpty(s)) return INT_MIN;

    return s->a[s->top];
}
