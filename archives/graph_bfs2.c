#include <stdio.h>
#include <stdlib.h>

#define MAXV 1000
#define MAXQ 6
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

typedef struct queue_{
	int size;
	int head,tail;
	int data[MAXQ];
}queue;



bool processed[MAXV + 1];
bool discovered[MAXV + 1];
int parent[MAXV +1];

void connected_components(graph *);
void find_path(int start, int end, int parents[]);
void initialize_search(graph*);
void process_vertex_early(int);
void process_vertex_late(int);
void process_edge(int,int);
void bfs(graph *, int);

void init_queue(queue*);
void enqueue(queue*,int);
int dequeue(queue*);
bool empty_queue(queue*);



int main(){
	return 0;
}

void initialize_search(graph* G){
	int i;
	for(i =1; i<G->nvertices; i++){
		processed[i] = discovered[i] = 0;
		parent[i] = -1;
	}
}

void bfs(graph * G, int start){
	queue q;
	int v,y;
	edgenode *p;

	init_queue(&q);
	enqueue(&q, start);
	discovered[start] = 1;

	while(!empty_queue(&q)){
		v = dequeue(&q);
		process_vertex_early(v);
		processed[v] = 1;

		p = G->edges[v];
		while(!p){
			y = p->y; 
			
			if(!processed[y] || G->directed)
				process_edge(v,y);
			if(!discovered[y]){
				enqueue(&q,y);
				discovered[y] = 1;
				parent[y] = v;	
			}
			p = p->next;
		}
		process_vertex_late(v);
	}

}

void process_vertex_early(int v){}
void process_vertex_late(int v){ printf("processed vertex: %d\n", v);}
void process_edge(int x,int y){printf("processed edge : %d %d\n", x,y);}

void init_queue(queue* Q){
	int i;
	Q->size =0;
	Q->head =0;
	Q->tail =0;
	for (i=0;i<MAXQ;i++) Q->data[i]=0;
}
void enqueue(queue* Q,int v){
	Q->data[Q->tail+1] = v;
	Q->tail = Q->tail + 1;
	Q->size = Q->size + 1;//? can i do Q->size++;
}

int dequeue(queue* Q){
	int datafound;
	if(!empty_queue) return 0;
	datafound = Q->data[Q->head];
	Q->head = Q->head + 1; 
}

bool empty_queue(queue* Q){
	if(Q->head == Q->tail) return 0;
	else return 1;
}


void find_path(int start, int end, int parents[]){
	if(start == end || end == -1) printf("\n%d ", start);
	else{
		find_path(start, parents[end], parents);
		printf(" %d",end);
	}
}

void connected_components(graph *G){
	int c, i;
	initialize_search(&G);
	c=0;

	for(i=1;i<=G->nvertices;i++){
		if(!discovered[i]){
			c++;
			printf("Component %d:",c);
			bfs(G,i);
			printf("\n");
		}
	}
	//set process_vertex_early to print v
	//set process_edge to blank fn	
}


void twocolor(grpah *G){
	int i;
	for (i=1;i<=G->nvertices;i++)
		color[i] = UNCOLORED;
	bipartite = TRUE;

	initialize_search(&G);

	for(i=1;i<=G->nvertices;i++)
		if(discovered[i] == FALSE){
			color[i] = WHITE;
			bfs(G,i);
		}
	//set process_edge to the following
		/*
		void process_edge(int x, int y){
	if(color[x] == color[y]){
		bipartite = FALSE;
		printf("Warning: not bipartite due to (%d, %d) \n",x,y);
	}
	color[y] = complement(color[x]);
}

int complement (int color){
	if(color == WHITE) return BLACK;
	else if(color == BLACK) return WHITE;
	else return UNCOLORED;
}

		*/
}

void dfs(graph *G, int start){
	edgenode *p;
	int y;

	if (finished) return;
	discovered[v] = TRUE;
	entime++;
	entry_time[v] = entime;

	process_vertex_early(v);

	p= G->edges[v];

	while(p!=NULL){
		y= p->y;
		if(discovered[y]){
			parent[y] = v;
			process_edge(v,y);
			dfs(g,y);
		}
		else if(!procesed[y] || G->directed)
			process_edge(v,y);
		if(finished) return;
		p=p->next;
	}
	process_vertex_late(v);
	entime++;
	exit_time[v] = time;
	processed[v] = TRUE;

}