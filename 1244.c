#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

typedef struct{
	char texto[3000];
}string;

void ordena(string *palavras, unsigned tam){
	short i = 1, j;
	string pivo;
	while (i < tam){
		j = i - 1;
		pivo = palavras[i];
		while (j >= 0 && strlen(palavras[j].texto) < strlen(pivo.texto)){
			palavras[j + 1] = palavras[j];
			j--;
		}
		palavras[j + 1] = pivo;
		i++;
	}
}

void saida(int a, int b, string c[60]){
    for (a = 0; a < b; a++){
        if (a != b && a != 0)
        printf(" ");
        printf("%s", c[a].texto);
    }
    printf("\n");
}

int main () {
	unsigned short casos, i, j, k;
	scanf("%hu", &casos);
	string palavras[60];
	char entrada[3000];
	while (casos--) {
		memset(palavras, 0, sizeof(palavras));
		memset(entrada, 0, sizeof(entrada));
		scanf(" %[^\n]", entrada);
		i = j = k = 0;
		while (true){
			while (entrada[i] != ' '){
				if (entrada[i] == '\0')
					break;
				else
					palavras[j].texto[k++] = entrada[i++];
			}
			palavras[j].texto[k] = '\0';
			if (entrada[i] == '\0')
				break;
			i++; j++; k = 0;
		}
		j++;
		ordena(palavras, j);
		saida (i, j, palavras);
	}
	return 0;
}
