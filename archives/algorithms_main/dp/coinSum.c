#include <stdio.h>

int countRecur(int *S, int m, int N){
    if (N == 0) return 1;
    if(N <0 ) return 0;
    if(m<=0 && N>=1) return 0;

    return countRecur(S, m-1, N) + countRecur(S,m, N-S[m-1]);

}
