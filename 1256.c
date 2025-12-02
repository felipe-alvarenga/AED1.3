#include <stdlib.h>
#include <stdio.h>

typedef struct no {
	int info;
	struct no *prox;
} No;
typedef No* PNo;

typedef struct list {
	PNo prim;
	PNo ult;
} list;
typedef list* Plist;

unsigned x;

void Push(Plist __hash, const int key) {
	PNo aux;
	aux = (PNo) malloc(sizeof(No));
	if(aux == 0)
		exit(1);
	int idx = key % x;
	if (__hash[idx].prim)
		__hash[idx].ult->prox = aux;
	else
		__hash[idx].prim = aux;
	__hash[idx].ult = aux;
	aux->prox = NULL;
	aux->info = key;
}

int main () {
	unsigned n;
	PNo j;
	int y, i, tmp;
	scanf("%u", &n);
	while (n--) {
		scanf("%u %d", &x, &y);
		list hash[x];
		for (i = 0; i < x; ++i)
			hash[i].prim = hash[i].ult = NULL;
		for (i = 0; i < y; ++i)
			scanf("%d", &tmp), Push(hash, tmp);
		for (i = 0; i < x; ++i) {	
			printf("%d -> ", i);
			for (j = hash[i].prim; j; j = j->prox)
				printf("%d -> ", j->info);
			printf("\\");
			printf("\n");
		}
		if (n)
			printf("\n");
	}
    return 0;
}
