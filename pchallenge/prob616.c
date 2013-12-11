// code needs change..
// need to start with string parsing.. compare against each chars

#include <stdio.h>

#define MAXF 480

long double fib[MAXF];

void findFib(){
    int i=0;

    for (i=0 ; i<MAXF; i++)
        fib[i] = 0;

    fib[0] = 0;
    fib[1] = 1;
    fib[2] = 2;

    for (i=3 ; i<MAXF; i++){
        fib[i] = fib[i-1] + fib[i-2];

    }
}
void findNum (long double a, long double b){
    int i, count =0;

    for (i=0; i< MAXF ;i++){
        if (fib[i] >= a && fib[i] <= b){
        printf("%Lf\n", fib[i]);
            count++;
        }
    }

    printf("%d", count);
}

int main(){
    long double a, b;
    while(1){
    scanf("%Lf %Lf", &a, &b);
    printf("%Lf %Lf\n", a,b);
    if (a ==0 && b ==0) return 0;


    findFib();
    findNum(a,b);
    }

    return 0;
}


