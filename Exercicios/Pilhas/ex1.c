#include <stdio.h>
#include <stdlib.h>

//1) imprimir os valores armazenados em uma pilha

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

void imprime_pilha(Pilha* p){
	Lista *l;
	if(pilha_vazia(p)){
		for(l=p->prim; l!=NULL; l=l->prox){
			printf("%.2f", l->info);
		}
	}else{
		printf("\npilha vazia");
	}
	
}

int main(){
	Pilha* p = pilha_cria();
	int n;
	
	printf("Informe os elementos da pilha. Digite 0 para parar: \n");
	while(n!=0){
		scanf("%d", &n);
		pilha_push(p, n);
	};
	
	imprime_pilha(p);
	return 0;
}