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

int isEmpty(cdq *q){
    if(q == NULL) return 1;
    else
        return 0;
}

void printOptions(){
    printf("*********************************************\n");
    printf("Select from the following Options\n");
    printf("1. add a cd\n");
    printf("2. delete a cd\n");
    printf("3. search my collection\n");
    printf("4. print my collecitons\n");
    printf("5. save data to file\n");
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
    printf("ok. job completed\n");
}
void printAddCdOption(){
    char aname[50];
    int idx;
    char title[100];

    printf("add an artist name: ");
    scanf("%s",aname);
    printf("add a unique index: ");
    scanf("%d",&idx);
    printf("add song title: ");
    scanf("%s",title);
    printf("\n");
    processNewCdIn(aname, idx, title);
}

void deleteItembyIndex(int targ){
    if(isEmpty(mainQ)) return;
    cdq * prev, *cur;
    cur= mainQ;
    prev=NULL;
    while(cur != NULL){
        if(cur->mycd->indexId == targ){
            if(prev == NULL)
                mainQ = cur->next;
            else
                prev->next = cur->next;

            free(cur->mycd->title);
            free(cur->mycd->artists);
            free(cur->mycd);
            free(cur);

            return;
        }

        prev= cur;
        cur = cur->next;
    }
}

int indexInRange(int targ){
    if(isEmpty(mainQ)) return 0;
    cdq * cur = mainQ;
    while(cur != NULL){
        if(cur->mycd->indexId == targ)
            return 1;
        cur=cur->next;
    }
    return 0;
}

void printDeleteCdOption(){
    int targ;
    printf("select index to delete: ");
    scanf("%d",&targ);

    if(!indexInRange(targ))
        return;

    deleteItembyIndex(targ);
}

int foundString(char * str, int stropt){
    cdq *nd;
    nd = mainQ;
    for(nd = mainQ; nd != NULL; nd=nd->next){
        if(stropt == 0 && strcmp(nd->mycd->artists, str) == 0){
            printf("artist: %s, index: %d, title: %s\n", nd->mycd->artists, nd->mycd->indexId, nd->mycd->title);
            return 1;
        }
        if(stropt == 1 && strcmp(nd->mycd->title, str) == 0){
            printf("artist: %s, index: %d, title: %s\n", nd->mycd->artists, nd->mycd->indexId, nd->mycd->title);
            return 1;
        }
    }
    return 0;
}

void searchByArtistName(){
    char name[100];
    printf("input artist name: ");
    scanf("%s",name);
    if(foundString(name, 0)){
        printf("found!\n");

    }else{
        printf("non found. Retry search\n");
    }
}
void searchByTitle(){
    char name[100];
    printf("input title name: ");
    scanf("%s",name);
    if(foundString(name, 1)){
        printf("found!\n");

    }else{
        printf("non found. Retry search\n");
    }
}
int foundInt(int idx){
    cdq *nd;
    nd = mainQ;
    for(nd = mainQ; nd != NULL; nd=nd->next){
        if(nd->mycd->indexId == idx){
            printf("artist: %s, index: %d, title: %s\n", nd->mycd->artists, nd->mycd->indexId, nd->mycd->title);
            return 1;
        }
    }
    return 0;
}
void searchByIndexId(){
    int idx;
    printf("input index Id: ");
    scanf("%d",&idx);
    if(foundInt(idx)){
        printf("found!\n");
    }else{
        printf("non found. Retry search\n");
    }
}

void printSearchCdOption(){
    int opt;
    printf("how do you want to search? \n");
    printf("1. By Artist Name\n");
    printf("2. By Index Id\n");
    printf("3. By Title\n");
    scanf("%d",&opt);

    switch(opt){
        case 1:
            searchByArtistName();
            break;
        case 2:
            searchByIndexId();
            break;
        case 3:
            searchByTitle();
            break;
        default :
            printf("no option avail\n");
    }

    return;
}
void readDataFile(){
    char str1[100];
    char str2[100];
    int indexid;

    FILE *fp = fopen("mycollection.txt","rt");
    if(fp == NULL) return;

    while(fscanf(fp,"%s %d %s", str1, &indexid, str2)!=EOF){
        cd * newcd = initCds();
        newcd->artists = (char*)malloc(sizeof(char)*100);
        strcpy(newcd->artists, str1);

        newcd->title = (char*)malloc(sizeof(char)*100);
        strcpy(newcd->title, str2);

        newcd->indexId = indexid;

        enqueueCdq(&mainQ, newcd);

    }
    fclose(fp);

}
void saveData2File(){
    FILE* fp = fopen("mycollection.txt","wt");
    if(fp == NULL) return;
    cdq *cur = mainQ;
    for(cur=mainQ; cur !=NULL; cur=cur->next){
        fprintf(fp,"%s %d %s\n", cur->mycd->artists, cur->mycd->indexId, cur->mycd->title);
    }
    fclose(fp);
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
        case 5:
            saveData2File();
            break;
    }
}


int main(){
    readDataFile();
    while(1){
        printOptions();
        readOptions();
        printf("\n");
    }
    return 0;
}
