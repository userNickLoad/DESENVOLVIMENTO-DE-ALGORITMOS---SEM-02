#include <stdio.h>

int main(void){
	int amount = 0;
	float sum = 0.0, input = 0.0;
	
	while(1){
	
		
		printf("Coloque um numero entre 1 e 100: ");
		scanf("%f", &input);
		printf("\n\n");
		
		if(!(1 <= input && input <= 100)){
			break;
		}
		
		sum += input;
		amount++;
	}
	
	printf("Media é %.2f", sum/amount);
	
	return 0;
}
