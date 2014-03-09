#include <stdio.h>
#include <stdlib.h>

#define BUFSZ 1024

void isStrRev(char *str1, char *str2,int len1,int len2){
	int i,j,k,hit;
	i = len1-1;
	k =i;
	hit =0;
	for(j=0; j<len2; j++){
		while(k>=0){
			if(str1[i] == str2[j]){
				hit++;
				break;
			}
			i--;
		}
		k--;
		
	}
	if (hit == len2) printf("YES\n");
	else printf("NO\n");
}

int main(){

	char line[BUFSZ];
	char str1[BUFSZ];
	char str2[BUFSZ];
	int num,linecnt, len1,len2;

	linecnt =0;
	//get two strings
	
	while(fgets(line, BUFSZ, stdin)){ //note: in c line declared as char array NOT POINTER.
		
		switch(linecnt){
			case 0:
				num = atoi(line);
				printf("mynum: %d\n", num);
			break;
			default:
				sscanf(line, "%s%n%s%n",str1,&len1,str2,&len2);
				printf("%s %d %s %d\n",str1,len1,str2,len2-len1-1);
				len2 = len2-len1-1;

				isStrRev(str1,str2,len1,len2);

			break;
		}

		linecnt++;
		
	}
	

	system("pause");
	return 0;
}