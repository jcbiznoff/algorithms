#include <stdio.h>
#include <string.h>

#define MAXB 1000

char tmpstr1[MAXB];
char tmpstr2[MAXB];
char str1[MAXB];
char str2[MAXB];
char tbuff[MAXB];
char strcom12[MAXB];


void printArr(){
    int i;
    for (i=0; i<strlen(strcom12); i++)
        printf("%c", strcom12[i]);
}

void sortAlpha(){
    int i,j;
    char tmpc123;
    int n = strlen(strcom12);
    for(i=1;i <n; i++){
        for (j=1; j<= n - i; j++){
            if (strcom12[j-1] > strcom12[j]){
                tmpc123 = strcom12[j-1];
                strcom12[j-1] = strcom12[j];
                strcom12[j] = tmpc123;
            }
        }
    }
}

void findComm(){
    int i, j, k = 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    for (i=0; i< len1 ; i++){
        for (j=0; j < len2 ; j++){
            if (str1[i] == str2[j] && tbuff[j] == 0){
                strcom12[k++] = str2[j];
                tbuff[j] = 1;
            }
        }
    }
}
void initArr(){
    int i;
    for (i=0; i<MAXB; i++){
        tbuff[i] = 0;
        strcom12[i] = 0;
        str1[i] = 0;
        str2[i] = 0;
    }
}
void dealloctmp(){
    int i;
    for (i=0; i<MAXB; i++){
        tmpstr1[i] = 0;
        tmpstr2[i] = 0;
    }
}

int main(){

    char * tmp;
    while (scanf("%s %s", tmpstr1, tmpstr2) != EOF){
        initArr();
        if (strlen(tmpstr1) > strlen(tmpstr2)){
            strcpy(str1, tmpstr1);
            strcpy(str2, tmpstr2);
        }
        else{
            strcpy(str2, tmpstr1);
            strcpy(str1, tmpstr2);
        }

        findComm();
        sortAlpha();
        printArr();

        dealloctmp();
    }
}
