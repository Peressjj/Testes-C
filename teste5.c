#include <stdio.h>

int main() { // chave fechada
    char nome[30][50]; // 30 clientes, 50 caracteres cada
    int idade[30];
    float altura[30];

    int total = 0;
    int opcao = 0;
    int limite = 3;

    while (opcao != 3) { // chave fechada

        printf("\n======= MENU =======\n");
        printf("(1) - Cadastrar clientes\n");
        printf("(2) - Mostrar clientes\n");
        printf("(3) - Sair\n");
        printf("ESCOLHA (apenas números)");
        scanf("%d", &opcao);
        getchar(); // Limpa o "ENTER" do teclado

        if (opcao == 1) { // 1 chave fechada

            if (total < limite) { // 2 chave fechada

                printf("Cadastro de cliente:\n");

                printf ("\nInsira seu nome: ");
                scanf("%49s", nome[total]);
                printf("\nNOME: %s", nome[total]);

                printf("\nInsira sua idade: ");
                scanf("%d", &idade[total]);
                printf("\nIDADE: %d", idade[total]);

                printf("\nInsira sua altura: ");
                scanf("%.2f", &altura[total]);
                printf("\nALTURA: %.2f", altura[total]);

                printf("\nCliente %s adastrado com sucesso!", nome[total]);
                total++;
            } // chave if 2
            else { // else 2

                printf("\nLimite de clientes cadastrados atingido.");    
            }

        } // chave if 1        
        else if (opcao == 2) { // chave elif do if 1

            if (total == 0) { // 3 chave fechada
                printf("\nNenhum cliente cadastradado");
            } // chave do if 3
            
            else { // 3 else do if 3 

                printf("\nLista de clientes");
                for (int i = 0; i < total; i++) { // chave for fechada

                    printf("\nCLIENTE: %s", nome[i]);
                    printf("\nIDADE: %d", idade[i]);
                    printf("\nALTURA: %.2f", altura[i]);

                } // chave do for
            } //chave else 2      
        } // chave do else if
        else if (opcao == 3) { //chave else if 2 fechada

            printf("\n======= ENCERRANDO PROGRAMA =======");
        } //chave else if 2    

        else { //chave else 4 fechada
            printf("======= OPCAO INVÁLIDA =======");
        } // chave else 4
    } // chave while

    return 0;
} // chvae main