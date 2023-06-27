#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main(int argc, char *argv[]) {
    int capacidade, num;
    printf("Digite a capacidade inicial do heap: ");
    scanf("%d", &capacidade);

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

    int max = removeMax(heap);
    printf("\nMaior elemento removido: %d\n", max);

    printHeap(heap);

    return 0;
}