typedef struct _node{
    struct _node *left;
    struct _node *right;
    int data;
}node;

//Tree base operations
node *newNode(int x);
node *build123();
node *build1234();
void print123();

//Dictionary Operation
void deleteAllNodes(node *nd);
void insertNodeBST(node *nd, int x);


//Traversals
void printInorderTraverse(node *nd);
void printPostorderTraverse(node *nd);
void printPreorderTraverse(node *nd);
void printLevelorderTraverse(node *nd);
void printLevelHelper(node *nd, int lvl);
void printSpiralLevelorder(node * nd); //to do
void printSpiralHelper(node *nd, int lvl);//to do
void printReverseLevelTraverse(node *nd);

//Apis
int getHeight(node*nd);
int getNodeLvl(node *nd,int k);// to do
int getNodeNum(node *nd);
void printR2Lpath(node *nd);
void printR2LpathHelper(node *nd, int arr[], int len);
int hasPathSum(node*nd, int sum);
void doubleTree(node *nd);
void mirrorTree(node *nd);


int getDiameter(node *nd);//to do
int getTreeMaxWidth(node *nd);//to do
int isFoldable(node *nd); // to do
void printNodesOneLevel(node *nd, int lvl);
void printAcestor(node *nd, int k);
void printGivenRangeBST(node *nd, int n1, int n2);
int isBSTSumTree(node* nd);
int isSubTree(node *nd1, node *nd2);
void convert2SumTree(node *nd1);
int largestBST(node *nd);
void printVerticalSum(node *nd);
int maxSumR2L(node *nd);
int binTree2BST(node*nd);
int isSingleChildTree(node *nd);
int isTreeComplete(node *nd);
void printBoundaryTraverse(node *nd);
void swap2Incorrect(node *nd);
void buildTreePreandPost(node *nd);
int getCeil(node *nd, int k);
void toBSTtoBin(node *); //add all nodes greater than current to val
int sumExists(node *, int sum);
void linklist2BinTree(node*); //convert a link list to bin tree
void removeNodesInRange(node *nd, int min, int max);
void binTree2DoubleLinkList(node *);
int isIsomorphic(node *n1, node *n2);
void removeNodesSumLessthanK(node *n1, int sum);
int getDeepestLeftNode(node *n1);
int findNextRightNode(node *n1, int k);

int getHeightIter(node *n);
void printCustomTree(node *n);
int diffOddEvenLvl(node *n);
int getDeepestOddLvl(node *n, int lvl);
int leavesSameLevel(node *n);
void printLeftNodesAllLevel(node *n);



int doesNodeExist(node *nd, int x);
int countPossibleTrees(int numberm);

//Two trees
int areTreesIdentical(node *nd1, node *nd2);

//BST only
int getMinValBST(node *nd);
int isBST1(node * nd);
int isBST2(node *nd);

int isHeightBalancedBST(node *nd);// to do
int getKthSmallets(node *nd, int k)// to do

//Array Helper funcitons
void printArray(int arr[], int len);

