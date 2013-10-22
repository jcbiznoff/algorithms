#include <stdio.h>
#include <stdlib.h>

int main(){
	double left, right;
	double next;
	char sex;

	printf("left and right\n");
	scanf("%lf %lf",&left,&right);
	
	printf("left and right\n");
	scanf("%lf",&next);
	//fflush(stdin);
	printf("sex?\n");
	scanf(" %c",&sex);

	printf("%.1lf %.1lf %c",left,right,sex);

	system("pause");
	return 0;
}