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
typedef struct _E{
    char d;
    int s;
    char c;
}E;
typedef struct _F{
    char d;
    char c;
    int s;
}F;



int main(){
    printf("size of A: %lu\n", sizeof(E));
    printf("size of A: %lu\n", sizeof(F));
    return 0;
}
