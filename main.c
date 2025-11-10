/*
------------------------------------------------------------
Trabalho da N2 – Algoritmos I
Aluno: Luca Guerreiro Ramos
Professor: Alessandro João Brassanini
Curso: Bacharelado em Sistemas de Informação
------------------------------------------------------------
Descrição:
Uma loja pretende simular um dia de suas vendas.
Os preços dos produtos variam de R$5,00 a R$100,00.
Cada cliente compra apenas um produto.
------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i;
    int produtos[200];       // Armazena preços dos produtos (em reais)
    int compras[50];         // Armazena qual produto cada cliente comprou
    int numProdutos;         // Quantos produtos existem
    int numClientes;         // Quantos clientes compraram
    int opcao;
    float totalVendas = 0;

    srand(time(NULL)); // semente para gerar números aleatórios diferentes

    do {
        printf("=============================================\n");
        printf("         SISTEMA DE VENDAS - SIMULADOR       \n");
        printf("=============================================\n");
        printf("    Desenvolvido por: Luca Guerreiro Ramos   \n");
        printf("=============================================\n");
        printf("1 - Gerar produtos e vendas automaticamente\n");
        printf("2 - Mostrar relatório das vendas\n");
        printf("3 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        printf("\n");

        if (opcao == 1) {
            // Gera número aleatório de produtos e clientes
            numProdutos = (rand() % 200) + 1; // entre 1 e 200
            numClientes = (rand() % 50) + 1;  // entre 1 e 50

            // Gera preços aleatórios entre 5 e 100
            for (i = 0; i < numProdutos; i++) {
                produtos[i] = (rand() % 96) + 5; // 5 a 100
            }

            // Gera as compras aleatórias
            for (i = 0; i < numClientes; i++) {
                compras[i] = rand() % numProdutos; // índice de produto
            }

            printf("Produtos e vendas gerados com sucesso!\n\n");
        }

        else if (opcao == 2) {
            if (numProdutos == 0 || numClientes == 0) {
                printf("Primeiro gere os produtos e as vendas (opção 1)!\n\n");
            } else {
                printf("========== RELATÓRIO DO DIA ==========\n");
                printf("Total de produtos disponíveis: %d\n", numProdutos);
                printf("Total de clientes atendidos: %d\n\n", numClientes);

                for (i = 0; i < numClientes; i++) {
                    int prod = compras[i];
                    printf("Cliente %d comprou o produto %d (R$ %d)\n",
                           i + 1, prod + 1, produtos[prod]);
                    totalVendas += produtos[prod];
                }

                printf("\n--------------------------------------\n");
                printf("TOTAL ARRECADADO: R$ %.2f\n", totalVendas);
                printf("--------------------------------------\n\n");

                totalVendas = 0; // zera para nova simulação
            }
        }

        else if (opcao == 3) {
            printf("Encerrando o programa... Até logo, Luca!\n");
        }

        else {
            printf("Opção inválida! Tente novamente.\n\n");
        }

    } while (opcao != 3);

    return 0;
}
