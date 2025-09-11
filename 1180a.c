#include <stdio.h>

int main (){
  int n, i, k;
  do{
    scanf ("%d", &n);
  }while (n < 1 || n > 1000);
  int v[n];
  for (i = 0; i < n; i++){
    scanf ("%d", &v[i]);
  }
  k = v[0];
  for (i = 0; i < n; i++){
    if (k > v[i])
      k = v[i];
    else
      continue;
  }
  printf ("Menor valor: %d\n", k);
  for (i = 0; i < n; i++){
    if (k == v[i])
      break;
    else
      continue;
  }
  printf ("Posicao: %d\n", i);
  return 0;
}
