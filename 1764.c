#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_EDGES 40050
#define MAX_VERTS 40000

typedef struct edge {
    int x, y, w;
} Vert;

Vert edges[MAX_EDGES];
int parent[MAX_VERTS + 5];

int encontre_sorte(int v) {
    if (parent[v] != v)
        parent[v] = encontre_sorte(parent[v]);
    return parent[v];
}

int compare_vertices(const void *a, const void *b) {
    const Vert *e1 = (const Vert *)a;
    const Vert *e2 = (const Vert *)b;
    return e1->w - e2->w;
}

int kruskal(int num_edges) {
    int i, mst_cost = 0;

    for (i = 0; i < num_edges; ++i) {
        int a = encontre_sorte(edges[i].x);
        int b = encontre_sorte(edges[i].y);

        if (a != b) {
            parent[a] = b;
            mst_cost += edges[i].w;
        }
    }

    return mst_cost;
}

int main(void) {
    int m, n, i;

    while (scanf("%d %d", &m, &n), m && n) {

        memset(edges, 0, sizeof(edges));
        memset(parent, 0, sizeof(parent));

        for (i = 0; i < n; ++i)
            scanf("%d %d %d", &edges[i].x, &edges[i].y, &edges[i].w);

        qsort(edges, n, sizeof(Vert), compare_vertices);

        for (i = 0; i < m; ++i)
            parent[i] = i;

        printf("%d\n", kruskal(n));
    }

    return 0;
}
