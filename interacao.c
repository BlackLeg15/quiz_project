#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "interacao.h"

void apresenta_programa(char* msg)
{
    printf("%s\n", msg);
}

void mensagem_despedida(char* msg)
{
    printf("%s\n", msg);
    system("pause");
}

void limpa_tela(void)
{
    system("clear || cls");
}

void limpa_buffer(void)
{
    int valorLido;
    do {
        valorLido = getchar();
    } while ((valorLido != '\n') && (valorLido != EOF));
}

int le_opcao(int menor_valor, int maior_valor)
{
    int op;
    while (1) {
        printf("\nDigite sua opcão: ");
        op = getchar();
        if (op >= menor_valor && op <= maior_valor) {
            limpa_buffer();
            break;
        }
        else {
            printf("\nOpção inválida. Tente novamente.");
            printf("\nA opção deve estar entre %c e %c. \n", menor_valor, maior_valor);
            limpa_buffer();
        }
    }
    return op;
}

char* le_string(void)
{
    char aux[181];
    scanf(" %180[^\n]", aux);
    int n = strlen(aux);
    char* st = (char*) malloc((n+1)*sizeof(char));
    strcpy(st, aux);
    limpa_buffer();
    return st;
}

void apresenta_menu(int n_itens, int menor_opcao, ...)
{
    int i;
    va_list argumentos;
    va_start(argumentos, menor_opcao);
    for(i = 0; i < n_itens; ++i)
        printf("%c-%s\n", menor_opcao++, va_arg(argumentos, char *));
    va_end(argumentos);
}

