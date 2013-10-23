#include <stdio.h>
#include "graph.h"

static int processed[MAXV+1];
static int discovered[MAXV+1];
static int parent[MAXV+1];

/*
void bfs(graph *g, int start){
    int y;
    int v;
    edgenode *p;
    queue q;

    discovered[start] = 1;
    while(!is_queue_empty(&q)){
        v = dequeue(&q);
        process_vertex_early(v);
       processed[v] = 1;
        p = g->edge[v];
        while (p!=NULL){
            y = p->y;
            if(!processed[y]){
                process_edge(v,y);
            }
            if(!discovered[y]){
                enqueue(&q, y);
                discovered[y] = 1;
                parent[y] = v;
            }
            p = p->next;
        }
        process_vertex_late(v);
    }
}
*/
void initg(graph *g, int isDirected){
    int i;
    g->nvertex = 0;
    g->nedge = 0;
    for(i=0; i<MAXV; i++) g->degree[i] = 0;
    for(i=0; i<MAXV; i++) g->edge[i] = 0;
    g->isDirected = isDirected;
 }
void readg(graph *g, int isDirected){
    int i;
    int n, m, x, y;

    initg(g, isDirected);
    printf("type in number of vertices and number of edges: \n ");
    scanf("%d %d", &(g->nvertex), &m);
    for (i=1; i<=m ;i++){
        printf("edge a  b: \n");
        scanf("%d %d", &x , &y);
        insertedge(g, x, y, isDirected);
    }
}

void insertedge(graph *g, int x, int y, int isDirected){
    edgenode *p;

    p = (edgenode *)malloc(sizeof(edgenode));
    p->y = y;
    p->weight = 0;

    p->next = g->edge[x];
    g->edge[x] = p;

    g->degree[x]++;
    if(!isDirected)
        insertedge(g,y,x,isDirected);
    else
        g->nedge++;
}

void printgraph(graph *g){
    int i;
    edgenode *p;

    for (i = 1; i<= g->nvertex ;i++){
        printf("%d: {", i);
        p = g->edge[i];
        while (p!=NULL){
            printf("%d ", p->y);
            p = p->next;
        }
        printf("}\n");
    }
}
