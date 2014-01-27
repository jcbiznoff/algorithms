#ifndef C_BINARYTREE_H
#define C_BINARYTREE_H
//base structure
typedef struct _node{
    struct _node *left;
    struct _node *right;
    int data;
}node;

//Tree base operations
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
void print123();

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

/*deleteNode:
 *  delete a single node with value x.
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
 *  gets height in iterative version
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
 */
int getDiameter(node *nd);//to do
/*getTreeMaxWidth:
 *  width = number of nodes in a single level
 *  max width = longest width in a tree
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
 */
void printGivenRangeBST(node *nd, int n1, int n2); //to do

/*isBSTSumTree:
 *  sum tree: node data is sum of all sub nodes
 */
int isBSTSumTree(node* nd);

/*isSubTree:
 *  check if one tree is contained with another
 */
int isSubTree(node *nd1, node *nd2);

/*largestBST:
 *  find largest BST in a Binary Tree
 */
int largestBST(node *nd);

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

/*sumExist:
 *  ?
 */
int sumExists(node *, int sum);

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
void convert2SumTree(node *nd1);
void toBSTtoBin(node *); //add all nodes greater than current to val
int binTree2BST(node*nd);
void linklist2BinTree(node*); //convert a link list to bin tree
void binTree2DoubleLinkList(node *);


//Two trees
int areTreesIdentical(node *nd1, node *nd2);

//BST only
int getMinValBST(node *nd);
int getMaxValBST(node *nd);
int isBST1(node * nd);
int isBST2(node *nd);
int isHeightBalancedBST(node *nd);// to do
int getKthSmallets(node *nd, int k);// to do

//Array Helper funcitons
void printArray(int arr[], int len);
#endif
