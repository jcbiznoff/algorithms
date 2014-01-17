#define MAXQ 1000
typedef struct _pq{
    int q[MAXQ];
    int n;
}pq;

int pq_parent( int n);
int pq_child(int n);
void pq_init(pq* q);

void bubbleup(pq *q, int x);
void bubbledown(pq *q, int x);

void makeheap(pq *q, int *a, int len);
int extractmin(pq*);
void insertpq(pq *q, int x);
void deletepq(pq *q, int x);
void heapsortt(int *a, int len);
