#include <stdio.h>
#include <string.h>

void resultado(int a, int b) {
    if (!a && b == -1)
        printf("correct\n");
    else
        printf("incorrect\n");
}

int main() {
    char expressao[1001];
    char parenteses[1001];
    int ultimo;

    while (scanf("%s", expressao) != EOF) {
        int erro = 0;
        int tam = strlen(expressao);
        ultimo = -1;
        for (int i = 0; i < tam; i++) {
            if (expressao[i] == '(') {
                parenteses[++ultimo] = '(';     
            }
            else if (expressao[i] == ')') {
                if (ultimo == -1) {      
                    erro = 1;
                    break;
                }
                ultimo--;                  
            }
        }
        resultado(erro, ultimo);
    }
    return 0;
}
