#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _cds{
    char *artists;
    int indexId;
    char *title;
}cd;

typedef struct _cdq{
    cd *mycd;
    struct _cdq *next;
}cdq;

cdq *mainQ;

cdq* initcdq(){
    cdq * myq = (cdq*)malloc(sizeof(cdq));
    myq->mycd = NULL;
    myq->next = NULL;
    return myq;
}

void enqueueCdq(cdq **q, cd *mycd){
    cdq * newNode = (cdq*)malloc(sizeof(cdq));

    newNode->mycd = mycd; //would this work? not sure
    newNode->next = *q;
    *q = newNode;
}

void deleteCq(cdq **q){
    cdq *cur = *q;
    cdq *tmp;
    while(cur != NULL){
        tmp = cur;
        *q = cur->next;
    //to do
        free(tmp);
        cur= cur->next;
    }
}

cd* initCds(){
    cd * myCd = (cd *)malloc(sizeof(cd));
    myCd->title = NULL;
    myCd->indexId = 0;
    myCd->title = NULL;
    return myCd;
}

void printOptions(){
    printf("*********************************************\n");
    printf("Select from the following Options\n");
    printf("1. add a cd\n");
    printf("2. delete a cd\n");
    printf("3. search a cd my artist\n");
    printf("4. print cd by artist name\n");
    printf("*********************************************\n");
}

void printPrintCdOption(){
    cdq *cur = mainQ;
    while(cur != NULL){
        printf("artist: %s, index: %d, title: %s\n", cur->mycd->artists, cur->mycd->indexId, cur->mycd->title);
        cur= cur->next;

    }
}
void processNewCdIn(char *aname, int idx, char *title){
   cd* cd1 = initCds();
    // add name
    cd1->artists = (char*)malloc(sizeof(char)*50);
    strcpy(cd1->artists, aname);
    cd1->indexId = idx;
    cd1->title = (char*)malloc(sizeof(char)*100);
    strcpy(cd1->title, title);
    //add to queue/stack?
    enqueueCdq(&mainQ, cd1);
    //signal finish:
    printf("done\n");
}
void printAddCdOption(){
    char aname[50];
    int idx;
    char title[100];

    printf("1. add artist name: \n");
    scanf("%s",aname);
    printf("2. add index for cd\n");
    scanf("%d",&idx);
    printf("3. add title of the song\n");
    scanf("%s",title);

    processNewCdIn(aname, idx, title);
}

void printDeleteCdOption(){

}
void printSearchCdOption(){

}
void readOptions(){
    int opt;
    scanf("%d", &opt);
    switch(opt){
        case 1:
           printAddCdOption();
            break;
        case 2:
            printDeleteCdOption();
            break;
        case 3:
            printSearchCdOption();
            break;
        case 4:
            printPrintCdOption();
            break;
    }
}


int main(){
    while(1){
        printOptions();
        readOptions();
    }
    return 0;
}
