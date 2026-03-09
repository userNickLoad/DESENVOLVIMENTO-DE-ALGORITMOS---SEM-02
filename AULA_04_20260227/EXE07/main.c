#include <stdio.h>

struct User {
    char nome[50];
    char senha[20];
};

int main(void) {
    char ch;
    short nxt = 0, i = 0;
    struct User user;
    FILE * raw_dados;

    raw_dados = fopen("cadastro.txt", "r");

    if (raw_dados == NULL) {
        fprintf(stderr, "Nao foi possivel abrir o arquivo.");
        return -1;
    }

    while ((ch = fgetc(raw_dados)) != EOF) {
        if (ch == ';') {i=0; nxt++; continue;};

        switch (nxt) {
            case 0:
                user.nome[i] = ch;
                break;
            case 1:
                user.senha[i] = ch;
                break;
            default:
                break;
        }

        i++;
    }

    printf("Nome do usuario: %s; Senha do usuario: %s", user.nome, user.senha);

    fclose(raw_dados);

    return 0;
}