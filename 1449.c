#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct palavra{
	char japones[500];
	char portugues[500];
}palavra;

int posicao;

int busca(palavra *dicionario, char *palavra, int tam){
	short inicio, fim, meio;
	inicio = 0;
	fim = tam - 1;
	while(inicio <= fim){
		meio = (inicio + fim) / 2;
		if (strcmp(dicionario[meio].japones, palavra) < 0)
			inicio = meio + 1;
		else if(strcmp(dicionario[meio].japones, palavra) > 0)
			fim = meio-1;
		else
		{
			posicao = meio;
			return 1;
		}
	}
	return 0;
}

int compara(const void *a, const void *b){
	if (strcmp((*(struct palavra*)a).japones, (*(struct palavra*)b).japones) == 0)
		return 0;
	else if ((strcmp((*(struct palavra*)a).japones, (*(struct palavra*)b).japones) > 0))
		return 1;
	else
		return -1;
}

void main (){
	int short i, numPalavras, numLinhas, casos, espacos;
	char frase[500] = { 0 }, *palavraTmp;
	scanf("%hu", &casos);
	while (casos--){
		scanf("%u %hu", &numPalavras, &numLinhas);
		palavra dicionario[numPalavras];
		for (i = 0; i < numPalavras; i++){
			scanf(" %[^\n]", dicionario[i].japones);
			scanf(" %[^\n]", dicionario[i].portugues);
		}
		qsort(dicionario, numPalavras, sizeof(palavra), compara);
		while (numLinhas--){
			scanf(" %[^\n]", frase);
			if (!strlen(frase))
				printf("\n");
			else{
				palavraTmp = strtok(frase, " ");
				if (busca(dicionario, palavraTmp, numPalavras))
					printf("%s", dicionario[posicao].portugues);
				else
					printf("%s", palavraTmp);
				do{
					palavraTmp = strtok('\0', " ");
					if (palavraTmp)
						printf(" ");
					if (palavraTmp)
						if (busca(dicionario, palavraTmp, numPalavras))
							printf("%s", dicionario[posicao].portugues);
						else
							printf("%s", palavraTmp);
				} while (palavraTmp);
			}
			printf("\n");
			memset(frase, 0, sizeof(frase));
		}
		printf("\n");
	}
}
