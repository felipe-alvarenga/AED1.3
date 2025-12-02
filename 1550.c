#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct no {
    int info[100010];
    int cab;
    int tail;
} No;
typedef No* PNo;

int a, b;
int d[100010];

int front(PNo fila) {
    return fila->info[fila->cab];
}

_Bool vazio(PNo fila) {
    return fila->cab == fila->tail;
}

void bfs(int start) {
    No q;
    make_queue(&q);
    d[start] = 0;
    Push(&q, start);
    while (vazio(&q) == 0) {
        int v = front(&q);
        Pop(&q);
        if (v == b) 
            return;
        int uu = v, rev = 0;
        if (uu == 0) 
            rev = 0;
        else {
            while (uu > 0) {
                rev = rev * 10 + (uu % 10);
                uu /= 10;
            }
        }
        if (rev >= 0 && rev <= 100000 && d[rev] == -1) {
            d[rev] = d[v] + 1;
            Push(&q, rev);
        }
        if (v + 1 <= 100000 && d[v + 1] == -1) {
            d[v + 1] = d[v] + 1;
            Push(&q, v + 1);
        }
    }
}

void make_queue(PNo fila) {
    fila->cab = 0;
    fila->tail = 0;
}

void Push(PNo fila, int data) {
    if (fila->tail >= 100010) {
        return;
    }
    fila->info[fila->tail++] = data;
}

void Pop(PNo fila) {
    if (vazio(fila) == 0) {
        fila->cab++;
    }
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) 
        return 0;
    while (t--) {
        memset(d, -1, sizeof(d));
        if (scanf("%d %d", &a, &b) != 2) 
            return 0;
        bfs(a);
        printf("%d\n", d[b]);
    }
    return 0;
}
