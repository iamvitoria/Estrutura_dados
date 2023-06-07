#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node {
    int row;
    int col;
    Node* next;
};

typedef struct {
    int n;
    int* data;
} Matrix;

//Criação da matriz
Matrix create_matrix(int n) {
    Matrix m;
    m.n = n;
    m.data = (int*) calloc(n * n, sizeof(int));
    return m;
}

//liberação de espaço
void free_matrix(Matrix* m) {
    free(m->data);
    m->data = NULL;
}

//mostra de elementos
void set_value(Matrix* m, int row, int col, int value) {
    m->data[row * m->n + col] = value;
}

//preenchimento da matriz
int get_value(Matrix* m, int row, int col) {
    return m->data[row * m->n + col];
}

//impressão da matriz
void print_matrix(Matrix* m) {
    printf("\nMatriz:\n");
    for (int i = 0; i < m->n; i++) {
        for (int j = 0; j < m->n; j++) {
            printf("%d ", get_value(m, i, j));
        }
        printf("\n");
    }
}

Node* create_node(int row, int col) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->next = NULL;
    return node;
}

void insert_node(Node** head, int row, int col) {
    Node* node = create_node(row, col);
    node->next = *head;
    *head = node;
}

void free_list(Node** head) {
    while (*head != NULL) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

Node* find_violations(Matrix* m) {
    Node* violations = NULL;
    for (int i = 0; i < m->n; i++) {
        for (int j = 0; j < m->n; j++) {
            int value = get_value(m, i, j);
            if (i == j && value != 1) {//se a linha e a coluna forem iguais e diferentes de 1
                insert_node(&violations, i, j);
            } else if (i != j && value != 0) {//se a linha e coluna forem diferentes e diferentes de 0
                insert_node(&violations, i, j);
            }
        }
    }
    return violations;
}

int main() {
    int n;
    printf("Informe a ordem da matriz: ");
    scanf("%d", &n);

    Matrix m = create_matrix(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int value;
            printf("\nDigite o valor para a posicao [%d][%d]: ", i+1, j+1);
            scanf("%d", &value);
            set_value(&m, i, j, value);
        }
    }

    print_matrix(&m);

    Node* violations = find_violations(&m);
    if (violations == NULL) {
        printf("\nEh uma matriz identidade\n");
    } else {
        printf("Nao eh uma matriz identidade\n");
        printf("\nViolacoes:\n");
        Node* temp = violations;
        while (temp != NULL) {
        	printf("Elemento %d na linha %d e coluna %d\n", get_value(&m, temp->row, temp->col), temp->row+1, temp->col+1);
        temp = temp->next;
	    }
	    free_list(&violations);
	}
	free_matrix(&m);

	return 0;
}