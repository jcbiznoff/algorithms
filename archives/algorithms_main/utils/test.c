#include <stdio.h>
#include <stdlib.h>
#include "utils.c"

int main(){
    int i;
    char a[][10] = {"mark","blehbleh", "zch", "chat"};
    qsort((void*)a, 4, sizeof(a[0]), strCmpr);

    for(i=0; i<4;i++)
        printf("%s\n",a[i]);

    return 0;
}

