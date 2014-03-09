#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSZ 128

int __atoi(char cSrc[]);
void __itoa(int nVal, char cRes[], int nBase);
int getSize(int num,int base);
void convBase(char* mystr, int strsz, int num, int base);
void tokenizeNumBase(char* cSrc, int* num, int *base);

int main(){
	char str1[BUFSZ];
	char str2[BUFSZ];
	char *str3;
	int linecnt =0;
	int num1;
	int num2, base;

	printf("Enter number1: ");
	scanf("%d",&num1);
	__itoa(num1, str1, 10);

	fflush(stdin);

	printf("Enter number2 & Conversion: ");
	fgets(str2, BUFSZ, stdin);
	__atoi(str2);
	
	system("pause");
	return 0;
}
void __itoa(int nVal, char cRes[], int nBase){
	int num = nVal;
	int strsz = 0;
	char *mystr;
	int i =0;

	int stidex =0;
	
	if(num < 0) {
		cRes[0] ='-';
		stidx++;
	}

	strsz =  getSize(num, 10);

	mystr = (char*)malloc(sizeof(char)*strsz + 1);

	num = abs(nVal);
	mystr[strsz]='\0';
	
	convBase(mystr, strsz, num, 10);

	free(mystr);
}

int __atoi(char cSrc[]){
	int tnum, base;
	char *pch; 
	int num, modval, count;
	int strsz;
	char* mystr;
	
	tokenizeNumBase(cSrc, &num, &base);

	//printf("num: %d, base: %d\n",num, base);
	if(base <= 0  && num == 0){
		printf("input correct base and num");
		return 0;
	}

	strsz =  getSize(num, base);
	mystr = (char*)malloc(sizeof(char)*strsz + 1);
	mystr[strsz]='\0';
	convBase(mystr, strsz, num, base);
	//printf("String of the number is \"%s\"\n", mystr);
	free(mystr);
	return 0;
}

int getSize(int num,int base){
	int strsz =0;
	while((num/base)>=0){
		strsz++;
		if(num/base ==0 )break;
		num = num/base;
	}
	//printf("string sz: %d\n",strsz);
	return strsz;
}

void convBase(char* mystr, int strsz, int num, int base){
	char tmpchar;
	int i=0;
	int modval;

	while((num/base)>=0){
		modval = num%base;
		if(base > 10 && modval> 9)
			tmpchar = '0' + modval +39;	
		else
			tmpchar = '0' + modval; //key to the algorithm
		mystr[strsz-i-1] = tmpchar ;
		i++;
		if(num/base ==0 )break;
		num = num/base;
	}
	printf("String of the number is \"%s\"\n", mystr);
}

void tokenizeNumBase(char* cSrc, int* num, int *base){
	char *pch;
	pch = strtok (cSrc,", ");
	*num = atoi(pch);
	while (pch != NULL){
	    //printf ("%s\n",pch);
	    *base = atoi(pch);
	    pch = strtok (NULL, ", ");
	}
}