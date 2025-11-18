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

int compara_desc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int decisao(PFila cab, int* a, int b){
    for (int i = 0; i < b; i++) {
        int nota;
        scanf("%d", &nota);
        push(cab, nota);
        a[i] = nota;
    }

    qsort(a, b, sizeof(int), compara_desc);
    int nao_mudaram = 0;

    for (int i = 0; i < b; i++) {
        int notaAlunoFila = pop(cab);
        if (notaAlunoFila == a[i]) {
            nao_mudaram++;
        }
    }
    return (nao_mudaram);
}

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        int M;
        scanf("%d", &M);

        PFila Fila = inicializa();
        int* Notas = (int*)malloc(M * sizeof(int));

        printf("%d\n", decisao (Fila, Notas, M));
        free(Notas);
        free(Fila);
    }
    return 0;
}
