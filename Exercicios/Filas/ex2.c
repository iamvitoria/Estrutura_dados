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

void fila_imprime(Fila* f) {
	Lista* q;
	printf("\nFila: ");
	for (q = f->ini; q != NULL; q = q->prox) {
		printf("%.2f\n", q->info);
	}
}

int fila_vazia(Fila* f) {
	return (f->ini == NULL);
}

float fila_retira(Fila* f) {
	float v;
	if (fila_vazia(f)) {
		printf("\n\n*** Fila vazia.\n");
		system("pause");
		exit(1); /* aborta programa */
	}
	/* retira elemento do início */
	Lista* t = f->ini;
	v = t->info;
	f->ini = f->ini->prox;
	free(t);
	return v;
}

void combina_filas(Fila* f_res, Fila* f1, Fila* f2) {
	while (!fila_vazia(f1) && !fila_vazia(f2)) {
		float elemento = fila_retira(f1);
		fila_insere(f_res, elemento);
		elemento = fila_retira(f2);
		fila_insere(f_res, elemento);
	}
	
	while (!fila_vazia(f1)) {
		float elemento = fila_retira(f1);
		fila_insere(f_res, elemento);
	}
	
	while (!fila_vazia(f2)) {
		float elemento = fila_retira(f2);
		fila_insere(f_res, elemento);
	}
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

	combina_filas(f_res, f1, f2);
	fila_imprime(f_res);

	free(f_res);
	free(f1);
	free(f2);

	return 0;
}