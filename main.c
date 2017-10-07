#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "interacao.h"
#include "Sistema.h"

int main()
{
    setlocale(LC_ALL, "");
    unsigned char op;
    unsigned int saida = 0;
    Sistema* sys = sis_cria();
    //FILE* cadastros = fopen("cadastros.txt", "rt");
    do {
        limpa_tela();
        apresenta_menu(N_OPCOES, OPCAO1,
                      TITULO_OPCAO1, TITULO_OPCAO2,
                      TITULO_OPCAO3);
        op = le_opcao(OPCAO1, OPCAO1 + N_OPCOES - 1);
        switch(op) {
            case OPCAO1:
                limpa_tela();
                realiza_cadastro(sys);
                break;
            case OPCAO2:
                limpa_tela();

                break;
            case OPCAO3:
                limpa_tela();
                mensagem_despedida("Se a montanha não vai à Maomé... é, ninguém liga.\n");
                saida = 1;
                break;
            default:
                printf("Este programa possui um bug.");
                return 1;
        }
    } while(!saida);
    return 0;
}
