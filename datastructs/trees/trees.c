#include <stdio.h>
#include <stdlib.h>
#include "trees.h"
node * newNode(int x){
    node * nd = (node*)malloc(sizeof(node));
    nd->left = NULL;
    nd->right = NULL;
    nd->data = x;
    return nd;
}
node * build123(){
    node * a = newNode(2);
    a->left = newNode(1);
    a->right = newNode(3);
    return a;
}
node * build1234(){
    node *a = newNode(2);
    a->left = newNode(1);
    a->right = newNode(4);
    a->right->left = newNode(3);
    return a;
}
node *buildLLTree(){
    node *a = newNode(10);
    a->left = newNode(4);
    a->right = newNode(15);
    a->left->left = newNode(2);
    a->left->right = newNode(8);
    a->left->left->left = newNode(1);
    a->left->left->right = newNode(3);
    return a;
}
node * buildRRTree(){
    node * a = newNode(10);
    a->left = newNode(2);
    a->right = newNode(20);
    a->right->left = newNode(15);
    a->right->right = newNode(24);
    a->right->right->left = newNode(22);
    a->right->right->right = newNode(100);
    return a;
}
node * buildLRTree(){
    node *a = newNode(10);
    a->left = newNode(5);
    a->right = newNode(20);
    a->left->left = newNode(3);
    a->left->right = newNode(8);
    a->left->right->left = newNode(6);
    a->left->right->right = newNode(9);
    return a;
}
node *buildRLTree(){
    node *a = newNode(10);
    a->left = newNode(5);
    a->right =newNode(20);
    a->right->right = newNode(30);
    a->right->left = newNode(15);
    a->right->left->left = newNode(12);
    a->right->left->right = newNode(18);
    return a;
}
node *buildComplex(){
    node *a = newNode(4);
    a->left = newNode(1);
    a->right = newNode(5);
    a->left->right = newNode(3);
    a->left->right->left = newNode(2);
    a->right->right = newNode(10);
    a->right->left = newNode(7);
    a->right->right->right = newNode(12);

    return a;
}
void print123(node *a){
    printf("  %d\n",a->data);
    printf(" / \\\n");
    printf("%d   %d\n",a->left->data, a->right->data);
}
void deleteAllNodes(node * nd){
    if(nd == NULL) return;

    deleteAllNodes(nd->left);
    deleteAllNodes(nd->right);
    free(nd);
}
void insertNodeBST(node *nd, int x){
    if(nd == NULL) {
        nd = newNode(x);
        return;
    }
    if(x <= nd->data)
        insertNodeBST(nd->left, x);
    else
        insertNodeBST(nd->right,x);
}

node* searchNodeBST(node *nd, int x){
    if(nd == NULL) return NULL;

    if(nd->data == x) return nd;

    else if (nd->data > x)
        return searchNodeBST(nd->right, x);
    else
        return searchNodeBST(nd->left, x);

}

node *deleteNodeBST(node *nd, int x){
    node * retval = NULL;
    if (nd == NULL) return NULL;
    if (nd->data == x){
        if(nd->left == NULL){
            retval = nd->right;
            free(nd);
            return retval; // dont worry about linking parent to grand. just return
        }
        else if (nd->right == NULL){
            retval = nd->left;
            free(nd);
            return retval;
        }else{
            node *successor = getSuccessor(nd->left);
            nd->data = successor->data;
            nd->left = deleteNodeBST(nd->left, successor->data);
        }
    }
    else if( nd->data < x){
        nd->right = deleteNodeBST(nd->right, x);// link parent to grand here.
    }
    else
        nd->left = deleteNodeBST(nd->left, x);

    return nd;
}

node *getSuccessor(node * nd){
    while(nd != NULL)
        nd= nd->right;
    return nd;
}

node *searchNode(node * nd, int k){
    node *res = NULL;
    if(nd == NULL) return NULL;

    if(nd->data == k) return nd;

    if(nd->left != NULL)
        return searchNode(nd->left,k);
    if(nd->right != NULL)
        return searchNode(nd->right,k);
}

