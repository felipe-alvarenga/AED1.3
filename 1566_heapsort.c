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

void InsereEmHeap(int m, int v[]) {
    int f = m + 1;
    while (f > 1 && v[f / 2] < v[f]) {
        int t = v[f / 2];
        v[f / 2] = v[f];
        v[f] = t;
        f = f / 2;
    }
}

void SacodeHeap(int m, int v[]) {
    int t, f = 2;
    while (f <= m) {
        if (f < m && v[f] < v[f + 1]) ++f;
        if (v[f / 2] >= v[f]) break;
        t = v[f / 2];
        v[f / 2] = v[f];
        v[f] = t;
        f *= 2;
    }
}

void Heapsort(int n, int v[]) {
    int m;
    for (m = 1; m < n; m++) {
        InsereEmHeap(m, v);
    }
    for (m = n; m > 1; m--) {
        int t = v[1];
        v[1] = v[m];
        v[m] = t;
        SacodeHeap(m - 1, v);
    }
}

int main(void) {
    int NC = read_int();
    if (NC < 0) return 0; 

    for (int case_i = 0; case_i < NC; ++case_i) {
        int N = read_int(); 
        if (N <= 0) {
            putchar_unlocked('\n');
            continue;
        }

        int *v = (int*) malloc((size_t)(N + 1) * sizeof(int));
        if (!v) { 
            fprintf(stderr, "malloc failed\n"); 
            return 1; 
        }

        for (int i = 1; i <= N; ++i) {
            v[i] = read_int();
        }

        Heapsort(N, v);

        for (int i = 1; i <= N; ++i) {
            char sep = (i == N) ? '\n' : ' ';
            write_int_sep(v[i], sep);
        }
        free(v); // Libera a memória
    }
    return 0;
}
