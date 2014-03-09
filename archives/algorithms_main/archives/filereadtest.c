#include <stdio.h>

void dostuff(){

}

int main(){
	FILE *fp;
	fp = fopen("myfiletest","w");
	int num=0;

	while(true){
		fprintf(fp,"%d\n",num);
		if (num == 10) break;
		num++;
	}
	fclose(fp);

	//read file
	fp = fopen("myfiletest","r");
	while(true){
		fscanf(fp, %d, &num);
		if(feof(fp) !=NULL) break;
	}


	scanf("%d",num);
	return 0;
}