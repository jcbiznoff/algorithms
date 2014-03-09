#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXVAL 6
#define BUFSIZE 128

typedef struct{
	int status;
	char *name;
}Task;

typedef struct{
	Task data[MAXVAL];
	int front;
	int rear;
}Queue;

Queue myqueue;

void initData();
int printOptions();
void queueData();
void processData();
void removeData();
void printData();

int main(){

	//initData();
	while(1){
		switch(printOptions()){
			case 1:
			//queueData();
			break;
			case 2:
			//processData();
			break;
			case 3:
			//removeData();
			break;
			case 4:
			//printData();
			break;
			default:
			printf("\nmake a valid selection\n");
			break;
		}
		printf("\n\n\n");
	}

	//printf("\n@myqueue: %s\n",myqueue.data[0].name);
	//free(myqueue.data[0].name);
	//system("pause");

	return 0;
}


void initData(){
	char nname[BUFSIZE];
	Task tp;

	printf("typein name: ");
	fgets(nname,BUFSIZE,stdin);
	nname[strlen(nname) -1] = '\0';
	tp.name = (char*)malloc(sizeof(char)*MAXVAL);
	//strcpy(tp.name, nname);
	tp.name = &nname[0];

	printf("\n");
	printf("%s",tp.name);
	myqueue.data[0] = tp;	
}

int printOptions(){
	int num;
	printf("====================\n");
	printf("1. Queue data\n");
	printf("2. Process data\n");
	printf("3. Remove data from Queue\n");
	printf("4. Print Queue Data\n");
	printf("====================\n");
	printf("your selection: [   ]\b\b\b");
	scanf("%d", &num);
	return num;
}