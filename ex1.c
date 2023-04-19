#include <stdio.h>
#include <stdlib.h>

struct diagonal {
    int ordem;
    int* v;
};
typedef struct diagonal Diagonal;

// Cria uma matriz diagonal vazia com a ordem informada
Diagonal criarMatriz(int ordem) {
    Diagonal mat;
    mat.ordem = ordem;
    mat.v = (int*) malloc(ordem * sizeof(int));
    return mat;
}

// Preenche a matriz diagonal com os valores informados pelo usuário
void preencherMatriz(Diagonal* mat) {
    int valor;
    for (int i = 0; i < mat->ordem; i++) {
        for (int j = 0; j < mat->ordem; j++) {
            if (i == j) {
                printf("Digite o valor para a posicao [%d][%d]: ", i+1, j+1);
                scanf("%d", &valor);
                mat->v[i] = valor;
            }
        }
    }
}

// Imprime a matriz diagonal
void imprimirMatriz(Diagonal mat) {
    for (int i = 0; i < mat.ordem; i++) {
        for (int j = 0; j < mat.ordem; j++) {
            if (i == j) {
                printf("%d ", mat.v[i]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

// Retorna o valor da matriz diagonal na posição informada
int consultarElemento(Diagonal mat, int linha, int coluna) {
    if (linha == coluna) {
        return mat.v[linha];
    } else {
        return 0;
    }
}

int main() {
    int ordem;
    printf("Digite a ordem da matriz diagonal: ");
    scanf("%d", &ordem);

    Diagonal mat = criarMatriz(ordem);
    preencherMatriz(&mat);

    printf("\nMatriz diagonal:\n");
    imprimirMatriz(mat);

    int linha, coluna;
    printf("\nDigite a posicao para consulta (linha e coluna separadas por espaco): ");
    scanf("%d %d", &linha, &coluna);

    int valor = consultarElemento(mat, linha-1, coluna-1);
    printf("\nValor na posicao [%d][%d]: %d\n", linha, coluna, valor);

    free(mat.v);
    return 0;
}