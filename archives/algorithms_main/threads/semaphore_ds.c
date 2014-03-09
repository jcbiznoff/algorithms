
typedef struct {
    int value;
   struct process *list;
}semaphore_me;

void wait_s(semaphore_me *S){
    S->value--;
    if(S->value <0){
        //add process to S->list
        block();
    }
}

void signal_s(semaphore_me *S){
    S->value++;
    if(S->value <= 0){
        //remove a process P from S->list
        wakup(P);
    }
}

