#include "trees.h"
#include <malloc.h>
#include <stdio.h>

int main(void) {
    char buff[101];
    for (int i = 0; i < 101; i++) buff[i] = '\0';
    long num = 0, float_dot = 1;

    printf("Calculadora 3000!\n\n");
    printf("\t - Regras:\n");
    printf("\t\t + As unicas operacoes aceitas sao +, -, * e /\n");
    printf("\t\t + Caso tenha x / 0, sera invalidada\n\n");

    printf("Coloque a sua expressao: ");
    scanf("%100s", buff);

    Node * crr = NULL;

    // Organiza operações
    for (int i = 0; i < 100; i++) {
        if (buff[i] == ' ') continue;

        if (('0' <= buff[i] && (int) buff[i] <= '9') || buff[i] == '.'){
            if(buff[i] != '.'){
                num *= 10;
                num += buff[i] - 48;
            }
            
            float_dot *= (buff[i] == '.' || float_dot > 1)? 10 : 1;
            continue;
        }

        if(num != 0){
            float ff_num = (double) num / ((float_dot > 1)? float_dot / 10 : 1);
            printf("Numero: %f\n\n",ff_num);
            crr = num_to_tree(crr, ff_num);
            num = 0;
            float_dot = 1;
        }

        if (buff[i] == '+' || buff[i] == '-' || buff[i] == '*' || buff[i] == '/'){
            printf("Op: %c\n\n",buff[i]);

            crr = op_to_tree(crr, buff[i]);
        }
  
    }

    float result = calculate(crr);

    printf("\n\n\nO resultado da conta eh: %.4f", result);

    return 0;
}