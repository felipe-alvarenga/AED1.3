#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int N, M, found_cycle;
unsigned char *adj, *cor;

int idx(int u, int v){ 
    return u * (N+1) + v; 
}

void imprime_resultado(int a){
     if (a != 0)
        printf("SIM\n");
    else
        printf("NAO\n");

}

void dfs(int u){
    if(found_cycle) 
        return;
    cor[u] = 1; 
    for(int v = 1; v <= N; ++v){
        if(adj[idx(u,v)]){
            if(cor[v] == 1){
                found_cycle = 1;
                return;
            }else if(cor[v] == 0){
                dfs(v);
                if(found_cycle) return;
            }
        }
    }
    cor[u] = 2;
}

void libera(unsigned char* a, unsigned char* b){
    free(a);
    free(b);
}

int main(void){
    int T;
    if(scanf("%d", &T) != 1) return 0;
    while(T--){
        if(scanf("%d %d", &N, &M) != 2) return 0;

        size_t cells = (size_t)(N+1) * (size_t)(N+1);
        adj = (unsigned char*) calloc(cells, sizeof(unsigned char));
        if(!adj){
            fprintf(stderr, "Erro: memória insuficiente para matriz %d x %d\n", N+1, N+1);
            return 1;
        }

        cor = (unsigned char*) calloc(N+1, sizeof(unsigned char));
        if(cor == 0){
            fprintf(stderr, "Erro: memória insuficiente para vetor de cores\n");
            free(adj);
            return 1;
        }

        int a,b;
        for(int i=0;i<M;++i){
            scanf("%d %d", &a, &b);
            if(a>=1 && a<=N && b>=1 && b<=N && a!=b){
                adj[idx(a,b)] = 1;
            }
        }

        found_cycle = 0;
        for(int u=1; u<=N && !found_cycle; ++u){
            if(cor[u] == 0) dfs(u);
        }

        imprime_resultado(found_cycle);
        libera(adj, cor);
    }
    return 0;
}
