#include "arrays.c"
#include <stdio.h>
#include "../utils/utils.c"

int main(){
    int a[] = {3, 7};
    int b[] = {1,2,4,5,6,7,8,9,10};
    int *c;

    c = findUnionSortedArr(a,b,2,9);
    c = findIntersectionSortedArr(a,b,2,9);

    printarray(c, 10);
    free(c);
}
