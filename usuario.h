#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

typedef struct usuario Usuario;

Usuario* usu_cria (char* nome, int perfil, int id, char* login, char* senha);

void usu_imprime (Usuario* u);

void usu_edita (Usuario* u, char* nome, char* login, char* senha);

char* usu_nome (Usuario* u);

char* usu_login (Usuario* u);

char* usu_senha (Usuario* u);

int usu_perfil (Usuario* u);

int usu_id (Usuario* u);

void usu_libera(Usuario* u);

#endif // USUARIO_H_INCLUDED
