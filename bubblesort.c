#include <stdio.h>
#include <string.h>

void bubblesortt(char **a, int len){
    char *tmp;
    int i, j =0;
    for (i=1; i< len; i++){
        for (j=1; j<= len-i; j++){
            if( strcmp(a[j-1] ,a[j])>0 ){
                tmp=a[j];
                a[j]=a[j-1];
                a[j-1]=tmp;
            }
        }
    }

    for (i=0; i<len;i++)
        printf("%s ",a[i]);
    printf("\n");
}


int main(){
    //int a[] = {3,1,10,3,2,7,9,22,35,75, 8,6};
    char *a[100] = {"fabd", "abcd", "wer","zxcv","rtyu"};
    int len = sizeof(a)/sizeof(char**);
    //int len =5;
    bubblesortt(a,len);
    printf("\n");
    return 0;
}
