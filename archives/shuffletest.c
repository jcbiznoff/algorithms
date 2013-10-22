#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int **, int);

int main(){
	
	int n = 25;
	int i;
	int *arr;

	arr = (int *)malloc(sizeof(int)*n);
	
	for (i=0; i<n; i++) arr[i] = i+1;
	for (i=0;i<n;i++) printf("%d ", arr[i]);
	
	shuffle(&arr, n);
/*
	for (i=n-1; i>0; i--) {
		j = rand() % i;
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
*/
	printf("\n");
	for (i=0;i<n;i++) printf("%d ", arr[i]);

	system("pause");
	free(arr);
	return 0;
}


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

