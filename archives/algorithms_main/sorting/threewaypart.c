#include <stdio.h>

/* microsoft interview question
 * three way partitioning, dutch national flag algorithm
 * kind of like paritioning in quick sort
 *
 * time complexity: O(n)
*/

void swapInts(int *a, int *b){
    int tmp = *a;
    *a=*b;
    *b=tmp;
}

void sort012(int *a, int n){
    //1. init l,m,h index
    int l=0, m=0, h=n-1;
    //2. loop while m<=h
    while(l<=m && m<=h){
    //3.    three cases for a[m]
        switch(a[m]){
    //          0: swap a[l] and a[m]; l++, m++
            case 0:
                swapInts(&a[l], &a[m]);
                l++; m++;
                break;
    //          1: m++
            case 1:
                m++;
                break;
    //          2: swap a[m] and a[h]; h--
            case 2:
                swapInts(&a[m], &a[h]);
                h--;
                break;
        }
    }
}
void sort01(int *a, int n){
    //1. init l=0; h = n-1;
    int l=0, h=n-1;
    //2. loop while l<=h
    while(l<=h){
    //3. if a[l] =0, l++
        if(a[l] == 0) l++;
    //   else swap a[l] and a[h]; h--;
        else{
            swapInts(&a[l], &a[h]);
            h--;
        }
    }
}

