#include <stdio.h>
#include <stdlib.h>
#include "shows.h"

int main() 
{
    int n;
    
    do
    {
        printf("-------------------------------------------------------\n");
        printf("|             VENDA DE INGRESSOS DE SHOW              |\n");
        printf("-------------------------------------------------------\n");
        printf("|(1) Comprar ingresso                                 |\n");
        printf("|(2) Gerenciar shows                                  |\n");
        printf("|(3) Lista de shows                                   |\n");
        printf("|(0) Sair                                             |\n");
        printf("-------------------------------------------------------\n\n");
        printf("Selecione a funcao que deseja acessar: ");
        scanf("%d", &n);
        getchar();
    
        switch (n) 
        {
            case 1:
                comprarIngresso();
                break;
            case 2:
                gerenciador();
                break;
            case 3:
                listarShows();
                break;
            case 0:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (n != 0);

    return 0;
}
