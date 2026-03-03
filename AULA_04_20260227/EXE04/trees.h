
typedef union  cf{
    float f;
    char c;
} cf;

typedef struct Node{
    cf value;
    // unsigned int looseness_right;
    // unsigned int looseness_left;
    struct Node *left;
    struct Node *right;
} Node;


Node * init_node();

Node * num_to_tree(Node * node, float num);

Node * op_to_tree(Node * node, char op);

float calculate(Node * crr);