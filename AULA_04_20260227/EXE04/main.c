#include "trees.h"
#include <malloc.h>
#include <stdio.h>

int main(void) {
    char buff[101], num_staged = 0x0;
    for (int i = 0; i < 101; i++) buff[i] = '\0';
    long num = 0, float_dot = 1;

    printf("Calculadora 3000!\n\n");
    printf("\t - Regras:\n");
    printf("\t\t + As unicas operacoes aceitas sao +, -, * e /\n");
    printf("\t\t + Caso tenha x / 0, sera invalidada\n\n");

    printf("Coloque a sua expressao: ");
    fgets(buff, sizeof(buff), stdin);

    Node * crr = NULL;

    // Organiza operações
    for (int i = 0; i < 100; i++) {
        if (buff[i] == ' ') continue;
        if (buff[i] == '\0') break;

        if (('0' <= buff[i] && (int) buff[i] <= '9') || buff[i] == '.'){
            num_staged = 0x1;
            if(buff[i] != '.'){
                num *= 10;
                num += buff[i] - 48;
            }
            
            float_dot *= (buff[i] == '.' || float_dot > 1)? 10 : 1;
            continue;
        }

        if(num_staged){
            float ff_num = (double) num / ((float_dot > 1)? float_dot / 10 : 1);
            crr = num_to_tree(crr, ff_num);
            if(crr == NULL) return -1;
            num = 0;
            float_dot = 1;
            num_staged = 0x0;
        }

        if (buff[i] == '+' || buff[i] == '-' || buff[i] == '*' || buff[i] == '/'){
            crr = op_to_tree(crr, buff[i]);
        }
  
    }

    float result = calculate(crr);

    printf("\n\n\nO resultado da conta eh: %.4f", result);

    return 0;
}