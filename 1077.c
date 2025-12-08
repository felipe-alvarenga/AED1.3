#include <stdlib.h>
#include <stdio.h>

typedef struct no{
	char caractere;
	struct No *proximo;
} No;
typedef No* PNo;

typedef struct pilha{
	PNo topo;
} Pilha;
typedef Pilha* PPilha;

char top(PPilha pilha){
	return (pilha->topo->caractere);
}

void pop(PPilha pilha){
	PNo auxiliar;
	auxiliar = pilha->topo;
	if (auxiliar)
	{
		pilha->topo = auxiliar->proximo;
		free(auxiliar);
	}
}

void stack(PPilha pilha){
	pilha->topo = NULL;
}

int prioridade(char c, char t){
	int pc, pt;
	if (c == '^')
		pc = 3;
	else if (c == '*' || c == '/')
		pc = 2;
	else if (c == '+' || c == '-')
		pc = 1;
	else if (c == '(')
		pc = 4;
	if (t == '^')
		pt = 3;
	else if (t == '*' || t == '/')
		pt = 2;
	else if (t == '+' || t == '-')
		pt = 1;
	else if (t == '(')
		pt = 0;
	return (pc > pt);
}

void Posfixa(char *expressao){
	int i = 0;
	char c, t;
	Pilha pilha;
	stack(&pilha);
	push(&pilha, '(');
	do{
		c = expressao[i];
		++i;
		if (c >= 'A' && c <= 'Z' || c >= '0' && c <= '9' || c >= 'a' && c <= 'z')
			printf("%c", c);
		else if (c == '(')
			push(&pilha, '(');
		else if (c == ')' || c == '\0'){
			do{
				t = top(&pilha);
				pop(&pilha);
				if (t != '(')
					printf("%c", t);
			} 
			while (t != '(');
		}
		else if (c == '+' || c == '-' || c == '*' || c == '^' || c == '/'){
			while (1){
				t = top(&pilha);
				pop(&pilha);
				if (prioridade(c, t)){
					push(&pilha, t), push(&pilha, c);
					break;
				}
				else
					printf("%c", t);
			}
		}
	} 
	while (c != '\0');
	printf("\n");
}

void push(PPilha pilha, char caractere){
	PNo auxiliar;
	auxiliar = (PNo) malloc(sizeof(No));
	if (!auxiliar)
		exit(1);
	auxiliar->proximo = pilha->topo;
	pilha->topo = auxiliar;
	auxiliar->caractere = caractere;
}

int main (){
	char expressao[400];
	unsigned short qtsCasos;
	scanf("%hu", &qtsCasos);
	while (qtsCasos--)
	{
		scanf("%s", expressao);
		Posfixa(expressao);
	}
	return 0;
}
