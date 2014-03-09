/*
 * count the number of words in a text
 *
 * int wdcount(char * pat, char *txt)
 */

#include <stdio.h>
#include <string.h>

int wdcount(char *pat, char *txt){
    int i,j,count = 0;
    int plen = strlen(pat);
    int tlen = strlen(txt);

    for (i=0; i<=tlen-plen; i++){
        for(j=0; j<plen;j++){
            if(pat[j] != txt[i+j]) break;
        }
        if(j == plen) count++;
    }
    return count;

}
int main(){
    char * txt = "this is not a game just this game is game";
    char * pat = "game";

    int count =0;
    count = wdcount(pat,txt);
    printf("count: %d\n", count);
    return 0;
}
