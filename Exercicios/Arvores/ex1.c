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

Arv* arv_libera(Arv* a) {
    if (!arv_vazia(a)) {
        arv_libera(a->esq);
        arv_libera(a->dir);
        free(a);
    }
    return NULL;
}

void arv_imprime_preOrdem(Arv* a) {
    if (!arv_vazia(a)) {
        printf("%c ", a->info);
        arv_imprime_preOrdem(a->esq);
        arv_imprime_preOrdem(a->dir);
    }
}

void arv_imprime_posOrdem(Arv* a) {
    if (!arv_vazia(a)) {
        arv_imprime_posOrdem(a->esq);
        arv_imprime_posOrdem(a->dir);
        printf("%c ", a->info);
    }
}

void arv_imprime_simetrica(Arv* a) {
    if (!arv_vazia(a)) {
        arv_imprime_simetrica(a->esq);
        printf("%c ", a->info);
        arv_imprime_simetrica(a->dir);
    }
}

int main() {
    Arv* i = arv_cria('i', arv_criavazia(), arv_criavazia());
    Arv* j = arv_cria('j', arv_criavazia(), arv_criavazia());
    Arv* g = arv_cria('g', i, arv_criavazia());
    Arv* h = arv_cria('h', j, arv_criavazia());
    Arv* e = arv_cria('e', g, arv_criavazia());
    Arv* f = arv_cria('f', arv_criavazia(), h);
    Arv* d = arv_cria('d', e, f);
    Arv* c = arv_cria('c', d, arv_criavazia());
    Arv* b = arv_cria('b', arv_criavazia(), c);
    Arv* a = arv_cria('a', arv_criavazia(), b);

    printf("Pre-ordem: ");
    arv_imprime_preOrdem(a);
    printf("\nPos-ordem: ");
    arv_imprime_posOrdem(a);
    printf("\nOrdem simetrica: ");
    arv_imprime_simetrica(a);
    
    a = arv_libera(a);

    return 0;
}