#ifndef C_BINARYTREE_H
#define C_BINARYTREE_H
//tree's node struct
typedef struct _node{
    struct _node *left;
    struct _node *right;
    int data;
}node;

/*newNode:
 *  creates a newNode in heap with data. Returns pointer to this node.
 */
node *newNode(int x);

/*build123:
 * builds the following
 *           2
 *          / \
 *         1   3
 */
node *build123();

/*build1234:
 * builds the following
 *           2
 *          / \
 *         1   4
 *            /
 *           3
 */
node *build1234();

/*buildComplex:
 * builds the following
 *            4
 *          /   \
 *         1     5
 *          \   / \
 *          3  7   10
 *         /        \
 *        2         12
 */
node* buildComplex();

/*print123:
 * prints the following on console
 *           2
 *          / \
 *         1   3
 */
void print123(node *a);

/*buildLLTree:
 *          10
 *         /  \
 *        4   15
 *       / \
 *      2   8
 *     / \
 *    1  3
 */
node* buildLLTree();


/*buildRRTree:
 *  10
 *  / \
 * 2  20
 *   / \
 *  15  24
 *      / \
 *     22  100
 */
node * buildRRTree();

/*buildLRTree:
 *      10
 *     /  \
 *    5   20
 *   / \
 *  3   8
 *     /  \
 *    6    9
 */
node *buildLRTree();

/*buildRLTree
 *    10
 *    / \
 *   5   20
 *       / \
 *      15  30
 *     / \
 *    12  18
 *
 */
node *buildRLTree();

//Dictionary Operation
/*deleteAllNodes:
 *  free all nodes from a tree
 */
void deleteAllNodes(node *nd);

/*insertNodeBST:
 *  inserts a single node to a BST with value x
 */
void insertNodeBST(node *nd, int x);

/*searchNodeBST:
 *  search a tree with node value k
 */
node *searchNodeBST(node *nd, int k);

/*deleteNodeBST:
 */
node* deleteNodeBST(node *nd, int k);

node *getSuccessor(node *nd);

/*searchNode:
 *  search a tree with node value k
 */
node *searchNode(node *nd, int k);

/*deleteNode:
 *  delete a single node with value x.
 *  this sounds impossible. probably need some structure on how to handle deletes
 *
 */
void deleteNode(node *nd, int x);

//reads: Traversals
/*printInorderTraverse:
 *  print data using in order traversal
 */
void printInorderTraverse(node *nd);

/*printPostorderTravers:
 *  print data using post order traverse
 */
void printPostorderTraverse(node *nd);

/*printPreorderTraverse:
 *  print data using pre order traverse
 */
void printPreorderTraverse(node *nd);

/*printLevelorderTraverse:
 *  print data on each level from top to bottom
 */
void printLevelorderTraverse(node *nd);

/*printLevelHelper:
 *  level order helper
 */
void printLevelHelper(node *nd, int lvl);

/*printSpiralLevelorder:
 *  print nodes in a spiral order
 */
void printSpiralLevelorder(node * nd);

/*printSpiralHelper
 *  print in a spiral fashion
 */
void printSpiralHelper(node *nd, int lvl, int dir);

/*pintReverseLevelTraverse:
 *  print in a reverse order
 */
void printReverseLevelTraverse(node *nd); //needs verification

/*printBoundaryTraverse:
 *  prints the boundary of a binary tree root counter clock wise
 *  => print left : root to leaf-1
 *  => print leaves: left to right
 *  => print right: leaf-1 to root
 */
void printBoundaryTraverse(node *nd);// to do

/*printNodesOneLevel:
 *  given a level, print all nodes in it.
 */
void printNodesOneLevel(node *nd, int lvl);// to do

//basic apis
/*getHeight:
 *  gets the tree height recursive version
 */
int getHeight(node*nd);

/*getHeightIter:
 *  gets height in iterative version using queue ds, like level order traversal
 *  1. init queue and push root
 *  2. loop
 *  3. if not empty, increase height by 1
 *  4. else return;
 *  5. while not empty
 *      pop front
 *      push children to queue
 *      decrease node count
 *  6. go to 2
 */
int getHeightIter(node *n);// to do

/*getNodeLvl:
 *  gets the level which k is located in
 */
int getNodeLvl(node *nd,int k,int lvl);

/*getNodeNum:
 * find the number of nodes in a tree
 */
int getNodeNum(node *nd);

/*printR2Lpath:
 *  print the path from root to leaf
 */
void printR2Lpath(node *nd);

/*printR2LpathHelper:
 *  helper funciton for the above
 */
void printR2LpathHelper(node *nd, int arr[], int len);

/*hasPathSum:
 *  if path sum is equal to sum return true
 */
int hasPathSum(node*nd, int sum);

/*doubleTree:
 *  adds duplicate node to left
 */
void doubleTree(node *nd);

/*mirrorTree:
 *  swaps the position of nodes
 */
