//study notes:

//1. bubble sort:
void bubblesort(int dataarr[], int arrlen){
	int i=0,j=0,tmp=0;
	for(i=arrlen-1; i>0; i--){
		for(j=1;j<=i;j++){
			if(dataarr[j] < dataarr[j-1]){
				tmp = dataarr[j-1];
				dataarr[j-1] = dataarr[j];
				dataarr[j] = tmp;
			}
		}
	}
}

//2. insertion sort:
void insertionsort(int dataarr[], int arrlen){
	int i,j;
	int key;
	for(i=1; i<arrlen; i++){
		if(dataarr[i-1] > dataarr[i]){
			key = dataarr[i-1]; // can use dataarr[i] instead of dataarr[i-1]?
			for(j=0;j<i;j++){
				if(dataarr[j] > key){
					memmove(&dataarr[j+1], &dataarr[j], sizof(dataarr[0]) * (i-j));
					dataarr[j] = key;
					break;
				}
			}
		}
	}
}

//3. quicksort
void quicksort(int datarr[], int left, int right){
	int p;
	if(left<right){
		p = partition(dataarr, left, right);
		quicksort(datarr, left, p-1);
		quicksort(datarr, p+1, right);
	}
}


int partition (int dataarr[], int left, int right){
	int first = left;
	int p = dataarr[first];
	p = dataarr[0];

	left++;
	while(left <= right){
		while(dataarr[left] <= p && left<=right)
			left++;
		while(dataarr[right] > p && left <right)
			right--;
		if(left<right)
			qsswap(&dataarr[left], &dataarr[right]);
		else
			break;
	}
	qsswap(&dataarr[firt], &dataarr[right]);
	return right;
}

//4. counting sort
void countingsort(int dataarr[], int arrlen, int B[]){
	int i, max, k;
	int *B, *C;
	//find max of A
	max = dataarr[0];
	for(i=0;i<arrlen;i++) if(dataarr[0]> max) max = dataarr[0];
	k = max;

	//init C
	C = (int*)malloc(sizeof(int)*(k+1));
	for(i=0; i<=k;i++) C[i] = 0;

	for(i=0;i<arrlen;i++) C[dataarr[i]]++;
	for(i=1;i<=k;i++) C[i] = C[i] + C[i-1];

	for(i=0;i<arrlen;i++){
		B[C[dataarr[i]] - 1] = dataarr[i];
		C[dataarr[i]] --;
	}
	outarr = B;
	free(C);
}
//5. merge sort
void mergeSort(int dataset[], int start, int end){
	int middle;
	if(end - start < 1 ) return;
	middle = (end+start)/2; //misake: average, not difference
	mergeSort(dataset, start, middle);
	mergeSort(dataset, middle +1 , end);
	merge(dataset, start, middle, end);
}

void merge(int dataset[], int start, int middle, int end){
	int left = start;
	int right = middle +1;
	int destidx = 0;
	int i;
	int * dest = (int *)malloc(sizeof(int)* (end-start +1)); // this stays the same.

	while (left <= middle && right <= end){ // comparison operator has higher priority than &&
		if (dataset[left] < dataset[right]){
			dest[destidx] = dataset[left]; //misake: not sure
			left++;
		}else{
			dest[destidx] = dataset[right];//misake: not sure
			right++;
		}
		destidx++;
	}

	while(left<=middle)
		dest[destidx++] = dataset[left++];
	while(right <=end)
		dest[destidx++] = dataset[right++];

	destidx =0;
	for (i=start; i<=end;i++){
		dataset[i] = dest[destidx++];
	}
	free(dest);
}

//string reverse
void revString(char * line){
	int len;
	char tmpc;

	//implem1.
	/*
	len = strlen(line);
	len = line/2;
	for(i=0; i<len; i++){
		tmpc = line[i];
		line[i] = line[strlen(line)-i] ;
		line[strlen(line)-i] = tmpc;
	}
	*/
	//implem2.
	for(i=0, j=strlen(line)-1; i<j; i++,j--){
		tmpc = line[i];
		line[i] = line[j];
		line[j] = tmpc;
	}
}
//create a string in heap
char * makeStringinHeap(const char* source){
	char * newString;
	newString = (char*)malloc(strlen(source) + 1);
	assert(newString);
	strcpy(newString, source);
	return newString;
}



