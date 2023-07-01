#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main(int argc, char* argv[]) {
    int capacidade, num, val, pos;
    
    printf("Esse eh um programa de heap Maximo!\n\n");
    printf("Digite a capacidade inicial do heap: ");
    scanf("%d", &capacidade);
    printf("\n");

    Heap* heap = createHeap(capacidade);

    char escolha;

    do {
        printf("Digite um valor para inserir no heap: ");
        scanf("%d", &num);
        add(heap, num);

        printf("Deseja inserir mais valores? (s/n): ");
        scanf(" %c", &escolha);
    } while (escolha == 's' || escolha == 'S');

    printHeap(heap);
    
    printf("\nDigite um valor para consultar no heap: ");
    scanf("%d", &val);
    consulta_heap(heap, val, &pos);
    printf("Posicao do valor %d no heap: %d\n", val, pos);

    int max = removeMax(heap);
    printf("\nMaior elemento removido: %d\n", max);

    printHeap(heap);
	libera_heap(heap);
    return 0;
}