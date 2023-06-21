#include <stdio.h>
#include <stdlib.h>

struct arv {
    char info;
    struct arv* esq;
    struct arv* dir;
};
typedef struct arv Arv;

Arv* arv_criavazia(void) {
    return NULL;
}

Arv* arv_cria(char c, Arv* sae, Arv* sad) {
    Arv* p = (Arv*)malloc(sizeof(Arv));
    p->info = c;
    p->esq = sae;
    p->dir = sad;
    return p;
}

int arv_vazia(Arv* a) {
    return a == NULL;
}

Arv* criarArvore() {
    char c;
    scanf(" %c", &c); // Lê um caractere fornecido pelo usuário
    
    if (c == '.') { // Se o caractere for '.', retorna uma árvore vazia
        return arv_criavazia();
    }
    
    // Cria os ramos esquerdo e direito da árvore recursivamente
    Arv* esq = criarArvore();
    Arv* dir = criarArvore();
    
    // Cria e retorna a árvore com o caractere fornecido e os ramos esquerdo e direito
    return arv_cria(c, esq, dir);
}

int calculaPares(Arv* a){
	int cont = 0;
	if(arv_vazia(a)){
		return 0;
	}
	if(a->info%2==0){
		cont = 1;
	}
	return cont+calculaPares(a->esq)+calculaPares(a->dir);
}

void arv_imprime_preOrdem(Arv* a) {
    if (!arv_vazia(a)) {
        printf("%c ", a->info);
        arv_imprime_preOrdem(a->esq);
        arv_imprime_preOrdem(a->dir);
    }
}

Arv* arv_libera(Arv* a) {
    if (!arv_vazia(a)) {
        arv_libera(a->esq);
        arv_libera(a->dir);
        free(a);
    }
    return NULL;
}

int main() {
    printf("Digite os valores da arvore (use '.' para representar um no vazio):\n");
    Arv* arvore = criarArvore();

    printf("Pre-ordem: ");
    arv_imprime_preOrdem(arvore);
    
    arvore = arv_libera(arvore);

    return 0;
}