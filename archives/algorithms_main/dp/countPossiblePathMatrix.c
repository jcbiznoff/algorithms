#include <stdio.h>

int numberOfPaths(int m, int n){
    if(m == 1 || n ==1 )
        return 1;

    return numberOfPaths(m-1,n) + numberOfPaths(m,n-1);
}

int numberOfPathsDP(int m, int n){
    //1. set up a 2d count matrix
    int count[m][n];
    int i,j;
    //2. init first row and col to 1
    for(i=0; i<m ;i++)
        count[i][0] = 1;
    for(j=0; j<n; j++)
        count[0][j] = 1;
    //3. loop both rows and cols
    for(i=1; i<m ;i++)
        for(j=1; j<n; j++)
        //4. add next from both up ([i-1][j])and left[i][j-1]
        count[i][j] = count[i-1][j] + count[i][j-1];     //5. return result

    return count[m-1][n-1];// important to return m-1 and n-1
}

int main(){
    printf("number of paths: %d\n", numberOfPaths(3,3));
    printf("number of paths: %d\n", numberOfPathsDP(3,3));
    return 0;
}
