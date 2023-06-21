#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

Heap* createHeap(int capacity) {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->heap = (int*)malloc(capacity * sizeof(int));
    heap->tail = -1;
    heap->capacity = capacity;
    return heap;
}

int isEmpty(Heap* heap) {
    return heap->tail == -1;
}

int left(int index) {
    return 2 * index + 1;
}

int right(int index) {
    return 2 * (index + 1);
}

int parent(int index) {
    return (index - 1) / 2;
}

void add(Heap* heap, int n) {
    if (heap->tail >= (heap->capacity - 1)) {
        printf("Heap is full. Resizing...\n");
        heap->capacity *= 2;
        heap->heap = (int*)realloc(heap->heap, heap->capacity * sizeof(int));
    }

    heap->tail += 1;
    heap->heap[heap->tail] = n;
    
    int i = heap->tail;
    while (i > 0 && heap->heap[parent(i)] < heap->heap[i]) {
        int aux = heap->heap[i];
        heap->heap[i] = heap->heap[parent(i)];
        heap->heap[parent(i)] = aux;
        i = parent(i);
    }
}

int removeValue(Heap* heap) {
    if (isEmpty(heap)) {
        printf("Heap is empty.\n");
        exit(1);
    }

    int element = heap->heap[0];
    heap->heap[0] = heap->heap[heap->tail];
    heap->tail -= 1;

    heapify(heap, 0);

    return element;
}

void heapify(Heap* heap, int index) {
    if (index > parent(heap->tail))
        return;

    int leftIndex = left(index);
    int rightIndex = right(index);
    int maxIndex = index;

    if (leftIndex <= heap->tail && heap->heap[leftIndex] > heap->heap[maxIndex])
        maxIndex = leftIndex;

    if (rightIndex <= heap->tail && heap->heap[rightIndex] > heap->heap[maxIndex])
        maxIndex = rightIndex;

    if (maxIndex != index) {
        int aux = heap->heap[index];
        heap->heap[index] = heap->heap[maxIndex];
        heap->heap[maxIndex] = aux;
        heapify(heap, maxIndex);
    }
}

void printHeap(Heap* heap) {
    printf("Heap elements: ");
    for (int i = 0; i <= heap->tail; i++) {
        printf("%d ", heap->heap[i]);
    }
    printf("\n");
}