#include <stdio.h>

int main(void) {

    int a, b;

    printf("Entre com o primeiro numero: ");
    scanf("%d", &a);

    printf("Entre com o segundo numero: ");
    scanf("%d", &b);

    if (a == b) {
        printf("Os numeros são iguais, pois ambos valem %d", a);

        return 0;
    }

    printf("O %s eh o maior, valendo %d", (a > b) ? "primeiro" : "segundo", (a > b) ? a : b);

    return 0;
}