#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void printInorderNoRecur(tnode *node){
    //1. init a stack
    snode *head = NULL;
    tnode *cur = node;
    int flag=1;

    while(flag){
    //2. push left until null
        if(cur != NULL){
            push(&head, cur);
            cur = cur->left;
        }else{
            if(!isEmpty(head)){
                //3. pop and print
                cur = pop(&head);
                printf("%d ", cur->data);
                //4. move right
                cur = cur->right;
            }else{
                flag = 0;
            }
        }
    }
}
//helpler API function
void push(snode **head, tnode *node){
    //1. allocate memory for a new snode
    snode *s = (snode *)malloc(sizeof(snode));
    //s->t = (tnode *)malloc(sizeof(tnode)); //? questionable. usually string requires allocation..
    s->t = node;
   //insert at front
    s->next= *head;//no need to check for when head is null
    *head = s;
}

tnode *pop(snode **head){
    if(isEmpty(*head))
        return NULL;

    snode *tmps = *head;
    tnode *tmpt = tmps->t;
    *head = tmps->next;
    free(tmps);
    return tmpt;
}

int isEmpty(snode *head){
    return (head == NULL)? 1 : 0;
}
