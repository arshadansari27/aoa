#include<stdio.h>
#include<stdlib.h>
#ifndef DATA_TYPE2
#include "data2.c"
#endif

typedef struct _heap {
    datatype2 **nodes;
    int heapsize;
    int length;
} Heap;

Heap *create_heap(int length){
    Heap *heap = (Heap *) malloc(sizeof(Heap));  
    heap->nodes = malloc(length * sizeof(datatype2 *));
    heap->length = length;
    heap->heapsize = 0;
    return heap;
}

int parent(int i) {
    return (i - 1)/2 ;
}

int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return 2 * i + 2;
}

void swap(Heap *heap, int i, int j) {
    datatype2 *temp;
    temp = heap->nodes[i];
    heap->nodes[i] = heap->nodes[j];
    heap->nodes[j] = temp;
}

void min_heapify(Heap *heap, int i) {
    int l, r, value;
    l = left(i); r = right(i);
    if (l < heap->heapsize && heap->nodes[l]->key <= heap->nodes[i]->key) 
        value = l;
    else 
        value = i;
    if (r < heap->heapsize && heap->nodes[r]->key <= heap->nodes[value]->key) 
        value = r;
    if (value != i) {
        swap(heap, value, i);
        min_heapify(heap, value);
    }
}

void insert(Heap *heap, datatype2 *data) {
    int temp, j, i, len, size;
    datatype2 **nodes, *node;
    if (heap->length < (heap->heapsize + 1)){
        len = 2 * heap->length;
        nodes = malloc(len * sizeof(datatype2 *));
        for(j = 0; j < heap->heapsize; j++) {
            nodes[j] = heap->nodes[j];
        }
        free(heap->nodes);
        heap->nodes = nodes;
        heap->length = len;
    }
    node = (datatype2 *) malloc(sizeof(datatype2));
    node->key = data->key;
    node->board = data->board;
    node->node = data->node;
    node->visited = data->visited;
    node->path = data->path;
    heap->nodes[heap->heapsize] = node;
    i = heap->heapsize;
    heap->heapsize++;
    while(i >= 0 && parent(i) != i) {
        if (heap->nodes[parent(i)]->key > heap->nodes[i]->key) {
            swap(heap, i, parent(i));
        }
        i = parent(i);
    }
}

float extract_min(Heap *heap, datatype2 *data) {
    float min;
    if(heap->heapsize <= 0) {
        printf("Heap empty\n");
        return 0;
    }
    min = heap->nodes[0]->key;
    data->key = heap->nodes[0]->key;
    data->board = heap->nodes[0]->board;
    data->node = heap->nodes[0]->node;
    data->visited = heap->nodes[0]->visited;
    data->path = heap->nodes[0]->path;
    heap->nodes[0] = heap->nodes[heap->heapsize - 1];
    heap->nodes[heap->heapsize - 1] = NULL;
    heap->heapsize--;
    min_heapify(heap, 0);
    return min;
}

void build_min_heap(Heap *heap) {
    int i;
    int len = heap->heapsize;
    for(i = len/2; i >= 0; i--) {
        min_heapify(heap, i);
    }
}

void heapsort(Heap *heap) {
    int i;
    build_min_heap(heap);
    for(i = heap->heapsize / 2; i >= 0; i--){
        swap(heap, 0, i);
        min_heapify(heap, 0);
    }
}

void small_display(Heap *heap) {
    int i;
    printf("[");
    for(i = 0; i < heap->heapsize; i++) {
        if(i < heap->heapsize - 1)
            printf("%f, ", heap->nodes[i]->key);
        else
            printf("%f", heap->nodes[i]->key);
    }
    printf("]\n");
}

void display(Heap *heap) {
    int i;
    printf("Heap Max Size: %d\n", heap->length);
    printf("Heap Current Size: %d\n", heap->heapsize);
    printf("Heap Data: [");
    for(i = 0; i < heap->heapsize; i++) {
        if(i < heap->heapsize - 1)
            printf("%f, ", heap->nodes[i]->key);
        else
            printf("%f", heap->nodes[i]->key);
    }
    printf("]\n");
}

/*
void main() {
    int i, min;
    Heap *heap = create_heap(10);
    datatype2 *d;
    for(i = 0; i < 20; i++) {
        d = (datatype2 *) malloc(sizeof(datatype2));
        d->key = 20 - i;
        d->node = 10 * i;
        d->visited = NULL;
        d->path = NULL;
        insert(heap, d);
        free(d);
    }
    small_display(heap); 
    //printf("Sorting again\n");
    //heapsort(heap);
    small_display(heap); 
    while(heap->heapsize > 0) {
        printf("Getting min\n");
        d = (datatype2 *) malloc(sizeof(datatype2));
        min = extract_min(heap, d);
        printf("Min :%d {%f}\n", min, d->key);
        small_display(heap); 
        free(d);
    }
}*/