//Adj Matrix : graph implementation
#define maxV 50
int j,i,V,E;
int v1, v2;
int a[maxV][maxV];
adjmtx(){
	scanf("%d %d", &V, &E);
	for (i=0;i<V; i++)
		for(j=0;j<E;j++) a[i][j]=0;
	for(i=0;i<V;i++)a[i][i]=1;
	for(j=0;j<E;j++){
		scanf("%d %d", &v1,&v2);
		a[v1][v2]=1;
		a[v2][v1]=1;

	}

}

//Adj List
#define maxV 1000
struct node{int v; struct node *next};
int i,j, V,E;
struct node *t, *z;
struct node *adj[maxV];
adjlist(){
	scanf("%d %d", &V, &E);
	z = (struct node*)malloc(sizeof(struct node));
	z->next = z;
	for(i=0; i<V;i++) adj[i] = z;
	for(i=0;i<E;i++){
		scanf("%d %d", &v1,&v2);
		t = (struct node*) malloc (sizeof(struct node));
		t->v = v1;
		t->next = adj[v2];
		adj[v2] = t;

		t = (struct node*) malloc (sizeof(struct node));
		t->v = v2;
		t->next = adj[v1];
		adj[v1] = v2;
	}
}

//List Reverse:
ListNode * reverse(ListNode *head){
	ListNode *p, *c, *n;
	p=head;
	n=null;

	while(p != NULL){
		n=c;
		c=p;
		p = p->next;
		c->next = n;
	}
	return c;
}

// Allocated 3d array: a[6][5][4]
int ***dataarr;
int i,j;
dataarr = (int ***)malloc(sizeof(int*)*6);
//dataarr = (int ***)calloc(6, sizeof(int*));
for(i=0;i<5;i++){
	dataarr[i] = (int**)malloc(sizeof(int*)*5);
	//dataarr[i]=(int**)calloc(5,sizeof(int*));
	for(j=0; j<4;j++){
		dataarr[i][j] = (int*)malloc(sizeof(int)*4); //careful: last malloc stores int
		//dataarr[i][j] = (int*)calloc(4,sizeof(int));
	}

}


//shuffle
void shuffle(int **arr, int n){
	int i,j, tmp;
	srand(time(NULL));

	for (i=n-1; i>0; i--) {
		j = rand() % i;
		tmp = *(*arr+i);
		*(*arr+i) = *(*arr+j);
		*(*arr+j) = tmp;
	}
}



//Extras.
//sizeof vs. strlen
//ASCII characters
/*
'A' -> 65
'0' -> 48
'a' -> 97
space -> 34

//caution using fgets: add null at the end (replace newline character)
fgets(line,BUFSZ,stdin)
line[strlen(line)-1] = '0'

//when you do malloc always check for if space avail:
int * temp;
if((tepm = (int*)malloc(sizeof(int))) )== -1 ) return;

//Question List
1. add a data element to a stack

//Double linked List
//circularly double linked List
//Graphs


//string and io library review
//1. strcpy
//2. fgets
//3. scanf
//4. strlen
//5. fflush
//6. sscanf


//study samples: http://j.finfra.com/zbl/lecCSource2/3269
//linked list : http://cafe.naver.com/funcc/2571

//operator precedence table:
1. ( ) [ ] . ->
2. - ++ -- ~ ! *(as in dereference) &(as in address) sizeof (type)
3. * % /
4. + -
5. << >>
6. < <= >= >
7. == !=
8. &
9. ^
10. |
11. &&
12. ||
13. ? :
14. = += -= *= /= %= &= ^= != <<= >>=
15. ,


//Graph@ mastering algorithms with c is implemented in list, set (but set is a list)
//Tip: printMenu() -> while(printMen()){switch{case 0: ... break; case 1: ... break;}}

//x++++ is an error

