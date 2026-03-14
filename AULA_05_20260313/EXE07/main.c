#include <stdio.h>
#include <time.h>

long fib(long n_1, long n_2, int stp){
	return (stp > 3)? fib(n_2, n_1+n_2, --stp) :  n_1+n_2;
}

int main(void){
	long int clock_ticks;
	long fibonacci[40];
	
	fibonacci[0] = 1;
	fibonacci[1] = 1;	
	
	int i = 2;
	long int clocks = clock();
	
	for (; i < 40; i++){
		fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
		printf("Fi: %lu\n", fibonacci[i]);
	}
	
	printf("Tempo para achar o 40o de fibonacci com for: %fs\n", (float) clocks/CLOCKS_PER_SEC);
	
	printf("Usando recursividade: \n");
	
	clocks = clock();
	
	printf("40o termo: %lu\n", fib(1, 1, 40));
	
	printf("\n\n Tempo: %fs \n", (float) clocks/CLOCKS_PER_SEC);
	
	
	
	return 0;
}
