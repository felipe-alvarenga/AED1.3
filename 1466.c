#include <stdlib.h>
#include <stdio.h>

typedef struct no {
    
	unsigned numero;
	struct no *direita;
	struct no *esquerda;

}No;
typedef No* PNo;

unsigned qtsNos;

void profundidade(PNo no) {
	PNo fila;
	unsigned i, f;
	_Bool flag = 0;

	fila = (PNo) malloc(qtsNos * sizeof(No));
	fila[0] = *no;
	i = 0; f = 1;

	while (f > i)
	{
		*no = fila[i++];
		if (flag == 0)
			printf("%u", no->numero), flag = 1;
		else
			printf(" %u", no->numero);
		if (no->esquerda)
			fila[f++] = *no->esquerda;
		if (no->direita)
			fila[f++] = *no->direita;

	}
	free(fila);
}

void imprime(PNo a, unsigned b){
    printf("Case %u:\n", b);
	profundidade(a);
	printf("\n\n");
    
}

PNo push(PNo no, unsigned numero) {

	if (no == 0)
	{

		no = (PNo) malloc(sizeof(No));
		no->numero = numero;
		no->esquerda = no->direita = NULL;

	}
	else if (no->numero > numero)
		no->esquerda = push(no->esquerda, numero);
	else
		no->direita = push(no->direita, numero);

	return no;

}

void main ()
{

	unsigned i, num, qtsNum;
	unsigned qtsCasos, caso;

	scanf("%u", &qtsCasos);

	caso = 0;
	while (qtsCasos--)
	{

		scanf("%u", &qtsNum);

		qtsNos = 0;
		PNo no = NULL;
		for (i = 0; i < qtsNum; ++i)
		{

			scanf("%u", &num);
			no = push(no, num);
			++qtsNos;

		}
		imprime(no, ++caso);
	}

}
