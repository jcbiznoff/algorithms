#include <stdio.h>
#include "graph.h"

static int processed[MAXV+1];
static int discovered[MAXV+1];
static int parent[MAXV+1];


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


