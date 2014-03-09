//structure
//tree node
typedef struct _tnode{
    struct _tnode *left;
    struct _tnode *right;
    int data;
}tnode;
//stack: linked list implementation
typedef struct _node{
    tnode *t;
    struct _node* next;
}snode;
//Api for stack extending for tree case
/*push:
 * push a tree node into a stack
 */
void push(snode **head, tnode *node);

/*pop:
 * pops a tree element out of stack
 */
tnode *pop(snode ** head);

/*isEmpty:
 * check if stack is empty
 */
int isEmpty(snode *head);

tnode *newNode(int x);

//Api for tree + stack
/*printinordernorecur:
 *  1. initialize a stack
 *  2. loop until done
 *  3.  push left node if current node is not null
 *      else pop current node
 *           print value
 *           move right
 *  4. repeat until node is null and stack is empty
 */
void printInorderNoRecur(tnode *node);

