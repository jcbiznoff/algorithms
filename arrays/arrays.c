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

int findMedianSortedUtil(int a[], int b[], int l, int r, int n){

    int i,j;

    if(l>r)
        return findMedianSortedUtil(b,a,0,n-1,n);

    i = (l+r)/2;
    j = n-1-i;

    if(a[i] > b[j] && (j == n-1 || a[i]<=b[j+1])) {
        if( i==0 || b[j]> a[i-1])
            return (a[i]+b[j])/2;
        else
            return (a[i] + b[i-1])/2;
    }
    else if(a[i]>b[j] && j!=n-1 && a[i]>b[j+1])
        return findMedianSortedUtil(a,b,l,i-1,n);
    else
        return findMedianSortedUtil(a,b,i+1,r,n);
}

int findMedianSorted(int a[], int b[], int n){
    return findMedianSortedUtil(a,b,0,n-1,n);
}
