/*
 * given two pointers to string, copy one from the other
 *
 * void cpystr(char *str1, char *str2)
 *
 * modify a string within a function
 * void modstr2(char **str1)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void modstr2(char (*str1)[]){
    char * mystr = *str1;
    mystr[0]= 'M';
}
void cpystr(char *str1, char *str2){

    while(*str2 != 0){
        *str1++ = *str2++;
    }
}
char *cpystrInside(char *str1){
    char *tmpstr;
    int i; //use index. Not wise to manipulate pointer of tmpstr and return tmpstr
    tmpstr = (char*)malloc(strlen(str1)+1);
    for(i=0; i<=strlen(str1); i++)
        tmpstr[i] = str1[i];

    printf("tmpstr: %s\n",tmpstr);
    return tmpstr;
}

int main(){
    //char *a= "abcd";//readonly!!!!!!!
    char a[10] = "abcd"; //array eanbles read/write
    char b[10] = "kbsdf";

    char *c1 = "bleasdf";// read only
    char *c2;
    printf("%s\n",a);
    //modstr2(&a);
    //cpystr(a,b);

    c2 = cpystrInside(c1);
    printf("%s\n",c2);
    free(c2);
    return 0;
}

