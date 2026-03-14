#include <stdio.h>

float recursive_pow(float num, int pow, float c){
	return (pow > 0)? recursive_pow(num, --pow, c*num) : c;
}

int main(void){
	float num, c = 1;
	int pow, pow2;
	
	printf("Entre com um numero: ");
	scanf("%f", &num);
	
	printf("\nEntre com o seu expoente: ");
	scanf("%d", &pow);
	pow2 = pow;
	
	printf("\n\nVersao recursiva: \n");
	printf("\tResultado: %f;\n", recursive_pow(num, pow, 1));
	
	printf("\n\nVersao loop: \n");
	
	for(; pow2 > 0 ; pow2--){
		c *= num;
	}
	
	printf("\tResultado: %f;\n", c);
	
	
	return 0;
}
