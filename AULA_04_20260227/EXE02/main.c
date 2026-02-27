#include <stdio.h>

int main(void) {
    float sum = 0;

    for (int i = 0; i < 3; i++) {
        float temp;
        printf("Entre com a %d nota do aluno: ", i+1);
        scanf("%f", &temp);
        sum += temp;
    }

    sum /= 3;

    if (sum >= 7) {
        printf("A média eh %.2f parabens, você passou liso.", sum);
    } else if (sum >= 5){
        printf("A media eh %.2f, voce esta de recuperacao.", sum);
    } else {
        printf("Infelizmente voce foi reprovado, pois sua media foi %.2f", sum);
    }

    return 0;
}

