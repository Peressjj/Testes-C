#include <stdio.h>
// struct

/* O sistema calcula media de precos e maior preco do 
catalogo de produtos */

    typedef struct Produto {
        char nome[50];
        float preco;
        int quantidade;
    } Produto;
    Produto listaproduto[5] = {
        {"Produto 1", 1.11, 1},
        {"Produto 2", 2.22, 2},
        {"Produto 3", 3.33, 3},
        {"Produto 4", 4.44, 4},
        {"Produto 5", 5.55, 5},
    };
    

int main() {

    int opcao;
    while (opcao != 0) {
        printf("|   1 - Mostrar produtos:\n");
        printf("|                        \n");
        printf("|   2 - Exibir produto com maior preco.\n");
        printf("|                        \n");
        printf("|   3 - Exibir preco médio dos produtos:\n");
        printf("|                        \n");
        printf("|   0 - Sair.\n");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            for (int i = 0; i < 5; i++) {
                printf("Produto: %s\nValor: %.2f\nQuantidade: %d\n\n", listaproduto[i].nome, listaproduto[i].preco, listaproduto[i].quantidade);
            }    
            printf("\n\n");
        break;

        case 2: 
            float maior;
            maior = listaproduto[0].preco;
            for (int i = 0; i < 5; i++) {
                if (listaproduto[i].preco > maior) {
                    maior = listaproduto[i].preco;
                }
            }
            printf("Maior preco: %.2f\n\n", maior);
        break;

        case 3:
            printf("Preco dos produtos:\n");
            float total = 0;
            for (int i = 0; i < 5; i++) {
                printf("R$%.2f\n", listaproduto[i].preco);
                total += listaproduto[i].preco;
            }
            printf("\n\nMédia final: %.2f\n\n", (total / 5));
        break;
        
        default:
            printf("Opcao inválida.\n");
        break;
        }
    }

    printf("\nPrograma encerrado.\n\n");
    





}