#include <stdlib.h>
#define MAXV 100

typedef struct _edgenode{
    int y;
    int weight;
    struct _edgenode *next; // important to name structure here
}edgenode;
typedef struct{
    int nvertex;
    int nedge;
    int isDirected;
    int degree[MAXV+1];
    edgenode *edge[MAXV+1];
}graph;

typedef struct{
    int q[MAXV];
    int start;
    int end;
}queue;

//void bfs(graph *g, int start);
void initg(graph *g, int isDirected);
void readg(graph *g, int isDirected);
void insertedge(graph *g, int v, int y, int isDirected);
void printgraph(graph *g);
