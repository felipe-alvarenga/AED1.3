#include <stdlib.h>
#include <stdio.h>

int M, N, *head, *to, *next, eidx, found_cycle;

unsigned char *color;

void add_edge(int u, int v){
    to[eidx] = v;
    next[eidx] = head[u];
    head[u] = eidx++;
}

void imprime_resultado(int a){
     if (a != 0)
        printf("SIM\n");
    else
        printf("NAO\n");

}

void dfs(int u){
    if(found_cycle) return;
    color[u] = 1;
    for(int ei = head[u]; ei != -1; ei = next[ei]){
        int v = to[ei];
        if(color[v] == 1){
            found_cycle = 1;
            return;
        } else if(color[v] == 0){
            dfs(v);
            if(found_cycle) return;
        }
    }
    color[u] = 2;
}

void libera(int* a, int* b, int* c, unsigned char* d){
    free(a);
    free(b);
    free(c);
    free(d);
}

int main(void){
    int T;
    if(scanf("%d", &T) != 1) 
        return 0;
    while(T--){
        if(scanf("%d %d", &N, &M) != 2) return 0;

        head = (int*) malloc((N+1)*sizeof(int));
        to   = (int*) malloc((M+5)*sizeof(int));
        next = (int*) malloc((M+5)*sizeof(int));
        if(!head || !to || !next){
            fprintf(stderr, "Erro: memoria insuficiente\n");
            return 1;
        }
        for(int i=1;i<=N;++i){
            head[i] = -1;
        }
        eidx = 0;

        int a,b;
        for(int i=0;i<M;++i){
            scanf("%d %d", &a, &b);
            if(a>=1 && a<=N && b>=1 && b<=N && a!=b){
                add_edge(a,b);
            }
        }

        color = (unsigned char*)calloc(N+1, sizeof(unsigned char));
        found_cycle = 0;
        for(int u=1; u<=N && !found_cycle; ++u){
            if(color[u] == 0) dfs(u);
        }

        imprime_resultado(found_cycle);
        libera(head, to, next, color);
    }
    return 0;
}
