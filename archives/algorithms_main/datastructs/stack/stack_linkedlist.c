#include "stack_linkedlist.h"

snode *newNode(int x){
    snode *nd = (snode *)malloc(sizeof(snode));
    nd->data =x;
    nd->next = NULL;
    return nd;
}

int isEmpty(snode *s){
    return s == NULL;
}

void push(snode **head, int x){
    snode *nnd = newNode(x);
    nnd->next = *head;
    *head = nnd;
    printf("pushed node with data %d into stack",x);
}

int pop(snode **head){
    if(isEmpty(*head))
        return INT_MIN;
    int data;
    snode *tmp = *head;
    *head = tmp->next;
    data = tmp->data;
    free(tmp);

    return data;
}
