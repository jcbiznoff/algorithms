#include <stdlib.h>

int * findUnion(int *a, int *b, int n, int m){
    int i=0, j=0,k=0;
    int *c = (int *)malloc(sizeof(int)* (m+n));
    while( i<n && j<m){
        if(a[i] < b[j])
            c[k++] = a[i++];
        else if(a[i] > b[j])
            c[k++] = b[j++];
        else{
            c[k++] = a[i];
            i++;j++;
        }
    }
    return c;
}

int *findIntersection(int *a, int*b, int n, int m){

}
