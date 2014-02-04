#include <stdio.h>
#include <stdlib.h>
#include "avl.h"


node *insertNodeAVL(node * nd, int key){
    //1. Normal BST insert, moving down tree
    if(nd == NULL) return newNode(key);

    if(key < nd->data)
       nd->left = insertNodeAVL(nd->left, key);
    else
        nd->right =  insertNodeAVL(nd->right, key);

    //2. get height of the current node
    nd->height = max(getHeight(nd->left), getHeight(nd->right)) + 1;

    //3. check if balance is good
    int balance = getBalance(nd);

    //4. rotate according to 4 configration
    //LL
    if(balance > 1 && getBalance(nd->left)>=0){
        return rightRotate(nd);
    }
    //RR
    if(balance < -1 && getBalance(nd->right) <0){
        return leftRotate(nd);
    }
    //LR
    if(balance > 1 && getBalance(nd->left) <0){
        nd->left = leftRotate(nd->left);
        return rightRotate(nd);
    }
    //RL
    if(balance < -1 && getBalance(nd->right)>=0){
        nd->right = rightRotate(nd->right);
        return leftRotate(nd);
    }
    return nd;
}

node * deleteNodeAVL(node  *nd, int key){
    //1. do a standard BST deletion
    //  using post order
    if(nd == NULL) return NULL;

    if(key < nd->data)
        nd->left = deleteNodeAVL(nd->left,key);
    else if(key > nd->data)
        nd->right = deleteNodeAVL(nd->right,key);
    else{ //match found
        //does it have any child?
        if(nd->right == NULL || nd->left == NULL){
            node * tmp = nd->left ? nd->left : nd->right;
            // if no child
            if(tmp==NULL){
                tmp = nd;
                nd = NULL;
            }else{ //one child
                *nd = *tmp; //copy contents
                free(tmp);
            }
        }else{ //yes. has both child
            node * tmp = getSuccessor(nd->left);
            nd->data = tmp->data;
            nd->left = deleteNodeAVL(nd->left, tmp->data);
        }
    }
    //if only one node, return
    if(nd == NULL) return NULL;

    //2. adjust height
     nd->height = max(getHeight(nd->left), getHeight(nd->right)) + 1;

    //3. get balance
    int balance = getBalance(nd);

    //3. do rotation based on configuration (if unbalanced)
    //LL
    if(balance > 1 && getBalance(nd->left) >=0)
        return rightRotate(nd);
    //LR
    if(balance > 1 && getBalance(nd->left) < 0){
        nd->left = leftRotate(nd->left);
        return rightRotate(nd);
    }
    //RR
    if(balance < -1 && getBalance(nd->right) <= 0)
        return leftRotate(nd);
    //RL
    if(balance < -1 && getBalance(nd->right) >0 ){
        nd->right = rightRotate(nd->right);
        return leftRotate(nd);
    }
    //4. return root node.
    return nd;
}

node *leftRotate(node *nd){
    //save tmp data and swap
    node * tmp = nd->right;
    node * tmp2 = tmp->left;

    tmp->left = nd;
    nd->right = tmp2;

    //2. update height
    tmp->height = max(getHeight(tmp->left), getHeight(tmp->right)) + 1;
    tmp2->height = max(getHeight(tmp2->left), getHeight(tmp2->right)) + 1;

    //3. return root
    return nd;
}

node * rightRotate(node * nd){
    //save tmp data, and swap
    node * tmp = nd->left;
    node * tmp2 = tmp->right;

    tmp-> right = nd;
    nd->left = tmp2;

    //2. update heights
    tmp->height = max(getHeight(tmp->left), getHeight(tmp->right)) + 1;
    tmp2->height = max(getHeight(tmp2->left), getHeight(tmp2->right)) + 1;
    //3. return root
    return tmp;
}

//helper fn
node *newNode(int k){
    node * a = (node *)malloc(sizeof(node));
    a->left = NULL;
    a->right = NULL;
    a->data = k;
    a->height = 1;
    return a;
}
int getBalance(node * nd){
    if(nd == NULL) return 0;
    return getHeight(nd->left) - getHeight(nd->right);
}
int getHeight(node *nd){
    if(nd == NULL) return 0;

    return nd->height;
}
int max(int a, int b){
    return (a > b) ? a: b;
}
