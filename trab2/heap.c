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
        printf("Heap esta cheio...\n");
        
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

void heapify(Heap* heap, int index) {
    // Verifica se o índice está além do pai do último elemento do heap
    // Caso esteja, retorna, pois não há mais elementos para ajustar
    if (index > parent(heap->tail))
        return;

    // Obtém os índices dos filhos esquerdo e direito do índice atual
    int leftIndex = left(index);
    int rightIndex = right(index);
    
    // Inicialmente, considera o índice atual como o máximo
    int maxIndex = index;

    // Compara o valor do filho esquerdo com o valor máximo atual
    // Se o filho esquerdo for maior, atualiza o índice do valor máximo
    if (leftIndex <= heap->tail && heap->heap[leftIndex] > heap->heap[maxIndex])
        maxIndex = leftIndex;

    // Compara o valor do filho direito com o valor máximo atual
    // Se o filho direito for maior, atualiza o índice do valor máximo
    if (rightIndex <= heap->tail && heap->heap[rightIndex] > heap->heap[maxIndex])
        maxIndex = rightIndex;

    // Se o índice do valor máximo for diferente do índice atual
    // Realiza a troca dos valores e continua o ajuste recursivamente
    if (maxIndex != index) {
        int aux = heap->heap[index];
        heap->heap[index] = heap->heap[maxIndex];
        heap->heap[maxIndex] = aux;
        heapify(heap, maxIndex);
    }
}

int removeMax(Heap* heap) {
    // Verifica se o heap está vazio
    if (isEmpty(heap)) {
        printf("Heap está vazio.\n");
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

/*void printHeap(Heap* heap, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", heap->heap[i]);
    }
    printf("\n");
}*/

void printHeapTraversal(Heap* heap, int index, int traversalOrder) {
    if (index <= heap->tail) {
        if (traversalOrder == 1) {
            printf("%d ", heap->heap[index]); // Pré-ordem
            printHeapTraversal(heap, left(index), traversalOrder);
            printHeapTraversal(heap, right(index), traversalOrder);
        } else if (traversalOrder == 2) {
            printHeapTraversal(heap, left(index), traversalOrder);
            printf("%d ", heap->heap[index]); // Em ordem
            printHeapTraversal(heap, right(index), traversalOrder);
        } else if (traversalOrder == 3) {
            printHeapTraversal(heap, left(index), traversalOrder);
            printHeapTraversal(heap, right(index), traversalOrder);
            printf("%d ", heap->heap[index]); // Pós-ordem
        }
    }
}

// Função de impressão em pré-ordem, em ordem e pós-ordem
void printHeap(Heap* heap) {
    printf("\nImpressao em pre-ordem: ");
    printHeapTraversal(heap, 0, 1);
    printf("\n");
    
    printf("Impressao em ordem: ");
    printHeapTraversal(heap, 0, 2);
    printf("\n");
    
    printf("Impressão em pos-ordem: ");
    printHeapTraversal(heap, 0, 3);
    printf("\n");
}