#include <stdio.h>
#include <stdlib.h>

void preprocess(int k, int Table[][2]){
    int trans0, trans1;
    int state;
    for(state=0; state<k; state++){
        trans0 = state<<1;
        //printf("trans0: %d ", trans0);
        Table[state][0] = (trans0<k)?trans0:trans0-k;
        printf("Table[state][0]: %d ", Table[state][0]);

        trans1 = (state<<1)+1;
        //printf("trans1: %d ", trans1);
        Table[state][1] = (trans1<k)?trans1:trans1-k;
        printf("Table[state][1]: %d ", Table[state][1]);
        printf("\n");
    }
}

void isDivisibleUtil(int num, int *state, int Table[][2]){
    if(num != 0){
        isDivisibleUtil(num>>1, state, Table);
        *state = Table[*state][num&1];
    }
}

int isDivisible(int num, int k){
    int (*Table)[2] = (int (*)[2])malloc(sizeof(*Table)*k);
    preprocess(k, Table);

    int state=0;
    isDivisibleUtil(num, &state, Table);

    return state;
}

int main(){
    int num = 47;
    int k=5;

    int rem = isDivisible(num,k);

    if(rem == 0)
        printf("divisible\n");
    else
        printf("not divisible, remainder: %d \n",rem);


    return 0;
}
