#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

struct Heap* createHeap() {
    struct Heap* heap = (struct Heap*)malloc(sizeof(struct Heap));
    heap->size = 0;
    return heap;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(struct Heap* heap, int index) {
    int parent = (index - 1) / 2;
    if (index > 0 && heap->elements[index] > heap->elements[parent]) {
        swap(&heap->elements[index], &heap->elements[parent]);
        heapifyUp(heap, parent);
    }
}

void insert(struct Heap* heap, int value) {
    if (heap->size >= MAX_SIZE) {
        printf("Heap is full. Cannot insert any more elements.\n");
        return;
    }
    heap->elements[heap->size] = value;
    heapifyUp(heap, heap->size);
    heap->size++;
}

void heapifyDown(struct Heap* heap, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < heap->size && heap->elements[left] > heap->elements[largest])
        largest = left;
    if (right < heap->size && heap->elements[right] > heap->elements[largest])
        largest = right;

    if (largest != index) {
        swap(&heap->elements[index], &heap->elements[largest]);
        heapifyDown(heap, largest);
    }
}

int removeValue(struct Heap* heap, int value) {
    if (heap->size == 0) {
        printf("Heap está vazio\n");
        return -1;
    }
    
    // Procurar o valor no heap
    int index = -1;
    for (int i = 0; i < heap->size; i++) {
        if (heap->elements[i] == value) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Valor não encontrado no heap\n");
        return -1;
    }
    
    int removedValue = heap->elements[index];
    
    // Substituir o valor pelo último elemento do heap
    heap->elements[index] = heap->elements[heap->size - 1];
    heap->size--;
    
    // Reorganizar o heap
    heapifyDown(heap, index);
    
    return removedValue;
}

void printHeap(struct Heap* heap) {
    printf("\nElementos do heap: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->elements[i]);
    }
    printf("\n");
}