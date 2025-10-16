#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

typedef struct no{
     char simb;
     struct no* prox;
}No;
typedef No* PNo;

PNo inicializa (){
    return NULL;
}

PNo empilha (PNo top, char a){
    PNo novo = (PNo)malloc(sizeof(No));
    novo -> simb = a;
    novo -> prox = top;
    top = novo;
    return (top);
}

PNo desempilha (PNo top){
    if (top == NULL){
        return NULL;
    }
    PNo aux = top;
    top = top->prox;
    free (aux);
    return (top);
}

 int preencher (char s[]){
    int i, n = strlen(s);
    int cont = 0;
    PNo pilha = inicializa();
    for (i = 0; i < n; i++){
        if (s[i] == '<'){
            pilha = empilha (pilha, '<');
        } else if (s[i] == '>'){
            if (pilha != NULL){
                pilha = desempilha (pilha);
                cont ++;
            }
        }
    }
    while (pilha != NULL){
        pilha = desempilha(pilha);
    }
    return (cont);
}
 
int main() {
    int N, i;
    scanf("%d", &N);
    getchar();
    char dima[MAX];
    getchar();
    for (i = 0; i < N; i++){
        fgets(dima, sizeof(dima), stdin);
        int tamanho = strlen(dima);
        if (tamanho > 0 && dima[tamanho-1] == '\n'){
            dima[tamanho-1] = '\0';
        }
        printf ("%d\n", preencher(dima));
    }
    
    return 0;
}
