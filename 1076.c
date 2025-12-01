#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int vis[110];
char adj[110][110];

int x, ans;

void imprime(int a){
    printf("%d\n", a << 1);
}

void Profundidade(int u)
{
    int i;
    vis[u] = 1;

    for (i = 0; i < x; ++i)
        if (adj[u][i])
            if (vis[i] == 0)
                Profundidade(i), ans++;
}

int main(int argc, char **argv)
{
    int n, y, q, u, v, i;

    scanf("%d", &n);

    while (n--)
    {
        scanf("%d", &q);
        scanf("%d %d", &x, &y);

        memset(vis, 0, sizeof(vis));
        memset(adj, 0, sizeof(adj));
        for (i = 0; i < y; ++i)
        {
            scanf("%d %d", &u, &v);
            adj[u][v] = adj[v][u] = 1;
        }
        ans = 0;
        Profundidade(q);
        imprime(ans);
    }
    return 0;
}
