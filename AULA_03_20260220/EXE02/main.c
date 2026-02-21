#include <stdio.h>
#include "numeros.h"

int main(void){
	
	int a, e;
	
	printf("Entre um numero para a: ");
	scanf("%d", &a);
	
	printf("Entre um numero para o exponencial: ");
	scanf("%d", &e);
	
	printf("Resultados: \n\n");
	
	if(is_pair(a)){
		printf("\t%d Eh um numero par\n", a);
	}else{
		printf("\t%d Nao eh um numero par\n", a);
	}
	
	
	
	
	
	
	return 0;
}

