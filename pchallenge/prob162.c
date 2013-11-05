#include <stdio.h>
#define MAXV 100

void initMap(int (*map)[MAXV][MAXV], int (*map2)[MAXV][MAXV]){
    int i,j;
    for(i=0;i<MAXV;i++){
        for(j=0;j<MAXV;j++){
            (*map)[i][j]=0;
            (*map2)[i][j]=0;
        }
    }
}
void printMap(int (*map)[MAXV], int m, int n){
    int i,j;
    for(i=0; i<m;i++){
        for(j=0;j<n;j++){
            if(map[i][j] == 5)
                printf("*");
            else
                printf("%d", map[i][j]);
        }
        printf("\n");
    }
}
void findMines(int (*map)[MAXV][MAXV], int (*map2)[MAXV][MAXV], int M, int N){
    int i,j;
    int count;
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            count =0;
            if((*map)[i][j] == 1){
                (*map2)[i][j] = 5;
                continue;
            }
            if(i==0){
                    if(j==0){
                        if((*map)[i][j+1] == 1) count++;
                        if((*map)[i+1][j] == 1) count++;
                        if((*map)[i+1][j+1] == 1) count++;
                    }
                    else if( j == N-1){
                        if(*(map)[i][j-1] == 1) count++;
                        if((*map)[i+1][j] == 1) count++;
                        if((*map)[i+1][j-1] == 1) count++;
                    }
                    else{
                        if((*map)[i][j-1] == 1) count++;
                        if((*map)[i][j+1] == 1) count++;
                        if((*map)[i+1][j-1] == 1) count++;
                        if((*map)[i+1][j] == 1) count++;
                        if((*map)[i+1][j+1] == 1) count++;
                    }
            }
            else if(i == M-1){
                    if(j== 0){
                        if((*map)[i][j+1] == 1) count++;
                        if((*map)[i-1][j+1] == 1) count++;
                        if((*map)[i-1][j] == 1) count++;
                    }
                    else if (j == N-1){
                        if((*map)[i-1][j] == 1) count++;
                        if((*map)[i-1][j-1] == 1) count++;
                        if((*map)[i][j-1] == 1) count++;
                    }
                    else{
                        if((*map)[i][j-1] == 1) count++;
                        if((*map)[i][j+1] == 1) count++;
                        if((*map)[i-1][j-1] == 1) count++;
                        if((*map)[i-1][j] == 1) count++;
                        if((*map)[i-1][j+1] == 1) count++;
                    }
            }
            else{
                    if(j ==  0){
                        if((*map)[i-1][j] == 1) count++;
                        if((*map)[i+1][j] == 1) count++;
                        if((*map)[i-1][j+1] == 1) count++;
                        if((*map)[i][j+1] == 1) count++;
                        if((*map)[i+1][j+1] == 1) count++;
                    }
                    else if (j == N-1){
                        if((*map)[i-1][j] == 1) count++;
                        if((*map)[i+1][j] == 1) count++;
                        if((*map)[i-1][j-1] == 1) count++;
                        if((*map)[i][j-1] == 1) count++;
                        if((*map)[i+1][j-1] == 1) count++;
                    }
                    else{
                        if((*map)[i-1][j-1] == 1) count++;
                        if((*map)[i-1][j] == 1) count++;
                        if((*map)[i-1][j+1] == 1) count++;
                        if((*map)[i][j-1] == 1) count++;
                        if((*map)[i][j+1] == 1) count++;
                        if((*map)[i+1][j-1] == 1) count++;
                        if((*map)[i+1][j] == 1) count++;
                        if((*map)[i+1][j+1] == 1) count++;
                    }
            }
            (*map2)[i][j] = count;
        }
    }
}

