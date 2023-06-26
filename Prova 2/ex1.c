#include <stdio.h>
#include <stdlib.h>

struct lista {
    int matricula;
    float nota;
    struct lista* prox;
};
typedef struct lista Lista;

struct pilha {
    Lista* prim; /* aponta para o topo da pilha */
};
typedef struct pilha Pilha;

struct fila {
    Lista* ini; /* aponta para o inicio da fila */
    Lista* fim; /* aponta para o fim da fila */
};
typedef struct fila Fila;

void separaAlunos(Fila* f, Pilha* aprovados, Fila* reprovados) {
    Lista* aluno = f->ini;

    while (aluno != NULL) {
        if (aluno->nota >= 7) {
            // Aluno aprovado, insere na pilha de aprovados
            Lista* novoAprovado = (Lista*)malloc(sizeof(Lista));
            novoAprovado->matricula = aluno->matricula;
            novoAprovado->nota = aluno->nota;
            novoAprovado->prox = aprovados->prim;
            aprovados->prim = novoAprovado;
        } else {
            // Aluno reprovado, insere na fila de reprovados
            Lista* novoReprovado = (Lista*)malloc(sizeof(Lista));
            novoReprovado->matricula = aluno->matricula;
            novoReprovado->nota = aluno->nota;
            novoReprovado->prox = NULL;

            if (reprovados->ini == NULL) {
                reprovados->ini = novoReprovado;
                reprovados->fim = novoReprovado;
            } else {
                reprovados->fim->prox = novoReprovado;
                reprovados->fim = novoReprovado;
            }
        }

        Lista* proximoAluno = aluno->prox;
        free(aluno);
        aluno = proximoAluno;
    }

    f->ini = NULL;
    f->fim = NULL;
}

int main() {
    Fila alunos;
    alunos.ini = NULL;
    alunos.fim = NULL;

    Pilha aprovados;
    aprovados.prim = NULL;

    Fila reprovados;
    reprovados.ini = NULL;
    reprovados.fim = NULL;

    int matricula;
    float nota;
    char choice;

    do {
        printf("Digite a matricula do aluno: ");
        scanf("%d", &matricula);

        printf("Digite a nota do aluno: ");
        scanf("%f", &nota);

        // Insere o aluno na fila
        Lista* novoAluno = (Lista*)malloc(sizeof(Lista));
        novoAluno->matricula = matricula;
        novoAluno->nota = nota;
        novoAluno->prox = NULL;

        if (alunos.ini == NULL) {
            alunos.ini = novoAluno;
            alunos.fim = novoAluno;
        } else {
            alunos.fim->prox = novoAluno;
            alunos.fim = novoAluno;
        }

        printf("Deseja inserir mais alunos? (s/n): ");
        scanf(" %c", &choice);
    } while (choice == 's' || choice == 'S');

    separaAlunos(&alunos, &aprovados, &reprovados);

    printf("\nAlunos Aprovados:\n");
    Lista* alunoAprovado = aprovados.prim;
    while (alunoAprovado != NULL) {
        printf("Matricula: %d | Nota: %.2f\n", alunoAprovado->matricula, alunoAprovado->nota);
        alunoAprovado = alunoAprovado->prox;
    }

    printf("\nAlunos Reprovados:\n");
    Lista* alunoReprovado = reprovados.ini;
    while (alunoReprovado != NULL) {
        printf("Matricula: %d | Nota: %.2f\n", alunoReprovado->matricula, alunoReprovado->nota);
        alunoReprovado = alunoReprovado->prox;
    }

    // Libera a memória alocada para os alunos aprovados
    alunoAprovado = aprovados.prim;
    while (alunoAprovado != NULL) {
        Lista* proximoAluno = alunoAprovado->prox;
        free(alunoAprovado);
        alunoAprovado = proximoAluno;
    }

    // Libera a memória alocada para os alunos reprovados
    alunoReprovado = reprovados.ini;
    while (alunoReprovado != NULL) {
        Lista* proximoAluno = alunoReprovado->prox;
        free(alunoReprovado);
        alunoReprovado = proximoAluno;
    }

    return 0;
}
