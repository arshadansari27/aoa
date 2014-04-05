#include<stdio.h>
#include<stdlib.h>
#include "heapsort.c"

typedef struct _pq {
    Heap *heap;
} PQ;

PQ *create_PQ(int length) {
    PQ *pq = (PQ *) malloc(sizeof(PQ));
    pq->heap = create_heap(length);
    return pq;
}

void offer(PQ *pq, float key, int *board, int node, Set *visited, List *path) {
    datatype2 *d = (datatype2 *) malloc(sizeof(datatype2));
    d->key = key;
    d->node = node;
    d->visited = visited;
    d->path = path;
    d->board = board;
    insert(pq->heap, d);
    free(d);
}

datatype2 *take(PQ *pq) {
    datatype2 *data = (datatype2 *) malloc(sizeof(datatype2));
    extract_min(pq->heap, data);
    return data;
}

int is_empty(PQ *pq) {
    return pq->heap->heapsize <= 0;
}

/*
void main() {
    datatype2 *d;
    int i, min, key, node;
    Set *visited;
    List *path;
    PQ *pq = create_PQ(2000);
    for(i = 0; i < 20; i++) {
        key = 20 - i;
        node = 10 * i;
        visited = NULL;
        path = NULL;
        offer(pq, key, node, visited, path);
    }
    while(!is_empty(pq)) {
        printf("Getting min\n");
        d = take(pq);
        printf("Min :{%f}\n", d->key);
        free(d);
    }
}
*/
