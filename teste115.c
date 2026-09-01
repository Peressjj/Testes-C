#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// cadastro de clientes

/* O sistema cadastra e remove clientes da lista de clientes */


#define MAXCLIENTES 50


void codigocliente() {
    srand(time(NULL));
}

typedef struct CadastroClientes {
    int codigocliente;
    char nomecliente[50];
    char cpfcliente[50];
    char enderecocliente[50];
    char telefonecliente[50];
} CadastroClientes;

CadastroClientes listaclientes[MAXCLIENTES];
int clientescadastrados = 0;

void exibemenucliente();
void cadastrarcliente();
void exibirlistaclientes();
void removercliente();
void funcaocadastro();

int main() {

    funcaocadastro();    
}

void exibemenucliente() {

    printf("\n------------------------------------------------------------------------------\n"); 
    printf("|                                                                              |\n"); 
    printf("|                           CADASTRO DE CLIENTES:                              |\n"); 
    printf("|                                                                              |\n"); 
    printf("|   1   →   Cadastrar novo cliente.                                             |\n"); 
    printf("|                                                                              |\n");
    printf("|   2   →   Vizualizar lista de clientes.                                      |\n"); 
    printf("|                                                                              |\n");
    printf("|   3   →   Remover cliente do cadastro.                                             |\n"); 
    printf("|                                                                              |\n"); 
    printf("|   0   →   Retornar ao menu anterior. ↩                                       |\n"); 
    printf("|                                                                              |\n"); 
    printf("--------------------------------------------------------------------------------\n");

}

void cadastrarcliente() {

    if (clientescadastrados >= MAXCLIENTES) {
        printf("Limite de clientes cadastrados atingido.\n");
        return;
    }

    printf("\n------------------------------------------------------------------------------\n"); 
    printf("|   CADASTRO DE CLIENTES:                                                      |\n"); 
    printf("|                                                                              |\n");
    printf("|   Clientes cadastrados: %d                                                   |\n", clientescadastrados);
    printf("|                                                                              |\n");
    printf("|   Nome:  ");
    getchar();
    fgets(listaclientes[clientescadastrados].nomecliente, 50, stdin);
    printf("|   CPF:  ");
    fgets(listaclientes[clientescadastrados].cpfcliente,50, stdin);
    printf("|   Endereco:  ");
    fgets(listaclientes[clientescadastrados].enderecocliente, 50, stdin);
    printf("|   Telefone:  ");
    fgets(listaclientes[clientescadastrados].telefonecliente, 50, stdin);
    listaclientes[clientescadastrados].codigocliente += rand() % 9999 + 1111;
    printf("|   Codigo recebido: %d\n", listaclientes[clientescadastrados].codigocliente);
    printf("\n--------------------------------------------------------------------------------\n");

    clientescadastrados++;
}

void exibirlistaclientes() {

        printf("\n------------------------------------------------------------------------------\n"); 
        printf("|   CADASTRO DE CLIENTES:                                                      |\n"); 
        printf("|                                                                              |\n");
        printf("|   Clientes cadastrados: %d                                                   |\n", clientescadastrados);
        printf("|                                                                              |\n");
    for (int i = 0; i < clientescadastrados; i++) {
        printf("|   Cliente %d:\n", (i + 1));
        printf("|   Nome: %s", listaclientes[i].nomecliente);
        printf("|   CPF: %s", listaclientes[i].cpfcliente);
        printf("|   Endereco: %s", listaclientes[i].enderecocliente);
        printf("|   Telefone: %s", listaclientes[i].telefonecliente);
        printf("|   Código: %d\n\n", listaclientes[i].codigocliente);    
    }

}

void removercliente() {
    exibirlistaclientes();

    int codigo = 0;
    printf("|   Insira o código do cliente que voce deseja remover: \n");
    scanf("%d", &codigo);
    int posicao = -1;

    for (int i = 0; i < clientescadastrados; i++) {
        if (codigo == listaclientes[i].codigocliente) {
            posicao = i;
            break;
        } 
    }

    if (posicao == -1) {
        printf("Cliente nao encontrado.\n");
    }

    for (int i = posicao; i < clientescadastrados - 1; i++) {
        listaclientes[i] = listaclientes[i + 1];
    }
     

    clientescadastrados--;

    printf("Cliente removido com sucesso.\n");
}

void funcaocadastro() {

    int opcao = -1;
    while (opcao != 0) {
        exibemenucliente();
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                printf("Retornando ao menu anterior. \n");
            break;

            case 1:
                cadastrarcliente();
            break;

            case 2:
                exibirlistaclientes();
            break;  
            
            case 3:
                removercliente();
            break;
            
            default:
                printf("Opcao inválida\n");
            break;
        }
    }

    printf("Retornando ao menu principal.\n");
    

}