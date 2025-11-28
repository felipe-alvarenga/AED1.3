#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int info;
    struct no* prox;
} No;
typedef No* PNo;

PNo inicializa() {
    return NULL;
}

PNo push(PNo topo, int v) {
    PNo novo = (PNo) malloc(sizeof(No));
    novo->info = v;
    novo->prox = topo;
    return novo;
}

PNo pop(PNo topo) {
    if (topo == NULL) return NULL;
    PNo velho = topo;
    topo = topo->prox;
    free(velho);
    return topo;
}

int topo(PNo topo) {
    return topo->info;
}

int vazia(PNo topo) {
    return topo == NULL;
}

PNo apaga(PNo topo) {
    while (topo != NULL) {
        topo = pop(topo);
    }
    return NULL;
}

void imprime(int a){
    if (a) 
        printf("Yes\n");
    else 
        printf("No\n");
}

int main() {
    int N;

    while (scanf("%d", &N) && N != 0) {
        while (1) {
            int primeiro;
            scanf("%d", &primeiro);

            if (primeiro == 0) {
                printf("\n");
                break;
            }

            int target[N];
            target[0] = primeiro;

            for (int i = 1; i < N; i++)
                scanf("%d", &target[i]);

            PNo pilha = inicializa();
            int proximo = 1;
            int act = 1;

            for (int i = 0; i < N; i++) {
                int j = target[i];

                while ((vazia(pilha) || topo(pilha) != j) && proximo <= N) {
                    pilha = push(pilha, proximo);
                    proximo++;
                }
                if (!vazia(pilha) && topo(pilha) == j) {
                    pilha = pop(pilha);
                } else {
                    act = 0;
                    break;
                }
            }
            imprime (act);
            pilha = apaga(pilha);
        }
    }
    return 0;
}
