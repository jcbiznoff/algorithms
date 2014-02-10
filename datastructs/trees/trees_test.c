#include "trees.c"

int main(){
    node * root = build1234();

    printLevelorderTraverse(root);

    mirrorTree(root);

    printLevelorderTraverse(root);

    return 0;
}
