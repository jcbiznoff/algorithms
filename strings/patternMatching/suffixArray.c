/*suffixArray
 *
 * fast pattern matching. Faster than O(n) algorithm => O(mlgn)
 * time to preprocess text => O(n^2 lgn)
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct suffixMap{
    int index;
    char *suff;
}suffMap;

int cmp(void const *p1, void const *p2){
    return strcmp((char const*)((suffMap*)p1)->suff , (char const*)((suffMap*)p2)->suff);
}

/*buildSuffixArray(char *txt, int n)
 * n => length of text
 *
 * store all suffix to an array
 * sort the array
 * return array containing index, not the actual array ( need for binary searching later)
 */
int *buildSuffixArray(char *txt, int n){
    int *suffArray;
    suffMap suf[n];
    int i;
    //1. store each suffix and index to an Array
    for(i=0 ;i<n; i++){
        suf[i].index = i;
        suf[i].suff = txt+i;
    }
    //2.sort suffMap according to string //!!qsort on ds!! change the compare funtion only.
    qsort(suf, n, sizeof(suffMap), cmp);

    suffArray = (int *)malloc(sizeof(int)*n);
    for (i=0; i<n;i++)
        suffArray[i] = suf[i].index;
    return suffArray;
}


/*searchPatWithSuffArray(char * pat, char * text, int * suffArray, int n)
 */
int searchPatWithSuffArray(char * pat, char * text, int * suffArray, int n){
    //1.using binary search, init l and r
    int l = 0, r = n-1;
    int m = strlen(pat);
    //2. loop while (l<r)
    int mid;
    int res;
    while(l<=r){
    //3. check if text + suffArray[m] matches pat // text +!!! really important
        mid = (l+r)/2;
        res = strncmp(pat, text+suffArray[mid], m);
    //4. if not move up (l = mid + 1) or down (r = mid +1)
        if(res == 0){
            printf("pattern found @ index: %d\n",suffArray[mid]);
            return 1;
        }

        else if(res<0)
            r = mid - 1;
        else
            l = mid + 1;
    //5. continue
    }
}


int main(){
    char *txt = "banana";
    char *pat = "nan";
    int n = strlen(txt);
    int *suffixArr = buildSuffixArray(txt,n);
    int i;
    for(i=0; i<n; i++)
        printf("%d ", suffixArr[i]);
    printf("\n");

    if(searchPatWithSuffArray(pat, txt, suffixArr,n)){
        printf("found\n");
    }
    return 0;
}
