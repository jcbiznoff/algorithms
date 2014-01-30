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
void deleteList(node ** l){
    node *cur = *l;
    node *tmp;

    while(cur != NULL){
        tmp = cur->next;
        free(cur);
        cur = tmp;
    }
}
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


node* sortedInsert(node ** l1, node * l2){
    //two sorted list, give the intersection of two lists

    node * a;
    node *cur, *cur2;
    for(cur=a;cur!=NULL;cur=cur->next){
        for(cur2=a; cur2->x <cur->x; cur2=cur2->next){
            if(cur->x == cur2->x){
                push(&a,cur2->x);
                break;
            }
        }
    }
    return a;
    //1. advance cur until null for l1
    //2. advance cur2 until null for l2
    //3. if cur->x == cur2 ->x
    //      push(&a,x);
    //      break;
    //4. else continue;
    //5. return *a
    //
    //above is wrong assumption
    //1. loop while l1!=NULL and l2!=NULL
    //2. if l1->x == l2->x
    //      push x
    //      advance both
    //3. else if( l1->x > l2->x)
    //      l2 = l2->next;
    //4. else
    //      l1 = l1->next;
    //
}
void insertSort(node ** l){}
void append(node ** ldest, node ** lsrc){}
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
void removeDups(node * l){
}
void moveNode(node** l1, node** l2){}
void altSplit(node* src, node** l1, node** l2){}
node* shuffleMerge(node* l1, node* l2){}
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
            moveNode(lastRef, &l2);
        }
        else{
            //move l2 to l1
            moveNode(lastRef, &l1);
        }
        lastRef = &((*lastRef) -> next);
    }
    return(result);

}
node* sortedIntersect(node* l1, node* l2){}
void reverseList(node **l){}
void recurseReverse(node **l){}

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
