#include <stdio.h>
#include "backtrack.c"
int main(){
    int a[100];
    int i;
    for (i=0; i<100; i++) a[i] = 0;
    backtrackk(a,0,4);

    return 0;
}
