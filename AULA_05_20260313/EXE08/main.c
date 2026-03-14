#include <stdio.h>
#include <malloc.h>

int main(void){
	int n;
	
	printf("Entre com o numero de andares: ");
	scanf("%d", &n);
	
	char * row = malloc(n+1);
	int i = 0;
	for(; i < n; i++){
		row[i] = '*';
		row[i+1] = '\0';
		printf("%s\n", row);
	}
	free(row);
	
	return 0;
}
