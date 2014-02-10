#include <stdio.h>


typedef struct _stocks{//use a stock ds: price and day
    int day;
    int price;
}stock;

int main(){
    /*Solution1: use a struct to store price and day, compare by price, swap ds
     */
    stock mystock[] = {{0,23}, {1,55}, {2,12}, {3,23}, {4,61}, {5,53}, {6,45}, {7,12}, {8,24}, {9,188}};
    stock tmp;
    int i,j;

    for (i=0; i<10; i++){
        for(j=0; j<10-i-1; j++){
            if(mystock[j].price > mystock[j+1].price){//compare on prices
                tmp = mystock[j];//swap stock ds
                mystock[j] = mystock[j+1];
                mystock[j+1] = tmp;
            }
        }
    }



    /*
     * Solution2:  use two arrays, => compare on price, but swap both
     */
    /*
    int mystock[] = {23,55,12,23,61,53,45,12,24,188};
    int days[] = {0,1, 2, 3,4,5,6,7,8,9};
    int i,j,tmp,tmp2;

    for (i=0; i<10; i++){
        for(j=0; j<10-i-1; j++){
            if(mystock[j] > mystock[j+1]){
                tmp = mystock[j];
                mystock[j] = mystock[j+1];
                mystock[j+1] = tmp;

                tmp2 = days[j];
                days[j] = days[j+1];
                days[j+1] = tmp;
            }
        }
    }
    */
    for(i=0; i<10; i++){
        printf("%d ", mystock[i].price);
    }
    printf("\n");
    for(i=0; i<10; i++){
        printf("%d ", mystock[i].day);
    }
    printf("\n");

    printf("sell on day : %d\n", mystock[0].day);
    printf("buy on day: %d\n",mystock[9].day);

    return 0;

}
