#include <stdio.h>
#include <stdlib.h>

//lista de valores não nulos da matriz esparsa. Os elementos não nulos da matriz são armazenados nesta lista. Os valores restantes, q são nulos, não são armazenados em nenhum lugar.
struct lista {
	int linha; // linha onde se encontra o elemento não nulo
	int coluna; // coluna onde se encontra o elemento não nulo
	int info; // valor do elemento não nulo
	struct lista* prox; // apontador para o proximo elemento não nulo da matriz
};
typedef struct lista Lista;

struct esparsa{
	int linhas; //numero de linhas da matriz
	int colunas; //numero de colunas da matriz
	struct lista* prim; //apontador para o primeiro noh não nulo da matriz
};
typedef struct esparsa Esparsa;

// Função para criar uma matriz esparsa vazia
Esparsa* criar_matriz(int linhas, int colunas) {
    Esparsa* mat = (Esparsa*) malloc(sizeof(Esparsa));
    mat->linhas = linhas;
    mat->colunas = colunas;
    mat->prim = NULL;
    return mat;
}

// Preenche a matriz esparsa com os valores informados pelo usuário
void preencher_matriz(Esparsa* mat) {
	int linha, coluna, info;
	
	printf("Digite as posicoes e valores nao nulos da matriz:\n");
	printf("(para finalizar a leitura, digite uma posicao invalida)\n\n");
	
	do {
		printf("linha: ");
		scanf("%d", &linha);
		if (linha < 0 || linha > mat->linhas) break;
		printf("coluna: ");
		scanf("%d", &coluna);
		if (coluna < 0 || coluna > mat->colunas) break;
		printf("valor: ");
		scanf("%d", &info);
		printf("\n");
		if (info == 0) break;
		Lista* novo = (Lista*) malloc(sizeof(Lista));
		novo->linha = linha;
		novo->coluna = coluna;
		novo->info = info;
		novo->prox = mat->prim;
		mat->prim = novo;
	} while (1);
}

// Função para imprimir a matriz esparsa
void imprimir_matriz(Esparsa* mat) {
    Lista* p;
    int i, j;
    for (i = 1; i <= mat->linhas; i++) {
        for (j = 1; j <= mat->colunas; j++) {
            p = mat->prim;
            while (p != NULL && (p->linha != i || p->coluna != j)) {
                p = p->prox;
            }
            if (p != NULL) {
                printf("%d\t", p->info);
            } else {
                printf("0\t");
            }
        }
        printf("\n");
    }
}

// Função para consultar um elemento da matriz
int consultar_elemento(Esparsa* mat, int linha, int coluna) {
    Lista* p = mat->prim;
    while (p != NULL) {
        if (p->linha == linha && p->coluna == coluna) {
            return p->info;
        }
        p = p->prox;
    }
    return 0;
}

// Função para imprimir o somatório de uma linha da matriz
void somatorio_linha(Esparsa* mat) {
    int linha, soma = 0;
    printf("Digite a linha que deseja somar: ");
    scanf("%d", &linha);
    Lista* p = mat->prim;
    while (p != NULL) {
        if (p->linha == linha) {
            soma += p->info;
        }
        p = p->prox;
    }
    printf("\nSomatorio da linha %d: %d", linha, soma);
}

// Função para calcular o percentual de elementos não nulos na matriz
float percentual_nao_nulos(Esparsa* mat) {
	int num_nao_nulos = 0;
	Lista* p = mat->prim;
	while (p != NULL) {
		num_nao_nulos++;
		p = p->prox;
	}
	float percentual = (float) num_nao_nulos / (mat->linhas * mat->colunas) * 100;
	return percentual;
}

int main() {
	int linhas, colunas;
	printf("\nDigite o numero de linhas e colunas da matriz: ");
	scanf("%d %d", &linhas, &colunas);
	Esparsa* mat = criar_matriz(linhas, colunas);
	preencher_matriz(mat);
	printf("\nMatriz esparsa:\n");
	imprimir_matriz(mat);
	int linha, coluna;
	printf("\n\nDigite a posicao que deseja consultar: ");
	scanf("%d %d", &linha, &coluna);
	int valor = consultar_elemento(mat, linha, coluna);
	printf("Valor da posicao (%d,%d): %d", linha, coluna, valor);
	somatorio_linha(mat);
	float percentual = percentual_nao_nulos(mat);
	printf("\nPercentual de elementos nao nulos: %.2f%%\n", percentual);
	return 0;
}