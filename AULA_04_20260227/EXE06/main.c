#include <stdio.h>
#include <malloc.h>

int main(void) {
    unsigned short amount;

    printf("Coloque a quantidade da entrada: ");
    scanf("%hu", &amount);

    int * nums = malloc(sizeof(int) * amount);

    if (nums == NULL) {
        fprintf(stderr, "Nao foi possivel alocar a lista para os %d numeros", amount);
        return -1;
    }

    for (int i = 0; i < amount; i++) {
        printf("Entre o seu %d numero da sequencia: ", i+1);
        scanf("%d", &nums[i]);
        printf("\n\n");
    }

    for (int i = 1; i<=amount; i++) {
        for (int p = 1; p<=amount-i; p++) {
            if (nums[p-1] > nums[p]) {
                int temp = nums[p];
                nums[p] = nums[p-1];
                nums[p-1] = temp;
            }
        }
    }

    printf("O maior numero eh %d e o menor eh %d.\n\n", nums[0], nums[amount-1]);

    printf("nums = {%d", nums[0]);
    for (int i = 0; i<amount; i++) {
        printf(", %d", nums[i]);
    }
    printf("};\n");

    free(nums);

    return 0;
}