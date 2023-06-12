#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	struct Heap* heap = createHeap();
    int value, num;
    char choice;

    do {
        printf("Digite um valor para inserir no heap: ");
        scanf("%d", &value);
        insert(heap, value);

        printf("Deseja inserir mais valores? (s/n): \n");
        scanf(" %c", &choice);
    } while (choice == 's' || choice == 'S');

    printHeap(heap);

    printf("\nInforme o elemento que deseja remover\n");
    scanf("%d", &num);
    int max = removeValue(heap, num);
    printf("Elemento removido: %d\n", max);

    printHeap(heap);

    return 0;
}