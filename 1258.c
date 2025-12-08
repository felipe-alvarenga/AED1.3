#include <string.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct camisa{
    char nome[60];
    char cor[20];
    char tamanho;
}camisa;
typedef camisa* Pcamisa;

void cor(Pcamisa camisas, unsigned short tam){
    short i = 1, j;
    camisa pivo;
    while (i < tam){
        j = i - 1;
        pivo = camisas[i];
        while (j >= 0 && strcmp(camisas[j].cor, pivo.cor) > 0){
            camisas[j + 1] = camisas[j];
            j--;
        }
        camisas[j + 1] = pivo;
        i++;
    }
}

void tamanho(Pcamisa camisas, unsigned short tam){
    short i = 1, j;
    camisa pivo;
    while (i < tam){
        j = i - 1;
        pivo = camisas[i];
        while (j >= 0 && camisas[j].tamanho < pivo.tamanho){
            camisas[j + 1] = camisas[j];
            j--;
        }
        camisas[j + 1] = pivo;
        i++;
    }
}

void alpha(Pcamisa camisas, unsigned short tam){
    short i = 1, j;
    camisa pivo;
    while (i < tam){
        j = i - 1;
        pivo = camisas[i];
        while (j >= 0 && strcmp(camisas[j].nome, pivo.nome) > 0){
            camisas[j + 1] = camisas[j];
            j--;
        }
        camisas[j + 1] = pivo;
        i++;
    }
}

int main (){
    unsigned short qtsCamisetas;
    unsigned short i;
    scanf("%hu", &qtsCamisetas);
    while (true){
        if (qtsCamisetas == 0)
            break;
        camisa camisas[qtsCamisetas];
        for (i = 0; i < qtsCamisetas; i++){
            scanf(" %[^\n]", camisas[i].nome);
            scanf("%s %c", camisas[i].cor, &camisas[i].tamanho);
        }
        alpha(camisas, qtsCamisetas);
        tamanho(camisas, qtsCamisetas);
        cor(camisas, qtsCamisetas);
        for (i = 0; i < qtsCamisetas; i++)
            printf("%s %c %s\n", camisas[i].cor, camisas[i].tamanho, camisas[i].nome);
        scanf("%hu", &qtsCamisetas);
        if (qtsCamisetas != 0)
            printf("\n");
    }
    return 0;
}
