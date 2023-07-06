#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main(int argc, char* argv[]) {
    int capacidade, num, val, pos, cont=0;
    
    printf("Esse eh um programa de heap Maximo!\n\n");
    printf("Digite a capacidade inicial do heap: ");
    scanf("%d", &capacidade);
    cont = capacidade;
    printf("\n");

    Heap* heap = createHeap(capacidade);

    do {
        printf("Digite um valor para inserir no heap: ");
        scanf("%d", &num);
        add(heap, num);
        cont--;

    } while (cont!=0);

    printHeapWithChildren(heap);
    
    printf("\nDigite um valor para consultar no heap: ");
    scanf("%d", &val);
    consulta_heap(heap, val, &pos);
    printf("Posicao do valor %d no heap: %d\n", val, pos+1);

    int max = removeMax(heap);
    printf("\nMaior elemento removido: %d\n", max);

    printHeapWithChildren(heap);
    libera_heap(heap);
    return 0;
}