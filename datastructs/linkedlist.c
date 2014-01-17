#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linkedlist.h"

int pop(node ** l){
    int data;
    node *cur = *l;

    assert(cur != NULL);//isEmpty condition

    data = cur->x; //store data
    *l = cur->next; //unlink
    free(cur); //free

	return data;
}
void push(node ** l, int data){
    node * newnode = (node*)malloc(sizeof(node));
    newnode->x = data; //insert data
    newnode->next = *l; //link next
    *l = newnode;
}
int length(node * l){
    int count = 0;
    node* cur = l;
    while(cur != NULL){
        count++;
        cur = cur->next;
    }
    return count;
}
node* appendNode(node ** l, int data){
    node * cur = *l;
    if(cur == NULL)
        push(l , data);

    while (cur->next != NULL){
        cur= cur->next;
    }
    push(&(cur->next),data);
}
/*
node* copyList(node * l){
    node * newlist ;
    node * cur = l;
    while(cur->next != NULL){
        push(&newlist, cur->x);
        cur = cur->next;
    }
    return newlist;
}
*/
void insertAt(node ** l, int k, int data){
    node * cur = *l;
    int count = 0 ;
    if(k==0) push(l,data);
    while(cur !=NULL){
        if (count == k)
            break;
        count ++;
        cur = cur->next;
    }
    push(&(cur->next),data);

}
void deleteList(node ** l){}
void printList(node *l){
    int n = length(l);
    node *cur = l;

    for(int i=0; i<n;i++){
        printf("%d ", cur->x);
        cur =cur->next;
    }
    printf("\n");
}
node* build123(){
    node *l = NULL;
    for(int i=0; i<3;i++)
        push(&l, 3-i);
    return l;
}

int count(node* l, int data){
    node* cur = l;
    int c=0;
    while (cur != NULL)
    {
        if(cur->x == data)  c++;
        cur=cur->next;
    }
    return c;
}
int getNth(node* l, int k){}

void sortedInsert(node ** l1, node * l2){}
void insertSort(node ** l){}
void append(node ** ldest, node ** lsrc){}
void frontBackSplit(node * lsrc, node **l1, node **l2){}
void removeDups(node * l){}
void moveNode(node** l1, node** l2){}
void altSplit(node* src, node** l1, node** l2){}
node* shuffleMerge(node* l1, node* l2){}
node* sortedMerge(node* l1, node* l2){}
void mergeSort(node* l){}
node* sortedIntersect(node* l1, node* l2){}
void reverseList(node **l){}
void recurseReverse(node **l){}
