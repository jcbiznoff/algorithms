/*Knuth Morris Pratt pattern searching algorithm
 * implementation in c
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int *computeLPS(char *pat, int m, int* lps);
void KMPSearch(char *pat, char *txt){
    //Algo:
    //1. create lps
    //2. pattern to lps
    //3. while looping index
    //4. if mismatch found, skip text given by lps
    int i=0,j=0;
    int m,n;
    m = strlen(pat);
    n = strlen(txt);

    int *lps = (int*)malloc(sizeof(int)*m);

    computeLPS(pat,m, lps);

    while(i<n){

        if(pat[j] == txt[i]){
            i++;j++;
        }
        if(j == m){
            printf("found patter @ idx %d\n", i-j);
            j = lps[j-1];
        }
        if(pat[j] != txt[i]){
            if(j!=0)
                j = lps[j-1];
            else
                i++;
        }
    }
    free(lps);

}

int *computeLPS(char *pat, int m, int* lps){
    int len=0;
    int i;

    lps[0] = 0;
    i=1;

    while(i<m){
        if(pat[i] == pat[len]){
            len++;
            lps[i]= len;
            i++;
        }
        else{
            if(len!=0)
                len=lps[len-1];
            else{
                lps[i] =0;
                i++;
            }
        }
    }
}

int main(){

    char *txt = "ABABDABACDABABCABAB";
    char *pat = "ABABCABAB";
    KMPSearch(pat,txt);
    return 0;
}


