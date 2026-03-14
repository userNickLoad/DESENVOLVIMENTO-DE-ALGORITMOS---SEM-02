#include <stdio.h>

int main(void){
	
	int mode, num;
	
	do{
		do {
			printf("\n\nEntre um numero de 1 a 3 segundo as opcoes: \n\n");
			printf("\t[1] Calcular quadrado de um número;\n");
			printf("\t[2] Calcular cubo de um número;\n");
			printf("\t[3] Sair;\n");
			printf("Numero: ")
			scanf("%d", &mode);
			
		}while(mode != 1 && mode != 2 && mode != 3);
		
		if(mode == 3){
			return 0;
		}
		
		printf("\nEntre com o número: ");
		scanf("%d", &num);
		
		switch(mode){
			case 1:
				printf("O quadrado de %d eh %d", num, num*num);
				break;
			case 2:
				printf("O cubo de %d eh %d", num, num*num*num);
				break;
		}
		
	}while(1);
	
	
	return 0;
}
