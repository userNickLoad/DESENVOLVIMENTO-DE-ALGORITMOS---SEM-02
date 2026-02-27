#include <stdio.h>

int main(void) {
    short age;
    printf("%d\n\n\n", sizeof(int));
    printf("Entre a sua idade: ");
    scanf("%hd", &age);

    (age >= 18)
        ? printf("Com %hd voce ja pode ser preso.", age)
        : printf("Com %hd voce nem pode beber", age);

    return 0;
}