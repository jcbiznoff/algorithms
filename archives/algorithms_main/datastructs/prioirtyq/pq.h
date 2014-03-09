#define MAXQ 1000
typedef struct _pq{
    int q[MAXQ];
    int n;
}pq;

int pq_parent( int n);
int pq_child(int n);
void pq_init(pq* q);

/*bubbleup
 * base: when parent index is 0
 * leaf: swap when val@parent index > curent val
 * recur up with parent idx
 */
void bubbleup(pq *q, int x);

/*bubbledown
 * base: child is greater than n?
 * compare children, select min val
 * swap nodes with minval
 * recur down with child idx
 */
void bubbledown(pq *q, int x);

/*makeheap
 * 1. init a priority queue
 * 2. insert each elemente to it
 */
void makeheap(pq *q, int *a, int len);


int extractmin(pq*);

void insertpq(pq *q, int x);


void deletepq(pq *q, int x);


/*heapsortt
 * 1. make a heap from pq => O(n)
 * 2. extractmin and store to each array element => logn
 */
void heapsortt(int *a, int len);
