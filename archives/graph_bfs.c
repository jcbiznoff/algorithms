typedef struct linkedlist { // linked list of ints (for use in Node)
  int index;
  struct linkedlist *next;
} List;

typedef struct { // a Node of a Graph
  char *name;
  List *outlist; // adjacency list
  int outdegree; 
  int visited;// length of outlist
  int indegree;
  //double pagerank_score; //not needed for this exercise
} Node;

typedef struct {
  // your code goes here
  int MaxSize;
  Node *table;
} Graph;

/* Good luck */
void bfs(Graph *mygraph){
//int i=0;
int u;

 for(u=1;u<mygraph->MaxSize;u++)
   mygraph->table[u].visited=0;
 for(u=1;u<mygraph->MaxSize;u++){
   if(mygraph->table[u].visited==0){
     printf("%s \n",mygraph->table[u].name);
     visit(u,mygraph);
   }
 }
}

void visit(int u,Graph *mygraph){
 // i ++;
  List *current;
  mygraph->table[u].visited++;
  current= mygraph->table[u].outlist;

  while (current!=NULL) { 
    if(mygraph->table[current->index].visited==0)
      printf("%i \n",current->index);
      visit(current->index,mygraph);
      current = current->next;}

}