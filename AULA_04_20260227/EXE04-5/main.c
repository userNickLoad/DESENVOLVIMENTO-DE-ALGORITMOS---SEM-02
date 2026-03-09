#include <stdio.h>
#include <malloc.h>

typedef struct Node_d 
{
    struct Node_d *nxt;
    double value;
} Node_d;

typedef struct Node_c 
{
    struct Node_c *nxt;
    char value;
} Node_c;

union Nodes
{
    Node_d double_t;
    Node_c char_t;
};

typedef struct List
{
    int len;
    union Nodes *head;
    union Nodes *tail;
} List;

union db_cr
{
    double d;
    char c;
};

union Nodes * init_node()
{
    union Nodes *p = malloc(sizeof(union Nodes));

    if(p == NULL){
        fprintf(stderr, "Erro ao alocar o nodo.\n");
        
        return NULL;
    }

    p->double_t.nxt = NULL;
    p->double_t.value = 0;

    return p;
}

List * init_list(){
    List *p = malloc(sizeof(struct List));

    if(p == NULL){
        fprintf(stderr, "Erro ao alocar a list.\n");

        return NULL;
    }

    p->head = NULL;
    p->tail = NULL;
    p->len = NULL;

    return p;
}

int add_to_tail(List *p, union db_cr value)
{
    union Nodes *new_node = init_node();

    new_node->double_t.value = value.d;

    p->tail = new_node;

    if(p->len == 0) p->head = new_node;

    p->len++;

    return 1;
}

int remove_flist(List *p, int idx_start, int amount){
    if(idx_start + amount > p->len){
        fprintf(stderr, "Erro ao alocar a list.\n");
        return 0;
    }

    for(int i = 0; i <= idx_start; i++){

    }
}

int main(void) {
    char ops[16];
    double nums[16];
    char buff[101];
    int l_num = 0, l_op = 0;
    long num = 0l, float_dot = 1;

    for(int i = 0; i < 16; i++){
        ops[i] = '\0';
        nums[i] = 0;
    }

    printf("Calculadora 3000!\n\n");
    printf("\t - Regras:\n");
    printf("\t\t + As unicas operacoes aceitas sao +, -, * e /\n");
    printf("\t\t + Caso tenha x / 0, sera invalidada\n\n");

    printf("Coloque a sua expressao: ");
    scanf("%100s", buff);

    for (int i = 0; i<100; i++){
        if(buff[i] == ' ' || buff[i] == '\0') continue;

        if (('0' <= buff[i] && (int) buff[i] <= '9') || buff[i] == '.'){
            if(buff[i] != '.'){
                num *= 10;
                num += buff[i] - 48;
            }
            
            float_dot *= (buff[i] == '.' || float_dot > 1)? 10 : 1;
            continue;
        }

        if(num != 0){
            nums[l_num] = (double) num / ((float_dot > 1)? float_dot / 10 : 1);
            num = 0;
            float_dot = 1;
            l_num++;
        }

        if(buff[i] == '*' || buff[i] == '+' || buff[i] == '-' || buff[i] == '/'){
            ops[l_op] = buff[i];
            l_op++;
        } 

    }

    printf("Números obtidos = [ %f", nums[0]);
    for(int i = 1; i < l_num; i++){
        printf(", %f", nums[i]);
    }
    printf(" ].\n");

    printf("l_op: %d\n", l_op);
    printf("Sinais obtidos = [ %c", ops[0]);
    for(int i = 1; i < l_op; i++){
        printf(", %c", ops[i]);
    }
    printf(" ].\n");


    return 0;
}