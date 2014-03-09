#include <stdio.h>
#include <stdlib.h>


int main(){
	int days, run, up, down;
	
	int depth;
	double fdepth;
	
	while(1){

		printf("Type in a depth val: ");
		scanf("%d",&depth);
		
		run =0; up =50; down = 20; days=0;
		
		while(1){
			if(depth == 0) break;
			days++;
			run += up;
			if(run >= depth) break;
			run -= down;
			
		}
		
		days = recRun(depth, up);

		printf("\n");
		fdepth = depth/100.0 ;
		printf("%.2fm deep takes %d days\n", fdepth, days);
	}
	system("pause");
	return 0;
}
