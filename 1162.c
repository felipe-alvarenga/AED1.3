#include <stdio.h>

int ordena(int vet[], unsigned tam){
	int i, j, cont = 0, aux;
	while (tam--){
		for (i = 0, j = 1; i < tam; i++, j++)
			if (vet[i] > vet[j]){	
				cont++;
				aux = vet[i];
				vet[i] = vet[j];
				vet[j] = aux;
			}
	}
	return cont;
}

void main (void){
	int casos, tamTrem, i;
	scanf("%u", &casos);
	while (casos--){
		scanf("%u", &tamTrem);
		int vagoes[tamTrem];
		for (i = 0; i < tamTrem; i++)
			scanf("%d", &vagoes[i]);
		printf("Optimal train swapping takes %u swaps.\n", ordena(vagoes, tamTrem));
	}
}
