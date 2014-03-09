#include <stdio.h>
#include <stdlib.h>
#define HMAX 30000
#define RMAX 500
int h[HMAX];
int a[RMAX];
int data[RMAX];
int minsum[HMAX];
int getHmax(int len){
    int mx;
    int i;
    mx = a[0];
    for(i=0; i<len;i++){
        if (a[i] > mx) mx = a[i];
    }
    return mx;
}
void initArray(){
    int i;
    for(i=0; i<RMAX;i++){
        data[i] = 0;
    }
    for(i=0; i<HMAX; i++){
        h[i] = 0;
        minsum[i] = 0;
    }
}
void csorta(int len){
    int i,max;
    initArray();
    max = getHmax(len);

    for (i=0; i<len;i++){
        h[a[i]]++;
    }
    for(i=1; i<=max ;i++){
        h[i] = h[i] + h[i-1];
    }
    for(i=len-1; i>=0 ; i--){
        data[h[a[i]]-1] = a[i];
        h[a[i]]--;
    }
}
void findDist(int len){
    int i,j;
    int len2 = data[len-1] - data[0] + 1;
    for (i=data[0]; i<=data[len-1];i++){
        for(j=0; j<len; j++)
             minsum[i]+= abs(i - data[j]);
    }
}
int getMin(int len){
    int min = minsum[data[0]];
    int i;
    for(i=data[0] ;i<=data[len-1];i++)
    {
        if(min>minsum[i])
            min = minsum[i];
    }
    return min;
}
int main(){
    int len,num;
    int loc,i;
    int minval;
    scanf("%d", &num);
    while(num > 0){
        scanf("%d", &len);
        for(i=0 ;i<len;i++){
            scanf("%d",&a[i]);
        }
        csorta(len);
        findDist(len);
        minval = getMin(len);
        printf("%d\n", minval);
        num --;
    }
    return 0;
}
