#include <stdlib.h>
#define VMAX 100
typedef struct _edgenode{
    int y;
    struct _edgenode *next;
}edgenode;

typedef struct _graph{
    int nvertex;
    int nedge;
    int ndeg[VMAX];
    edgenode *edge[VMAX];
    int isDirected;
}graph;

