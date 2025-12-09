#include <string.h>
#include <stdio.h>

char *paises[24] = { "brasil", "alemanha", "austria", "coreia", "espanha", "grecia", "estados-unidos",
			"inglaterra", "australia", "portugal", "suecia", "turquia", "argentina", "chile",
			"mexico", "antardida", "canada", "irlanda", "belgica", "italia", "libia", "siria",
			"marrocos", "japao" };
char *saudacoes[24] = { "Feliz Natal!", "Frohliche Weihnachten!", "Frohe Weihnacht!", "Chuk Sung Tan!",
				"Feliz Navidad!", "Kala Christougena!", "Merry Christmas!", "Merry Christmas!",
				"Merry Christmas!", "Feliz Natal!", "God Jul!", "Mutlu Noeller", "Feliz Navidad!",
				"Feliz Navidad!", "Feliz Navidad!", "Merry Christmas!", "Merry Christmas!", "Nollaig Shona Dhuit!",
				"Zalig Kerstfeest!", "Buon Natale!", "Buon Natale!", "Milad Mubarak!", "Milad Mubarak!", "Merii Kurisumasu!" };

typedef struct tradutor{
	char pais[50];
	char saudacao[100];
}Tradutor;

int posicao;
Tradutor traducao[24];

int pesquisaPais(char *pais){
	unsigned short i;
	for (i = 0; i < 24; i++)
		if (strcmp(traducao[i].pais, pais) == 0){
			posicao = i;
			return 1;
		}
	return 0;
}

void preencheTradutor(){
	unsigned short i;
	for (i = 0; i < 24; i++){
		strcpy(traducao[i].pais, paises[i]);
		strcpy(traducao[i].saudacao, saudacoes[i]);
	}
}

int main (){
	preencheTradutor();
	char pais[100];
	while (scanf(" %s", pais) != EOF){
		if (pesquisaPais(pais))
			printf("%s\n", traducao[posicao].saudacao);
		else
			printf("--- NOT FOUND ---\n");
	}
	return 0;
}
