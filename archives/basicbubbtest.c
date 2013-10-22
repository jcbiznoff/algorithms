

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int i=0, j=0;
	int tmp =0;
	int myarr[10] = {9, 3, 5, 1, 2, 5, 1, 8,1, 5};

	for (i = 0; 	i< 10; i++){
		for (j=0; j< i ; j++){
			if (myarr[j] > myarr[j+1])
			{
				tmp = myarr[j];
				myarr[j] = myarr[j+1];
				myarr[j+1] = tmp;
			}
		}
	}

	//for (i =0; i< 10; i++){
	//	printf("%d ",myarr[i]);
	//}

	int a =1, b =2;
	if(a&&b) printf("true1");
	if(a&b) printf("true2");
	if((a==1)&&(b==2)) printf("true3");
	if((a==1)&(b==2)) printf("true4");

	char one[30] = {'A','B', 'C','\0','d'};
	char two[30] = {'A','B', 'C','\0','F'};

	if (strcmp(one,two) == 0) printf("same string");
	else printf("diff string");

	printf("\n");
	int sum =0;
	for(i = 1; i<20; i*=2){
		for( i =0; i<=10; i+=2){
			sum += i;
			printf("%d ", sum);
		}
		printf("\n");
	}


	system("pause");
}