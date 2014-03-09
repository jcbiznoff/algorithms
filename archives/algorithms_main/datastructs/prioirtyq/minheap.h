
typedef struct _minheapnode{
    int data;
    int i; //index of the array
    int j; // index of the next element of the array
}minheapnode;

typedef struct _minheap{
    minheapnode *hp;
    int size;
}minheap;

//Apis:

minheap* init(minheapnode *a, int size);
int left(int i);
int right(int i);
minheapnode getmin();
void replaceMin(minheapnode nd);

void minHeapify(minheap *hp, int i);
