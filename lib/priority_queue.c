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

void offer(PQ *pq, datatype *data) {
    insert(pq->heap, data);
}

int take(PQ *pq, datatype *data) {
    return extract_min(pq->heap, data);
}

int is_empty(PQ *pq) {
    return pq->heap->heapsize <= 0;
}
