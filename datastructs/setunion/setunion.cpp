#include "setunion.h"
void initSetUnion(setunion* s, int n){
    int i;
    for (i=0; i<=n ;i++){
        s->p[i] = i;
        s->size[i] = 1;
    }
    s->n = n;
}
int findSet(setunion * s, int i){
    int res = i;
    if(s->p[i] == i) return i;

    return(findSet(s,i));
}
void unionSet(setunion * s, int i, int j){
    int s1,s2;
    s1 = findSet(s,i);
    s2 = findSet(s,j);
    if (s1 == s2) return;

    if(s->size[s1] > s->size[s2]){
        s->size[s1] = s->size[s1] + s->size[s2];
        s->p[s2] = s1;
    }
    else{
        s->size[s2] = s->size[s1] + s->size[s2];
        s->p[s1] = s2;

    }
}
bool sameComponent(setunion* s, int i, int j){
    return (findSet(s,i) == findSet(s,j));
}
