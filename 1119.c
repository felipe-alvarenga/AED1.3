#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    int id;
    struct no *ant;
    struct no *prox;
} No;
typedef No* PNo;

PNo preenche(int size){
    PNo no;
    PNo no_ant;
    PNo start = NULL;
    for (int i = 1; i <= size; ++i){
        no = (PNo)malloc(sizeof(No));
        no->id = i;
        if (start == NULL)
            start = no;
        else{
            no_ant->prox = no;
            no->ant = no_ant;
        }
        no_ant = no;
    }
    start->ant = no;
    no->prox = start;
    return start;
}

PNo deletar (PNo list, PNo reg){
    PNo no_ant = reg->ant;
    PNo no_prox = reg->prox;
    if (reg == list){
        list = list->prox;
        no_ant->prox = list;
        list->ant = reg->ant;
    }
    else{
        no_ant->prox = no_prox;
        no_prox->ant = no_ant;
    }
    free(reg);
    return list;
}

int cont(PNo list){
    int i;
    PNo no = list;
    for (i = 1; list != no->prox; ++i)
        no = no->prox;
    return i;
}

PNo percorre(PNo list, int n, int direction){
    PNo no = list;
    if (direction == 0)
        while (--n)
            no = no->prox;
    else
        while (--n)
            no = no->ant;
    return no;
}

int main(int argc, char **argv){
    int n, k, m, i;
    PNo list, K, M, auxK, auxM;
    while (scanf("%d %d %d", &n, &k, &m), n){
        list = preenche(n);
        K = list;
        M = list->ant;
        while (cont(list) > 2){
            K = percorre(K, k, 0x0);
            M = percorre(M, m, 0x1);
            if (K->prox == M)
                auxK = M->prox;
            else
                auxK = K->prox;
            if (M->ant == K)
                auxM = K->ant;
            else
                auxM = M->ant;
            if (K == M){
                printf("%3d,", M->id);
                list = deletar (list, K);
            }
            else{
                printf("%3d%3d,", K->id, M->id);
                list = deletar (list, M);
                list = deletar (list, K);
            }
            K = auxK;
            M = auxM;
        }
        if (cont(list) == 2){
            K = percorre(K, k, 0x0);
            M = percorre(M, m, 0x1);
            if (K == M)
                printf("%3d,%3d\n", K->id, K->prox->id);
            else
                printf("%3d%3d\n", K->id, K->prox->id);
        }
        else
            printf("%3d\n", list->id);
    }
    return 0;
}
