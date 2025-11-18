#include <stdio.h>

void responde (int a, int b, int c) {
    if (a && !b && !c) 
        printf("stack\n");
    else
        if (!a && b && !c) 
            printf("queue\n");
    else
        if (!a && !b && c) 
            printf("priority queue\n");
    else
        if (!a && !b && !c) 
            printf("impossible\n");
    else 
        printf("not sure\n");
}

int main() {
    int n, op, x;
    while (scanf("%d", &n) == 1) {
        int stack[1000], top = 0;
        int queue[1000], qb = 0, qe = 0;
        int pq[1000], pqn = 0;
        int pilha = 1, fila = 1, filap = 1;

        for (int i = 0; i < n; i++) {
            scanf("%d %d", &op, &x);

            if (op == 1) {
                stack[top++] = x;
                queue[qe++] = x;
                pq[pqn++] = x;
            } else {
                if (pilha) {
                    if (top == 0 || stack[top - 1] != x) pilha = 0;
                    else top--;
                }
                if (fila) {
                    if (qb == qe || queue[qb] != x) fila = 0;
                    else qb++;
                }
                if (filap) {
                    if (pqn == 0) filap = 0;
                    else {
                        int maxI = 0;
                        for (int j = 1; j < pqn; j++)
                            if (pq[j] > pq[maxI]) maxI = j;
                        if (pq[maxI] != x) filap = 0;
                        else {
                            pq[maxI] = pq[--pqn];
                        }
                    }
                }
            }
        }
        responde (pilha, fila, filap);
    }
    return 0;
}