void mirrorTree(node *nd);

/*sumAllPathVals:
 *  root to leaf : build number
 *  sum all root to leafs
 */
int sumAllPathVals(node *nd);

/*getDiameter:
 *  diameter of a tree = length of the longest path between two nodes
 *      max of 1)height of left + height of right + 1, 2) diameter of left subtree, 3) diameter of right subtree
 *  1. Base: if nd is null return 0
 *  2. Leaf: should return 1, but take into account @ recursion
 *  3. Recur: return max of getHeight(left sub)+getHeight (right sub)+1, getDiameter(leftsub), getDiameter(rightsub)
 */
int getDiameter(node *nd);//to do

/*getTreeMaxWidth:
 *  width = number of nodes in a single level
 *  max width = longest width in a tree
 *
 *  1.base: if nd is null return 0;
 *  2.leaf: same as base
 *  3. recur:
 */
int getTreeMaxWidth(node *nd);//to do

/*isFoldable:
 *  foldable: left and right subtrees are mirror images
 */
int isFoldable(node *nd); // to do

/*printAncestor:
 *  ancestor: all parents from a node
 *  list all parents from a node when found.
 */
void printAncestor(node *nd, int k);// to do

/*printGivenRangeBST:
 *  given a lower bound and a upper bound, print a range of values in BST
 *
 */
void printGivenRangeBST(node *nd, int n1, int n2); //to do

/*isBSTSumTree:
 *  sum tree: node data is sum of all sub nodes
 *      => do a preorder traversal of all nodes
 *  1. Base: if node null then return 1
 *  2. Leaf: if node left and right  does not exist return 1
 *  3. check each leaf
 *  4. check condition, recur down both left and right, return with and operation
 */
int isBSTSumTree(node* nd);

/*isSubTree:
 *  check if one tree is contained with another
 *  1. base: if node 1 and 2 are both null return true
 *  2. false case: if node 1 or node 2 either null return false
 *  3. recur: && data, l subtree, right subtree
 */
int isSubTree(node *nd1, node *nd2);

/*printVerticalSum:
 *  vertical sum: tree divided into vertical cells, find sum of node data in each cell
 */
void printVerticalSum(node *nd);

/*maxSumR2L:
 * SumR2L: sum of elementes from a path
 * max: maximum of these sums
 */
int maxSumR2L(node *nd);

/*isSingleChildTree:
 * check if each child of node is single.
 */
int isSingleChildTree(node *nd);

/*isComplete:
 *  completeness: all levels are filled. last level fills from left.
 */
int isComplete(node *nd);

/*swap2Incorrect:
 *  two incorrect nodes in a BST, => swap the two nodes
 */
void swap2Incorrect(node *nd);

/*buildTreePreandPost:
 *  build a tree from list of preorder traversal and post order traversal
 */
void buildTreePreandPost(node *nd);

/*getCeil:
 *  given a value find the next higer value in a BST?
 */
int getCeil(node *nd, int k);

/*removeNodesInRange:
 *  remove all nodes with data less than min and greater than max.
 *
 */
void removeNodesInRange(node *nd, int min, int max);

int isIsomorphic(node *n1, node *n2);

/*removeNodesSumLessThanK:
 * removes all nodes for path sum greatear than given k
 */
void removeNodesSumLessthanK(node *n1, int sum);

int getDeepestLeftNode(node *n1);

/*:findNextRightNode:
 *  given node with value k, return data to the right on the same lvl
 */
int findNextRightNode(node *n1, int k);

/*countLeafNodeNum:
 *  count how many leaves are in a tree
 *      => recursive add left and right sub trees, with returning 1 in the leaf case
 */
int countLeafNodeNum(node *nd);

/*printCustomTree:
 *  give a set of links, draw a tree
 */
void printCustomTree(node *n);

/*diffOddEvenLvl:
 *  difference between the sum of odds and even level nodes
 */
int diffOddEvenLvl(node *n);
/*getDeepestOddLvl:
 * returns node data at the deepest odd lvl
 */
int getDeepestOddLvl(node *n, int lvl);

/*leavesSameLevel:
 *      check if all leaves are at same lvl
 */
int leavesSameLevel(node *n);

/*printLeftNodesAllLevel:
 *  print only the left most nodes on each lvl.
 */
void printLeftNodesAllLevel(node *n);

/*doesNodeExist:
 *  determine if a node with a certain value x exists.
 */
int doesNodeExist(node *nd, int x);

/* countPossibleTrees(int n):
 * all possible formation of a BST with a given number of nodes
 *  bstn = catalan # = (2n)! / (n+1)!n!
 *
 *  this implementation relies on a recursive formulation for the above
 *  b(n) = sum(b(i-1)*b(n-i)) where i=1 to n
 *
 */
int countPossibleTrees(int numberm);

