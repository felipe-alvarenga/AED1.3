#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int info;
    struct no* prox;
} No;
typedef No* PNo;

typedef struct fila {
    PNo inicio;
    PNo fim;
} Fila;
typedef Fila* PFila;

PFila inicializa() {
    PFila cab = (PFila)malloc(sizeof(Fila));
    cab->inicio = NULL;
    cab->fim = NULL;
    return (cab);
}

void push(PFila cab, int valor) {
    PNo novo = (PNo)malloc(sizeof(No));
    novo->info = valor;
    novo->prox = NULL;
    if (cab->inicio == NULL) 
        cab->inicio = novo;
    else 
        cab->fim->prox = novo;
    cab->fim = novo;
}

int pop(PFila cab) {
    if (cab->inicio == NULL) 
        return -1;
    PNo aux = cab->inicio;
    int valor = aux->info;
    cab->inicio = aux->prox;
    if (cab->inicio == NULL) 
        cab->fim = NULL;
    free(aux);
    return valor;
}

void solucao(PFila f) {
    int M;
    scanf("%d", &M);

    int* saiu = (int*)calloc(100001, sizeof(int));

    for (int i = 0; i < M; i++) {
        int valor_saiu;
        scanf("%d", &valor_saiu);
        saiu[valor_saiu] = 1;
    }

    int primeiro = 1;
    
    while (f->inicio != NULL) {
        int valor_atual = pop(f);
        
        if (saiu[valor_atual] == 0) {
            if (!primeiro) printf(" ");
            printf("%d", valor_atual);
            primeiro = 0;
        }
    }
    printf("\n");

    free(saiu);
    free(f);
}

int main() {
    int N;
    scanf("%d", &N);

    PFila fila = inicializa();

    for (int i = 0; i < N; i++) {
        int valor;
        scanf("%d", &valor);
        push(fila, valor);
    }
    solucao(fila);
    return 0;
}
