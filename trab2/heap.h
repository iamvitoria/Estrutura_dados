#ifndef HEAP_H
#define HEAP_H

#define MAX_SIZE 100

struct Heap {
    int elements[MAX_SIZE];
    int size;
};

struct Heap* createHeap();
void swap(int* a, int* b);
void heapifyUp(struct Heap* heap, int index);
void insert(struct Heap* heap, int value);
void heapifyDown(struct Heap* heap, int index);
int removeValue(struct Heap* heap, int value);
void printHeap(struct Heap* heap);

#endif
