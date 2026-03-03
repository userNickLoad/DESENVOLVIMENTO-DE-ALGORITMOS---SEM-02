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
    Node * right = node->left->right;
    node->left->right = node;
    node->left = right;

    return node;
};

Node * num_to_tree(Node * node, float num){
    Node * new_node = init_node();

    new_node->value.f = num;

    if(node == NULL){
        return new_node;
    }

    if(node->left == NULL) node->left = new_node;

    if(node->right == NULL) node->right = new_node;

    return node;
};

Node * op_to_tree(Node * node, char op){

    Node * new_node = init_node();

    new_node->value.c = op;

    if(node == NULL){
        fprintf(stderr, "Não é possivel começar a conta com um sinal.");
        return NULL;
    }

   if (op == '+' || op == '-'){
        new_node->left = node;
        return new_node;
   }

   if(op == '*' || op == '/'){
        new_node->left = node;
        return rotateRight(new_node);
   }

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