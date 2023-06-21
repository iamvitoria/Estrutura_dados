#include <stdio.h>
#include <stdlib.h>

//4) ezvaziar a pilha

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

void pilha_imprime (Pilha* p){
	Lista* q;
	if (!pilha_vazia(p))
		for (q=p->prim; q!=NULL; q=q->prox)
			printf ("\n\t Lista: %.2f\n", q->info);
	else
		printf ("\nNao ha como imprimir a pilha, pois esta vazia\n");
}

float pilha_pop (Pilha* p){
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

int conta_objetos(Pilha* p){
	Lista* q;
	int cont = 0;
	
	if(!pilha_vazia(p)){
		for(q=p->prim; q!=NULL; q=q->prox){
			cont++;
		}
	}else{
		printf("\nPilha vazia");
	}
	return cont;
}

void esvazie (Pilha *p){
	float topo;
	while (!pilha_vazia(p)){
		/* retira elemento do topo */
		printf ("\nPilha com %d elementos. Tirando o topo: %.2f", conta_objetos(p), p->prim->info);
		topo = pilha_pop(p);
	}
	printf("\n*** Pilha vazia!!\n");
}

int main(){
	Pilha* p = pilha_cria();
	int n;
	
	printf("informe os valores da pilha. digite 0 para parar: ");
	while(n!=0){
		scanf("%d", &n);
		if(n!=0){
			pilha_push(p, n);
		}
	}
	pilha_imprime(p);
	esvazie(p);
}