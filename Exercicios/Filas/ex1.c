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

Fila* fila_cria (void){
	Fila* f = (Fila*) malloc(sizeof(Fila));
	f->ini = f->fim = NULL;
	return f;
}

void fila_insere (Fila* f, float v){
	Lista* n = (Lista*) malloc(sizeof(Lista));
	n->info = v; /* armazena informação */
	n->prox = NULL; /* novo nó passa a ser o último */
	if (f->fim != NULL) /* verifica se lista não estava vazia */
		f->fim->prox = n;
	else /* fila estava vazia */
		f->ini = n;
	f->fim = n; /* fila aponta para novo elemento */
}

void fila_imprime(Fila* f){
	Lista* q;
	printf("\nFila: ");
	for(q = f->ini; q!=NULL; q = q->prox){
		printf("%.2f\n", q->info);
	}
}

int main(){
	Fila* f = fila_cria();
	int n;
	
	printf("informe os valores da fila. 0 para parar: ");
	while(n!=0){
		scanf("%d", &n);
		if(n!=0){
			fila_insere(f, n);
		}
	}
	fila_imprime(f);
}