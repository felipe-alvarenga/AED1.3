#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    char info;
    struct no* esq;
    struct no* dir;
}Arv;
typedef Arv* PArv;
int first;

PArv insereABB (PArv a, char c) {
    if (a == NULL){
        a = (PArv)malloc(sizeof(Arv));
        a->info = c;
        a->esq = a->dir = NULL;
        return (a);
    }
    if (c < a->info)
        a->esq = insereABB (a->esq, c);
    else if (c > a->info)
        a->dir = insereABB (a->dir, c);
    return (a);
}

PArv busca(PArv a, char b) {
  if (a == NULL)
    return NULL;
  if (a->info == b)
    return a;
  if (b < a->info)
    return (busca(a->esq, b));
  else
    return (busca(a->dir, b));
}

void PREFIXA(PArv a) {
    if (a == NULL) 
        return;
    if (!first) 
        printf(" ");
    printf("%c", a->info);
    first = 0;
    PREFIXA(a->esq);
    PREFIXA(a->dir);
}

// IN-ORDEM
void INFIXA(PArv a) {
    if (a == NULL) 
        return;
    INFIXA(a->esq);
    if (!first) 
        printf(" ");
    printf("%c", a->info);
    first = 0;
    INFIXA(a->dir);
}

// POS-ORDEM
void POSFIXA(PArv a) {
    if (a == NULL) 
        return;
    POSFIXA(a->esq);
    POSFIXA(a->dir);
    if (first == 0) 
        printf(" ");
    printf("%c", a->info);
    first = 0;
}

int main() {
    PArv raiz = NULL;
    char comando[20];
    char c;

    while (scanf("%s", comando) != EOF) {
        if (comando[0] == 'I' && comando[1] == '\0') {
            scanf(" %c", &c);
            raiz = insereABB(raiz, c);
        }
        else if (comando[0] == 'P' && comando[1] == '\0') {
            scanf(" %c", &c);
            if (busca(raiz, c) != NULL)
                printf("%c existe\n", c);
            else
                printf("%c nao existe\n", c);
        }
        else if (comando[0] == 'P' && comando[1] == 'R') {
            first = 1;
            PREFIXA(raiz);
            printf("\n");
        }
        else if (comando[0] == 'I' && comando[1] == 'N') {
            first = 1;
            INFIXA(raiz);
            printf("\n");
        }
        else if (comando[0] == 'P' && comando[1] == 'O') {
            first = 1;
            POSFIXA(raiz);
            printf("\n");
        }
    }
    return 0;
}
