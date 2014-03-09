#include <stdio.h>

int cylen(int n, int count){
    if (n ==1 ) return count;
    if (n%2 == 0)
        n = n/2;
    else
        n = 3*n +1;
    count++;
    return cylen(n,count);
}

int maxcylen(int s, int e){
    int tmp,i,maxcy, sz;
    if(s>e){
        tmp =s;
        s = e;
        e = tmp;
    }

    maxcy = 0;
    for(i=s;i<=e;i++){
        sz = cylen(i,1);
        if (sz> maxcy)
            maxcy  =sz;
    }
    return maxcy;
}

int main(){
    int s,e;
    while(scanf("%d %d", &s, &e) != EOF){
        printf("%d %d %d\n",s,e,maxcylen(s,e));
    }
    return 0;
}
