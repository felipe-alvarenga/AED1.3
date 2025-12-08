#include <string.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct{
	char nome[200];
	int presenca;
	int ausencia;
	int atestado;
	float taxa;
}classe;

int main (){
	int qtsAlunos, casos, qtsTotalFrequencia, i, aux, j;
	char registro[5000];
	scanf("%hu", &casos);
	while (casos--){
		scanf("%hu", &qtsAlunos);
		classe alunos[qtsAlunos];
		memset(alunos, 0, sizeof(alunos));
		for (i = 0; i < qtsAlunos; i++)
			scanf(" %s", alunos[i].nome);
		aux = qtsAlunos;
		i = 0;
		bool primSpaco = false;
		while (aux--){
			scanf(" %s", registro);
			for (j = 0; registro[j]; j++){
				if (registro[j] == 'P')
					alunos[i].presenca++;
				else if (registro[j] == 'A')
					alunos[i].ausencia++;
				else if (registro[j] == 'M')
					alunos[i].atestado++;
			}
			memset(registro, 0, sizeof(registro));
			alunos[i].taxa = (1.0f * alunos[i].presenca) / (alunos[i].presenca + alunos[i].ausencia);
			if (alunos[i].taxa < 0.75f){
				if (primSpaco)
					printf(" ");
				printf("%s", alunos[i].nome);
				primSpaco = true;
			}
			i++;
		}
		printf("\n");
	}
	return 0;
}
