#include <stdlib.h>
#include <stdio.h>

int decrescente(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (y > x) - (y < x);
}

int crescente(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

void saida(int* a, int* b, int c, int d) {
    for (int i = 0; i < c; i++)
        printf("%d\n", a[i]);
    for (int i = 0; i < d; i++)
        printf("%d\n", b[i]);
    free(a);
    free(b);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) 
	    return 0;

    int *imp = malloc(n * sizeof(int));
    int *par = malloc(n * sizeof(int));
    
    if (par == 0 || imp == 0) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    int ce = 0, co = 0;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if ((x & 1) == 0)
            par[ce++] = x;
	    else
            imp[co++] = x;
    }

    qsort(par, ce, sizeof(int), crescente);
    qsort(imp,  co, sizeof(int), decrescente);
    
    saida(par, imp, ce, co);

    return 0;
}
