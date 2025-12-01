#include <stdio.h>

typedef struct Fracao {
    int a, b;
} Raz;

Raz soma(Raz f1, Raz f2) {
    Raz retorno;
    retorno.a = f1.a * f2.b + f2.a * f1.b;
    retorno.b = f1.b * f2.b;
    return retorno;
}

Raz subtracao(Raz f1, Raz f2) {
    Raz retorno;
    retorno.a = f1.a * f2.b - f2.a * f1.b;
    retorno.b = f1.b * f2.b;
    return retorno;
}

Raz multiplicacao(Raz f1, Raz f2) {
    Raz retorno;
    retorno.a = f1.a * f2.a;
    retorno.b = f1.b * f2.b;
    return retorno;
}

Raz divisao(Raz f1, Raz f2) {
    Raz retorno;
    retorno.a = f1.a * f2.b;
    retorno.b = f1.b * f2.a;
    return retorno;
}

int MDC(int a, int b) {
    return (b == 0) ? a : MDC(b, a % b);
}

Raz irredutivel(Raz f) {
    int mdc = (f.a < 0) ? MDC(-f.a, f.b) : MDC(f.a, f.b);
    f.a /= mdc;
    f.b /= mdc;

    if (f.b < 0) {
        f.b = -f.b;
        f.a = -f.a;
    }

    return f;
}

int main() {
    int N;
    char operador;
    Raz f1, f2, resultado;

    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        scanf("%d / %d %c %d / %d", &f1.a, &f1.b, &operador, &f2.a, &f2.b);

        switch (operador) {
            case '+': 
                resultado = soma(f1, f2); 
                break;
            case '-': 
                resultado = subtracao(f1, f2); 
                break;
            case '*': 
                resultado = multiplicacao(f1, f2); 
                break;
            case '/': 
                resultado = divisao(f1, f2); 
                break;
        }

        printf("%d/%d = ", resultado.a, resultado.b);
        resultado = irredutivel(resultado);
        printf("%d/%d\n", resultado.a, resultado.b);
    }

    return 0;
}
