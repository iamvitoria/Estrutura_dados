#ifndef HEAP_H
#define HEAP_H

typedef struct {
    int* heap;
    int tail;
    int capacity;
} Heap;

Heap* createHeap(int capacity);
int isEmpty(Heap* heap);
int left(int index);
int right(int index);
int parent(int index);
void add(Heap* heap, int n);
int removeMax(Heap* heap);
void heapify(Heap* heap, int index);
void printHeap(Heap* heap);
void printHeapWithChildren(Heap* heap);
int consulta_heap(Heap* h, int n, int* pos);
void libera_heap(Heap* h);

#endif