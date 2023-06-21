#include <stdio.h>
#include <stdlib.h>

//3) retornar o nº de objetos da pilha

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

int objetos(Pilha* p){
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

float topo_imprime (Pilha* p){
	if (pilha_vazia(p)){
		printf("\nPilha vazia. Nao ha topo para imprimir\n");
		system("pause");
		exit(1);
	}
	/* retorna elemento do topo sem desempilhar*/
	return (p->prim->info);
}

int main(){
	Pilha* p = pilha_cria();
	int n;
	
	printf("informe os valores da pilha, digite 0 para encerrar: \n");
	do{
		scanf("%d", &n);
		if(n!=0){
			pilha_push(p, n);	
		}
	}while(n!=0);
	int quant = objetos(p);
	printf("A pilha possui %d objetos", quant);
	int topo = topo_imprime(p);
	printf("\nValor do topo: %d", topo);
}