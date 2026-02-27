#include <stdio.h>

#include <malloc.h>

typedef struct Node{
    float value;
    char op;
    unsigned int looseness_right;
    unsigned int looseness_left;
    struct Node *left;
    struct Node *right;
} Node;

Node * init_node() {
    Node * p = malloc(sizeof(Node));

    if (p == NULL) {
        fprintf(stderr, "Não foi possivel alocar o nodo.");
        return NULL;
    }

    p->left = NULL;
    p->right = NULL;
    p->value = 0;
    p->op = '\0';
    p->looseness_left = 0xffffffff;
    p->looseness_right = 0xffffffff;

    return p;
}

int loose_nodes(Node *node) {
    Node * right = node->right;
    Node * left = node->left;
    if (right == NULL && left == NULL && node->op == '\0') return 0;

    if (node->looseness_left != 0xffffffff && node->looseness_left != 0xffffffff)
        return node->looseness_left + node->looseness_left;

    int go_left, go_right;

    if (right != NULL) {
        go_right = loose_nodes(right);
    }

    if (left != NULL) {
        go_left = loose_nodes(left);
    }

    return go_right + go_left;
}

int main(void) {
    char buff[101];

    printf("Calculadora 3000!\n\n");
    printf("\t - Regras:\n");
    printf("\t\t + As unicas operacoes aceitas sao +, -, * e /\n");
    printf("\t\t + Caso tenha x / 0, sera invalidada\n\n");

    printf("Coloque a sua expressao: ");
    scanf("%100s", buff);

    Node * initial_node = init_node();

    Node * crr = initial_node;

    float num = 0;

    // Organiza operações
    for (int i = 0; i < 100; i++) {
        if (buff[i] == ' ') continue;

        if (48 <= (int) buff[i] && (int) buff[i] <= 57) {
            num *= 10;
            num += 48 + (int) buff[i];
            continue;
        }

        if (num != 0) {
            Node *new_node = init_node();
            new_node->value = num;

        }

        if (buff[i] == '+' || buff[i] == '-' || buff[i] == '*' || buff[i] == '/') {
            Node *new_node = init_node();
            new_node->op = buff[i];
            new_node->left = crr;
            initial_node = new_node;


        }
    }



    return 0;
}