#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct no {
    char info;
    struct no* prox;
} No;
typedef No* PNo;

typedef struct pilha {
    int tam;
    PNo topo;
} Pilha;
typedef Pilha* PPilha;

PPilha inicializa(PPilha p){
    p->tam = 0;
    p->topo = NULL;
    return NULL;
}

PPilha empilha(PPilha p, char c){
    PNo novo = (PNo) malloc(sizeof(No));
    novo->info = c;
    novo->prox = p->topo;

    p->topo = novo;
    p->tam++;

    return p->topo;
}

PPilha desempilha(PPilha p){
    if(p->tam == 0) return NULL;

    PNo velho = p->topo;
    p->topo = velho->prox;
    p->tam--;

    free(velho);
    return p->topo;
}

char topo(PPilha p){
    return p->topo->info;
}

int tamanho(PPilha p){
    return p->tam;
}

int vazia(PPilha p){
    return p->tam == 0;
}

PPilha apaga(PPilha p){
    while(!vazia(p)){
        desempilha(p);
    }
    return NULL;
}

void imprime (int a, int b, Pilha c){
    if(a == b && vazia(&c))
        printf("correct\n");
    else
        printf("incorrect\n");
}

int main(){
    int i, tam;
    Pilha p;
    char expressao[1001];

    while(scanf("%s\n", expressao) != EOF){
        inicializa(&p);
        tam = strlen(expressao);
        for(i = 0; i < tam; ++i){
            if(expressao[i] == '('){
                empilha(&p, '(');
            } else if(expressao[i] == ')'){
                if(vazia(&p)) break;
                else desempilha(&p);
            }
        }
        imprime(i, tam, p);
    }
    return 0;
}
