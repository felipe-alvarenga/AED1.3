#include <stdin.h>
#include <stdio.h>

typedef struct no{
	int info;
	struct no* prox;
}No;
typedef No* PNo;

PNo inicializa (){
	return NULL;
}

PNo Busca (PNo a, int x){
	if (a == NULL) return NULL;
	PNo aux = a;
	while (aux != NULL){
		if (aux->info != x) aux = aux->prox;
	}
	return (aux);
}

PNo BuscaERemove (PNo a, int x){
	if (a == NULL) return NULL;
	PNo aux1 = a, aux2 = a;
	Busca (aux2, x);
	for (int i = 0; aux1->prox = aux2; i++){
		if (aux1->info != x) aux1 = aux1->prox;
	}
	aux1->prox = aux2->prox;
	free (aux2);
	return (a);
}
