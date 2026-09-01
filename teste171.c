//30.05.26
#include <stdio.h>
#include <stdlib.h>
// realoc

typedef struct ddclientes {
    char nome[50];
    int idade;
    float altura;
} ddclientes;

    int opcao = -1;
    ddclientes *clientes;
    int tamanho = 0;

void menu() {

    printf("------------------------------------------\n");
    printf("|                                       | \n");
    printf("|   1 - Cadastrar cliente.              | \n");
    printf("|                                       | \n");
    printf("|   2 - Exibir lista de clientes.       | \n");
    printf("|                                       | \n");
    printf("|   0 - Sair.                           | \n");
    printf("|                                       | \n");
    printf("------------------------------------------\n");

}

void cadastrarcliente() {

    tamanho++;
    clientes = realloc(clientes, tamanho * sizeof(ddclientes));

    if (clientes == NULL) {
        printf("Erro ao alocar memória.\n");
    }

    printf("insira o nome do cliente: ");
    getchar();
    fgets(clientes[tamanho - 1].nome, 50, stdin);
    printf("Insira a idade do cliente: ");
    scanf("%d", &clientes[tamanho - 1].idade);
    printf("Insira a altura do cliente: ");
    scanf("%f", &clientes[tamanho - 1].altura);

    printf("Cliente cadastrado com sucesso!\n");

}

void exibemenucliente() {

            printf("\n------------------------------------------\n");
            printf("|                                        |\n");
            printf("|   Clientes cadastrados: %d             |\n", tamanho);
        for (int i = 0; i < tamanho; i++) {
            printf("|   Cliente %d:\n", (i + 1));
            printf("|   Nome: %s\n", clientes[i].nome);
            printf("|   Idade: %d\n", clientes[i].idade);
            printf("|   altura: %.2f\n", clientes[i].altura);
        }        
        printf("|                                        |\n");
        printf("------------------------------------------\n\n");

}



int main() {


    while (opcao != 0) {
        menu();
        scanf("%d", &opcao);

        switch (opcao) {
        case 1: // cadastrar cliente
            cadastrarcliente();
        break;

        case 2: // exibir lista de clientes
            exibemenucliente();
        break;
        
        default:
            printf("Opcao inválida.\n");
            break;
        }
    }
    
    free(clientes);
    
    printf("Programa encerrado.\n");
    



    return 0;
}