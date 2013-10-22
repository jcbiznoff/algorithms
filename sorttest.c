#include <stdio.h>
#include "sorttest.h"
#include <string.h>
void printarray(int *a, int len){
    int i;
    printf("{");
    for (i=0; i<len;i++){
        printf("%d ",a[i]);
    }
    printf("}\n");
}
void selectionSort(int *a, int len){
    int min, tmp;
    int i,j;
    for (i=0; i<len; i++){
        min = i;
        for (j=i+1; j<len; j++){
            if(a[j] < a[min]){
                tmp = a[min];
                a[min] = a[j];
                a[j] = tmp;
            }
        }
    }

    printarray(a,len);
}

void insertionSort(int *a, int len){
    int i,j,tmp;
    for (i=1; i<len ;i++){
        j=i;
        while ((j>0) && (a[j-1]> a[j])){
            tmp = a[j];
            a[j] = a[j-1];
            a[j-1] = tmp;

            j--;
        }
    }
    printarray(a,len);
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
    printarray(a,len);
}
int partition (int *a, int l, int h){
    int key = h;
    int i;
    int idx = l;
    int tmp;

    for (i=1; i<h ;i++){
        if(a[key] > a[i]){
            tmp = a[idx];
            a[idx] = a[i];
            a[i] = tmp;
            idx++;
        }
    }

    tmp = a[key];
    a[key] = a[idx];
    a[idx] = tmp;

    return idx;

}
int partition2(int *a, int l, int h){
    int f= l;
    int p = a[f];
    int tmp;
    //p = a[0];
    l++;
    while(l<=h){
        while(a[l] <= p && l<=h)
            l++;
        while(a[h] > p && l<h)
            h--;
        if(l<h){
            tmp = a[l];
            a[l] = a[h];
            a[h] = tmp;
        }
        else
            break;
    }
    tmp = a[f];
    a[f] = a[h];
    a[h] = tmp;

    return h;
}

void quicksortt(int *a, int l, int h){
    int p;
    if (l<h){
        p = partition2(a,l,h);
        quicksortt(a,l,p-1);
        quicksortt(a,p+1,h);
    }
}

void quicksortexec(int *a, int l, int  h){
    quicksortt(a,l,h);
    printarray(a,h);
}
