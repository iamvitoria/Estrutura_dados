#include <stdio.h>
#include <stdlib.h>

struct lista {
	int matricula;
	float nota;
	struct lista* prox;
};
typedef struct lista Lista;

struct pilha{
	Lista* prim; /* aponta para o topo da pilha */
};
typedef struct pilha Pilha;

struct fila{
	Lista* ini; /* aponta para o inicio da fila */
	Lista* fim; /* aponta para o fim da fila */
};
typedef struct fila Fila;

//inserir os alunos aprovados na pilha e os reprovados na fila
void separaAlunos(Fila *f, Pilha *aprovados, Fila *reprovados){
	Lista* aluno = f->ini;
	
	while(aluno != NULL){
		Lista* novo = (Lista*)malloc(sizeof(Lista));
		novo->matricula = aluno->matricula;
		novo->nota = aluno->nota;
		novo->prox = NULL;
		
		if(aluno->nota >= 7){
			if(aprovados->prim == NULL){
				aprovados->prim = novo;
			}else{
				novo->prox = aprovados->prim;
				aprovados->prim = novo;
			}
		}else{
			if(reprovados->ini == NULL){
				reprovados->ini = novo;
				reprovados->fim = novo;
			}else{
				reprovados->fim->prox = novo;
				reprovados->fim = novo;
			}
		}
		
		aluno = aluno->prox;
	}		
}