//conversions
/*convert2SumTree:
 *  sum tree: every node is a sum of two children node
 *      => diff = node->data - sum(child1, child2)
 *  1. base: nd == NULL => return
 *  2. leaf: return
 *  3. post ordr recur
 *  4. diff: diff<0 =>  add diff to node->data
 *  5.      diff>0 => increment left child by diff
 *
 * incrementSumTree:
 *  0. if left node exists
 *  1. increment left child by diff
 *  2. recur down left
 *  3. if right node exists
 *  4. increase node->right
 *  5. recur down right
 *
 */
void convert2SumTree(node *nd1);

/*convert2sumtree2:
 *  1. base: node is null return 0
 *  2. store current val
 *  3. update current val = sum of subtree left, subtree right
 *  4. return curval + old val;
 */
int convert2Sumtree2(node *nd1);


void toBSTtoBin(node *); //add all nodes greater than current to val

/*binTree2BST:
 *  convert a binary tree to BST:
 *  => do an inorder traversal, saving each element to an array
 *  => perform sorting on the array
 *  => copy sorted array to each element while doing inorder traversal again.
 */
int binTree2BST(node*nd);

/*addGreaterValNodesInBST:
 *  prop: sum all nodes in the right, which is always greater than current
 *  1. recur right
 *  2. sum = sum + node->data;
 *  3. update node->data;
 *  2. recur left subtree with sum
 */
void addGreaterValNodesInBST(node *);

void linklist2BinTree(node*); //convert a link list to bin tree

/*binTree2DoubleLinkList:
 *  convert a binary tree to double link list with head as left most tree
 *  1. If left sub tree exists, process left
 *  2. convert left sub tree to DLL, recursivly
 *  3. find inorder prdecessor of root in left subtree ( right most node in the left sub tree)
 *  4. make in order predeccessor as previous  of root and root as next of inorder predecessor
 *  5. If right sub tree exists, process right do similar as above
 *  6. find left most node and return it.
 */
void binTree2DoubleLinkList(node *);
void binTree3CircularDLL(node *);


//Two trees
int areTreesIdentical(node *nd1, node *nd2);

//BST only
int getMinValBST(node *nd);
int getMaxValBST(node *nd);

int isBST1(node * nd);
int isBST2(node *nd);
int isHeightBalancedBST(node *nd);// to do
int getKthSmallets(node *nd, int k);// to do

//other ds combined:
//preorder to BST
/*preorder2BST:
 *  given a list of array build a BST
 *  1. set first element as root
 *  2. find index i, greater than the root. set this as right
 *  3. recurse elements l to i
 *  4. recurse elements i+1 to h
 */
 void preorder2BST(node *);
 void preorder2BSTHelper(node *, int arr[], int* cur, int start, int end, int size);

 /*preorder2BSTStack:
  * read an array, save it into stack, return node
  * 1. init root node with arr[0] and push to stack
  * 2. iterate thtrough size
  * 3. pop stack until empty and while next value is greater than top
  * 4. make current node's right to data, push on top.
  * 5. if next value small, make current nodes left to data, push on top
  * 6. return root.
  */
node * preorder2BSTStack(int arr[], int size);

//inorder traversal no recursion
/*printInorderWithStack:
 *  1. initialize cur node as root
 *  2. push cur node and cur=cur->left until cur is null
 *  3. if cur is null and stack not empty
 *      1) pop from top
 *      2) print popped item and cur=cur->right
 *      3) go to step2
 *  4. if cur is null and stack empty then done
 */
void printInorderWithStack(node * nd);

/*printInorderMoris:
 * inorder traversal no recursion, no stack
 * 1. initi cur as root
 * 2. while cur is not null
 * 3. if cur->left is null
 * 4. print cur data, and cur=vur->right
 * 5. else
 * 6. make cur->right as right most node is currents left sub tree
 * 7. cur=cur->left
 */
void printInorderMorris(node *nd);

/*mergeBSTs:
 *  merge two binary trees
 *  => sol1: insert each elements of bst1 to bst2
 *  => sol2: 1) inorder traversal of each, save to array, 2) merge two arrays 3) create a new bst from this array
 *  => sol3: in place merge using DLL: 1) convert each BST to DLL 2) merge two DLLS 3) Build BST from list
 */
node * mergeBSTs(node *n1, node *n2);


/*mergeBSTNoSpace: extremely difficult
 */
node * mergeBSTNoSpace(node* n1, node* n2);

// difficult here:
//
/*inorderSuccssorBST:
 *  finds the next biggest node in a BST
 *
 *  */
node * inOrderSuccessorBST(node *nd, node *n);

node * sortedArray2BST(int arr[],int left, int right);

/*largestBST:
 *  find largest BST in a Binary Tree
 */
int largestBST(node *nd);

//struct with next*
connectsNodeSameLevel(node *);
connectsNodeSameLevelNoSpace(node*);
populateInorderSuccessor(node *);

//Array Helper funcitons
void printArray(int arr[], int len);
#endif
