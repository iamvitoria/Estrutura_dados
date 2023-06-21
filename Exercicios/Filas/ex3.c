#include <stdio.h>
#include <stdlib.h>

/* nó da lista para armazenar valores reais */
struct lista {
	float info;
	struct lista* prox;
};
typedef struct lista Lista;

/* estrutura da fila */
struct fila {
	Lista* ini;
	Lista* fim;
};
typedef struct fila Fila;

Fila* fila_cria(void) {
	Fila* f = (Fila*)malloc(sizeof(Fila));
	f->ini = f->fim = NULL;
	return f;
}

void fila_insere(Fila* f, float v) {
	Lista* n = (Lista*)malloc(sizeof(Lista));
	n->info = v; /* armazena informação */
	n->prox = NULL; /* novo nó passa a ser o último */
	if (f->fim != NULL) /* verifica se lista não estava vazia */
		f->fim->prox = n;
	else /* fila estava vazia */
		f->ini = n;
	f->fim = n; /* fila aponta para novo elemento */
}

float fila_retira(Fila* f) {
	float v;
	if (fila_vazia(f)) {
		printf("\n\n*** Fila vazia.\n");
		exit(1); /* aborta programa */
	}
	/* retira elemento do início */
	Lista* t = f->ini;
	v = t->info;
	f->ini = f->ini->prox;
	free(t);
	return v;
}

int fila_vazia(Fila* f) {
	return (f->ini == NULL);
}

void fila_imprime(Fila* f) {
	Lista* q;
	printf("\nFila: ");
	for (q = f->ini; q != NULL; q = q->prox) {
		printf("%.2f ", q->info);
	}
	printf("\n");
}

Fila* ORDENAR(Fila* fila1, Fila* fila2) {
	Fila* res = fila_cria();
	while (!fila_vazia(fila1) && !fila_vazia(fila2)) {
		float frente1 = fila1->ini->info;
		float frente2 = fila2->ini->info;
		if (frente1 < frente2)
			fila_insere(res, fila_retira(fila1));
		else
			fila_insere(res, fila_retira(fila2));
	}
	
	while (!fila_vazia(fila1)) {
		fila_insere(res, fila_retira(fila1));
	}
	
	while (!fila_vazia(fila2)) {
		fila_insere(res, fila_retira(fila2));
	}
	
	return res;
}

int main() {
	Fila* f_res = fila_cria();
	Fila* f1 = fila_cria();
	Fila* f2 = fila_cria();
	float n = 9999, t = 9999;

	printf("Informe os valores da primeira fila (0 para parar): ");
	while (n != 0) {
		scanf("%f", &n);
		if (n != 0) {
			fila_insere(f1, n);
		}
	}

	printf("Informe os valores da segunda fila (0 para parar): ");
	while (t != 0) {
		scanf("%f", &t);
		if (t != 0) {
			fila_insere(f2, t);
		}
	}

	Fila* resultado = ORDENAR(f1, f2);
	fila_imprime(resultado);

	free(f_res);
	free(f1);
	free(f2);
	free(resultado);

	return 0;
}