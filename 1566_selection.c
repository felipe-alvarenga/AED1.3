#include <stdio.h>
#include <stdlib.h>

static int read_int(void) {
    int c = getchar_unlocked();
    while (c != EOF && (c < '0' || c > '9')) c = getchar_unlocked();
    if (c == EOF) return -1;
    
    int x = 0;
    while (c >= '0' && c <= '9') {
        x = x * 10 + (c - '0');
        c = getchar_unlocked();
    }
    return x;
}

static void write_int_sep(int x, char sep) {
    char buf[16];
    int i = 0;
    
    if (x == 0) {
        buf[i++] = '0';
    } else {
        char rev[16];
        int j = 0;
        int tmp = x;
        while (tmp > 0) {
            rev[j++] = '0' + (tmp % 10);
            tmp /= 10;
        }
        while (j--) buf[i++] = rev[j];
    }
    for (int k = 0; k < i; ++k) putchar_unlocked(buf[k]);
    putchar_unlocked(sep);
}

static inline void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void selectionSort(int v[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (v[j] < v[min_idx]) {
                min_idx = j;
            }
        }

        if (min_idx != i) {
            swap(&v[min_idx], &v[i]);
        }
    }
}

int main(void) {
    int NC = read_int(); // Número de casos de teste
    if (NC < 0) return 0; // EOF

    for (int case_i = 0; case_i < NC; ++case_i) {
        int N = read_int();
        if (N <= 0) {
            putchar_unlocked('\n');
            continue;
        }

        int *alturas = (int*) malloc((size_t)N * sizeof(int));
        if (!alturas) { 
            fprintf(stderr, "malloc failed\n"); 
            return 1; 
        }

        for (int i = 0; i < N; ++i) {
            alturas[i] = read_int();
        }

        selectionSort(alturas, N);

        for (int i = 0; i < N; ++i) {
            char sep = (i + 1 == N) ? '\n' : ' ';
            write_int_sep(alturas[i], sep);
        }

        free(alturas); 
    }

    return 0;
}
