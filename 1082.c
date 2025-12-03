#include <stdlib.h>
#include <stdio.h>
#include <string.h>

_Bool visitados[30];
char adj[30][30];
char vertices[30];
typedef char* Pchar;

int tam, m, n;

int compara(char *a, char *b) {
	if (*a == *b)
		return 0;
	if (*a > *b)
		return 1;
	else
		return -1;
}

void dfs(int u) {
	int i;
	visitados[u] = 1;
	vertices[tam++] = u;
	for (i = 0; i < m; ++i)
		if (adj[u][i])
			if (visitados[i] == 0)
				dfs(i);
}

void main () {
	int i, j, casos, caso = 0;
	char a, b;
	
	scanf("%d", &casos);

	while (casos--){
		scanf("%d %d", &m, &n);

		for (i = 0; i < n; ++i){
			scanf(" %c %c", &a, &b);
			adj[a - 'a'][b - 'a'] = 1;
			adj[b - 'a'][a - 'a'] = 1;
		}

		printf("Case #%d:\n", ++caso);
		int ans = 0;
		
		for (i = 0; i < m; ++i){
			if (visitados[i] == 0){
				++ans, dfs(i);
				qsort(vertices, tam, sizeof(char), compara);
				for (j = 0; j < tam; ++j)
					printf("%c,", vertices[j] + 'a');
				printf("\n");
			}
			tam = 0;
		}
        printf("%d connected components\n", ans);
        printf("\n");
        memset(visitados, 0, sizeof(visitados));
        memset(adj, 0, sizeof(adj));
	}
}
