#define MAXS 100
typedef struct _setunion{
    int p[MAXS+1];
    int size[MAXS+1];
    int n;
}setunion;

int findSet(setunion *, int i);
void unionSet(setunion *, int i, int j);
void initSetUnion(setunion*, int);
bool sameComponent(setunion*, int i, int j);
