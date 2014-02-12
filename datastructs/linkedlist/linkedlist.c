#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linkedlist.h"
#include <limits.h>

node* build123(){
    node *l = NULL;
    for(int i=0; i<3;i++)
        push(&l, 3-i);
    return l;
}

void printList(node *l){
    node *cur;
    printf("{ ");
    for(cur = l; cur != NULL; cur = cur->next)
        printf("%d ", cur->x);
    printf("}\n");
}

int pop(node ** l){
    int data;
    node *cur = *l;
    if(cur == NULL)
        return INT_MIN;

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

void insertAt(node ** l, int k, int data){
    node * cur = *l;
    int i ;
    if(k==0) push(l,data);
    else{
        for(i=0; i<k-1 ;i++)
            cur = cur->next;

        push(&(cur->next),data);
    }
}

void deleteList(node ** l){
    node *cur = *l;
    node *tmp;

    while(cur != NULL){
        tmp = cur->next;
        free(cur);
        cur = tmp;
    }
}

int countOccurence(node* l, int data){
    node* cur = l;
    int c=0;
    while (cur != NULL)
    {
        if(cur->x == data)  c++;
        cur=cur->next;
    }
    return c;
}

int getNth(node* l, int k){
    int count =0;
    node * cur = l;
    while (k!=count){
        count++;
        cur = cur->next;
    }
    return cur->x;
}
void sortListViaBubble(node **l);
void sortListViaMerge(node **h){
    node * head = *h;
    node *a;
    node *b;
    if( head ==NULL || head->next == NULL)
        return;
    frontBackSplit(head, &a, &b);

    sortListViaMerge(&a);
    sortListViaMerge(&b);

    *h = sortedMerge(a,b);
}


//given a list and node, insert node to a list
void insertToSortedList(node ** l, node * nd){

    if(*l == NULL || (*l)->x >= nd->x){
        nd->next = *l;
        *l = nd;
    }
    else{
        node *cur = *l;
        while(cur->next != NULL){
            if(cur->next->x > nd->x)
                break;
            cur=cur->next;
        }
        nd->next = cur->next;
        cur->next = nd;
    }
}
//given a list, change it to a sorted order => sort a list!
void insertSort(node ** l){
    node *a = NULL;
    node *cur = *l;
    node *tmp;

    while(cur != NULL){
        tmp = cur->next;
        insertToSortedList(&a, cur);
        cur = cur->next;
    }
    *l = a;
}

void appendLists(node ** ldest, node ** lsrc){
    node *cur = *ldest;
    if(*ldest == NULL) *ldest = *lsrc;
    else {
        while(cur!=NULL){
            cur=cur->next;
        }
        cur->next = *lsrc;
    }
    *lsrc= NULL;
}

void frontBackSplit(node * lsrc, node **l1, node **l2){
    //split list into front and back. save each list to parameter address
    node *cur = lsrc;
    node *fastcur = cur;
    if(cur == NULL) return;
    if(cur->next == NULL) {
        *l1 = cur;
        return;
    }

    while(fastcur !=NULL){
        fastcur = fastcur->next; // fastcur is next not cur->next->next
        if(fastcur != NULL){
            cur = cur->next;
            fastcur = fastcur -> next; //fast cur independent of cur
        }
    }

    *l1 = lsrc; // do not use cur here. cur is at mid point
    *l2 = cur->next;
    cur->next = NULL;

}
void removeDupsSortedList(node * l){
    node *cur = l;
    node *tmp;

    if(cur == NULL) return;

    while(cur->next != NULL){
        if(cur->x == cur->next->x){
            tmp = cur->next;
            cur->next = tmp->next;
            free(tmp);
        }
        else
            cur=cur->next;
    }
}

void movefrontNode(node** l1, node** l2){

    node *src = *l2;
    if(src == NULL)return;

    *l2 = src->next;
    src->next = *l1;
    *l1 = src;
}

void altSplit(node* src, node** l1, node** l2){

    node *a=NULL, *b=NULL;
    node *cur = src;
    while(cur != NULL){
        movefrontNode(&a, &cur);
        if(cur != NULL)
            movefrontNode(&b, &cur);
    }
    *l1 = a;
    *l2 = b;
}
node* shuffleMerge(node* l1, node* l2){
    node * res =NULL;
    node *cur1=l1, *cur2=l2;


    while(1){
        if(cur1 == NULL)
            res = l2;
        if(cur2 == NULL)
            res = l1;

        res = cur1;
        res->next = cur2;

        cur1 = cur1->next;
        cur2 = cur2->next;

    }
}

node* sortedMerge(node* l1, node* l2){
    node *result; //returning node ptr
    node **lastRef = &result; //

    while(1){
        if( l1 == NULL){
            *lastRef = l2;
            break;
        }else if( l2 == NULL){
            *lastRef = l1;
            break;
        }
        if(l1->x > l2->x){
            //move l1 to lastrRef
            movefrontNode(lastRef, &l2);
        }
        else{
            //move l2 to l1
            movefrontNode(lastRef, &l1);
        }
        lastRef = &((*lastRef) -> next);
    }
    return(result);

}

node* getIntersectListfromSorted(node* l1, node* l2){
    node * cur1,*cur2;
    node * res=NULL;
    for(cur1 = l1; cur1 != NULL; cur1=cur1->next){
        for(cur2 = l2; cur2 != NULL; cur2=cur2->next){
            if(cur1->x == cur2->x)
                push(&res, cur1->x);
        }
    }
    return res;
}


void reverseList(node **l){
    node *cur= *l, *tmp;
    node *res = NULL; // push on to here

    while(cur != NULL){
        tmp = cur->next;
        cur->next = res;
        res = cur;
        cur = tmp;
    }
    *l = res;
}

void recurseReverse(node **l){
    node * first;
    node * rest;

    if(*l == NULL) return;

    first = *l;
    rest = first->next;

    if(rest == NULL) return;
    recurseReverse(&rest);

    first->next->next = first;
    first->next = NULL;
    *l = rest;

}

void pairwiseSwapIter(node ** l){
   if(*l== NULL || (*l)->next == NULL) return;

   node *prev = *l;
   node *cur = prev->next;
   node *tmp = NULL;

   *l= cur;
   while(1){
    tmp = cur->next; // future pointer
    cur->next = prev; // change cur direction

    if(tmp == NULL || tmp->next == NULL){
        prev->next= NULL;
        break;
    }
    prev->next = tmp->next; //jump 2 not 1.

    prev = tmp; //update pointers
    cur = tmp->next;
   }
}

node * pairwiseSwapRecur(node * l){
    if (l == NULL || l->next == NULL)
        return l;

    node * rem = l->next->next;
    node * newh = l ->next;

    l->next->next = l;
    l->next = pairwiseSwapRecur(rem);
}
