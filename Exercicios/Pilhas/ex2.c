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

Pilha* pilha_cria (void){
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->prim = NULL;
	return p;
}

void pilha_push (Pilha* p, float v){
	Lista* n = (Lista*) malloc(sizeof(Lista));
	n->info = v;
	n->prox = p->prim;
	p->prim = n;
}

int pilha_vazia(Pilha* p){
	return (p->prim==0);
}

float pilha_pop (Pilha* p){
	Lista* t;
	float v;
	if (pilha_vazia(p)){
		printf("Pilha vazia.\n");
		exit(1); 
	} /* aborta programa */
	
	t = p->prim;
	v = t->info;
	p->prim = t->prox;
	free(t);
	return v;
}

void pilha_imprime(Pilha* p){
	Lista* q;
	
	printf("\nPilha atual: ");
	if(!pilha_vazia(p)){
		for(q=p->prim; q!=NULL; q=q->prox){
			printf("%.2f, ", q->info);
		}
	}else{
		printf("\nPilha vazia");
	}
}

void pilha_libera (Pilha* p){
	Lista* q = p->prim;
	while (q!=NULL) {
		Lista* t = q->prox;
		free(q);
		q = t;
	}
	free(p);
}

int main(){
	Pilha* p;
	p = pilha_cria();
	printf ("\nInserindo na pilha: \n");
	pilha_push (p, 4);
	pilha_push (p, 3);	
	float topo;
	pilha_pop(p);
	pilha_push (p, 8);
	pilha_pop(p);
	pilha_imprime (p);
	pilha_libera (p);
	system("PAUSE");
	return 1;
}