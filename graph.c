#include "graph.h"

void initg(graph *g){
    int i;
    g->nvertex = 0;
    g->nedge = 0;
    for (i=0; i<VMAX; i++) g->ndeg[i] =0;
    for (i=0; i<VMAX; i++) g->edge[i]=0;
    g->isDirected = 0;
}

void insertedge(graph *g, int v, int y){
    if(g->nvertex >= VMAX)
        return;

    g->nedge++;
    edgenode *p = g->edge[v];
    edgenode *new = (edgenode*)malloc(sizeof(edgenode));
    new->y = y;

    while(p != 0){
        p = p->next;
    }
    new->next = p->next;

    if(g->isDirected == 0)
        insertedge(g,y,v);
}

void insertvertex(graph *g, int n){
    if (n >= VMAX)
        return;
    g->nvertex = n;
}
