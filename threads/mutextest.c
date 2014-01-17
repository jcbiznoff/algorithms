#include <stdio.h>
#include <pthread.h>

int main(){
    pthread_mutex_t mut;
    pthread_mutex_init(&mut, NULL);
    int sum =0;
    pthread_mutex_lock(&mut);//acquire
    sum++;
    printf("locked\n");

    pthread_mutex_unlock(&mut);//release
    return 0;
}
