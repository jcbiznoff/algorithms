#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void revstr1(char * a){
    int i,j;
    char tmp;

    for(i=0,j=strlen(a)-1; i<j; i++,j--){
        tmp = a[i];
        a[i]= a[j];
        a[j] = tmp;
    }
    printf("%s\n", a);
    return;
}

char* revstr2 (char * str){
    int len = strlen(str);
    int i;
    char *str2;
    str2 = malloc(len + 1);
    for(i = 0; i < len; i++){
        str2[i] = str[len-1 -i];
    }

    return str2;

}

void revRecur(char *a, int i){
    if(i == strlen(a) + 1  ) return;
    revRecur(a, i+1);
    printf("%c",a[i]);
}

void revRecur2(char *a){
    if (*a == 0) return;
    revRecur2(a+1);
    printf("%c", *a);
}

int main(){

    char a[100] = "my name is hyunjin";
   // revstr1(a);
   // revRecur(a, 0);
   //revRecur2(a);

    char * tmp;
    tmp = revstr2(a);
    printf("%s", tmp);
    free(tmp);
    return 0;
}
