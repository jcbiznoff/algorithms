typedef struct _tnode{
    struct _tnode *p;
    struct _tnode *l;
    struct _tnode *r;
    int data;
}tnode;

void insertT(tnode**, int);
void deleteTNode(tnode**, int);
int predecessorT();
int successorT();
int minimumT();
int maximumT();
int searchT();
