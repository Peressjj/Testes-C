#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// cadastro de clientes

/* Atualizacao do cadastro de clientes 3.0*/
/* O sistema cadastra e remove clientes da lista de clientes */


#define   MAXCLIENTES    50
#define   MAX_DESCRICAO  26
#define   QTDE_PRODUTOS  50
#define   TIPO_LIMPEZA   1
#define   TIPO_ALIMENTO  2
#define   TIPO_PADARIA   3


typedef struct CadastroClientes {
    int codigocliente;
    char nomecliente[50];
    char cpfcliente[50];
    char enderecocliente[50];
    char telefonecliente[50];
} CadastroClientes;

CadastroClientes listaclientes[MAXCLIENTES];
int clientescadastrados = 0;

typedef struct Produto {
    int   codigo_produto;
    char  descricao_produto[MAX_DESCRICAO];
    float preco_produto;
    int   tipo_produto;    //1 para limpeza, 2 para alimentos e 3 para padaria
    int   estoque_produto; //Quantidade disponível do produto em estoque
    float margem_lucro;    // margem de lucro de cada produto em porcentagem
} Produto;
    Produto lista_produtos[QTDE_PRODUTOS] = {
        {101,  "Detergente",                1.99,    TIPO_LIMPEZA,    0,  0.20},
        {102,  "Sabao em po (1Kg)",         8.99,    TIPO_LIMPEZA,    0,  0.20},
        {103,  "Esponja",                   1.50,    TIPO_LIMPEZA,    0,  0.20},
        {104,  "Amaciante (1L)",            15.00,   TIPO_LIMPEZA,    0,  0.20},
        {105,  "Bucha de Pia (kit c/3)",    4.99,    TIPO_LIMPEZA,    0,  0.20},
        {106,  "Desinfetante(1Lt)",         7.99,    TIPO_LIMPEZA,    0,  0.20},
        {107,  "Sabao em Barra(Un)",        1.00,    TIPO_LIMPEZA,    0,  0.20},

        {201,  "Cafe",                      19.99,   TIPO_ALIMENTO,   0,  0.25},
        {202,  "Leite (1L)",                5.90,    TIPO_ALIMENTO,   0,  0.25},
        {203,  "Arroz (1Kg)",               4.50,    TIPO_ALIMENTO,   0,  0.25},
        {204,  "Feijao preto (1Kg)",        8.00,    TIPO_ALIMENTO,   0,  0.25},
        {205,  "Acucar (1Kg)",              5.00,    TIPO_ALIMENTO,   0,  0.25},
        {206,  "Sal (1kg)",                 2.00,    TIPO_ALIMENTO,   0,  0.25},
        {207,  "Farinha de Trigo (1kg)",    5.00,    TIPO_ALIMENTO,   0,  0.25},

        {301,  "Pao de Forma",              9.50,    TIPO_PADARIA,    0,  0.15},
        {302,  "Pao Integral",              12.50,   TIPO_PADARIA,    0,  0.15},
        {303,  "Pao Frances (Unid)",        1.90,    TIPO_PADARIA,    0,  0.15},
        {304,  "Sonho",                     8.50,    TIPO_PADARIA,    0,  0.15},
        {305,  "Biscoito(kg)",              12.50,   TIPO_PADARIA,    0,  0.15},
        {306,  "Pao Doce (Un)",             2.50,    TIPO_PADARIA,    0,  0.15},
        {307,  "Salgado (Un)",              17.50,   TIPO_PADARIA,    0,  0.15}
    };

void exibemenucadastro();
void cadastrarcliente();
void cadastrarproduto();
void exibirlistaprodutos();
void exibirlistaclientes();
void removercliente();
void funcaocadastro();

int main() {
    funcaocadastro();    
}

void exibemenucadastro() {

    printf("\n------------------------------------------------------------------------------\n"); 
    printf("|                                                                              |\n"); 
    printf("|                                 CADASTRO:                                    |\n"); 
    printf("|                                                                              |\n"); 
    printf("|   1   →   Cadastrar novo cliente.                                             |\n"); 
    printf("|                                                                              |\n");
    printf("|   2   →   Cadastrar novo produto.                                            |\n");
    printf("|                                                                              |\n");
    printf("|   3   →   Vizualizar lista de clientes.                                      |\n"); 
    printf("|                                                                              |\n");
    printf("|   4   →   Vizualizar lista de produtos.                                       |\n");
    printf("|                                                                              |\n");
    printf("|   5   →   Remover cliente do cadastro.                                       |\n"); 
    printf("|                                                                              |\n"); 
    printf("|   0   →   Retornar ao menu anterior. ↩                                       |\n"); 
    printf("|                                                                              |\n"); 
    printf("--------------------------------------------------------------------------------\n");

}

