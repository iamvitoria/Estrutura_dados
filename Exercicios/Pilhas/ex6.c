#include <stdio.h>
#include <stdlib.h>

/* nó da lista para armazenar valores reais */
struct lista {
	float info;
	struct lista* prox;
};
typedef struct lista Lista;

/* estrutura da pilha */
struct pilha {
	Lista* prim; /* aponta para o topo da pilha */
};
typedef struct pilha Pilha;

Pilha* pilha_cria(void) {
	Pilha* p = (Pilha*)malloc(sizeof(Pilha));
	p->prim = NULL;
	return p;
}

void pilha_push(Pilha* p, float v) {
	Lista* n = (Lista*)malloc(sizeof(Lista));
	n->info = v;
	n->prox = p->prim;
	p->prim = n;
}

int pilha_vazia(Pilha* p) {
	return (p->prim == NULL);
}

void pilha_imprime(Pilha* p) {
	Lista* q;
	if (!pilha_vazia(p))
		for (q = p->prim; q != NULL; q = q->prox)
			printf("%.2f\n", q->info);
	else
		printf("Nao ha como imprimir a pilha, pois esta vazia\n");
}

float pilha_pop(Pilha* p) {
	Lista* t;
	float v;
	if (pilha_vazia(p)) {
		printf("Pilha vazia.\n");
		exit(1);
	} /* aborta programa */
	t = p->prim;
	v = t->info;
	p->prim = t->prox;
	free(t);
	return v;
}

void concatena_pilhas(Pilha* p1, Pilha* p2) {
	Pilha* p3 = pilha_cria();
	while (!pilha_vazia(p2))
		pilha_push(p3, pilha_pop(p2));
	printf("Pilha 3: ");
	pilha_imprime(p3);
	
	while (!pilha_vazia(p3))
		pilha_push(p1, pilha_pop(p3));
}

int main() {
	Pilha* p1 = pilha_cria();
	Pilha* p2 = pilha_cria();
	float n = 9999, t = 9999;

	printf("Informe o valor da primeira pilha (0 para parar): ");
	while (n != 0) {
		scanf("%f", &n);
		if (n != 0) {
			pilha_push(p1, n);
		}
	}

	printf("Informe o valor da segunda pilha (0 para parar): ");
	while (t != 0) {
		scanf("%f", &t);
		if (t != 0) {
			pilha_push(p2, t);
		}
	}

	concatena_pilhas(p1, p2);
	printf("Pilha 1 apos a concatenacao: ");
	pilha_imprime(p1);

	free(p1);
	free(p2);

	return 0;
}