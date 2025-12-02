#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int vis[101010];
int dist[101010];

typedef struct no{
	int u, w;
	struct no *next;
}No;
typedef No* PNo;

typedef struct g{
	PNo adj;	
}G;
typedef G* Pg;

Pg Grafo(int tam) {
	int i;
	Pg g = (Pg) malloc(sizeof(G));
	g->adj = (PNo) malloc(sizeof(No) * (tam + 1));
	for (i = 0; i < tam; ++i)
		g->adj[i].next = NULL;
	return g;
}

PNo FazNo(int u, int w) {
	PNo new = (PNo) malloc(sizeof(No));
	new->u = u;
	new->w = w;
	new->next = NULL;
	return new;
}

void Push(Pg g, int u, int v, int w) {
	PNo new = FazNo(u, w);
	new->next = g->adj[v].next;
	g->adj[v].next = new;
}

void dijkstra(Pg g, int s, int tam) {
	PNo k;
	int i, j, v;
	for (i = 0; i < tam; ++i)
		dist[i] = 100000;
	memset(vis, false, sizeof(vis));
	dist[s] = 0;
	for (i = 0; i < tam; ++i) {
		v = -1;
		for (j = 0; j < tam; ++j)
			if (!vis[j] && (v == -1 || dist[j] < dist[v]))
				v = j;
		if (dist[v] == 100000)
			break;
		vis[v] = true;
		for (k = g->adj[v].next; k != NULL; k = k->next) {
			int to = k->u;
			int len = k->w;
			if (dist[v] + len < dist[to])
				dist[to] = dist[v] + len;
		}
	}
}

int main(int argc, char **argv) {	
	int i;
	int n, m, c, k, a, b, w;
	while (scanf("%d %d %d %d", &n, &m, &c, &k), (c && n && m && k)) {	
		Pg graph = Grafo(n + 1);
		for (i = 0; i < m; ++i) {
			scanf("%d %d %d", &a, &b, &w);
			if (a >= c && b >= c || ((a < c) && (b < c) && (abs(a - b) == 1)))
				Push(graph, a, b, w), Push(graph, b, a, w);
			if (a >= c && b < c)
				Push(graph, b, a, w);
			if (b >= c && a < c)
				Push(graph, a, b, w);
		}
		dijkstra(graph, k, n);
		printf("%d\n", dist[c - 1]);
	}
	return 0;
}
