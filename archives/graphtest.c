//Graph study
//undirected vs. directed
//weighted vs unweighted
//simple vs nonsimple : self-loop, multiedge
//sparse vs dense
//cyclic vs acyclic
//embedded vs topological: geometric positions
//implicit vs explicit:backtrack search
//labeled vs unlabeled

#include <stdio.h>
#include <stdlib.h>

#define MAXV 1000
typedef struct edgenode_{
	int y;
	int weight;
	struct edgenode_ *next;
} edgenode;

typedef struct{
	edgenode *edges[MAXV+1];
	int degrees[MAXV+1];
	int nvertices;
	int nedges;
	bool directed;
} graph;

void initialize_graph(graph*, bool);
void build_graph(graph*, bool);
void insert_edge(graph*, int, int, bool);
void print_graph(graph*);

int main(){
	return 0;
}

void initialize_graph(graph* G, bool isDirected){
	int i;
	G->nvertices =0;
	G->nedges =0;
	G->directed = isDirected;
	for(i=0;i<MAXV;i++) G->degrees[i] =0;
	for(i=0;i<MAXV;i++) G->edges[i] = NULL;
}

void build_graph(graph* G, bool isDirected){
	int i,x,y,m;
	initialize_graph(G,isDirected);
	//scanf("%d %d", &G->nvertices, &G->nedges); //nedges increased after edge is added.
	scanf("%d %d", &G->nvertices, &m);

	for(i=0;i<m;i++){
		scanf("%d %d", &x, &y);
		insert_edge(G,x,y,isDirected);
	}
}

void insert_edge(graph* G, int x, int y, bool isDirected){
	edgenode *p;
	p = (edgenode *)malloc(sizeof(edgenode));

	p->y = y;
	p->weight =0;
	p->next = G->edges[x];

	G->edges[x] = p;
	G->degrees[x]++;

	if(!isDirected) insert_edge(G,y,x,isDirected);
	else
		G->nedges++;
}
void print_graph(graph* G){
	int i;
	edgenode *p; 
	for(i=1;i<=G->nvertices;i++){
		printf("%d: ",i);
		p = G->edges[i];
		while(p!=NULL){
			printf("%d ",p->y);
			p = p->next;
		}
		printf("\n");

	}

}