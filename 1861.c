#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct tipoDado{
	char nome[20];
	unsigned qtsMortes;
} Assassinos;

typedef struct ArvHall{
	Assassinos dado;
	struct ArvHall *esquerdo;
	struct ArvHall *direito;
}Hall;
typedef Hall* PHall;

typedef struct ArvMortos{
	char morto[20];
	struct ArvMortos *esquerdo;
	struct ArvMortos *direito;
}Mortos;
typedef Mortos* PMortos;

PHall insereAssassinos(PHall hall, Assassinos assassino){
	if (hall == 0){
		hall = (PHall) malloc(sizeof(Hall));
		hall->dado = assassino;
		hall->dado.qtsMortes++;
		hall->esquerdo = hall->direito = NULL;
	}
	else if (strcmp(hall->dado.nome, assassino.nome) > 0)
		hall->esquerdo = insereAssassinos(hall->esquerdo, assassino);
	else if (strcmp(hall->dado.nome, assassino.nome) < 0)
		hall->direito = insereAssassinos(hall->direito, assassino);
	else
		hall->dado.qtsMortes++;
	return hall;
}

PMortos insereMortos(PMortos mortos, char *morto){
	if (mortos == 0){
		mortos = (PMortos) malloc(sizeof(Mortos));
		strcpy(mortos->morto, morto);
		mortos->esquerdo = mortos->direito = NULL;
	}
	else if (strcmp(mortos->morto, morto) > 0)
		mortos->esquerdo = insereMortos(mortos->esquerdo, morto);
	else
		mortos->direito = insereMortos(mortos->direito, morto);
	return mortos;
}

int busca(PMortos mortos, char *chave){
	int direita, esquerda;
	if (mortos == 0)
		return 0;
	if (strcmp(mortos->morto, chave) == 0)
		return 1;
	if (strcmp(mortos->morto, chave) > 0)
		esquerda = busca(mortos->esquerdo, chave);
	else
		direita = busca(mortos->direito, chave);
}

void show(PHall hall, PMortos mortos){
	if (hall != NULL){
		show(hall->esquerdo, mortos);
		if (busca(mortos, hall->dado.nome) == 0)
			printf("%s %u\n", hall->dado.nome, hall->dado.qtsMortes);
		show(hall->direito, mortos);
	}
}

int main (){
	char matou[20], morreu[20];
	PHall hall = NULL;
	PMortos mortos = NULL;
	while (scanf(" %s %s", matou, morreu) != EOF){
		Assassinos assassino = { 0 };
		strcpy(assassino.nome, matou);
		hall = insereAssassinos(hall, assassino);
		mortos = insereMortos(mortos, morreu);
	}
	printf("HALL OF MURDERERS\n");
	show(hall, mortos);
	return 0;
}
