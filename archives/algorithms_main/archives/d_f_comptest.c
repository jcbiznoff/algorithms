/**
test float and double comparisons
**/
#include <stdio.h>

int main(){
	float one = 1.1; //float takes 4bytes
	double two = 1.1; // double takes 10 bytes
	float three = 1.1;
	int temp;

	if (one == two)	printf("same \n");
	else printf("diff \n");

	if (one == three)	printf("same \n");
	else printf("diff \n");


	scanf("%d", &temp);
	return 0;
}