void cadastrarcliente() {

    srand(time(NULL));

    if (clientescadastrados >= MAXCLIENTES) {
        printf("Limite de clientes cadastrados atingido.\n");
        return;
    }


    int codigos[50];
    int contador = 0;

    while (contador < 50) {
        int numero = rand() % 8888 + 1111;
        int repetido = 0;

        for (int i = 0; i < contador; i++) {
            if (codigos[i] == numero) {
                repetido = 1;
                break;
            }
        }
        if (!repetido) {
        codigos[contador] = numero;
        contador++;
        }
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
    listaclientes[clientescadastrados].codigocliente += codigos[clientescadastrados];
    printf("|   Codigo recebido: %d\n", listaclientes[clientescadastrados].codigocliente);
    printf("\n--------------------------------------------------------------------------------\n");

    clientescadastrados++;
}

void cadastrarproduto() {

    printf("\n------------------------------------------------------------------------------\n"); 
    printf("|   CADASTRO DE PRODUTOS:                                                      \n"); 
    printf("|                                                                              \n");
    printf("|   Produtos cadastrados: %d                                                   \n", QTDE_PRODUTOS);
    printf("|                                                                              ");
    printf("|   Insira o nome do produto:\n");
    scanf("%s", &lista_produtos[(QTDE_PRODUTOS + 1)]);
    printf("|                                                                              \n");
    printf("|                                                                              \n");
    printf("|                                                                              \n");
    printf("|                                                                              \n");

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

void exibirlistaprodutos() {
        printf("\n------------------------------------------------------------------------------\n"); 
        printf("|   CADASTRO DE PRODUTOS:                                                      \n"); 
        printf("|                                                                              \n");
        printf("|   Produtos cadastrados: %d                                                   \n", QTDE_PRODUTOS);
        printf("|                                                                              \n");

        /*printf("|Código| Nome                      | Preço   | Tipo          | Estoque | Margem de Lucro |\n");*/

    /*for (int i = 0; i < 21; i++) {
        printf("{%d,        %s,         %.2f,         %d          %.2f}\n", lista_produtos[i].codigo_produto, lista_produtos[i].descricao_produto, lista_produtos[i].preco_produto, lista_produtos[i].estoque_produto, lista_produtos[i].margem_lucro);
    }*/
            /*  {101,  "Detergente",                1.99,    TIPO_LIMPEZA,    0,        0.20},
                {102,  "Sabao em po (1Kg)",         8.99,    TIPO_LIMPEZA,    0,        0.20},
                {103,  "Esponja",                   1.50,    TIPO_LIMPEZA,    0,        0.20},
                {104,  "Amaciante (1L)",            15.00,   TIPO_LIMPEZA,    0,        0.20},
                {105,  "Bucha de Pia (kit c/3)",    4.99,    TIPO_LIMPEZA,    0,        0.20},
                {106,  "Desinfetante(1Lt)",         7.99,    TIPO_LIMPEZA,    0,        0.20},
                {107,  "Sabao em Barra(Un)",        1.00,    TIPO_LIMPEZA,    0,        0.20},

                {201,  "Cafe",                      19.99,   TIPO_ALIMENTO,   0,        0.25},
                {202,  "Leite (1L)",                5.90,    TIPO_ALIMENTO,   0,        0.25},
                {203,  "Arroz (1Kg)",               4.50,    TIPO_ALIMENTO,   0,        0.25},
                {204,  "Feijao preto (1Kg)",        8.00,    TIPO_ALIMENTO,   0,        0.25},
                {205,  "Acucar (1Kg)",              5.00,    TIPO_ALIMENTO,   0,        0.25},
                {206,  "Sal (1kg)",                 2.00,    TIPO_ALIMENTO,   0,        0.25},
                {207,  "Farinha de Trigo (1kg)",    5.00,    TIPO_ALIMENTO,   0,        0.25},

                {301,  "Pao de Forma",              9.50,    TIPO_PADARIA,    0,        0.15},
                {302,  "Pao Integral",              12.50,   TIPO_PADARIA,    0,        0.15},
                {303,  "Pao Frances (Unid)",        1.90,    TIPO_PADARIA,    0,        0.15},
                {304,  "Sonho",                     8.50,    TIPO_PADARIA,    0,        0.15},
                {305,  "Biscoito(kg)",              12.50,   TIPO_PADARIA,    0,        0.15},
                {306,  "Pao Doce (Un)",             2.50,    TIPO_PADARIA,    0,        0.15},
                {307,  "Salgado (Un)",              17.50,   TIPO_PADARIA,    0,        0.15}*/


    for (int i = 0; i < 21; i++) {
        printf("|   Código: %d\n", lista_produtos[i].codigo_produto);
        printf("|   Produto %s:\n", lista_produtos[i].descricao_produto);
        printf("|   Preço: R$ %.2f\n", lista_produtos[i].preco_produto);
        printf("|   Estoque: %d\n", lista_produtos[i].estoque_produto);
        printf("|   Margem de Lucro: %.0f%%\n\n", lista_produtos[i].margem_lucro * 100);    
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
        exibemenucadastro();
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                printf("Retornando ao menu anterior. \n");
            break;

            case 1:
                cadastrarcliente();
            break;

            case 2:

            break;


            case 3:
                exibirlistaclientes();
            break;  

            case 4:
                exibirlistaprodutos();
            break;

            break;
            
            case 5:
                removercliente();
            break;
            
            default:
                printf("Opcao inválida\n");
            break;
        }
    }

    printf("Retornando ao menu principal.\n");
    

}