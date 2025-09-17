#include <stdio.h>
#include <stdlib.h>

typedef int* Pint;
typedef int** PPint;

int verificaLinhas(PPint sudoku) {
    int linha, coluna, num;
    for (linha = 0; linha < 9; linha++) {
        int vistos[10] = {0};
        for (coluna = 0; coluna < 9; coluna++) {
            num = sudoku[linha][coluna];
            if (num < 1 || num > 9 || vistos[num] == 1) {
                return 0;
            }
            vistos[num] = 1;
        }
    }
    return 1;
}

int verificaColunas(PPint sudoku) {
    int linha, coluna, num;
    for (coluna = 0; coluna < 9; coluna++) {
        int vistos[10] = {0};
        for (linha = 0; linha < 9; linha++) {
            num = sudoku[linha][coluna];
            if (num < 1 || num > 9 || vistos[num] == 1) {
                return 0;
            }
            vistos[num] = 1;
        }
    }
    return 1;
}

int verificaSubgrades(PPint sudoku) {
    int linha, coluna, num;
    int inicioLinha, inicioColuna;
    for (inicioLinha = 0; inicioLinha < 9; inicioLinha += 3) {
        for (inicioColuna = 0; inicioColuna < 9; inicioColuna += 3) {
            int vistos[10] = {0};
            for (linha = inicioLinha; linha < inicioLinha + 3; linha++) {
                for (coluna = inicioColuna; coluna < inicioColuna + 3; coluna++) {
                    num = sudoku[linha][coluna];
                    if (num < 1 || num > 9 || vistos[num] == 1) {
                        return 0;
                    }
                    vistos[num] = 1;
                }
            }
        }
    }
    return 1;
}

int main() {
    int n, instancia;
    scanf("%d", &n);

    for (instancia = 1; instancia <= n; instancia++) {
        PPint sudoku;
        int linha, coluna, i;

        sudoku = (PPint) malloc(9 * sizeof(Pint));
        if (sudoku == NULL) {
            printf("Erro de alocacao de memoria!\n");
            return 1;
        }

        for (i = 0; i < 9; i++) {
            sudoku[i] = (Pint) malloc(9 * sizeof(int));
            if (sudoku[i] == NULL) {
                printf("Erro de alocacao de memoria!\n");
                return 1;
            }
        }

        for (linha = 0; linha < 9; linha++) {
            for (coluna = 0; coluna < 9; coluna++) {
                scanf("%d", &sudoku[linha][coluna]);
            }
        }

        printf("Instancia %d\n", instancia);

        if (verificaLinhas(sudoku) && verificaColunas(sudoku) && verificaSubgrades(sudoku)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        
        printf("\n");

        for (i = 0; i < 9; i++) {
            free(sudoku[i]);
        }
        free(sudoku);
    }

    return 0;
}
