#include <limits.h>

int max(int a, int b){ return a>b?a:b;}

int eggDrop(int e, int f){
    if (f== 0 || f == 1)
        return f;

    if(e == 1)
        return f;

    int min = INT_MAX, i, res;

    for(i= 1; i<= f ;i++){
        res = max(eggDrop(e-1, i-1), eggDrop(e, f-i));
        if(res < min)
            min = res;
    }

    return min + 1;

}
