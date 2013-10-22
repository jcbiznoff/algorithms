#include <stdlib.h>
#define MAXV 100

typedef struct{
    int y;
    int weight;
    struct edgenode *next;
}edgenode;


typedef struct{
    int nvertex;
    int nedge;
    int isDirected;
    int degree[MAXV];
    edgenode * edge[MAXV];
}graph;

typedef struct{
    int q[MAXV];
    int start;
    int end;
}queue

void bfs(graph *g, int start);
