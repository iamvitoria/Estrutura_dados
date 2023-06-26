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

int removeValue(Heap* heap, int num) {
    // Verifica se o heap está vazio
    if (isEmpty(heap)) {
        printf("Heap esta vazio.\n");
        exit(1);
    }

    // Procura o índice do elemento a ser removido
    int index = -1;
    for (int i = 0; i <= heap->tail; i++) {
        if (heap->heap[i] == num) {
            index = i;
            break;
        }
    }
    
    // Se o elemento não foi encontrado no heap, retorna -1
    if (index == -1) {
        printf("Elemento nao encontrado no heap.\n");
        return -1;
    }

    // Armazena o valor do elemento a ser removido
    int element = heap->heap[index];
    
    // Substitui o elemento a ser removido pelo último elemento do heap
    heap->heap[index] = heap->heap[heap->tail];
    heap->tail -= 1;

    // Realiza o ajuste do heap para manter a propriedade de heap máximo
    heapify(heap, index);

    // Retorna o elemento removido
    return element;
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

void printHeap(Heap* heap) {
    printf("\nElementos do heap: "); // Imprime a mensagem inicial
    
    // Percorre os elementos do heap a partir da raiz até o último elemento
    for (int i = 0; i <= heap->tail; i++) {
        printf("%d ", heap->heap[i]); // Imprime o valor do elemento
    }
    
    printf("\n"); // Imprime uma quebra de linha no final
}