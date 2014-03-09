#include <stdio.h>
#include <pthread.h>

static int sum;

void *pfunction(void *param){
    int count = *((int*)param);
    printf("count read :%d\n",count);
    int i;
    sum = 0;
    for(i=0; i<=count;i++){
        sum += i;
    }
}

int main(){
    pthread_t tid;
    pthread_attr_t attr;
    int count =2;

    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, pfunction, &count);

    pthread_join(tid,NULL);
    printf("sum: %d\n", sum);

    return 0;
}
