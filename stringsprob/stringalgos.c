#include <stdio.h>
#include <string.h>
//NSM: Naive String Matcher
int isPatternMatched(char *p, char *t){

    int plen = strlen(p);
    int tlen = strlen(t);
    int i,j,count=0;

    for(i=0; i<= tlen-plen; i++){
        for(j=0; j<plen; j++){
            if(p[j] == t[i+j])
                count++;
            else
                break;
        }
        if(count == plen) return 1;
        count = 0;
    }
    return 0;
}

int isCleverPatternMatched(char *p, char *t){

    int plen = strlen(p);
    int tlen = strlen(t);
    int i,j; //removed count

    for(i=0; i<= tlen-plen; i++){
        for(j=0; j<plen; j++){
            if(p[j] != t[i+j]) //use a not condition
                break;
        }
        if(j == plen) return 1; //use j index as count instead of count variable
    }
    return 0;
}


/*
 * lessions learned:
 * string input handling:
 *  scanf: word
 *  fgets: text
 *  strtok: text split each word  to array?
 *  strstr: find index of pattern from text
 *  strlen: string length
 * */


int main(){
    char p[100];
    char t[1000];

    while(1){
        fgets(p,99,stdin);
        p[strlen(p)-1] = '\0';

        //read text, save in t
        fgets(t,999,stdin);
        t[strlen(t)-1] = '\0';

        //TO DO: check string format: 0 0? \n \n?
        if(isCleverPatternMatched(p,t))
            printf("found pattern\n");
        else
            printf("pattern not exist\n");

    }


    return 0;
}
