#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int info;
    struct no *prox;
} No;
typedef No* PNo;

typedef struct fila {
    PNo head;
    PNo tail;
} Fila;
typedef Fila* PFila;

PFila inicializa() {
    PFila f = (PFila) malloc(sizeof(Fila));
    f->head = f->tail = NULL;
    return f;
}

void empilha(PFila f, int x) {
    PNo novo = (PNo) malloc(sizeof(No));
    novo->info = x;
    novo->prox = NULL;
    if (f->tail == NULL) {
        f->head = f->tail = novo;
    } else {
        f->tail->prox = novo;
        f->tail = novo;
    }
}

int desempilha(PFila f) {
    if (f->head == NULL) return -1;
    PNo tmp = f->head;
    int v = tmp->info;
    f->head = tmp->prox;
    if (f->head == NULL) f->tail = NULL;
    free(tmp);
    return v;
}

int tamanho(PFila f) {
    int c = 0;
    PNo p = f->head;
    while (p) { c++; p = p->prox; }
    return c;
}

void libera(PFila f) {
    PNo p = f->head;
    while (p) {
        PNo t = p;
        p = p->prox;
        free(t);
    }
    free(f);
}

void virgula(int a){
    if (a != 0) 
        printf("\n"); 
    else 
        printf("\n");
}

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        PFila f = inicializa();
        for (int i = 1; i <= n; i++) empilha(f, i);

        printf("Discarded cards:");
        int first = 1;

        while (tamanho(f) > 1) {
            int d = desempilha(f); /* descarta */
            if (first) { printf(" %d", d); first = 0; }
            else printf(", %d", d);

            int mover = desempilha(f); 
            empilha(f, mover);
        }

        virgula (first);
        int last = desempilha(f);
        printf("Remaining card: %d\n", last);

        libera(f);
    }
    return 0;
}
