#include "functions.h"

int main(void)
{
    short mode;
    float result;

    printf("calculadora 7000\n\n");
    printf("Excolha entre as opções: \n\n");

    printf("\t- [0] Area do quadrado;\n");
    printf("\t- [1] Area do retangulo;\n");
    printf("\t- [2] Area do triangulo;\n");
    printf("\t- [3] Area do circulo;\n");
    printf("\t- [3<x<0] Sair;\n");

    printf("Entrada: ");
    scanf("%hd", &mode);

    switch (mode)
    {
        case 0:
            square();
            break;
        case 1:
            rectangle();
            break;
        case 2:
            triangle();
            break;
        case 3:
            circle();
        default:
            break;
    }

    return 0;
}