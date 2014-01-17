typedef struct _node{
    struct _node *l;
    struct _node *r;
    int data;
}tnode;

void insertT(tnode**, int);
void deleteTNode(tnode**, int);
int predecessorT();
int successorT();
int minimumT();
int maximumT();
int searchT();