//Traversals
void printInorderTraverse(node * nd){
    if(nd == NULL) return;
    printInorderTraverse(nd->left);
    printf("%d ", nd->data);
    printInorderTraverse(nd->right);
}
void printPostorderTraverse(node *nd){
    if(nd == NULL) return;
    printPostorderTraverse(nd->left);
    printPostorderTraverse(nd->right);
    printf("%d ", nd->data);
}
void printPreorderTraverse(node *nd){
    if (nd == NULL) return;
    printf("%d ",nd->data);
    printPreorderTraverse(nd->left);
    printPreorderTraverse(nd->right);
}
void printLevelorderTraverse(node *nd){
    int i=0;
    for(i=1; i<=getHeight(nd);i++){
        printLevelHelper(nd,i);
        printf("\n");
    }
    printf("\n");
}
void printLevelHelper(node *nd, int height){
    if (nd == NULL) return;
    if(height == 1) printf("%d ", nd->data);//leaf case
    printLevelHelper(nd->left, height-1);
    printLevelHelper(nd->right, height -1);
}
void printSpiralLevelorder(node *nd){
    int i;
    int dir=0;

    for(i=1; i<=getHeight(nd); i++){
        printSpiralHelper(nd, i, dir);
        dir= !dir;
    }
}
void printSpiralHelper(node *nd, int lvl, int dir){
    if(nd == NULL) return;
    if(lvl == 1) printf("%d ", nd->data);

    if(dir == 0){
        printSpiralHelper(nd->left, lvl-1, dir);
        printSpiralHelper(nd->right,lvl-1, dir);
    }
    else{
        printSpiralHelper(nd->right, lvl-1, dir);
        printSpiralHelper(nd->left,lvl-1, dir);
    }
}
void printReverseLevelTraverse(node *nd){
    int i;
    for(i=getHeight(nd) ; i>0; i--){
        printLevelHelper(nd, i);
    }
}

void printInorderMorris(node *nd){
    node *cur = nd;
    node *pre;
    if(nd == NULL)
         return;

    while(cur != NULL){
        if(cur->left == NULL){
            printf("%d ", nd->data);
            cur = cur->right;
        }else{

            pre= cur->left;
            while(pre->right != NULL && pre->right != cur)
                pre=pre->right;
            if(pre->right ==NULL){
                pre->right =cur;
                cur= cur->left;
            }else{
                pre->right =NULL;
                printf("%d ", cur->data);
                cur=cur->right;
            }
        }
    }
}


void printNodesOneLevel(node *nd, int lvl){
    printLevelHelper(nd,lvl);
}
int getHeight(node * nd){
    int a = 0;
    int b =0;

    if(nd == NULL) return 0;

    a = getHeight(nd->left);
    b = getHeight(nd->right);

    if(a>b) return a+1;
    return b+1;
}
int getNodeLvl(node *nd, int k, int lvl){
    if (nd == NULL) return 0;

    if(nd->data == k) return lvl;

    int dlev = getNodeLvl(nd->left, k, lvl+1);

    if(dlev) return dlev;

    dlev = getNodeLvl(nd->right, k, lvl +1);
    return dlev;
}
int getNodeNum(node *nd){
    if(nd == NULL) return 0;
    return getNodeNum(nd->left) + 1 + getNodeNum(nd->right);
}
void printR2Lpath(node *nd){
    int arr[1000];
    printR2LpathHelper(nd,  arr, 0);
}
void printR2LpathHelper(node *nd, int arr[], int len){
    if(nd == NULL) return;

    if(nd->left == NULL && nd->right == NULL)
        printArray(arr,len);
    arr[len++] = nd->data;
    printR2LpathHelper(nd->left, arr, len+1);
    printR2LpathHelper(nd->right, arr, len+1);
}
int hasPathSum(node *nd, int sum){
    if (nd == NULL) return (sum == 0); //base case

    sum = sum - nd->data;
    return hasPathSum(nd->left, sum) || //recursive case
           hasPathSum(nd->right,sum);
}
void doubleTree(node *nd){
    if(nd == NULL) return;
    doubleTree(nd->left);
    doubleTree(nd->right);

    node *tmp = nd->left;
    nd->left = newNode(nd->data);
    nd->left->left = tmp;
}
void mirrorTree(node *nd){
    if(nd==NULL) return;

    mirrorTree(nd->left);
    mirrorTree(nd->right);
    node *tmp = nd->right;
    nd->right = nd->left;
    nd->left= tmp;
}
int countPossibleTrees(int n){
    if(n == 0 || n ==1) return 1;

    int sum = 0;
    int i;
    for(i=1; i<=n; i++){
        sum = sum + countPossibleTrees(i-1)*countPossibleTrees(n-i);
    }

    return sum;
}
int areTreesIdentical(node *a, node *b){
    if(a == NULL && b == NULL) return 1;

    if(a != NULL && b!= NULL){
    return (a->data == b->data)
        &&areTreesIdentical(a->left,b->left)
        &&areTreesIdentical(a->right,b->right);
    }
    return 0;
}
int getMinValBST(node *nd){
    node * cur = nd;
    while(cur != NULL){
        cur = cur->left;
    }
    return cur->data;
}
int getMaxValBST(node *nd){
    node *cur = nd;
    while(cur != NULL){
        cur = cur->right;
    }
    return cur->data;
}
int isBST1(node *nd){
    if(nd == NULL) return 1;

    if(nd->left != NULL && getMaxValBST(nd->left) > nd->data)
        return 0;

    if(nd->right != NULL && getMaxValBST(nd->right) <= nd->data)
        return 0;

    if(!isBST1(nd->left) || !isBST1(nd->right))
        return 0;

    return 1;
}
int isBST2(node *nd){}

//util funcitons below
void printArray(int arr[], int len){
    int i;
    for(i=0; i<len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int max(int a, int b){
    return (a>b)? a : b;
}
