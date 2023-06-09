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
    return 2 * index + 2;
}

int parent(int index) {
    return (index - 1) / 2;
}

void add(Heap* heap, int n) {
    // Verifica se o heap está cheio
    if (heap->tail >= (heap->capacity - 1)) {
        printf("Heap esta cheio\n");

        // Dobra a capacidade do heap
        heap->capacity *= 2;

        // Realoca o heap para a nova capacidade
        heap->heap = (int*)realloc(heap->heap, heap->capacity * sizeof(int));
    }

    // Incrementa o índice tail e insere o valor n no heap
    heap->tail += 1;
    heap->heap[heap->tail] = n;

    // Realiza o ajuste do heap para manter a propriedade de heap máximo
    int i = heap->tail;
    while (i > 0 && heap->heap[parent(i)] < heap->heap[i]) {
        // Troca o valor do elemento atual com o valor do pai
        int aux = heap->heap[i];
        heap->heap[i] = heap->heap[parent(i)];
        heap->heap[parent(i)] = aux;

        // Atualiza o índice para o pai
        i = parent(i);
    }
}

int removeMax(Heap* heap) {
    // Verifica se o heap está vazio
    if (isEmpty(heap)) {
        printf("Heap esta vazio.\n");
        exit(1);
    }

    // Armazena o valor máximo (no topo do heap)
    int max = heap->heap[0];

    // Substitui o valor máximo pelo último elemento do heap
    heap->heap[0] = heap->heap[heap->tail];
    heap->tail -= 1;

    // Realiza o ajuste do heap para manter a propriedade de heap máximo
    heapify(heap, 0);

    // Retorna o valor máximo removido
    return max;
}

void heapify(Heap* heap, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int size = heap->tail + 1;

    if (left < size && heap->heap[left] > heap->heap[largest])
        largest = left;

    if (right < size && heap->heap[right] > heap->heap[largest])
        largest = right;

    if (largest != index) {
        int temp = heap->heap[index];
        heap->heap[index] = heap->heap[largest];
        heap->heap[largest] = temp;
        heapify(heap, largest);
    }
}

void printHeap(Heap* heap) {
    if (heap == NULL || isEmpty(heap)) {
        printf("Heap vazio.\n");
        return;
    }

    printf("\nFila em ordem de prioridade máxima: ");
    for (int i = 0; i <= heap->tail; i++) {
        printf("%d ", heap->heap[i]);
    }
    printf("\n");
}

void printHeapWithChildren(Heap* heap) {
    if (heap == NULL || isEmpty(heap)) {
        printf("Heap vazio.\n");
        return;
    }

    printf("\nFila em ordem de prioridade maxima (com filhos):\n");
    for (int i = 0; i <= heap->tail; i++) {
        printf("No: %d\n", heap->heap[i]);
        int leftIndex = left(i);
        int rightIndex = right(i);

        if (leftIndex <= heap->tail)
            printf("  Filho esquerdo: %d\n", heap->heap[leftIndex]);
        if (rightIndex <= heap->tail)
            printf("  Filho direito: %d\n", heap->heap[rightIndex]);

        printf("\n");
    }
}

int consulta_heap(Heap* h, int n, int* pos) {
    if (h == NULL || isEmpty(h)) {
        fprintf(stdout, "Nao e possível procurar elemento em heap vazio.\n");
        return 0;
    }

    for (int i = 0; i <= h->tail; i++) {
        if (n == h->heap[i]) {
            *pos = i;
            return 1;
        }
    }

    return 0;
}

void libera_heap(Heap* h) {
    free(h->heap);
    free(h);
}
