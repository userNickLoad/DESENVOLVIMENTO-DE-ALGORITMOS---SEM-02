#include <stdio.h>

int main(void) {
    unsigned short num;
    do {
        printf("Informe em qual dia da semana estamos de forma ordinais [1-7]: ");
        scanf("%hu", &num);
    }while (num > 7);

    switch (num) {
        case 1:
            printf("Domingo");
            break;
        case 2:
            printf("Segunda");
            break;
        case 3:
            printf("Terça");
            break;
        case 4:
            printf("Quarta");
            break;
        case 5:
            printf("Quinta");
            break;
        case 6:
            printf("Sexta");
            break;
        case 7:
            printf("Sabado");
            break;
    }

    return 0;
}