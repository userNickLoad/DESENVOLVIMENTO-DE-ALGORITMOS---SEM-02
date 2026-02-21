#include <stdio.h>
#include "calculadora.h"

int main(void){
	
	float a, b;
	
	printf("Entre um numero para a: ");
	scanf("%f", &a);
	
	printf("Entre um numero para b: ");
	scanf("%f", &b);
	
	printf("Resultados: \n\n");
	
	
	printf("\t %.2f + %.2f = %.2f\n", a, b, sum(a, b));
	
	printf("\t %.2f - %.2f = %.2f\n", a, b, sub(a, b));
	
	printf("\t %.2f * %.2f = %.2f\n", a, b, mul(a, b));
	
	if (b != 0)
	printf("\t %.2f / %.2f = %.2f\n", a, b, div(a, b));
	else
	printf("\t %.2f / %.2f = indefinido\n", a, b);
	
	
	
	return 0;
}
