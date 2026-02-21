#include <stdio.h>
#include "conversoes.h"

int main(void){
	int input;
	
	printf("---------- Bem vindo ----------\n\n\n");
	
	char frases[6][20] = {"celsius", "fahrenheit", "metros", "quilometros", "segundos", "horas"};
	char siglas[6][5] = {"° C", "° F", " M", " KM", "s", " H"};
	
	while(1){
		printf("O que você deseja: \n\n");
		
		printf("\t[0] celsius para fahrenheit;\n");
		printf("\t[1] fahrenheit para celsius;\n");
		printf("\t[2] metros para quilometros;\n");
		printf("\t[3] quilometros para metros;\n");
		printf("\t[4] segundos para horas;\n");
		printf("\t[5] horas para segundos;\n");
		printf("\t[6] SAIR;\n\n");
		
		do {
			
			printf("Entre com a sua resposta: ");
			scanf("%d", &input);
			
		} while(input > 6 && input < 0);
		
		if(input == 6)break;
			
		float value, result;	
			
		printf("\n\nEntre com o valor em %s para ser convertido em %s\n\n", frases[input], frases[(input % 2 == 0) ? input - 1 : input + 1]);
		scanf("%f", &value);
		
		
		switch(input){
			case 0:
				result = cel_to_fah(value);
				break;
			case 1:
				result = fah_to_cel(value);
				break;
			case 2:
				result = m_to_km(value);
				break;
			case 3:
				result = km_to_m(value);
				break;
			case 4:
				result = s_to_h(value);
				break;
			case 5:
				result = h_to_s(value);
				break;
		}
		
		printf("%.2f%s em %s eh %.2f%s\n\n", value, siglas[input], frases[(input % 2 == 0) ? input - 1 : input + 1], result, siglas[(input % 2 == 0) ? input - 1 : input + 1]);
		
		printf("Prescione enter para continuar.");
		scanf("");
	}
	
	printf("Volte sempre!");
	
	return 0;
}
