#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linkedlist.h"
#include "../../utils/utils.c"
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
/*
 * 1. check null
 * 2. store data
 * 3. update head
 * 4. free cur
 */
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
    push(&(cur->next),data);//important
}

node* deleteNodeRecur(node* cur, int targ){
    if(cur == NULL) return NULL;

    if(cur->x == targ){
        node *tmp = cur->next;
        free(cur);
        return tmp;
    }

    cur->next = deleteNodeRecur(cur->next, targ);

    return cur;
}

void deleteNodeIter(node ** l, int targ){
    node * prev, *cur;
    prev = NULL;

    for(cur=*l; cur!=NULL; prev=cur, cur=cur->next){
        if(cur->x == targ){
            if(prev == NULL)
                *l = cur->next;
            else{
                prev->next= cur->next;
            }
            free(cur);
        }
    }
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
void mergeSortList(node **h){
    node * head = *h;
    node *a, *b;
    //1. base
    if( head ==NULL || head->next == NULL)
        return;

    //2. split
    frontBackSplit(head, &a, &b);

    //3. recur
    mergeSortList(&a);
    mergeSortList(&b);

    //4. merger
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

void frontBackSplit(node *l, node **l1, node **l2){
    node *sp; //slow pointer
    node *fp; //fast pointer

    //base: read if lsrc is null return
    if(l == NULL || l->next == NULL) {
        *l1 = l;
        *l2 = NULL;
        return;
    }

    //initial assignment
    sp = l;
    fp = sp->next;

    //pointer traversals. No change in nodes
    while(fp !=NULL){
        fp = fp->next;
        if(fp != NULL){
            fp = fp->next;
            sp = sp->next;
        }
    }

    //assigning nodes here
    *l1 = l;
    *l2 = sp->next;
    sp->next = NULL;
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

void removeDupUnsorted(node *l){ //not changing head ptr
    node *i, *j, *tmp;

    i=l;
    while(i!=NULL && i->next != NULL){
        j = i;
        while(j->next != NULL){
            if(i->x == j->next->x){
                tmp = j->next;
                j->next = j->next->next;
                free(tmp);
            }else{
                j=j->next;
            }
        }
        i = i->next;
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

node *sortedMergeRecur(node *l1, node *l2){
    node * result;
    //base case: if one is null return the other
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;

    //compare immediate data
    if(l1->x < l2->x){
        //pre set result
        result = l1;
        l1->next = sortedMergeRecur(l1->next, l2);
    }
    else{
        result = l2;
        l2->next = sortedMergeRecur(l1, l2->next);
    }
    return result;
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

    //1. base
    if(*l == NULL) return;

    //2. divide into two halves
    first = *l;
    rest = first->next;

    //3. stopping condition
    if(rest == NULL) return;

    //4. recur
    recurseReverse(&rest);

    //5. put together: important
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
node * partitionList(node *h, node *e, node **newHead, node **newEnd){
    //1. set pivot as end of list
    node *pivot = e;
    node *prev= NULL, *cur = h, *tail = pivot;

    while(cur != pivot){
        // leave if smaller
        if(cur->x < pivot->x){
            if(*newHead == NULL)
                *newHead = cur;

            prev = cur;
            cur = cur->next;
        }else{
            //moving cur to end of tail=> tmp ptr, update tail
            if(prev)
                prev->next = cur->next;
            node *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if(*newHead == NULL)
        *newHead = pivot;

    *newEnd = tail;

    return pivot;
}
node *getTail(node *h){
    node *cur = h;
    while(cur != NULL && cur->next != NULL){
        cur = cur->next;
    }
    return cur;
}
node * quickSortList(node *head, node *e){
    //1. base
    if(head == NULL || head == e)
        return head;

    node * pivot;
    node *newHead = NULL, *newEnd = NULL;

    //2. parition
    pivot = partitionList(head, e, &newHead, &newEnd);

    //3. recur
    if(newHead != pivot){
        node *tmp = newHead;
        while(tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;

        newHead = quickSortList(newHead, tmp);

        tmp = getTail(newHead);
        tmp->next = pivot;
    }
    pivot->next = quickSortList(pivot->next, newEnd);

    return newHead;
}

node * pairwiseSwapRecur(node * l){
    if (l == NULL || l->next == NULL)
        return l;

    node * rem = l->next->next;
    node * newh = l ->next;

    l->next->next = l;
    l->next = pairwiseSwapRecur(rem);
}
/*
node * partitionDLL(node **head, node *l, node *r){
    int p = r->x;
    node *j = l->prev; //add for DLL

    for(node *i =l ; i != r ;i = i->next){
        if(i->x < p){//key 0
            j = (j == NULL) ? l : j->next;
            swapInts(&(j->x), &(i->x)); //key 1
        }
    }

    j = (j==NULL) ? l : j->next;
    swapInts(&(j->x), &(r->x)); //key2
    return j;


}

void quickSortDLL(node **head,node *l,node * r){
    node *p;
    if(r!=NULL && l != r && l!=r->next){
        p = partiitonDLL(head,l,r);
        quickSortDLL(head,l,p->prev);
        quickSortDLL(head,p->next,r);
    }
}
*/
node * getLastNode(node *l){
    node *cur = l;
    while(cur != NULL){
        cur = cur->next;
    }
    return cur;
}

void splitCLL(node *h, node **a, node **b){
    node * f, *s;
    //1. base
    if(h == NULL) return;
    //2. traverse: f,s pointers
    f = h; s = h;
    while(f->next != h && f->next->next != h){
        f = f->next->next;
        s = s->next;
    }
    //special case: even node case:
    if(f->next->next == h)
        f = f->next;
    //3. update head
    *a = h;
    if(h->next != NULL)
        *b = s->next;
    //4. update tail
    f->next = s->next;
    s->next = h;
}
