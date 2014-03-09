#include <stdio.h>
int main(){
	float sum =0.00;
	int i=2;
	float divRes;
	float num = -1.00;
	while(num != 0.00){
		scanf("%f", &num);
		if(num >5.19 || num <=0.00){
			break;
		}
		sum =0; i=2;
		//printf("%.2f\n",num);
		divRes= 0.00;
		while(sum <= num){
			divRes = 1.00/i;
			//printf("divRes: %f\n",divRes);
			sum = sum + divRes;
			//printf("%f\n",sum);
			i++;
		}
		printf("%d card(s)\n", i-2);
		
	}
	return 0;
}