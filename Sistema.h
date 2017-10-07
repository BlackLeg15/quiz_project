#ifndef SISTEMA_H_INCLUDED
#define SISTEMA_H_INCLUDED

#include "usuario.h"

typedef struct arv Sistema;

typedef struct arvno ArvNo;

Sistema* sis_cria (void);

ArvNo* sis_busca (Sistema* s, char* nome);

void sis_insere (Sistema* s, Usuario* u);

void sis_remove (Sistema* s, char* nome);

void sis_edita (ArvNo* no, char* nome, char* login, char* senha);

void sis_imprime (Sistema* s);

void sis_salva (FILE* fp, Sistema* s);

void imprime_usuario (ArvNo* usuario);

char** dados_antigos (ArvNo* no);

char* info_nada_consta (void);

void realiza_cadastro (Sistema* s);

#endif // SISTEMA_H_INCLUDED
