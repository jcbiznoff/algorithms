#include <stdio.h>
#include "backtrack.h"

#define MAXC 100
#define NMAX 100

static int finished = 0;
void backtrackk(int *a, int k,  int data){
    int c[MAXC];
    int ncandidates;
    int i;

    if (is_a_solution(a,k,data))
        process_solution(a,k,data);
    else
    {
        k++;
        construct_candidates(a,k,data,c,&ncandidates);
        for (i=0; i<ncandidates; i++){
            a[k] = c[i];
            make_move(a,k,data);
            backtrackk(a,k,data);
            unmake_move(a,k,data);
            if(finished) return;
        }
    }
}

int is_a_solution(int *a, int k, int data){
    return  k == data;
}

void construct_candidates(int *a, int k, int data, int*c, int* ncandidates ){

    /*c[0] = 1;
    c[1] = 0;
    *ncandidates = 2;
    */

    int i;
    int in_perm[NMAX] ={};

    *ncandidates = 0;

    for (i=0; i<k; i++)
        in_perm[a[i]] = 1;


    for (i=1;i<=data;i++){
        if(in_perm[i] == 0){
            c[*ncandidates] = i;
            *ncandidates = *ncandidates + 1;
        }
    }
}

void process_solution(int *a, int k, int data){
    int i;
    printf("{");
    for (i=1; i<=k ;i++){
        //if (a[i] == 1 )printf(" %d", i);
        printf(" %d", a[i]);
    }
    printf(" }\n");
}


void make_move(int *a, int k, int data){}

void unmake_move(int *a, int k, int data){}
