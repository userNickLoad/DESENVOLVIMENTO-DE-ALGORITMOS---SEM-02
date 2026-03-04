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

    printf("New number: %f\n\n", new_node->value.f);

    if(node == NULL){
        return new_node;
    }

    if(node->left == NULL) node->left = new_node;

    if(node->right == NULL) node->right = new_node;

    if(node->value.c == '*' || node->value.c == '/')
    return rotateRight(node);

    return node;
};

Node * op_to_tree(Node * node, char op){

    Node * new_node = init_node();

    new_node->value.c = op;

    printf("New op: %c\n\n", new_node->value.c);

    if(node == NULL){
        fprintf(stderr, "Não é possivel começar a conta com um sinal.");
        return NULL;
    }

    new_node->left = node;
    return new_node;

}

float calculate(Node * crr){
    printf("Nodo: %f\n", crr->value.f);

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
        right += left;
        break;

    case '-':
        right -= left;
        break;

    case '*':
        right *= left;
        break;

    case '/':
        right /= left;
        break;
    
    default:
        printf("Deu bosta CARALHOOOOOO\n");
        break;
    }

    free(crr);
    return right;
};