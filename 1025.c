#include <stdio.h>

void quicksort(int *a, int left, int right){
    int i, j, x, y;
     
    i = left;
    j = right;
    x = a[(left + right) / 2];
     
    while(i <= j){
        while(a[i] < x && i < right)
            i++;
        while(a[j] > x && j > left)
            j--;
        if(i <= j){
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > left) 
        quicksort(a, left, j);
    if(i < right)
        quicksort(a, i, right);
}

void imprime_achado (int a, int b, int c){
    if(a == 1)
        printf("%d found at %d\n", b, c);
    else
        printf("%d not found\n", b);
}

int main(){
    int n, q, cases = 1, i, consulta, flag;

    while(1){
        scanf("%d %d", &n, &q);
        if(n == 0 && q == 0)
            break;

        printf("CASE# %d:\n", cases);
        cases++;

        int marmores[n];
        for(i = 0; i < n; i++)
            scanf("%d", &marmores[i]);
        
        quicksort(marmores, 0, n-1);

        while(q > 0){
            scanf("%d", &consulta);
            flag = 0;     // false = 0

            for(i = 0; i < n; i++){
                if(marmores[i] == consulta){
                    flag = 1;   // true = 1
                    break;
                }
            }
            imprime_achado (flag, consulta, i+1);

            q--;
        }
    }

    return 0;
}
