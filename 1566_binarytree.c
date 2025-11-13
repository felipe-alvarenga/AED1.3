#include <stdio.h>
#include <stdlib.h> 

static int read_int(void) {
    int c = getchar_unlocked();
    while (c != EOF && (c < '0' || c > '9')) c = getchar_unlocked();
    if (c == EOF) return -1;
    
    int x = 0;
    while (c >= '0' && c <= '9') {
        x = x * 10 + (c - '0');
        c = getchar_unlocked();
    }
    return x;
}

typedef struct no {
    int info;
    struct no* esq;
    struct no* dir;
}No;
typedef No* PNo;

PNo insere (PNo raiz, int a) {
    if (raiz == NULL){
        raiz = (PNo)malloc(sizeof(No));
        raiz->info = a;
        raiz->dir = raiz->esq = NULL;
        return (raiz);
    }
    if (a < raiz->info)
        raiz->esq = insere (raiz->esq, a);
    if (a > raiz->info || a == raiz->info)
        raiz->dir = insere (raiz->dir, a);
    return (raiz);
}

void em_ordem (PNo raiz) {
    if (raiz == NULL)
        return;
    em_ordem (raiz->esq);
    printf ("%d ", raiz->info);
    em_ordem (raiz->dir);
}

void libera_arvore(PNo raiz) {
    if (raiz == NULL)
        return;
    libera_arvore(raiz->esq);
    libera_arvore(raiz->dir);
    free(raiz);
}

int main(void) {
    int NC = read_int();
    if (NC < 0) return 0;

    for (int case_i = 0; case_i < NC; ++case_i) {
        int N = read_int();
        
        PNo raiz = NULL; 

        if (N <= 0) {
            putchar_unlocked('\n');
            continue;
        }
        
        for (int i = 0; i < N; ++i) {
            raiz = insere(raiz, read_int());
        }

        em_ordem(raiz);
        putchar_unlocked('\n'); 

        libera_arvore(raiz);
    }

    return 0;
}
