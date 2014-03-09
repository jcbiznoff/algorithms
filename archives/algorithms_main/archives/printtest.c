#include <stdio.h>
int main(){
	int testint = 10;
	int num =0;
	int testhex = 15;

	float testfl = 123.123;
	float testfl2 = 123.126;
	
	printf("%.2f \n",testfl); // two decimal
	printf("%.2f \n",testfl2); //two decimals with rounding

	printf("%x\n",testhex);
	scanf("%d",&num);
	return 0;
}