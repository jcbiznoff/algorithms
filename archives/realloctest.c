#include <stdio.h>
#include <stdlib.h>

int main(){
	int *ip;
	int size = 5;
	int cnt=0;
	int num, i;

	ip = (int*)calloc(size,sizeof(int));

	while(true){
		printf("input vals: \n");
		scanf("%d",&num);
		if(num <=0) break;
		if(cnt<size) ip[cnt++] = num;

		else{
			size+=5;
			ip = (int*)realloc(ip,size*sizeof(int));
			ip[cnt++] =num;

		}


	}

	free(ip);
	return 0;
}