int main(){
    int M,N, i,j,l,cloop;
    int i1,j1;
    int mMap[MAXV][MAXV], newMap[MAXV][MAXV];
    char tmpbuff[MAXV+1];

    cloop=1;
    while(scanf("%d %d",&M,&N)!= EOF ){
        if (M == 0 && N == 0) break;
        i=0;
        //initMap(&mMap, &newMap);

        for(i1=0;i1<MAXV;i1++){
            for(j1=0;j1<MAXV;j1++){
                mMap[i1][j1]=0;
                newMap[i1][j1]=0;
            }
        }

        while(i<M){
            scanf("%s",tmpbuff);
            for(j=0;j<N;j++){ //careful here j is to N !!!
                if(tmpbuff[j] == '*')
                    mMap[i][j]=1;
            }
            i++;
        }
        //findMines(&mMap, &newMap,M,N);
        int count;
        for(i1=0;i1<M;i1++){
            for(j1=0;j1<N;j1++){
                count =0;
                if(mMap[i1][j1] == 1){
                    newMap[i1][j1] = 5;
                    continue;
                }
                if(i1==0){
                        if(j1==0){
                            if(mMap[i1][j1+1] == 1) count++;
                            if(mMap[i1+1][j1] == 1) count++;
                            if(mMap[i1+1][j1+1] == 1) count++;
                        }
                        else if( j1 == N-1){
                            if(mMap[i1][j1-1] == 1) count++;
                            if(mMap[i1+1][j1] == 1) count++;
                            if(mMap[i1+1][j1-1] == 1) count++;
                        }
                        else{
                            if(mMap[i1][j1-1] == 1) count++;
                            if(mMap[i1][j1+1] == 1) count++;
                            if(mMap[i1+1][j1-1] == 1) count++;
                            if(mMap[i1+1][j1] == 1) count++;
                            if(mMap[i1+1][j1+1] == 1) count++;
                        }
                }
                else if(i1 == M-1){
                        if(j1== 0){
                            if(mMap[i1][j1+1] == 1) count++;
                            if(mMap[i1-1][j1+1] == 1) count++;
                            if(mMap[i1-1][j1] == 1) count++;
                        }
                        else if (j1 == N-1){
                            if(mMap[i1-1][j1] == 1) count++;
                            if(mMap[i1-1][j1-1] == 1) count++;
                            if(mMap[i1][j1-1] == 1) count++;
                        }
                        else{
                            if(mMap[i1][j1-1] == 1) count++;
                            if(mMap[i1][j1+1] == 1) count++;
                            if(mMap[i1-1][j1-1] == 1) count++;
                            if(mMap[i1-1][j1] == 1) count++;
                            if(mMap[i1-1][j1+1] == 1) count++;
                        }
                }
                else{
                        if(j1 ==  0){
                            if(mMap[i1-1][j1] == 1) count++;
                            if(mMap[i1+1][j1] == 1) count++;
                            if(mMap[i1-1][j1+1] == 1) count++;
                            if(mMap[i1][j1+1] == 1) count++;
                            if(mMap[i1+1][j1+1] == 1) count++;
                        }
                        else if (j1 == N-1){
                            if(mMap[i1-1][j1] == 1) count++;
                            if(mMap[i1+1][j1] == 1) count++;
                            if(mMap[i1-1][j1-1] == 1) count++;
                            if(mMap[i1][j1-1] == 1) count++;
                            if(mMap[i1+1][j1-1] == 1) count++;
                        }
                        else{
                            if(mMap[i1-1][j1-1] == 1) count++;
                            if(mMap[i1-1][j1] == 1) count++;
                            if(mMap[i1-1][j1+1] == 1) count++;
                            if(mMap[i1][j1-1] == 1) count++;
                            if(mMap[i1][j1+1] == 1) count++;
                            if(mMap[i1+1][j1-1] == 1) count++;
                            if(mMap[i1+1][j1] == 1) count++;
                            if(mMap[i1+1][j1+1] == 1) count++;
                        }
                }
                newMap[i1][j1] = count;
            }
        }
        if(cloop>1)printf("\n");
        printf("Field #%d:\n", cloop);
        //printMap(newMap,M,N);
        for(i1=0; i1<M;i1++){
            for(j1=0;j1<N;j1++){
                if(newMap[i1][j1] == 5)
                    printf("*");
                else
                    printf("%d", newMap[i1][j1]);
            }
            printf("\n");
        }
        ++cloop;
    }
    return 0;
}
