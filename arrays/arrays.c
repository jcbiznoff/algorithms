#include <stdlib.h>

int * findUnionSortedArr(int *a, int *b, int n, int m){
    int i=0, j=0,k=0;
    int *c = (int *)malloc(sizeof(int)* (m+n));

    while( i<n && j<m){
        if(a[i] < b[j])
            c[k++] = a[i++];
        else if(a[i] > b[j])
            c[k++] = b[j++];
        else{
            c[k++] = a[i++];
            j++;
        }
    }

    while(i<n)
        c[k++] = a[i++];
    while(j<m)
        c[k++] = b[j++];
    return c;
}

int *findIntersectionSortedArr(int *a, int*b, int n, int m){
    int i=0,j=0,k=0;
    int *c = (int *)malloc(sizeof(int)*(m+n));

    while(i<n && j<m){
        if(a[i] < b[j]) i++;
        else if(a[i] > b[j]) j++;
        else{
            c[k++] = a[i];
            i++; j++;
        }
    }
    return c;
}
