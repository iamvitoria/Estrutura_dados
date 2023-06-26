#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da árvore
typedef struct No {
    int info;
    struct No* esq;
    struct No* dir;
} No;

// Função para criar um novo nó
No* criarNo(int info) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->info = info;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    return novoNo;
}

// Função para inserir um nó na árvore
No* inserirNo(No* raiz, int info) {
    if (raiz == NULL) {
        return criarNo(info);
    } else if (info < raiz->info) {
        raiz->esq = inserirNo(raiz->esq, info);
    } else if (info > raiz->info) {
        raiz->dir = inserirNo(raiz->dir, info);
    }
    return raiz;
}

// Função para imprimir a árvore seguindo a ordem (esquerda, direita, raiz)
void arv_imprime(No* raiz) {
    if (raiz != NULL) {
        arv_imprime(raiz->esq);
        arv_imprime(raiz->dir);
        printf("%d ", raiz->info + 1);
    }
}

int main() {
    int matricula = 2015;
    No* raiz = NULL;

    while (matricula > 0) {
        int digito = matricula % 10;
        raiz = inserirNo(raiz, digito);
        matricula /= 10;
    }
    printf("Saida: ");
    arv_imprime(raiz);

    return 0;
}