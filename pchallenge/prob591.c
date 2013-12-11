#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXS 10
char str1[MAXS];
char str2[MAXS];
int carry[MAXS+1];

int main(){
    int len1, len2, maxlen, i,j;
    int tcarry, ccount;
    int d1, d2;

    while (1){
        for (i=0; i<MAXS;i++){
            str1[i] = 0;
            str2[i] = 0;
        }

        scanf("%9s %9s", str1, str2);
        if (atoi(str1) ==0 && atoi(str2) ==0) break;
        if (atoi(str1) == 0){
            for (i=1; i<MAXS;i++){//key point: start at index 1 not at 0. otherwise strlen returns 0
                str1[i] = 0;
            }
        }
        if (atoi(str2) == 0){
            for (i=1; i<MAXS;i++){
                str2[i] = 0;
            }
        }

        len1 = strlen(str1);
        len2 = strlen(str2);

        maxlen = (len1 > len2) ? len1 : len2;

        for (i=0; i<MAXS+1;i++)
            carry[i]=0;

        for(i=0; i<MAXS ;i++){ // this is also key: populate 0 after scanf buffer read
            if (str1[i] == 0) break;
        }
        j =0;
        for(j = i; j<len1; j++)
            str1[j] = 0;
        for(i=0; i<MAXS ;i++){
            if (str2[i] == 0) break;
        }
        j =0;
        for(j = i; j<len1; j++)
            str2[j] = 0;
        i=0;
        while(i<maxlen){

            if((len1-1-i >= 0) && str1[len1 - 1 -i ]!= 0) // this is key: need to handle buffer overflow correctly: reading prior array index
                d1 = str1[len1 - 1 - i] - '0';
            else
                d1 = 0;

            if((len2-1-i >= 0) && str2[len2 - 1 - i] != 0)
                d2 = str2[len2 - 1 - i] - '0';
            else
                d2 = 0;

            tcarry = carry[i];
            carry[i+1] = (d1+d2+tcarry >= 10) ? 1 : 0;
            i++;
        }

        ccount = 0;
        for (i=0; i<MAXS+1 ;i++){
            if(carry[i] == 1)
                ccount++;
        }

        switch(ccount){
            case 0:
                printf("No carry operation.\n");
                break;
            case 1:
                printf("1 carry operation.\n");
                break;
            default:
                printf("%d carry operations.\n", ccount);
                break;
        }
    }
}
