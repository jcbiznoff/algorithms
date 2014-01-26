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
/*
 * builds the following
 *           2
 *          / \
 *         1   4
 *            /
 *           3
 * */

node * build1234(){
    node *a = newNode(2);
    a->left = newNode(1);
    a->right = newNode(4);
    a->right->left = newNode(3);
    return a;
}

void print123(node *a){
    printf("  %d\n",a->data);
    printf(" / \\\n");
    printf("%d   %d\n",a->left->data, a->right->data);
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

void printLevelHelper(node *nd, int height){
    if (nd == NULL) return;
    if(height == 1) printf("%d ", nd->data);//leaf case

    printLevelHelper(nd->left, height-1);
    printLevelHelper(nd->right, height -1);
}
void printLevelorderTraverse(node *nd){
    int i=0;
    for(i=0; i<getHeight(nd);i++){
        printLevelHelper(nd,i);
    }
}
int getNodeNum(node *nd){
    if(nd == NULL) return 0;
    return getNodeNum(nd->left) + 1 + getNodeNum(nd->right);
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

void deleteAllNodes(node * nd){
    if(nd == NULL) return;

    deleteAllNodes(nd->left);
    deleteAllNodes(nd->right);
    free(nd);
}

void mirrorTree(node *nd){
    if(nd==NULL) return;

    mirrorTree(nd->left);
    mirrorTree(nd->right);
    node *tmp = nd->right;
    nd->right = nd->left;
    nd->left= tmp;
}
void printArray(int arr[], int len){
    int i;
    for(i=0; i<len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void printR2LpathHelper(node *nd, int arr[], int len){
    if(nd == NULL) return;

    if(nd->left == NULL && nd->right == NULL)
        printArray(arr,len);
    arr[len++] = nd->data;
    printR2LpathHelper(nd->left, arr, len+1);
    printR2LpathHelper(nd->right, arr, len+1);

}
void printR2Lpath(node *nd){
    int arr[1000];
    printR2LpathHelper(nd,  arr, 0);
}

int getMinValBST(node *nd){
    node * cur = nd;
    while(cur != NULL){
        cur = cur->left;
    }

    return cur->data;
}
