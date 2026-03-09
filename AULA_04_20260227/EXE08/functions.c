#include "functions.h"
#define PI 3.1415

void square(){
    float side;
    printf("\n\n");
    printf("Entre com a medida do lado do quadrado: ");
    
    scanf("%f", &side);

    printf("A area do quadrado é %f * %f = %f", side, side, side*side);
}

void rectangle(){
    float width, height;
    printf("\n\n");

    printf("Entre com a medida do lado do retangulo: ");
    scanf("%f", &width);

    printf("Entre com a medida da altura do retangulo: ");
    scanf("%f", &height);

    printf("A area do quadrado é %f * %f = %f", width, height, width*height);
}

void triangle(){
    float base, height;
    printf("\n\n");

    printf("Entre com a medida da base do triangulo: ");
    scanf("%f", &base);

    printf("Entre com a medida da altura do triangulo: ");
    scanf("%f", &height);

    printf("A area do quadrado é %f * %f = %f", base, height, base*height/2);
}

void circle(){
    float radius;
    printf("\n\n");

    printf("Entre com o raio do circulo: ");
    scanf("%f", &radius);

    printf("A area do quadrado é %f * %f * %f = %f", PI, radius, radius, PI*radius*radius);
}