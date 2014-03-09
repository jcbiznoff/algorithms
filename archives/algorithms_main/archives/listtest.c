#include <stdio.h>
#include <stdlib.h>

#define BUFSZ 128
typedef struct ListN_{
	char name[BUFSZ];
	int altitude;
	struct ListN_ * next;
}ListN;

ListN* appendN(ListN *);
ListN* insertN(ListN *);
ListN* deleteN(ListN *);
void searchN(ListN *);
void displayN(ListN *);

int printMenu(){
	int num;
	system("cls");
	printf("\t\t *****Menu*****  \n");
	printf("\t\t 1. Append  \n");
	printf("\t\t 2. Display  \n");
	printf("\t\t 3. Insert  \n");
	printf("\t\t 4. Delete  \n");
	printf("\t\t 5. Search  \n");
	printf("\t\t 6. Quit  \n");
	printf("\t\t Choice:[   ]\b\b\b");
	scanf("%d",&num);
	return num;
}

int main(){
	ListN * head, *tail;
	head = (ListN *)malloc(sizeof(ListN));
	tail = head;
	head->next = NULL;

	while(true){
		switch(printMenu()){
			case 1: tail = appendN(tail); break;
			case 2: displayN(head); getchar(); break;
			case 3: head = insertN(head); break;
			case 4: head = deleteN(head); break;
			case 5: searchN(head); break;
			case 6: return 0; 
			default: printf("No menu");
		}
		return 0;
	}
	return 0;
}

ListN* appendN(ListN * tail){
	printf("\n\ttype mountain name: ");
	fflush(stdin);
	fgets(tail->name,BUFSZ,stdin);
	printf("\n\ttype altitude: ");
	fflush(stdin);
	scanf("%d", &tail->altitude);
	printf("mountain name:%s\t altitude: %d\n", tail->name, tail->altitude);
	
	tail->next = (ListN*)malloc(sizeof(ListN));
	tail = tail->next;
	tail->next = NULL;

	return tail;
}
ListN* insertN(ListN * head){return head;}
ListN* deleteN(ListN * head){return head;}
void searchN(ListN *head){}
void displayN(ListN *head){}