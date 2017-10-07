#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sistema.h"
#include "usuario.h"
#include "interacao.h"

struct arv{
    ArvNo* raiz;
};

struct arvno{
    Usuario* usuario;
    ArvNo* esq;
    ArvNo* dir;
};

Sistema* sis_cria()
{
    Sistema* s = (Sistema*) malloc(sizeof(Sistema));
    if(s == NULL){
        printf("Memória insuficiente - 'sis_cria' - programa sendo fechado!\n");
        exit(1);
    }
    s->raiz = NULL;
    return s;
}

static ArvNo* insere(ArvNo* a, Usuario* u)
{
    if(a == NULL){
        ArvNo* a = (ArvNo*) malloc(sizeof(ArvNo*));
        if(a == NULL){
            printf("erro - 'insere'\n");
            exit(1);
        }
        a->usuario = u;
        a->esq = NULL;
        a->dir = NULL;
        return a;
    }
    else if(strcmp(usu_nome(u), usu_nome(a->usuario)) < 0)
        a->esq = insere(a->esq, u);
    else if(strcmp(usu_nome(u), usu_nome(a->usuario)) > 0)
        a->dir = insere(a->dir, u);
    return a;
}

void sis_insere (Sistema* s, Usuario* u)
{
    s->raiz = insere(s->raiz, u);
}

static ArvNo* busca (ArvNo* r, char* nome)
{
    if(r != NULL){
        if(strcmp(nome, usu_nome(r->usuario)) > 0)
            return busca(r->dir, nome);
        else if(strcmp(nome, usu_nome(r->usuario)) < 0)
            return busca(r->esq, nome);
        else
            return r;
    }
    return NULL;
}

ArvNo* sis_busca (Sistema* s, char* nome)
{
    return busca(s->raiz, nome);
}

static ArvNo* retira (ArvNo* r, char* nome)
{
    if(r == NULL)
        return NULL;
    else if(strcmp(nome, usu_nome(r->usuario)) < 0)
        r->esq = retira(r->esq, nome);
    else if(strcmp(nome, usu_nome(r->usuario)))
        r->dir = retira(r->dir, nome);
    else{ //achou o no com 'v'
        if(r->esq == NULL && r->dir == NULL){//se for uma folha
            usu_libera(r->usuario);
            free(r);                         // apenas libera o no e retorna NULL
            r = NULL;
        }
        else if(r->esq == NULL){             //se tiver apenas um filho a direita
            ArvNo* aux = r;                  //esse filho troca de lugar com ele e libera o no "pai"
            r = r->dir;
            free(aux);
        }
        else if(r->dir == NULL){             //se tiver apenas um filho a esquerda
            ArvNo* aux = r;                  //esse filho troca de lugar com ele e libera o no "pai"
            r = r->esq;
            free(aux);
        }
        else{                               //se o no tiver dois filhos
            ArvNo* f = r->esq;
            while(f->dir != NULL){          //busca o no mais a direita da subarvore a esquerda dele
                f = f->dir;
            }
            Usuario* aux = r->usuario;
            r->usuario = f->usuario;
            f->usuario = aux;
            r->esq = retira(r->esq, nome);     //remove o no com o valor 'v' da subarvore esquerda
        }                                   //retorna o novo no
    }
    return r;
}

void sis_remove (Sistema* s, char* nome)
{
    s->raiz = retira(s->raiz, nome);
}

void sis_edita (ArvNo* no, char* nome, char* login, char* senha)
{
    usu_edita(no->usuario, nome, login, senha);
}

static void imprime (ArvNo* r)
{
    if(r != NULL){
        imprime(r->esq);
        usu_imprime(r->usuario);
        imprime(r->dir);
    }
}

void sis_imprime (Sistema* s)
{
    imprime(s->raiz);
}

static void salva (FILE* fp, ArvNo* r)
{
    if(r != NULL){
        salva(fp, r->esq);
        fprintf(fp, "%s\t%d\t%d\t%s\t%s\n", usu_nome(r->usuario), usu_perfil(r->usuario), usu_id(r->usuario), usu_login(r->usuario), usu_senha(r->usuario));
        salva(fp, r->dir);
    }
}

void sis_salva (FILE* fp, Sistema* s)
{
    salva(fp, s->raiz);
}

void imprime_usuario (ArvNo* no)
{
    usu_imprime(no->usuario);
}

char** dados_antigos (ArvNo* no)
{
    int l = strlen(usu_login(no->usuario));
    int s = strlen(usu_senha(no->usuario));

    char** dados_usuario = (char**) malloc(2*sizeof(char));
    dados_usuario[0] = (char*) malloc((l+1)*sizeof(char));
    dados_usuario[1] = (char*) malloc((s+1)*sizeof(char));

    int i;
    for(i = 0; i < 2; i++){
        if(dados_usuario[i] == NULL){
            printf("\n\tMemória insuficiente!\n");
            exit(1);
        }
    }
    strcpy(dados_usuario[0], usu_login(no->usuario));
    strcpy(dados_usuario[1], usu_senha(no->usuario));

    return dados_usuario;
}

char* info_nada_consta (void)
{
    char aux[] = "N/C";
    int n = strlen(aux);
    char* st = (char*) malloc((n+1)*sizeof(char));
    strcpy(st, aux);
    return st;
}


void realiza_cadastro(Sistema* s)
{
    printf("Digite seu nome: ");
    char* n = le_string();
    printf("Digite seu login: ");
    char* l = le_string();
    printf("Digite sua senha: ");
    char* pass = le_string();
    printf("Digite seu CPF: ");
    int i;
    scanf("%d", &i);
    printf("Qual seu perfil?\nDigite (1) para aluno e (2) para professor: ");
    int p;
    scanf("%d", &p);
    Usuario* u = usu_cria(n, p, i, l, pass);
    sis_insere(s, u);
    printf("Usuário cadastrado!\n");
    system("pause");
}
