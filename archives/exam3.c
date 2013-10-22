#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFMAX 128

bool checkSize(char *);
bool checkChar(char *);
bool checkSex(char *);
bool checkValidDig(char *);

int main(){
	bool flag = false;
	
	char line[BUFMAX];
	char dob[BUFMAX];
	char sex;

	while(fgets(line,BUFMAX, stdin)){
		line[strlen(line)] = '\0';
		if (!checkSize(line)){printf("check input length\n"); }
		if (!checkChar(line)){printf("input not digits\n"); }
		if (!checkSex(line)){printf("check sex\n"); }
		if (!checkValidDig(line)){printf("check valid dig\n"); }
		strncpy(dob,line,6);
		printf("%s\n",dob);
	}


	return 0;
}

bool checkSize(char *line){
	printf("strlen: %d\n", strlen(line));
	if(strlen(line) != 14) return false;
	else return true;
}

bool checkChar(char *line){
	int i=0;
	for(i=0; i<strlen(line)-1; i++){
		if(line[i] < 48 || line[i] > 57) {
			return false;
		}
	}
	return true;
}

bool checkSex(char *line){
	printf("sex: %c\n", line[6]);
	//if(line[6] != '1') return false;
	if((line[6] != '1') && (line[6] != '2') && (line[6] != '3') && (line[6] != '4') ) return false;
	else return true;
}

bool checkValidDig(char *line){
	int sum,i;
	sum =0;
	for(i=0;i<strlen(line)-2; i++){
		//printf("%d\n", (line[i] - '0'));
		sum = sum + (line[i] - '0');
	}

	if(line[12] == (sum%10))return true;
	else return false;
}