#include <stdin.h>
#include <stdio.h>

typedef struct no{
	int info;
	struct no* prox;
}No;
typedef No* PNo;

PNo incializaCabeça (){
	PNo cab = (PNo)malloc(sizeof(No));
	cab->prox = cab;
	return (cab);
}

PNo insere (PNo cab, int a){
	PNo novo = (PNo)malloc(sizeof(No));
	novo->info = a;
	novo->prox = cab->prox;
	cab->prox = novo;
	return (cab);
}

PNo remove (PNo cab){
	PNo aux = cab;
	do{
		aux = aux->prox;
	}while(aux->prox->prox != cab);
	free (aux->prox)
	aux->prox = cab;
	return (cab);
}
















