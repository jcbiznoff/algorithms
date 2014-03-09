/*
 * AVL > Red Black:
 *      search is more frequent
 *  Red Black > AVL:
 *      insertion, deletion is more frequent than search.
 */
typedef struct _node{
    struct _node *left, *right;
    int data;
    int height;
}node;

/*insertNode:
 *1. Do a normal BST insert w
  2. start@ w and move up until balance is false
  3. rebalance tree by 4 possible cases.
 */
node *insertNodeAVL(node *nd, int k);

//right-right case
//right-left case
//left-right case
node *leftRotate(node *);

//left-left case
//left-right case
//right-left case
node * rightRotate(node *);
node * newNode(int k);
int getHeight(node *);
node * deleteNode(node*);
int max(int, int);
int getBalance(node *);
node* getSuccessor(node *);
