#ifndef INTERACAO_H_INCLUDED
#define INTERACAO_H_INCLUDED

#define TITULO_OPCAO1 "Fazer Login"
#define TITULO_OPCAO2 "Ver Ranking"
#define TITULO_OPCAO3 "Sair"

#define N_OPCOES 3
#define OPCAO1 '1'
#define OPCAO2 '2'
#define OPCAO3 '3'

void apresenta_programa(char* msg);

void mensagem_despedida(char* msg);

void limpa_tela(void);

void limpa_buffer(void);

int le_opcao(int menor_valor, int maior_valor);

char* le_string(void);

void apresenta_menu(int n_itens, int menor_opcao, ...);

#endif // INTERACAO_H_INCLUDED
