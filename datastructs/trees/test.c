#include <stdio.h>
#include "trees.c"

int main(){
    node * a= build123();
    print123(a);

    printInorderTraverse(build1234());

    free(a);
    return 0;
}
