#include <stdio.h>
#define calcu_collatz(x) collatz(x, 0)

int collatz(int num, int steps)
{
    return (num == 1) ? steps : (num & 0x1) ? collatz(num * 3 + 1, ++steps)
                                            : collatz(num / 2, ++steps);
}

int main(void)
{
    int num, res;

    printf("Entre com um numero: ");
    scanf("%d", &num);

    printf("O numero %d, precisou de %d passos para virar 1", num, calcu_collatz(num));

    return 0;
}