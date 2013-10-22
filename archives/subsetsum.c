#include <stdio.h>
#include <stdlib.h>

#define M 20

int main(){

	int n = 5;
	int i, j;
	int a[] = {3,1,2,4,5};
	int m[5];
	int ans;
	
	/*
	for(i=0; i<M+10; i++) 
		m[i]=0;
	
	m[0]=1;

	for(i=0; i<n; i++){
		for(j=M; j>=a[i]; j--)
			m[j] |= m[j-a[i]];	
	}
	*/

	for (i=n-1; i>=0; i--){
		m[i] = 1;
		for (j = i+1; j< n; j++) if(a[j] > a[i])
			m[i] = m[i] > m[j] ? m[i] : m[j] + 1;	
	}

	ans = 0;
	for(i=0; i<n; i++) 
		printf ("%d ", m[i]);		
	
	
	system("pause");
	return 0;
}
