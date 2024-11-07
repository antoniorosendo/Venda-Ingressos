#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shows.h"

#define ARQUIVO "shows.txt"

//funcao para gerenciar outras funces
void gerenciador()
{
    int nG;
        printf("-------------------------------------------------------\n"); 
        printf("|              GERENCIAMENTO DE SHOWS                 |\n");
        printf("-------------------------------------------------------\n");
        printf("|SELECIONE A FUNCAO QUE DESEJA:                       |\n");
        printf("|(1) Cadastrar shows                                  |\n");
        printf("|(2) Excluir shows                                    |\n");
        printf("|(3) Alterar shows                                    |\n");
        printf("|(0) Retornar                                         |\n");
        printf("-------------------------------------------------------\n");
        printf("Selecione a funcao que deseja acessar: ");
        scanf("%d", &nG);

        switch (nG) 
        {
            case 1:
                cadastrarShow();
                break;
            case 2:
                excluirShow();
                break;
            case 3:
                alterarShow();
                break;
            case 0:
                break;
            default:
                printf("Funcao invalida.\n");
        }
}

// Funcao para cadastrar um show
void cadastrarShow() 
{
    char resp;
    FILE *arquivo = fopen(ARQUIVO, "ab"); // Abre para adicionar no final do arquivo
    if (arquivo == NULL) 
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

        Show show;
        int igual = 0; // Marca se encontrar um show com o mesmo codigo
        int cod_aux; // Guarda o código temporário para a verificação

        // Lê o código do show
    do 
    {
        printf("\nCodigo do Show: ");
        scanf("%d", &cod_aux);

        // Verifica se o codigo é valido (não pode ser 0)
        if (cod_aux == 0) 
        {
            printf("O codigo do show não pode ser 0. Insira um novo codigo.\n");
            igual = 1;  // Marca para repetir o loop
        } 
        else 
        {
            igual = 0;  // Reseta a flag de erro
            
            // Verifica se ja existe um show com esse mesmo codigo
            FILE *arquivo_temp = fopen(ARQUIVO, "rb");  // Abre para leitura
            if (arquivo_temp == NULL) 
            {
                printf("Erro ao abrir o arquivo para leitura.\n");
                fclose(arquivo);
                return;
            }

            while (fscanf(arquivo_temp, "%d|%49[^|]|%49[^|]|%19[^|]|%d\n", &show.codigo, show.nome, show.artista, show.data, &show.ingressos) != EOF) 
            {
                if (cod_aux == show.codigo) 
                {
                    printf("Ja existe um show com o mesmo codigo. Insira um novo codigo.\n");
                    igual = 1;  // Marca para repetir o loop
                    break;  // Sai do loop se encontrar codigo duplicado
                }
            }

            fclose(arquivo_temp);  // Fecha o arquivo temporario
            }
        } while (igual == 1);

        show.codigo = cod_aux;

        // Lê os outros dados do show
        getchar();  // Limpa o buffer após scanf
        printf("Nome do Show: ");
        fgets(show.nome, sizeof(show.nome), stdin);
        strtok(show.nome, "\n"); // Remove o \n do final da string

        printf("Artista/Banda: ");
        fgets(show.artista, sizeof(show.artista), stdin);
        strtok(show.artista, "\n");

        printf("Data do Show: ");
        fgets(show.data, sizeof(show.data), stdin);
        strtok(show.data, "\n");

        printf("Quantidade de ingressos disponiveis: ");
        scanf("%d", &show.ingressos);

        // Escreve no arquivo
        fprintf(arquivo, "%d|%s|%s|%s|%d\n", show.codigo, show.nome, show.artista, show.data, show.ingressos);
        printf("Show cadastrado com sucesso!\n\n");

    fclose(arquivo);
}

// Funcao para excluir um show
void excluirShow() 
{
    int codigo;
    char resp;
    
    do
    {
        printf("\nCodigo do Show para excluir: ");
        scanf("%d", &codigo);
        getchar();

        FILE *arquivo = fopen(ARQUIVO, "r");
        FILE *temp = fopen("temp.txt", "w");
        if (arquivo == NULL || temp == NULL) 
        {
            printf("Erro ao abrir o arquivo.\n");
            return;
        }

        Show show;
        int encontrado = 0; // Marca se o show foi encontrado
        while (fscanf(arquivo, "%d|%49[^|]|%49[^|]|%19[^|]|%d\n", &show.codigo, show.nome, show.artista, show.data, &show.ingressos) != EOF) 
        {
            if (show.codigo != codigo) 
            {
                fprintf(temp, "%d|%s|%s|%s|%d\n", show.codigo, show.nome, show.artista, show.data, show.ingressos);
            } 
            else 
            {
                encontrado = 1; // Marca se o show foi encontrado
            }
        }
        fclose(arquivo);
        fclose(temp);
        remove(ARQUIVO);
        rename("temp.txt", ARQUIVO);

        if (encontrado == 1) 
        {
           printf("Show excluido com sucesso!\n");
        } 
        else 
        {
            printf("Show nao encontrado.\n");
        }
        
        printf("\n - Deseja excluir outro show? [S]im ou [N]ao: ");
        resp = getchar();
        getchar();
        
    } while(resp == 'S' || resp == 's');

}

