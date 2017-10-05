#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

struct usuario{
    char nome[51];
    int perfil;
    int id;
    char login[21];
    char senha[21];
};

Usuario* usu_cria(char* nome, int perfil, int id, char* login, char* senha)
{
    Usuario* u = (Usuario*) malloc(sizeof(Usuario));
    if(u == NULL){
        printf("Memoria insuficiente - 'usu_cria' - programa sendo fechado!\n");
        exit(1);
    }
    strcpy(u->nome, nome);
    u->perfil = perfil;
    u->id = id;
    strcpy(u->login, login);
    strcpy(u->senha, senha);
    return u;
}

void realiza_cadastro()
{
    printf("Digite seu nome: ");
}
