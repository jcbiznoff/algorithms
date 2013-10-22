#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFSZ 1024
int main ()
{
  //char str[] ="- This, a sample string.";
  char * pch;
  
  int num;
  int i=0;
  char line[BUFFSZ], str1[BUFFSZ];
  char *tmpchar;

  char *strholder;

  int linecount =1;
  //scanf("%d",&num);
  while(fgets(line,BUFFSZ,stdin)){ //read each line: fgets prevents buffer overflow
  	if(linecount == 1){
  		num = atoi(line);
  		printf("num: %d\n",num);

  	}else if(linecount == 2){

	  	pch = strtok (line," "); //strtok is good when number of inputs is unknown
		while (pch != NULL){
		    printf ("%s\n",pch);
		    //strcpy(pch,str,BUFFSZ);
		    pch = strtok (NULL, " ");
		}
	}else{
		//cin << tmpchar << " " << str1 << endl; // do this in c++
		
		//below is kind of stupid way of parsing.
		/*
		pch = strtok(str," ");
		mychar = pch;
		pch = strtok(pch," ");
		sotreval = pch;
		*/
		sscanf(line,"%c %s",&tmpchar, str1);//way cooler: use when number and type of input is known
		printf("%c %s\n", tmpchar, str1);
	}
	linecount++;
  }
  

  pch = strtok (line," ,.-");
  while (pch != NULL)
  {
    printf ("%s\n",pch);
    i += *pch;
    pch = strtok (NULL, " ,.-");
  }
  system("pause");
  return 0;

}

/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int num;
	char buff[1024];
	scanf("%d", &num);
	printf ("intput: %d\n",num);
	scanf("%s", buff);
	printf ("intput: %s\n",buff);

	char* tmpstr;
	tmpstr = strtok(buff," ");

	while(tmpstr!= NULL){
		printf("%s\n", tmpstr);
		tmpstr = strtok(tmpstr, " ");

	}

	system("pause");



	return 0;
}

*/