/*
 * bin words and counts using array data structure. use hash tables. words for keys, count for corresponding occurences.
 *
 * parseWords(char (*arr)[], char * txt)
 * char *getMostFrequent(char (*arr)[])
 * int numberOfTimes(char *pat, char*txt)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getWordCount(char * str){
    int i=0;
    int count =0;
    if(strlen(str) == 0) return 0;

    while(*str != 0){
        if(*str == ' ')
            count++;
        str++;
    }
    return count;
}
/*createArr:
 *  allocate a memory for 2d array, given a row size.
 */
char **createArr(int rows){
    char ** tmparr;
    int i;

    tmparr = (char**)malloc(rows*sizeof(char*)); //2d malloc sizeof(char*) is important
    for(i=0; i<rows;i++)
        tmparr[i] = (char*)malloc(10);
    return tmparr;
}
void parseWords2arr(char** arr,int rows, char*txt){
    int i;
    //p = strtok(txt, " ");//strtok requires manipulating the original text. cannot use!!!
    int l=0,r=0,j=0,k=0;
    for(i=0;i<strlen(txt);i++){
        if(txt[i] == 0) break;
        if(txt[i] == ' '){
            r = i;
            for(j=l;j<r;j++)
                arr[k][j-l] = txt[j];
            arr[k][j] = 0;
            l = r+1;
            k++;
        }
    }
}
/*countUniqueWords:
 *  counts number of each unique words.
 *  1. find total number of words
 *  2. use O(n^2) search to find if matched.
 *  3. if matched,
 *      increase unqcount
 *      replace target string to blank
 */
int countUniqueWords(char * str, char **arr){
    int totwords = getWordCount(str);
    int dupcount = 0;
    int i,j;
    for(i=0; i<totwords; i++){
        for(j=0; j<totwords; j++){
            if(strcmp(arr[i],arr[j])){
                dupcount++;
                arr[j] = 0;
            }
        }
    }
    return totwords - dupcount;
}

int comparestr(const void * str1, const void* str2){
    return strcmp(*(char**)str1,*(char**)str2);

}
void freeArr(char **arr, int rows){
    int i;
    for(i=0; i<rows; i++){
        free(arr[i]);
    }
    free(arr);
}

void printArr(char ** arr, int rows){
    int i=0;
    for(i=0; i<rows; i++){
        printf("arr[%d]: %s \n", i, arr[i]);
    }
    printf("\n");
}

int main(){
    char *txt = "this is just a sample string this may not involve other strings but string is just a string and string loves another sample";
    int num=0,i,max,count;
    char **arr;
    char maxstr[10];
    //0. get the number of words.
    num = getWordCount(txt);
    printf("rowsz: %d\n", num);
    //.5 create array with malloc
    arr = createArr(num);
    printf("created arr\n");
    //1. parse text to 2d array
    parseWords2arr(arr, num, txt);
    printf("word parsed\n");
    //2. sort the array by increasing name
    printArr(arr,num);
    qsort(arr,num,sizeof(char*), comparestr);
    printArr(arr,num);

    //3. loop over array until element# -1.
    max =0; count=0;
    for (i=1; i<num; i++){
        if(strcmp(arr[i-1], arr[i])) count++;
        else {
            if (count>max){
                max = count;
                strcpy(maxstr,arr[i]);
            }
            count = 0;
        }
    }
    printf("frequent: %s", maxstr);
    freeArr(arr,num);
    return 0;
}

