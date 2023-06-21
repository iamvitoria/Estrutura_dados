#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct lista {
	char info;
	struct lista* prox;
};
typedef struct lista Lista;

/* estrutura da pilha */
struct pilha {
	Lista* prim; /* aponta para o topo da pilha */
};
typedef struct pilha Pilha;

char pilha_pop(Pilha* p){
	Lista* t;
	char v;
	if (pilha_vazia(p)){
		printf("*** Pilha vazia.\n");
		system("pause");
		exit(1);
	} /* aborta programa */
	t = p->prim;
	v = t->info;
	p->prim = t->prox;
	free(t);
	return v;
}

bool verifica_palindromo (Pilha* p, char palavra[30]){
	bool pal=true;
	char topo;
	for (int i=0;i<strlen(palavra);i++){
		topo = pilha_pop (p);
		if (topo!=palavra[i])
			pal=false;
	}
	return pal;
}

Pilha* pilha_cria (void){
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->prim = NULL;
	return p;
}

void pilha_push (Pilha* p, char v){
	Lista* n = (Lista*) malloc(sizeof(Lista));
	n->info = v;
	n->prox = p->prim;
	p->prim = n;
}

int pilha_vazia(Pilha* p){
	return (p->prim==0);
}

void pilha_libera (Pilha* p){
	Lista* q = p->prim;
	while (q!=NULL){
		Lista* t = q->prox;
		printf ("\nLiberando %c\n", q->info);
		free(q);
		q = t;
	}
	free(p);
}

void pilha_imprime (Pilha* p){
	Lista* q;
	if (!pilha_vazia(p))
		for (q=p->prim; q!=NULL; q=q->prox)
			printf ("\n\t Lista: %c\n", q->info);
	else
		printf ("\nNao ha como imprimir a pilha, pois esta vazia\n");
}

int main(){
	Pilha* p;
	while (1){
		p = pilha_cria();
		char palavra[30];
		printf ("\nDigite uma palavra: ");
		gets (palavra);
		for (int i=0;i<strlen(palavra);i++)
			pilha_push (p, palavra[i]);
		pilha_imprime (p);
		char pal = verifica_palindromo (p, palavra);
		if (pal==true)
			printf ("\nEh palindromo\n");
		else
			printf ("\nNAO eh palindromo\n");
		pilha_libera (p);
	}
	system("PAUSE");
	return 1;
}