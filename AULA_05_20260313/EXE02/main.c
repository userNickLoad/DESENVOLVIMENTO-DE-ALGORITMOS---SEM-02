#include <stdio.h>

int main(void){
	int i = 5;
	
	printf("Esse eh o i++, quando o i = 5: %d;\n", i++);
	
	printf("Esse eh o ++i, quando o i = 6: %d;\n\n", ++i);
	
	printf("Quando usamos i++, a incrementacao ocorre apos a operacao, no nosso caso seria o prinft. Quando usamos ++i, a incrementacao ocorre antes da operacao.");
	
	return 0;
}
