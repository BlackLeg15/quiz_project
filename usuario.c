#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "interacao.h"

struct usuario{
    char nome[51];
    int perfil;
    int id;
    char login[21];
    char senha[21];
};

Usuario* usu_cria (char* nome, int perfil, int id, char* login, char* senha)
{
    Usuario* u = (Usuario*) malloc(sizeof(Usuario));
    if(u == NULL){
        printf("Memória insuficiente - 'usu_cria' - programa sendo fechado!\n");
        exit(1);
    }
    strcpy(u->nome, nome);
    u->perfil = perfil;
    u->id = id;
    strcpy(u->login, login);
    strcpy(u->senha, senha);
    return u;
}

void usu_imprime (Usuario* u)
{
    if(u->perfil == 1)
        printf("Nome: %s\tLogin: %s\nPerfil: Aluno\n");
    else
        printf("Nome: %s\tLogin: %s\nPerfil: Professor\n");
}

void usu_edita (Usuario* u, char* nome, char* login, char* senha)
{
    strcpy(u->nome, nome);
    strcpy(u->login, login);
    strcpy(u->senha, senha);
}

char* usu_nome (Usuario* u)
{
    return u->nome;
}

char* usu_login (Usuario* u)
{
    return u->login;
}

char* usu_senha (Usuario* u)
{
    return u->senha;
}

int usu_perfil (Usuario* u)
{
    return u->perfil;
}

int usu_id (Usuario* u)
{
    return u->id;
}

void usu_libera(Usuario* u)
{
    free(u);
}
