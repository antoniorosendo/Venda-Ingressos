# Venda de Ingressos de Shows em C
Este é um projeto simples de linha de comando desenvolvido em C puro para gerenciar a venda de ingressos e informações de shows. Ele oferece funcionalidades básicas para cadastro, alteração, exclusão e listagem de shows, além de permitir a compra de ingressos.

## Visão Geral
O programa armazena os dados dos shows em um arquivo de texto (shows.txt), garantindo a persistência das informações mesmo após o encerramento do aplicativo. É uma aplicação leve e direta, ideal para demonstrações de gerenciamento de dados em arquivos.

## Funcionalidades
- Comprar Ingresso: Permite que os usuários selecionem um show e comprem uma quantidade específica de ingressos, atualizando a disponibilidade.
- Gerenciar Shows:
- Cadastrar Shows: Adicione novos shows com código, nome, artista, data e quantidade inicial de ingressos.
- Excluir Shows: Remova shows existentes pelo código.
- Alterar Shows: Modifique os detalhes de um show, incluindo nome, artista, data e número de ingressos.
- Listar Shows: Exibe todos os shows cadastrados com suas informações detalhadas e ingressos disponíveis.

## Tecnologias Utilizadas
- Linguagem: C (puro)
- Persistência de Dados: Arquivos de texto (.txt)

## Como Compilar e Executar
**Pré-requisitos:**
- Um compilador C (como GCC).

## Clonar o Repositório:
git clone https://github.com/antoniorosendo/Venda-Ingressos

## Compilar:
Você pode compilar o programa usando o GCC diretamente:
- gcc main.c shows.c -o VendaIngressos

## Executar:
./VendaIngressos

## Estrutura do Projeto
- main.c: Contém a função principal e o menu de interação com o usuário.
- shows.h: Define a estrutura Show e as declarações das funções de gerenciamento de shows.
- shows.c: Contém a implementação das funções de gerenciamento (cadastro, exclusão, alteração, listagem e compra).
- shows.txt: Arquivo de texto onde os dados dos shows são armazenados.
- VendaIngressos: O arquivo executável compilado.
