#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[50]; //50 caracteres cada
    int idade;
    float altura;
} Cliente;

Cliente clientes[4];

int main() {

    int total = 0;
    int opcao = 0;
    int limite = 3;

    while (opcao != 3) {

        printf("\n======= MENU =======\n");
        printf("(1) - Cadastrar clientes\n");
        printf("(2) - Mostrar clientes\n");
        printf("(3) - Sair\n");
        printf("ESCOLHA (apenas números)");
        scanf("%d", &opcao);
        
        switch (opcao){

        case 1:
            if (total < limite){

                Cliente novo_cliente;

                printf("Cadastro de cliente:\n");
                printf ("\nInsira seu nome: ");
                scanf("%49s", novo_cliente.nome);

                printf("\nNOME: %s,", novo_cliente.nome);
                printf("\nInsira sua idade: ");
                scanf("%d", &novo_cliente.idade);

                printf("\nIDADE: %d", novo_cliente.idade);
                printf("\nInsira sua altura: ");
                scanf("%f", &novo_cliente.altura);
                printf("\nALTURA: %.2f", novo_cliente.altura);

                clientes[total]=novo_cliente;
                
                printf("\nCliente %s cadastrado com sucesso!", novo_cliente.nome); //confirma cadastro

                total++;
            }else {
                printf("\nLimite de clientes cadastrados atingido.");    
            }
        break;

        case 2:
            if (total == 0) {
                printf("\nNenhum cliente cadastradado");
            }else{
                printf("\nLista de clientes");

                for (int i = 0; i < total; i++){
                    printf("\nCLIENTE: %s", clientes[i].nome);
                    printf("\nIDADE: %d", clientes[i].idade);
                    printf("\nALTURA: %.2f", clientes[i].altura);
                }
            }
        break;

        case 3:
            printf("\n======= ENCERRANDO PROGRAMA =======");
        break;
        
        default:
            printf("======= OPCAO INVÁLIDA =======");
        break;
        }
    }

    return 0;
}