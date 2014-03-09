#include <stdio.h>

int lisfn(int *a, int n, int *max){
    if(n==1) return 1;

    int i, res, lmax =1;

    for(i=1; i<n ; i++){
        res = lisfn(a, i, max);
        if(a[i-1] < a[n-1] && res + 1 > lmax)
            lmax = res + 1;
    }

    if(*max < lmax)
        *max = lmax;

    return lmax;
}
