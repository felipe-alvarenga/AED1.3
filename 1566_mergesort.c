#include <stdio.h>
#include <stdlib.h>

void Intercala(int V[], int esq, int meio, int dir) {
    int i = esq, j = meio + 1, k = 0;
    int *temp = malloc((dir - esq + 1) * sizeof(int));
    if (!temp) exit(1);
    while (i <= meio && j <= dir)
        temp[k++] = (V[i] <= V[j]) ? V[i++] : V[j++];
    while (i <= meio) temp[k++] = V[i++];
    while (j <= dir)  temp[k++] = V[j++];
    for (i = esq, k = 0; i <= dir; i++, k++)
        V[i] = temp[k];
    free(temp);
}

void Mergesort(int V[], int esq, int dir) {
    if (esq >= dir) return;
    int meio = (esq + dir) / 2;
    Mergesort(V, esq, meio);
    Mergesort(V, meio + 1, dir);
    Intercala(V, esq, meio, dir);
}

int main() {
    int NC;
    if (scanf("%d", &NC) != 1)
        return 0;
    while (NC > 0) {
        int N;
        scanf("%d", &N);
        int *h = (int*) malloc(N * sizeof(int));
        if (h == NULL) return 0;
        for (int i = 0; i < N; i++) {
            scanf("%d", &h[i]);
        }
        if (N > 0) {
            Mergesort(h, 0, N - 1);
        }
        if (N > 0) {
            printf("%d", h[0]);
            for (int i = 1; i < N; i++) {
                printf(" %d", h[i]);
            }
        }
        printf("\n");
        free(h);
        NC--;
    }
    return 0;
}
