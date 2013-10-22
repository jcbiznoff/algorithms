#include <stdio.h>
#include <stdlib.h> // misake: include this for malloc

void mergeSort(int dataset[], int start, int end);
void merge(int dataset[], int start, int middle, int end);


int main(){

	return 0;
}

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
