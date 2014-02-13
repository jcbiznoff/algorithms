#include <stdio.h>

typedef struct _A{
    char c;
    short int s;
}A;

typedef struct _B{
    short int s;
    char c;
    int i;
}B;

typedef struct _C{
    char c;
    double d;
    int s;
}C;

typedef struct _D{
    double d;
    int s;
    char c;
}D;

int main(){
    printf("size of A: %lu\n", sizeof(A));
    printf("size of A: %lu\n", sizeof(B));
    printf("size of A: %lu\n", sizeof(C));
    printf("size of A: %lu\n", sizeof(D));
    return 0;
}
