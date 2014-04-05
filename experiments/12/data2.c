#include<stdio.h>
#include<stdlib.h>
#include "list.c"
#ifndef SET_DECLARED
#define SET_DECLARED
#include "set.c"
#endif
#define DATA_TYPE2

typedef struct {
    float key;
    int node;
    int *board;
    Set *visited;
    List *path;
} datatype2;
