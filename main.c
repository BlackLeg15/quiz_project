#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "interacao.h"

int main()
{
    setlocale(LC_ALL, "");
    unsigned char op;
    unsigned int saida = 0;

    do {
        apresenta_menu(N_OPCOES, OPCAO1,
                      TITULO_OPCAO1, TITULO_OPCAO2,
                      TITULO_OPCAO3);
        op = le_opcao(OPCAO1, OPCAO1 + N_OPCOES - 1);
        switch(op) {
            case OPCAO1:




                break;
            case OPCAO2:




                break;
            case OPCAO3:
                saida = 1;
                break;
            default:
                printf("Este programa possui um bug.");
                return 1;
        }
    } while(!saida);
    return 0;
}
