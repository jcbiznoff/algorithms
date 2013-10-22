#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>

char ** inputString(int); // 동적메모리 할당 및 문자열 입력 함수
void outputString(char **, int); // 문자열 출력 함수
void sortString(char **, int); // 문자열 sort 함수
void memFree(char **, int); // 동적메모리 해제 함수

int main()
{
	char **str;
	int count;
	printf("처리할 단어의 개수를 입력하시오 : ");
	scanf("%d", &count);
	fflush(stdin); // 숫자 입력 후 입력버퍼내의 불필요한 문자 삭제
	str=inputString(count);
	printf("(입력내용 출력하기)\n");
	outputString(str, count);
	sortString(str,count);
	printf("(Sort하여 출력하기)\n");
	outputString(str, count);
	memFree(str, count);
	system("pause");
	return 0;
}

//-------------------------------------------------------------------------------------
// 동적메모리 할당 및 문자열 입력 함수
//-------------------------------------------------------------------------------------
char ** inputString(int cnt)
{
	// 이곳에 함수기능을 구현하시오
	char **myArr;
	int i=0;
	char line[80];

	myArr = (char**)malloc(sizeof(char*) * cnt);
	for(i=0; i<cnt ; i++){
		myArr[i] = (char*)malloc(sizeof(char) * 80);
	}
	
	
	for(i=0; i<cnt ; i++){
		fgets(line,80,stdin);
		strcpy(myArr[i],line);
		printf("%s\n",myArr[i]);
	}

	return myArr;
}

//-------------------------------------------------------------------------------------
// 문자열 출력 함수
//-------------------------------------------------------------------------------------
void outputString(char **ptr, int cnt)
{
	
	// 이곳에 함수기능을 구현하시오
	int i=0;
	for(i=0; i<cnt; i++){
		printf("%d. %s\n",i+1, ptr[i]);
	}
}

//-------------------------------------------------------------------------------------
// 문자열 sort 함수
//-------------------------------------------------------------------------------------
void sortString(char **ptr, int cnt)
{
	// 이곳에 함수기능을 구현하시오
	char *temp;
	int i,j;
	for(i = cnt -1; i>0; i--){
		for(j=1; j<=i; j++ ){
			if(strcmp(ptr[j], ptr[j-1]) < 0 ){
				temp = ptr[j-1];
				ptr[j-1]= ptr[j];
				ptr[j] = temp;
			}
		}
	}	
		
}

//-------------------------------------------------------------------------------------
// 동적메모리 해제 함수
//-------------------------------------------------------------------------------------
void memFree(char **ptr, int cnt)
{
	// 이곳에 함수기능을 구현하시오
	int i;

    for(i=0;i<cnt;i++)
    {
    	free(ptr[i]);
    }

    free(ptr);

}