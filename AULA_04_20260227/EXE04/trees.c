#include "trees.h"
#include <malloc.h>
#include <stdio.h>

Node * init_node() {
    Node * p = malloc(sizeof(Node));

    if (p == NULL) {
        fprintf(stderr, "Não foi possivel alocar o nodo.");
        return NULL;
    }

    p->left = NULL;
    p->right = NULL;
    p->value.f = 0;

    return p;
}

Node * rotateRight(Node* node){
    Node * left = node->left;
    node->left = left->right;
    left->right = node;

    return left;
};

Node * num_to_tree(Node * node, float num){
    Node * new_node = init_node();

    new_node->value.f = num;

    if(node == NULL){
        return new_node;
    }

    if(node->value.c == '/' && num == 0){
        fprintf(stderr, "qualquer x tal que x = n/0, com n sendo um numero real, eh indefinido.");
        return NULL;
    }

    if(node->left == NULL) node->left = new_node;

    if(node->right == NULL) node->right = new_node;

    if((node->value.c == '*' || node->value.c == '/') && (node->left->left != NULL && node->left->right != NULL))
    return rotateRight(node);

    return node;
};

Node * op_to_tree(Node * node, char op){

    Node * new_node = init_node();

    new_node->value.c = op;

    if(node == NULL){
        fprintf(stderr, "Não é possivel começar a conta com um sinal.");
        return NULL;
    }

    new_node->left = node;
    return new_node;

}

float calculate(Node * crr){

    if(crr->left == NULL && crr->right == NULL) {
        float result = crr->value.f;
        free(crr);
        return result;
    };

    float right, left;

    right = calculate(crr->right);
    left = calculate(crr->left);

    switch (crr->value.c)
    {
    case '+':
        left += right;
        break;

    case '-':
        left -= right;
        break;

    case '*':
        left *= right;
        break;

    case '/':
        left /= right;
        break;
    
    default:
        printf("Deu bosta CARALHOOOOOO\n");
        break;
    }

    free(crr);
    return left;
};