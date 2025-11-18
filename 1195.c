#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   int v;
   struct node *d, *e;
} node;

node *novo(int n) {
   node *nv = (node *)malloc(sizeof(node));
   if (!nv) {
      fprintf(stderr, "Erro ao alocar memória.\n");
      exit(1);
   }
   nv->v = n;
   nv->e = nv->d = NULL;
   return nv;
}

void pre(node *r) {
   if (r) {
      printf(" %d", r->v);
      pre(r->e);
      pre(r->d);
   }
}

void in(node *r) {
   if (r) {
      in(r->e);
      printf(" %d", r->v);
      in(r->d);
   }
}

void post(node *r) {
   if (r) {
      post(r->e);
      post(r->d);
      printf(" %d", r->v);
   }
}

void inserir(int n, node *r) {
   if (n < r->v) {
      if (r->e)
         inserir(n, r->e);
      else
         r->e = novo(n);
   } else {
      if (r->d)
         inserir(n, r->d);
      else
         r->d = novo(n);
   }
}

void liberarArvore(node *r) {
   if (r) {
      liberarArvore(r->e);
      liberarArvore(r->d);
      free(r);
   }
}

int main(void) {
   int c, n, v;
   scanf("%d", &c);
   
   for (int i = 1; i <= c; ++i) {
      scanf("%d %d", &n, &v);
      node *r = novo(v);
      
      for (int j = 1; j < n; ++j) {
         scanf("%d", &v);
         inserir(v, r);
      }
      
      printf("Case %d:", i);
      printf("\nPre.:"); pre(r);
      printf("\nIn..:"); in(r);
      printf("\nPost:"); post(r);
      printf("\n\n");
      
      liberarArvore(r);
   }
   
   return 0;
}