// Funcao para alterar um show
void alterarShow() 
{
    int codigo;
    char resp;
    
    do
    {
        printf("\nCodigo do Show para alterar: ");
        scanf("%d", &codigo);
        getchar();

        FILE *arquivo = fopen(ARQUIVO, "r");
        FILE *temp = fopen("temp.txt", "w");
        if (arquivo == NULL || temp == NULL) 
        {
            printf("Erro ao abrir o arquivo.\n");
            return;
        }
        Show show;
        int encontrado = 0; // Marca se o show for encontrado
        while (fscanf(arquivo, "%d|%49[^|]|%49[^|]|%19[^|]|%d\n", &show.codigo, show.nome, show.artista, show.data, &show.ingressos) != EOF) 
        {
            if (show.codigo == codigo) 
            {
                encontrado = 1; // Marca se o show for encontrado
                printf("Novo Nome do Show: ");
                getchar();
                fgets(show.nome, sizeof(show.nome), stdin);
                strtok(show.nome, "\n"); //Remove o \n do final da string
    
                printf("Novo Artista/Banda: ");
                fgets(show.artista, sizeof(show.artista), stdin);
                strtok(show.artista, "\n");
    
                printf("Nova Data do Show: ");
                fgets(show.data, sizeof(show.data), stdin);
                strtok(show.data, "\n");
    
                printf("Nova Quantidade de ingressos disponiveis: ");
                scanf("%d", &show.ingressos);
                getchar();
            }
            fprintf(temp, "%d|%s|%s|%s|%d\n", show.codigo, show.nome, show.artista, show.data, show.ingressos);
        }
    
        fclose(arquivo);
        fclose(temp);
        remove(ARQUIVO);
        rename("temp.txt", ARQUIVO);
    
        if (encontrado == 1) 
        {
            printf("Show alterado com sucesso!\n");
        } 
        else 
        {
            printf("Show nao encontrado.\n");
        }
        
        printf("\n - Deseja alterar outro show? [S]im ou [N]ao: ");
        resp = getchar();
        getchar();
        
    } while(resp == 'S' || resp == 's');
}

// Funcao para listar todos os shows
void listarShows() 
{
    FILE *arquivo = fopen(ARQUIVO, "r");
    if (arquivo == NULL) 
    {
        printf("Nenhum show cadastrado.\n");
        return;
    }

    Show show;
    printf("LISTA DE SHOWS DISPONIVEIS:\n");
    printf("-------------------------------------------------------\n");
    while (fscanf(arquivo, "%d|%49[^|]|%49[^|]|%19[^|]|%d\n", &show.codigo, show.nome, show.artista, show.data, &show.ingressos) != EOF) 
    {
        printf("Codigo: %d\nNome: %s\nArtista/Banda: %s\nData: %s\nIngressos: %d\n", show.codigo, show.nome, show.artista, show.data, show.ingressos);
        printf("-------------------------------------------------------\n");
    }
    fclose(arquivo);
}

//funcao para comprar ingressos
void comprarIngresso()
{
    int cod_compra, n_ing; 
    char resp;
    
    do
    {
        printf("-------------------------------------------------------\n");
        printf("|             VENDA DE INGRESSOS DE SHOW              |\n");
        printf("-------------------------------------------------------\n");
        
        printf("\nDigite o codigo do show que deseja comprar: ");
        scanf("%d", &cod_compra);
        printf("Quantos ingressos deseja comprar? ");
        scanf("%d", &n_ing);
        getchar();
    
        FILE *arquivo = fopen("shows.txt", "r");
        FILE *temp = fopen("temp.txt", "w");
        
        if (arquivo == NULL || temp == NULL) 
        {
            printf("Erro ao abrir o arquivo.\n");
            return;
        }
    
        Show show;
        int encontrado = 0; // Marca se o show foi encontrado
        int compra = 0; // Marca se a compra pode ser realizada
    
        // Percorre o arquivo para buscar o show e atualizar o número de ingressos
        while (fscanf(arquivo, "%d|%49[^|]|%49[^|]|%19[^|]|%d\n", &show.codigo, show.nome, show.artista, show.data, &show.ingressos) != EOF) {
            if (show.codigo == cod_compra) 
            {
                encontrado = 1;
                if (show.ingressos <= 0) 
                {
                    printf("Nao ha mais ingressos disponiveis para este show.\n");
                    compra = 0;
                } 
                else if (show.ingressos < n_ing) 
                {
                    printf("Quantidade insuficiente de ingressos. Apenas %d ingressos disponiveis.\n", show.ingressos);
                    compra = 0;
                } 
                else 
                {
                    show.ingressos -= n_ing;
                    printf("Compra realizada com sucesso! Ingressos restantes: %d\n", show.ingressos);
                    compra = 1;
                }
            }
            
            // Escreve o show no arquivo temporario, com ingressos atualizados, se aplicavel
            fprintf(temp, "%d|%s|%s|%s|%d\n", show.codigo, show.nome, show.artista, show.data, show.ingressos);
        }
    
        fclose(arquivo);
        fclose(temp);
    
        // Substitui o arquivo original pelo arquivo temporario atualizado
        if ((encontrado && compra) != 0) 
        {
            remove("shows.txt");
            rename("temp.txt", "shows.txt");
        } 
        else if (encontrado == 0) 
        {
            printf("Show nao encontrado.\n");
            remove("temp.txt"); // Remove o arquivo temporario se o show nao for encontrado
        }
        
        printf("\n - Deseja comprar outro ingresso? [S]im ou [N]ao: ");
        resp = getchar();
        getchar();
        
    } while(resp == 'S' || resp == 's');
}
