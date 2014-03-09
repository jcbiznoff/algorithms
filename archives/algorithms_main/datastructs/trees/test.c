#include <stdio.h>
#include "trees.c"

int main(){
    /*
    node * a= build123();
    print123(a);
    printInorderTraverse(build1234());
    free(a);
    */

    //test number of bst created from node#
    /*
    int i;
    for(i=0;i<5;i++)
        printf("#trees: %d\n", countPossibleTrees(i));
    */

    //create a sample tree to play with
    node *a = build1234();
    int tsum;
    while(1){
        scanf("%d", &tsum);
        printf("test res: %d\n", hasPathSum(a,tsum));
    }

    return 0;
}
