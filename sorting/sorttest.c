#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../datastructs/queue/queue.c"
#include "../utils/utils.c"
#include "sorttest.h"

void bubblesortt(char **a, int len){ //assume equal allocation size for each elem.
    int i, j =0;
    for (i=1; i< len; i++){
        for (j=1; j<= len-i; j++){
            if( strcmp(a[j-1] ,a[j])>0 )
                swapStr(&a[j-1], &a[j]);
        }
    }
}

void selectionSort(int *a, int len){
    int i,j;
    for (i=0; i<len; i++){
        for (j=i+1; j<len; j++){
            if(a[j] < a[i])
                swapInts(&a[j], &a[i]);
        }
    }
}

void insertionSort(int *a, int len){
    int i,j;
    for (i=1; i<len ;i++){
        j=i;
        while ((j>0) && (a[j-1]> a[j])){
            swapInts(&a[j-1], &a[j]);
            j--;
        }
    }
}

void insertionSort2(int *a, int len){
    int i,j,min;

    for (i=1; i<len; i++){
        if (a[i-1] > a[i]){
            min = a[i-1];
            for (j=0; j<i ;j++){
                if (a[j] > min){
                    memmove(&a[j+1], &a[j], sizeof(int)*(i-j));
                    a[j]= min;
                }
            }
        }
    }
}

int partition(int *a, int l, int h){
    int p = a[h];
    int j = l-1; //index of smaller elem.

    for(int i=l; i<h;i++){
        if(a[i] <= p){ //comparing against pivot. not a[i]
            j++;
            swapInts(&a[j], &a[i]);
        }
    }
    swapInts(&a[j+1], &a[h]);
    return j+1;
}

void quicksortt(int *a, int l, int h){
    int p;
    if (l<h){
        p = partition2(a,l,h);
        quicksortt(a,l,p-1);
        quicksortt(a,p+1,h);
    }
}

void mergeme(int *a, int s, int m, int e){
    int i;
    int l = s;
    int r = m + 1;
    int k =0;
    int *tmpa = (int*)malloc(sizeof(int)* (e-s+1));

    while( (l <= m) && (r <= e)){
        if (a[l] <= a[r])
            tmpa[k] = a[l++];
        else
            tmpa[k] = a[r++];
        k++;
    }
    while (l<=m)
        tmpa[k++] = a[l++];
    while (r<=e)
        tmpa[k++] = a[r++];

    k=0;
    for (i=s; i<=e; i++)
        a[i] = tmpa[k++];
    free(tmpa);
}
void mergemeq(int *a, int s, int m, int e){
    int i;
    queue buffer1, buffer2;

    initq(&buffer1);
    initq(&buffer2);

    for (i=s;i<=m;i++)enqueue(&buffer1, a[i]);
    for (i=m+1; i<=e; i++)enqueue(&buffer2, a[i]);

    i=s;
    while (!isEmpty(&buffer1) && !isEmpty(&buffer2)){
        if(headq(&buffer1) > headq(&buffer2))
            a[i++] = dequeue(&buffer2);
        else
            a[i++] = dequeue(&buffer1);
    }

    while (!isEmpty(&buffer1)) a[i++] = dequeue(&buffer1);
    while (!isEmpty(&buffer2)) a[i++] = dequeue(&buffer2);


}
void mergesortt(int *a, int start, int end){
    int mid;
    if (start < end){
        mid = (start + end) / 2;
        mergesortt(a, start, mid);
        mergesortt(a, mid+1, end);
        mergemeq(a, start,mid,end);
    }
}

void mergesortexec (int *a, int len){
    mergesortt(a, 0, len-1);
    printarray(a,len);
}
void heapsortexec(int *a, int len){
    /*
        pq q;
    initpq(&q);
    for (int i=0; i< len; i++)
        insertpq(&q, a[i]);

    heapsortt(&q);
    */
}

void countingsort(int *a, int len){
    int i,maxa=0;
    int c[100] ={};
    int b[100] = {};
    for (i=0;i<len; i++) maxa = maxInt(a[i],maxa);
    for (i=0;i<len; i++) c[a[i]]++;
    for (i=1; i<=maxa; i++) c[i] += c[i-1];

    for (i=len-1; i>=0 ; i--){
        b[c[a[i]]-1] = a[i];
        c[a[i]]--;
    }

    for(i=0; i<len; i++) a[i] = b[i];
}

/*radixSort:
 * sort digit by digit
 */

void countSortMod(int *a, int n, int digit){
    int i;
    int c[10]={}, out[n];
    for(i=0; i<n;i++) c[(a[i]/digit)%10]++; //smart move here. divide by the digit to truncate right most, then take mod to get right most dig. => sequential extrapolation: ex) 4321, digit 100 -> 43 -> 43 mod 10 => 3
    for(i=1; i<10; i++) c[i] += c[i-1];
    for (i=n-1; i>=0; i++){
        out[c[(a[i]/digit)%10 - 1]] = a[i];
        c[(a[i]/digit)%10]--;
    }

    for(i =0 ;i <n; i++) a[i] = out[i];
}


void radixSort(int *a, int n){
    int m = a[0]; //in order to save the maximum element for digit limit

    for (int i=0; i<n;i++)
        m = maxInt(m,a[i]);

    for (int i=1; m/i > 0; i*=10)
        countSortMod(a, n, i);
}
