#include <stdio.h>

int main(void){
	int n;
	
	printf("Coloque aqui o seu n: ");
	scanf("%d", &n);
	
	printf("Usando for: \n\n");
	
	int i = 0;
	for(i = 0; i < n; i++){
		printf("%d;\n", i+1);
	}
	
	printf("\n\nUsando while: \n\n");
	
	i = 0;
	while(i<n){
		printf("%d;\n", i+1);
		i++;
	}
	
	printf("\n\nEm resumo, devemos usar for quando tivermos o numero de repeticoes e while, quando um evento acabar com o laco;");
	
	return 0;
}
