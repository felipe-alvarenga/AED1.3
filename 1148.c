#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct no{
    int v;
    int a;
    int way[501][501];
}No;
No grafo;

void dijkstra(int origem, int destino) {
    int w, w0, fr[501], parnt[501], cst[501], i;

    for (i = 0; i < 501; ++i) {
        parnt[i] = -1;
        cst[i] = 999999;
        fr[i] = -1;
    }

    fr[origem] = origem;
    cst[origem] = 0;

    while (1) {
        int mincst = 999999;
        w0 = -1;
        for (w = 0; w < grafo.v; ++w) {
            if (parnt[w] == -1 && cst[w] < mincst) {
                mincst = cst[w];
                w0 = w;
            }
        }
        if (mincst == 999999 || w0 == -1) break;

        parnt[w0] = fr[w0];

        for (w = 0; w < grafo.v; ++w) {
            if (cst[w0] != 999999 && grafo.way[w0][w] != 999999) {
                if (cst[w] > cst[w0] + grafo.way[w0][w]) {
                    cst[w] = cst[w0] + grafo.way[w0][w];
                    fr[w] = w0;
                }
            }
        }
    }
    if (cst[destino] < 999999) printf("%d\n", cst[destino]);
    else printf("Nao e possivel entregar a carta\n");
}

int main () {
    memset(&grafo, 0, sizeof(grafo));
    int n, e, k, o, d, x, y, z, i, j;

    while (1) {
        if (scanf("%d %d", &n, &e) != 2) 
            break;
        if (n == 0 && e == 0) 
            break;

        for (i = 0; i <= n; ++i)
            for (j = 0; j <= n; ++j)
                grafo.way[i][j] = 999999;

        for (i = 0; i < e; ++i) {
            scanf("%d %d %d", &x, &y, &z);
            if (grafo.way[y][x] != 999999) {
                grafo.way[x][y] = 0;
                grafo.way[y][x] = 0;
            } else {
                grafo.way[x][y] = z;
            }
        }

        grafo.v = n + 1;
        grafo.a = e;

        scanf("%d", &k);
        for (i = 0; i < k; ++i) {
            scanf("%d %d", &o, &d);
            dijkstra(o, d);
        }
        printf("\n");
    }
    return 0;
}
