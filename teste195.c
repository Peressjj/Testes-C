// Bubliotecas: 
#include   <stdio.h> // De entrada e saída de dados
#include   <stdlib.h> // Usada em strtof(), para converter string em float, e em rand() e srand(), para gerar números aleatórios
#include   <time.h> // Usada para a função time(), que gera um número inteiro baseado no horário do sistema, utilizado para gerar um número aleatório
#include   <windows.h> // Usada para a função Sleep(), que pausa o programa por um tempo determinado
#include   <string.h>

// Constantes simbólicas definidas:
    #define   MAX_DESCRICAO  26
    #define   MAX_HISTORICO  500
    #define   QTDE_PRODUTOS  21
    #define   TIPO_LIMPEZA   1
    #define   TIPO_ALIMENTO  2
    #define   TIPO_PADARIA   3
    #define   TODOS_TIPOS    0
    #define   MAXCLIENTES    50
    #define   MAX_CARACTERES 150


// Estruturas:

typedef struct Produto {
    int    codigo;
    char   descricao[MAX_DESCRICAO];
    float  preco;
    int    categoria;    //1 para limpeza, 2 para alimentos e 3 para padaria
    int    estoque; //Quantidade disponível do produto em estoque
    float  margem_lucro;    // margem de lucro de cada produto em porcentagem
    float  preco_custo;
    int    estoque_min; //Quantidade mínima do produto que deve ser mantida em estoque, para controle de reposição
} Produto;

Produto produtos_pre_cadastrados[QTDE_PRODUTOS] = {
//   Cod   Nome                         Preco     Categoria        Estoque    marg lucro    Preco custo    Estoque min         
    {101,  "Detergente",                1.99,    TIPO_LIMPEZA,     0,         0.20,         1.66,          10},
    {102,  "Sabao em po (1Kg)",         8.99,     TIPO_LIMPEZA,    0,         0.20,         7.49,          10},
    {103,  "Esponja",                   1.50,     TIPO_LIMPEZA,    0,         0.20,         1.25,          10},
    {104,  "Amaciante (1L)",            15.00,    TIPO_LIMPEZA,    0,         0.20,         12.50,         10},
    {105,  "Bucha de Pia (kit c/3)",    4.99,     TIPO_LIMPEZA,    0,         0.20,         4.16,          10},
    {106,  "Desinfetante(1Lt)",         7.99,     TIPO_LIMPEZA,    0,         0.20,         6.66,          10},
    {107,  "Sabao em Barra(Un)",        1.00,     TIPO_LIMPEZA,    0,         0.20,         0.83,          10},

    {201,  "Cafe",                      19.99,    TIPO_ALIMENTO,   0,         0.25,         15.99,         10},
    {202,  "Leite (1L)",                5.90,     TIPO_ALIMENTO,   0,         0.25,         4.72,          10},
    {203,  "Arroz (1Kg)",               4.50,     TIPO_ALIMENTO,   0,         0.25,         3.60,          10},
    {204,  "Feijao preto (1Kg)",        8.00,     TIPO_ALIMENTO,   0,         0.25,         6.40,          10},
    {205,  "Acucar (1Kg)",              5.00,     TIPO_ALIMENTO,   0,         0.25,         4.00,          10},
    {206,  "Sal (1kg)",                 2.00,     TIPO_ALIMENTO,   0,         0.25,         1.60,          10},
    {207,  "Farinha de Trigo (1kg)",    5.00,     TIPO_ALIMENTO,   0,         0.25,         4.00,          10},

    {301,  "Pao de Forma",              9.50,     TIPO_PADARIA,    0,         0.15,         8.26,          10},
    {302,  "Pao Integral",              12.50,    TIPO_PADARIA,    0,         0.15,         10.87,         10},
    {303,  "Pao Frances (Unid)",        1.90,     TIPO_PADARIA,    0,         0.15,         1.65,          10},
    {304,  "Sonho",                     8.50,     TIPO_PADARIA,    0,         0.15,         7.39,          10},
    {305,  "Biscoito(kg)",              12.50,    TIPO_PADARIA,    0,         0.15,         10.87,         10},
    {306,  "Pao Doce (Un)",             2.50,     TIPO_PADARIA,    0,         0.15,         2.17,          10},
    {307,  "Salgado (Un)",              17.50,    TIPO_PADARIA,    0,         0.15,         15.22,         10}
};

Produto *produtos = NULL;
int total_produtos = 0;
int capacidade_produtos = 36;

typedef struct itemVenda {
    Produto produto;
    int     quantidade;
    float   valor;
} itemVenda;

typedef struct Venda {
    int       id;
    int       cliente;
    itemVenda *carrinho;
    int total_itens;
    int capacidade_carrinho;
    char      pago; //A - aberto, P - pago
} Venda;

Venda *historico = NULL;
int   total_historico = 0;
int capacidade_historico = 10;

typedef struct Pagamento {
    int     venda;
    float   pago_dinheiro;
    float   pago_cartao;
    char    tipo; //D - dinheiro, C - cartão, M - misto
} Pagamento;

Pagamento *pagamentos = NULL; // Lista de pagamentos realizados, para controle e relatório de vendas
int   total_pagamentos = 0;
int capacidade_pagamentos = 1;

typedef struct{
    char cep[10];
    char numero[5];
    char complemento[100];
    char bairro[100];
    char rua[100];
} Endereco;

typedef struct Cliente {
    int  id;
    char CPF[15]; //Formato XXX.XXX.XXX-XX
    char nome[30];
    char nome_social[30];
    char celular[20]; //Formato (XX)XXXXX-XXXX
    Endereco endereco;
} Cliente;

Cliente *clientes =  NULL;
int   total_clientes = 0;
int capacidade_clientes = 1;

//  Variáveis globais declaradas:
    int   caixa_aberto = 0;                     
    int   opcao = -1;
    float fundo_caixa_ini;
    float caixa;

    
// Prototipagem de Funções:

// Entrada e validacao
/*1*/    int   solicitaInt();    
/*2*/    float solicitaFloat();

// Calculo
/*3*/    float calculaDesconto(float valor);
/*4.1*/  float calculaValorVenda(itemVenda lista[],int posicao_final, int tipo_buscado);
/*4.2*/  float calculaTotal(Venda lista[], int posicao_final_lista, int tipo_buscado);

// Gestao de estoque
/*5*/    int   buscarIndice(int codigo);
/*6*/    void  gestorEstoque(int codigo, int quantidade);
/*7*/    void  addProdutoCarrinho(Produto produto); 
/*8*/    void  zerarLista(itemVenda lista[], int *posicao_final_lista);
/*9*/    void  addVendaHistorico();

// Caixa e pagamento
/*11*/    void  abreCaixa();
/*12*/    void  statusCaixa(int intencao);
/*13*/    void  aberturaCaixa();
/*14*/    void  fechamentoCaixa();

// Menus
/*15*/    void  exibeMenuPrincipal();
/*16*/    void  retornaMenuPrincipal();
/*17*/    void  exibeSubMenu();
/*18*/    void  exibeMenuCarrinho();
/*20*/    void  exibeConfirmacaoCartao();
/*21*/    void  exibeRelatorio();
/*22*/    void  menurelatorio();
/*24*/    void  exibirListaClientes();

// Cadastro
/*25*/    void  cadastrarcliente();
/*26*/    void  removercliente();
/*27*/    void  moduloCadastros();
/*28*/    int   verificaclientes();

// Funcoes principais
/*29*/    void  moduloVendas();
/*30*/    void  moduloPagamentos();
/*30*/    void  moduloRelatorios();
/*31*/    void  funcaorelatorio();
/*32*/    void  saida();


// Funcao principal:
int main() {
    produtos = calloc(QTDE_PRODUTOS, sizeof(Produto));
    if(produtos == NULL){
        printf("Erro de memória!\n");
        return 1;
    }
    for (int i = 0; i < QTDE_PRODUTOS; i++) {
        produtos[i] = produtos_pre_cadastrados[i];
        total_produtos++;
    }

    historico = calloc(capacidade_historico, sizeof(Venda)); // Histórico de vendas realizadas, para controle e relatório de vendas
    if(historico == NULL){
        printf("Erro de memória!\n");
        return 1;
    }
    pagamentos = calloc(capacidade_pagamentos, sizeof(Pagamento)); // Lista de pagamentos realizados, para controle e relatório de vendas
    if(pagamentos == NULL){
        printf("Erro de memória!\n");
        return 1;
    }
    clientes = calloc(capacidade_clientes, sizeof(Cliente));  // Lista de clientes cadastrados
    if(clientes == NULL){
        printf("Erro de memória!\n");
        return 1;
    }

    srand(time(NULL));  

    while (opcao != 0) {
        exibeMenuPrincipal();
        opcao = solicitaInt();

        switch (opcao) {
            case 0: // Sair 
                if (caixa_aberto) {
                    printf("\nFeche o caixa antes de sair.\n");
                    retornaMenuPrincipal();
                    break;
                }

                saida();
            break;

            case 1: // venda de produtos  
                statusCaixa(1);
                moduloVendas();
            break;

            case 2: // mostrar carrinho  
                statusCaixa(1);
                exibeMenuCarrinho();
            break;

            case 3: // pagamento
                statusCaixa(1);
                moduloPagamentos();
            break;

            case 4: // abertura de caixa 
                statusCaixa(0);
                aberturaCaixa();
            break;

            case 5: // fechamento de caixa 
                statusCaixa(1);
                fechamentoCaixa();
            break;

            case 6: // cadastros
                moduloCadastros();
            break;

            case 7: // relatorios
                moduloRelatorios();
            break;

            default:
                printf("Opcao inválida\n");
            break;
        }
    }

    free(produtos);
    for (int i = 0; i < total_historico; i++){
        free(historico[i].carrinho);
    }
    free(historico);
    free(pagamentos);
    free(clientes);

    return 0;
}


// Corpo das Funções:

// Entrada e validacao
int    solicitaInt() {
    int numero;

    while (scanf("%d", &numero) != 1) {
        printf("Entrada inválida. Digite um número inteiro: ");
        while(getchar() != '\n');
    }
    
    while(getchar() != '\n');
    return numero;
}

float  solicitaFloat() {
    float valor;
    char *nao_float, texto[10];

    do {
        printf("\nDigite um valor real: ");
        scanf("%9s", texto);

        valor = strtof(texto, &nao_float);

        if (*nao_float != '\0') {
            printf("Valor inválido!\n");
        }

    } while(*nao_float != '\0');

    return valor;
}


// Calculo
float  calculaDesconto(float valor) { //Calcula o desconto a ser aplicado no pagamento em dinheiro
    float percent = (valor <= 50) ? 0.05 : (valor < 200) ? 0.10 : 0; //Operador ternário para calcular o desconto com base no valor da compra

    if (percent != 0) return percent; //Se o ternário retornar 0 é porque o usuário deve informar desconto personalizado
    
    do {
        printf("\nVoce deve inserir o percentual de desconto a ser aplicado (entre 10 e 100)! ");
        percent = solicitaFloat()/100;
    } while(percent < 0.10 || percent > 1.00);
    
    return percent;
}

float  calculaValorVenda(itemVenda lista[],int posicao_final, int tipo_buscado) {
    float valor = 0;

    for (int i = 0; i < posicao_final; i++) {
        if (lista[i].produto.codigo <= 0) continue; //Pula posições vazias do carrinho
        if (lista[i].produto.categoria == tipo_buscado || tipo_buscado == TODOS_TIPOS) {
            valor += lista[i].valor;
        }
    }

    return valor;
}

float  calculaTotal(Venda lista[], int posicao_final_lista, int tipo_buscado) {
    float valor = 0;

    for (int i = 0; i < posicao_final_lista; i++) {
        if (lista[i].pago == 'P'){ //Só calcula o valor das vendas que foram finalizadas (pagas)
            valor += calculaValorVenda(lista[i].carrinho, lista[i].total_itens, tipo_buscado);
        }
    }

    return valor;
}


// Gestor de estoque
int   buscarIndice(int codigo) {
    for (int indice = 0; indice < total_produtos; indice++) {
        if (produtos[indice].codigo == codigo) {
            return indice;
        }
    }
    return -1; //Caso o código do produto não seja encontrado na produtos
}

void  gestorEstoque(int codigo, int quantidade) { //Atualiza o estoque do produto, somando a quantidade devolvida ou subtraindo a quantidade vendida
    int indice = buscarIndice(codigo);

    if (indice != -1) {
        produtos[indice].estoque += quantidade;
    }

    else printf("Produto nao encontrado para atualizar estoque!\n");

}

void  addProdutoCarrinho(Produto produto) { //Adiciona uma saída de produto (realiza uma 'venda'), atualizando o 'histórico' de vendas
    int cliente = 0;
    int posicao = historico[total_historico].total_itens;

    if(total_historico >= capacidade_historico){ //Aloca mais memória para o historico caso necessário

        capacidade_historico *= 2;
        Venda *temp = realloc(historico,sizeof(Venda)*capacidade_historico);

        if(temp == NULL){
            printf("Erro de memória!\n");
            return;
        }
        historico = temp;
    }
    
    if (historico[total_historico].total_itens == 0){ //No caso de ser o 1º produto deste carrinho associa um cliente a esta venda (historico[total_historico])
        printf("\nInforme o CPF do cliente: ");
        char cpf[15];

        do {
            scanf("%14s", cpf);

            for (cliente = 0; cliente < total_clientes; cliente++){
                if (strcmp(cpf, clientes[cliente].CPF) == 0)break;
            }

            if (cliente == total_clientes) printf("\nCliente nao encontrado, tente novamente: ");
            
        } while (cliente == total_clientes);

        historico[total_historico].id = total_historico + 1;
        historico[total_historico].cliente = clientes[cliente].id;
        historico[total_historico].total_itens = 0;
        historico[total_historico].capacidade_carrinho = total_produtos; 
        historico[total_historico].pago = 'A';
        historico[total_historico].carrinho = calloc(historico[total_historico].capacidade_carrinho, sizeof(itemVenda)); //Aloca o carrinho para a venda atual
        if(historico[total_historico].carrinho == NULL){
            printf("Erro de memória!\n");
            return;
        }
    }

    for (int i = 0; i < total_clientes; i++){
        if (historico[total_historico].cliente == clientes[i].id){
            cliente = i;
            break;
        }
    }
    
    printf("\nO cliente %s escolheu %s.\nQuantos ele deseja? ", clientes[cliente].nome, produto.descricao);
    int quantidade_vendida = solicitaInt();

    if (quantidade_vendida < 0){ //Valida se a quantidade é positiva
        printf("A quantidade deve ser positiva!");
        Sleep(1000); //Pausa de 1 seg
        return;
    }

    if (quantidade_vendida > produto.estoque){ //Valida se tem disponível em estoque a quantidade desejada
        printf("\nDesculpe, não temos essa quantidade em estoque. Temos apenas %d unidades disponíveis.\n", produto.estoque);
        Sleep(1000); //Pausa de 1 seg
        return;
    }

    printf("\nAdicionado %d unidades de %s ao carrinho. \n", quantidade_vendida, produto.descricao);
    gestorEstoque(produto.codigo, -quantidade_vendida); //Atualiza o estoque do produto, subtraindo a quantidade escolhida

    for (int i = 0; i < historico[total_historico].total_itens; i++){
        if (historico[total_historico].carrinho[i].produto.codigo == produto.codigo){
            quantidade_vendida += historico[total_historico].carrinho[i].quantidade; //Somar a quantidade anterior com a quantidade adicional
            posicao = i; //Atualiza a posicao que o produto deve ser adicionado/atualizado no carrinho
            break;
        }
    }
    
    historico[total_historico].carrinho[posicao] = (itemVenda){ produto, quantidade_vendida, produto.preco * quantidade_vendida}; //add produto ao carrinho
    
    printf("\nTotal: R$ %.2f\n", historico[total_historico].carrinho[posicao].valor); //Mostra o valor total da venda do produto escolhido
    
    if (posicao == historico[total_historico].total_itens)
        historico[total_historico].total_itens++; //Incrementa o índice do carrinho no caso de ser um novo produto
    
    int indice = buscarIndice(produto.codigo);

    if (produtos[indice].estoque <= produtos[indice].estoque_min){ //Verifica se o estoque do produto ficou abaixo do mínimo, mostrando um aviso caso tenha ficado{
        printf("\n- Atencao ⚠ Estoque de produto %s BAIXO!\n", produto.descricao);
        Sleep(1000);
    }
}


// Módulo de Relatórios
void  exibirListaVendas(){
    printf("\n---------------------------------------------------------------------------------------------------\n"); 
    printf("|                                           LISTA DE VENDAS:                                       |\n"); 
    printf("|                                                                                                  |\n");
    printf("|   Vendas registradas: %d                                                                         |\n", total_historico);
    printf("|                                                                                                  |\n");
    printf("| Id    | Cliente                        | Limpeza   | Alimento  | Padaria   | Faturamento | Lucro |\n");
    printf("|-------|--------------------------------|-----------|-----------|-----------|-------------|-------|\n");

    for (int i = 0; i < total_historico; i++){
        Venda v = historico[i];
        int cliente = 0;

        for (cliente = 0; cliente < total_clientes; cliente++){
            if (clientes[cliente].id == v.cliente) break;
        }

        float lucro = 0;

        for (int j = 0; j < v.total_itens; j++){
            if (v.carrinho[j].produto.codigo <= 0) continue; //Pula posições vazias do carrinho
            lucro += v.carrinho[j].produto.margem_lucro * v.carrinho[j].produto.preco_custo * v.carrinho[j].quantidade;
        };

        printf("| %-5d | %-30s | %-5.2f | R$ %-5.2f | R$ %-5.2f | R$ %-11.2f | R$ %-5.2f |\n", v.id, clientes[cliente].nome, calculaValorVenda(v.carrinho, v.total_itens, TIPO_LIMPEZA), calculaValorVenda(v.carrinho, v.total_itens, TIPO_ALIMENTO), calculaValorVenda(v.carrinho, v.total_itens, TIPO_PADARIA), calculaValorVenda(v.carrinho, v.total_itens, TODOS_TIPOS), lucro);
        printf("|                                                                                                  |\n");
    }

    printf("\n---------------------------------------------------------------------------------------------------\n"); 
}

// Módulo Abertura e Fechamento de Caixa
void  statusCaixa(int intencao) {
    if (intencao && !caixa_aberto){
        printf("-   O caixa está fechado! Abra o caixa para acessar esta opcao!\n");
        retornaMenuPrincipal();
    }

    if (!intencao && caixa_aberto){
        printf("-   O caixa está aberto! Feche o caixa para acessar esta opcao!\n");
        retornaMenuPrincipal();
    }
}

void  aberturaCaixa() {
    if (caixa_aberto){
        printf("O caixa já está aberto.\n");
        Sleep(1000);
        return;
    } else {
        printf("\nPara a abertura do caixa, informe o valor do suprimento inicial: \n");
        fundo_caixa_ini = solicitaFloat();

        caixa = fundo_caixa_ini; //Inicializa o fundo de caixa com o valor do suprimento inicial informado
        
        printf("\nCaixa aberto com suprimento inicial de R$%.2f\n", fundo_caixa_ini);

        caixa_aberto = 1;

        printf("\nAntes de registrar as vendas voce deve informar manualmente o estoque atual da padaria!\n");

        for (int i = 0; i < total_produtos; i++ ){
            if (produtos[i].categoria != TIPO_PADARIA){ //Se não for de padaria, determina um estoque aleatório pro produto e continua o loop
                produtos[i].estoque = rand() % 100 + 1;
                continue;
            }
            
            printf("\nDigite a quantidade de %s em estoque: ",produtos[i].descricao);
            produtos[i].estoque = solicitaInt();

            if (produtos[i].estoque < produtos[i].estoque_min){
                printf("-   ⚠ Estoque de produto %s BAIXO!\n", produtos[i].descricao);
                Sleep(1000);
            }
        }
        Sleep(1000);
    }
}

void  fechamentoCaixa() {
    if (caixa_aberto){ 
        float total_dinheiro = 0;
        float total_cartao = 0;

        for(int i = 0; i < total_pagamentos; i++) {
            total_dinheiro += pagamentos[i].pago_dinheiro;
            total_cartao += pagamentos[i].pago_cartao;
        }

        float lucroliquido = 0;

        for(int i = 0; i < total_historico; i++){
            if (historico[i].pago == 'P'){
                for (int j = 0; j < historico[i].total_itens; j++){
                    if (historico[i].carrinho[j].produto.codigo <= 0) continue; //Pula posições vazias do carrinho
                    lucroliquido += historico[i].carrinho[j].produto.margem_lucro * historico[i].carrinho[j].produto.preco_custo * historico[i].carrinho[j].quantidade;
                }
            }
        }


        printf("\n-------------------------------------------------------------------\n"); 
        printf("|                                                                 |\n"); 
        printf("|                      RELATÓRIO DO DIA                           |\n"); 
        printf("|                                                                 |\n"); 
        printf("|  1. Valor (R$) de Abertura – R$ %-32.2f|\n", fundo_caixa_ini);
        printf("|                                                                 |\n"); 
        printf("|  2. valor (R$) recebido em dinheiro – R$ %-23.2f|\n", total_dinheiro); // valor recebido em dinheiro, para mostrar o valor recebido em dinheiro durante o período em que o caixa ficou aberto, já com o desconto aplicado
        printf("|                                                                 |\n");
        printf("|  3. valor (R$) recebido no cartão – R$ %-30.2f|\n", total_cartao); // valor recebido no cartão, para mostrar o valor recebido no cartão durante o período em que o caixa ficou aberto, sem desconto
        printf("|                                                                 |\n");
        printf("|  4. Faturamento Total – R$ %-37.2f|\n", calculaTotal(historico, total_historico, TODOS_TIPOS));
        printf("|                                                                 |\n"); 
        printf("|  5. Faturamento por categoria:                                  |\n");
        printf("|      a. Material de Limpeza – R$ %-31.2f|\n", calculaTotal(historico, total_historico, TIPO_LIMPEZA));
        printf("|      b. Venda de Alimentos – R$ %-32.2f|\n", calculaTotal(historico, total_historico, TIPO_ALIMENTO));
        printf("|      c. Padaria - R$ %-43.2f|\n", calculaTotal(historico, total_historico, TIPO_PADARIA));
        printf("|                                                                 |\n"); 
        printf("|  6. Lucro liquido do dia: R$%-36.2f                             |\n", lucroliquido); 
        printf("-------------------------------------------------------------------\n");
        Sleep(3000);
        caixa_aberto = 0;
        printf("\nCaixa fechado!\nAbra novamente caso queira realizar uma venda!!\n");
    } else {
        printf("O caixa ja esta fechado!\n");
        Sleep(1000);
    }
}


// Menus
void  exibeMenuPrincipal() {
    printf("\n\n-------------------------------------------------------------------\n");
    printf("|                                                                 |\n");
    printf("|                           LOJA DA BERE                          |\n");
    printf("|                                                                 |\n");
    printf("|   1   →  Comprar produtos.                                      |\n");
    printf("|                                                                 |\n");
    printf("|   2   →  Mostrar carrinho.                                      |\n");
    printf("|                                                                 |\n");
    printf("|   3   →  Pagamento.                                             |\n");
    printf("|                                                                 |\n");
    printf("|   4   →  Abertura de Caixa.                                     |\n");
    printf("|                                                                 |\n");
    printf("|   5   →  Fechamento de Caixa.                                   |\n");
    printf("|                                                                 |\n");
    printf("|   6   →  Cadastros.                                             |\n");
    printf("|                                                                 |\n");
    printf("|   7   →  Relatórios.                                            |\n");
    printf("|                                                                 |\n");
    printf("|   0   →  Sair. ↩                                                |\n");
    printf("|                                                                 |\n");
    printf("-------------------------------------------------------------------\n\n");
    printf("\nDigite a opção desejada: ");
}

void  retornaMenuPrincipal() {
    printf("\n----------------- Retornando ao menu principal! ↩ -----------------\n");
    opcao = -1;
    Sleep(2000); //Pausa o programa por 2 segundos
}


// Módulo de Cadastro
void  cadastrarProduto() {

    if(total_produtos >= capacidade_produtos){

        capacidade_produtos *= 2;
        Produto *temp = realloc(produtos,sizeof(Produto)*capacidade_produtos);

        if(temp == NULL){
            printf("Erro de memória!\n");
            return;
        }
        produtos = temp;
    }

    Produto novo;
    // 
    printf("\n------------------------------------------------------------------------------\n"); 
    printf("|   CADASTRO DE PRODUTOS:                                                      |\n"); 
    printf("|                                                                              |\n");
    printf("|   Produtos cadastrados: %d                                                   |\n", total_produtos);
    printf("|                                                                              |\n");
    printf("|   Codigo do produto: ");
    novo.codigo = solicitaInt();

    for (int i = 0; i < total_produtos; i++){
        if (produtos[i].codigo == novo.codigo){
            printf("Erro: codigo %d ja cadastrado!\n", novo.codigo);
            return;
        }
    }

    do{
        printf("|   Categoria (1-Limpeza, 2-Alimento, 3-Padaria):                            |\n");
        novo.categoria = solicitaInt();
    } while (novo.categoria < 1 || novo.categoria > 3);

    printf("|   Descricao:                                                                   |\n");
    fgets(novo.descricao, MAX_DESCRICAO, stdin);
    novo.descricao[strcspn(novo.descricao, "\n")] = '\0';
    printf("|   Preco de compra:                                                              |\n");
    novo.preco_custo = solicitaFloat();
    printf("|   Margem de lucro (ex: 0.20 para 20%%):                                          |\n");
    novo.margem_lucro = solicitaFloat();
    printf("|   Estoque inicial:                                                               |\n");
    novo.estoque = solicitaInt();
    printf("|   Estoque minimo:                                                               |\n");
    novo.estoque_min = solicitaInt();
    printf("\n--------------------------------------------------------------------------------\n");

    novo.preco = novo.preco_custo * (1 + novo.margem_lucro);

    produtos[total_produtos] = novo;
    total_produtos++;
    printf("Produto cadastrado com sucesso!\n");
}

void  exibirListaProdutos() {
    printf("\n-----------------------------------------------------------------------------------------------------------\n"); 
    printf("|                                             LISTA DE PRODUTOS:                                           |\n"); 
    printf("|                                                                                                          |\n");
    printf("|   Produtos cadastrados: %d                                                                               |\n", total_produtos);
    printf("|                                                                                                          |\n");
    printf("| Cod    | Descricao                  | Categoria  | Compra     | Venda      | Margem  | Estq   | EstqMin  |\n");
    printf("|--------|----------------------------|------------|------------|------------|---------|--------|----------|\n");

    char categorias[3][9] = {"Limpeza","Alimento","Padaria"};

    for (int i = 0; i < total_produtos; i++) {
        Produto p = produtos[i];
        
        printf("| %-6d | %-26s | %-10s | R$ %-7.2f | R$ %-7.2f | %-6.0f%% | %-6d | %-8d |\n", p.codigo, p.descricao, categorias[p.categoria-1], p.preco_custo, p.preco, p.margem_lucro * 100, p.estoque, p.estoque_min);
        printf("|                                                                                                          |\n");
    }

    printf("\n-----------------------------------------------------------------------------------------------------------\n"); 
}

void  editarProduto() {
    // codigo, descricao, categoria,  compra, margem, estoque, estoque_min
    printf("\n------------------------------------------------------------------------------\n"); 
    printf("|   EDITAR PRODUTO:                                                           |\n"); 
    printf("|                                                                              |\n");
    printf("|   Produtos cadastrados: %d                                                   |\n", total_produtos);
    printf("|                                                                              |\n");
    printf("|   Codigo do produto a editar: ");
    int codigo = solicitaInt();
    int posicao = buscarIndice(codigo);
    if (posicao == -1){
        printf("|   Produto nao encontrado!                                                 |\n");
        return;
    }
    Produto *produto = &produtos[posicao];
    printf("|   Editando produto '%s' (Codigo: %d)                                              |\n", produto->descricao, produto->codigo);
    printf("|   Nova descricao (deixe em branco para manter):                                   |\n");
    char nova_descricao[MAX_DESCRICAO];
    fgets(nova_descricao, MAX_DESCRICAO, stdin);
    nova_descricao[strcspn(nova_descricao, "\n")] = '\0';
    if (strlen(nova_descricao) > 0){
        strncpy(produto->descricao, nova_descricao, MAX_DESCRICAO - 1);
        produto->descricao[MAX_DESCRICAO - 1] = '\0';
    }
    printf("|   Nova categoria (1-Limpeza, 2-Alimento, 3-Padaria, ou -1 para manter):                            |\n");
    int nova_categoria = solicitaInt();
    if (nova_categoria >= 1 && nova_categoria <= 3){
        produto->categoria = nova_categoria;
    }

    printf("|   Novo preco de compra (ou -1 para manter):                                                              |\n");
    float novo_preco_compra = solicitaFloat();
    if (novo_preco_compra >= 0){
        produto->preco_custo = novo_preco_compra;
    }
    printf("|   Nova margem de lucro (ex: 0.20 para 20%%, ou -1 para manter):                                          |\n");
    float nova_margem_lucro = solicitaFloat();
    if (nova_margem_lucro >= 0){
        produto->margem_lucro = nova_margem_lucro;
    }
    printf("|   Novo estoque inicial (ou -1 para manter):                                                               |\n");
    int novo_estoque = solicitaInt();
    if (novo_estoque >= 0){
        produto->estoque = novo_estoque;
    }
    printf("|   Novo estoque minimo (ou -1 para manter):                                                               |\n");
    int novo_estoque_min = solicitaInt();
    if (novo_estoque_min >= 0){
        produto->estoque_min = novo_estoque_min;
    }

    produto->preco = produto->preco_custo * (1 + produto->margem_lucro);
    
    printf("|   Produto editado com sucesso!                                               |\n");
}

void  removerProduto() {

    printf("\n------------------------------------------------------------------------------\n"); 
    printf("|   REMOVER PRODUTO:                                                           |\n"); 
    printf("|                                                                              |\n");
    printf("|   Produtos cadastrados: %d                                                   |\n", total_produtos);
    printf("|                                                                              |\n");
    printf("|   Codigo do produto a remover: ");
    int codigo = solicitaInt();
    int posicao = buscarIndice(codigo);
    if (posicao == -1){
        printf("|   Produto nao encontrado!                                                 |\n");
        return;
    }
    printf("|Confirma remocao de '%s'? (1-Sim / 0-Nao): ", produtos[posicao].descricao);
    int confirmacao = solicitaInt();
    if (confirmacao != 1) {
        printf("|   Remocao cancelada.                                                      |\n");
        return;
    }
    produtos[posicao] = produtos[total_produtos - 1];
    total_produtos--;

    printf("|   Produto removido com sucesso!                                               |\n");
    printf("\n------------------------------------------------------------------------------\n");
}

void  funcaoProduto() {
    do {
        printf("\n------------------------------------------------------------------------------\n"); 
        printf("|                                                                              |\n"); 
        printf("|                           CADASTRO DE PRODUTOS:                              |\n"); 
        printf("|                                                                              |\n"); 
        printf("|   1   →   Cadastrar novo produto.                                            |\n"); 
        printf("|                                                                              |\n");
        printf("|   2   →   Vizualizar lista de produtos.                                      |\n"); 
        printf("|                                                                              |\n");
        printf("|   3   →   Editar cadastro de produto.                                        |\n"); 
        printf("|                                                                              |\n");
        printf("|   4   →   Remover produto do cadastro.                                       |\n"); 
        printf("|                                                                              |\n"); 
        printf("|   0   →   Retornar ao menu anterior. ↩                                       |\n"); 
        printf("|                                                                              |\n"); 
        printf("--------------------------------------------------------------------------------\n");
        opcao = solicitaInt();

        switch (opcao) {
            case 0:
                retornaMenuPrincipal();
            break;

            case 1:
                cadastrarProduto();
            break;

            case 2:
                exibirListaProdutos();
            break;  
            
            case 3:
                editarProduto();
            break;

            case 4:
                removerProduto();
            break;
            
            default:
                printf("Opcao inválida\n");
            break;
        }
    }while (opcao != -1);
}

void  cadastrarCliente() {
         
    Cliente novo;

    printf("\n------------------------------------------------------------------------------\n");
    printf("|   CADASTRO DE CLIENTES                                                     |\n");
    printf("|                                                                            |\n");
    printf("|   Clientes cadastrados: %d                                                |\n", total_clientes);
    printf("|                                                                            |\n");

    printf("|   Nome: ");
    scanf(" %[^\n]", novo.nome);
    
    printf("|   CPF: ");
    scanf(" %14s", novo.CPF);

    for (int i = 0; i < total_clientes; i++) {
        if (strcmp(clientes[i].CPF, novo.CPF) == 0) {
            printf("\nCPF ja cadastrado!\n");
            return;
        }
    }

    if (total_clientes >= capacidade_clientes) {
        capacidade_clientes *= 2;
        Cliente *temp = realloc(clientes, sizeof(Cliente) * capacidade_clientes);
        
        if (temp == NULL) {
            printf("\nErro de memoria!\n");
            return;
        }

        clientes = temp;
    }

    novo.id = total_clientes + 1;

    printf("|   Codigo: %d\n", novo.id);

    printf("|   Nome social: ");
    scanf(" %[^\n]", novo.nome_social);

    printf("|   Telefone: ");
    scanf(" %19s", novo.celular);

    printf("|   Cadastro de endereco:\n");

    getchar();

    printf("|   Rua: ");
    scanf(" %[^\n]", novo.endereco.rua);

    printf("|   Numero: ");
    scanf(" %4s", novo.endereco.numero);

    printf("|   Complemento: ");
    scanf(" %[^\n]", novo.endereco.complemento);

    printf("|   Bairro: ");
    scanf(" %[^\n]", novo.endereco.bairro);

    printf("|   CEP: ");
    scanf(" %9s", novo.endereco.cep);

    clientes[total_clientes] = novo;

    total_clientes++;

    printf("\nCliente cadastrado com sucesso!\n");
}

void  exibirListaClientes() {

        printf("\n------------------------------------------------------------------------------\n");
        printf("|   LISTA DE CLIENTES:                                                       |\n");
        printf("|                                                                            |\n");
        printf("|   Clientes cadastrados: %-3d                                              |\n", total_clientes);
        printf("|                                                                            |\n");
    for (int i = 0; i < total_clientes; i++) {
        printf("|--------------------------------------------------------------------------|\n");
        printf("|   Cliente: %-61d|\n", i + 1);
        printf("|   Nome: %-64s|\n", clientes[i].nome);
        printf("|   Nome social: %-57s|\n", clientes[i].nome_social);
        printf("|   CPF: %-65s|\n", clientes[i].CPF);
        printf("|   Rua: %-65s|\n", clientes[i].endereco.rua);
        printf("|   Numero: %-62s|\n", clientes[i].endereco.numero);
        printf("|   Complemento: %-57s|\n", clientes[i].endereco.complemento);
        printf("|   Bairro: %-62s|\n", clientes[i].endereco.bairro);
        printf("|   CEP: %-65s|\n", clientes[i].endereco.cep);
        printf("|   Telefone: %-60s|\n", clientes[i].celular);
        printf("|   Codigo: %-62d|\n", clientes[i].id);
    }
        printf("------------------------------------------------------------------------------\n");

}

void  editarCliente() { 
    exibirListaClientes();

    printf("\n------------------------------------------------------------------------------\n");
    printf("|   EDITAR CADASTRO                                                         |\n");
    printf("|                                                                            |\n");
    printf("|   Clientes cadastrados: %d                                                |\n", total_clientes);
    printf("|                                                                            |\n");
    printf("|   Codigo do cliente a editar: ");

    int codigo = solicitaInt();
    int posicao = -1;

    // Procura o codigo do cliente 
    for (int i = 0; i < total_clientes; i++) {
        if (codigo == clientes[i].id) {
            posicao = i;
            break;
        }
    }

    // Se nao encontrar o codigo do cliente
    if (posicao == -1) {
        printf("\nCliente nao encontrado.\n");
        return;
    }

    Cliente *cliente = &clientes[posicao];

    printf("\n|   Editando cliente '%s' (Codigo: %d)\n",
        cliente->nome,
        cliente->id);

    getchar();


    char entrada[100];
    
    // Editar nome
    printf("\n|   Nome anterior: %s\n", clientes[posicao].nome);
    printf("|   Novo nome (Enter para manter): ");
    fgets(entrada, sizeof(entrada), stdin);

    entrada[strcspn(entrada, "\n")] = '\0';

    if (strlen(entrada) > 0) {
        strcpy(cliente->nome, entrada);
    }

    // Editar nome social
    printf("\n|   Nome social anterior: %s\n", clientes[posicao].nome_social);
    printf("|   Novo nome social (Enter para manter): ");
    fgets(entrada, sizeof(entrada), stdin);

    entrada[strcspn(entrada, "\n")] = '\0';

    if (strlen(entrada) > 0) {
        strcpy(cliente->nome_social, entrada);
    }

    // Editar telefone 
    printf("\n|   Telefone anterior: %s\n", clientes[posicao].celular);
    printf("|   Novo telefone (Enter para manter): ");
    fgets(entrada, sizeof(entrada), stdin);

    entrada[strcspn(entrada, "\n")] = '\0';

    if (strlen(entrada) > 0) {
        strcpy(cliente->celular, entrada);
    }

    // Editar endereco
    printf("\n|   Rua anterior: %s\n", clientes[posicao].endereco.rua);
    printf("|   Nova rua (Enter para manter): ");
    fgets(entrada, sizeof(entrada), stdin);

    entrada[strcspn(entrada, "\n")] = '\0';

    if (strlen(entrada) > 0) {
        strcpy(cliente->endereco.rua, entrada);
    }

    printf("\n|   Novo numero (Enter para manter): ");
    fgets(entrada, sizeof(entrada), stdin);

    entrada[strcspn(entrada, "\n")] = '\0';

    if (strlen(entrada) > 0) {
        strcpy(cliente->endereco.numero, entrada);
    }

    // Editar complemento
    printf("\n|   Complemento anterior: %s\n", clientes[posicao].endereco.complemento);
    printf("|   Novo complemento (Enter para manter): ");
    fgets(entrada, sizeof(entrada), stdin);

    entrada[strcspn(entrada, "\n")] = '\0';

    if (strlen(entrada) > 0) {
        strcpy(cliente->endereco.complemento, entrada);
    }

    // Editar bairro
    printf("\n|   Bairro anterior: %s\n", clientes[posicao].endereco.bairro);
    printf("|   Novo bairro (Enter para manter): ");
    fgets(entrada, sizeof(entrada), stdin);

    entrada[strcspn(entrada, "\n")] = '\0';

    if (strlen(entrada) > 0) {
        strcpy(cliente->endereco.bairro, entrada);
    }

    // Editar CEP
    printf("\n|   CEP anterior: %s\n", clientes[posicao].endereco.cep);
    printf("|   Novo CEP (Enter para manter): ");
    fgets(entrada, sizeof(entrada), stdin);

    entrada[strcspn(entrada, "\n")] = '\0';

    if (strlen(entrada) > 0) {
        strcpy(cliente->endereco.cep, entrada);
    }

    printf("\nCliente editado com sucesso!\n");
}

void  removerCliente() {
    exibirListaClientes();

    int codigo = 0;
    printf("|   Insira o código do cliente que voce deseja remover: \n");
    codigo = solicitaInt();
    int posicao = -1;

    for (int i = 0; i < total_clientes; i++) {
        if (codigo == clientes[i].id) {
            posicao = i;
            break;
        } 
    }if (posicao == -1) {
        printf("Cliente nao encontrado.\n");
        return;
    }
    printf("Confirma remocao de '%s'? (1-Sim / 0-Nao): ", clientes[posicao].nome);
    int confirmacao = solicitaInt();
    if (confirmacao != 1) {
        printf("Remocao cancelada.\n");
    return;
    }
    for (int i = posicao; i < total_clientes - 1; i++) {
        clientes[i] = clientes[i + 1];
    }
    total_clientes--;
    printf("Cliente removido com sucesso.\n");
}

void  funcaoCliente() {
    do {
        printf("\n------------------------------------------------------------------------------\n"); 
        printf("|                                                                              |\n"); 
        printf("|                           CADASTRO DE CLIENTES:                              |\n"); 
        printf("|                                                                              |\n"); 
        printf("|   1   →   Cadastrar novo cliente.                                            |\n"); 
        printf("|                                                                              |\n");
        printf("|   2   →   Vizualizar lista de clientes.                                      |\n"); 
        printf("|                                                                              |\n");
        printf("|   3   →   Editar cadastro de cliente.                                        |\n"); 
        printf("|                                                                              |\n");
        printf("|   4   →   Remover cliente do cadastro.                                       |\n"); 
        printf("|                                                                              |\n"); 
        printf("|   0   →   Retornar ao menu anterior. ↩                                       |\n"); 
        printf("|                                                                              |\n"); 
        printf("--------------------------------------------------------------------------------\n");
        opcao = solicitaInt();

        switch (opcao) {
            case 0:
                retornaMenuPrincipal();
            break;

            case 1:
                cadastrarCliente();
            break;

            case 2:
                exibirListaClientes();
            break;  
            
            case 3:
                editarCliente();
            break;

            case 4:
                removerCliente();
            break;
            
            default:
                printf("Opcao inválida\n");
            break;
        }
    }while (opcao != -1);
}


// Módulo de Vendas
void  exibeSubMenu() {
    char texto_tipo_produto[3][9] = {"Limpeza","Alimento","Padaria"};

        printf("\n------------------------------------------------------------------------\n"); 
        printf("|                                                                      |\n"); 
        printf("|                               PRODUTOS:                              |\n");
        printf("|                                                                      |\n");
        printf("|   Código    Descrição                 Tipo     Estoque    Vlr Unit   |\n"); 
        printf("|                                                                      |\n");
    for (int i = 0; i < total_produtos; i++) {
        printf("|   %-6d →  %-26s%-8s %7d    R$ %-8.2f|\n", produtos[i].codigo, produtos[i].descricao,texto_tipo_produto[produtos[i].categoria-1], produtos[i].estoque, produtos[i].preco);
        printf("|                                                                      |\n");
    }
        printf("|   0⃣   →   Voltar ao menu principal.   ↩                              |\n"); 
        printf("|                                                                      |\n"); 
        printf("------------------------------------------------------------------------\n");
}

void  exibeMenuCarrinho() {
    if (opcao == -1) return;

    printf("\n-------------------------------------------------------------------\n"); 
    printf("|                                                                 |\n"); 
    printf("|                             CARRINHO:                           |\n");
    printf("|                                                                 |\n");
    printf("|   Qtde      Produto                              Vlr Total      |\n");  
    printf("|                                                                 |\n");
    for (int i = 0; i < historico[total_historico].total_itens; i++) {
        printf("|   %-4d   →  %-36s R$ %-12.2f|\n", historico[total_historico].carrinho[i].quantidade, historico[total_historico].carrinho[i].produto.descricao, historico[total_historico].carrinho[i].valor);
        printf("|                                                                 |\n");
    }
    printf("|  --  --  --  --  --  --  --  --  --  --  --  --  --  --  --  -- |\n");
    printf("|                                                                 |\n");
    printf("|                              RESUMO:                            |\n");
    printf("|                                                                 |\n");
    printf("|  Materiais de limpeza: R$ %-38.2f|\n", calculaValorVenda(historico[total_historico].carrinho, historico[total_historico].total_itens, TIPO_LIMPEZA)); 
    printf("|                                                                 |\n"); 
    printf("|  Alimentos: R$ %-49.2f|\n", calculaValorVenda(historico[total_historico].carrinho, historico[total_historico].total_itens, TIPO_ALIMENTO)); 
    printf("|                                                                 |\n"); 
    printf("|  Padaria: R$ %-51.2f|\n", calculaValorVenda(historico[total_historico].carrinho, historico[total_historico].total_itens, TIPO_PADARIA));  
    printf("|                                                                 |\n"); 
    printf("|  Compra total: R$ %-46.2f|\n", calculaValorVenda(historico[total_historico].carrinho, historico[total_historico].total_itens,  TODOS_TIPOS));
    printf("|                                                                 |\n");
    printf("-------------------------------------------------------------------\n");
    Sleep(3000);
}

void  exibeConfirmacaoCartao() {
    printf("\n------------------------------------------------------------------------------\n"); 
    printf("|                                                                              |\n"); 
    printf("|                            PAGAMENTO NO CARTÃO:                              |\n"); 
    printf("|                                                                              |\n"); 
    printf("|   1⃣   →   Pagamento na maquininha OK!                                       |\n"); 
    printf("|                                                                              |\n"); 
    printf("|   0⃣   →   Pagamento na maquininha recusado. Voltar ao menu de pagamento. ↩  |\n"); 
    printf("|                                                                              |\n"); 
    printf("--------------------------------------------------------------------------------\n");
    printf("\nDigite a opção desejada: ");
}


// Funcoes principais
void  moduloCadastros() {
    while (opcao != -1){
        printf("\n------------------------------------------------------------------------------\n"); 
        printf("|                                                                              |\n"); 
        printf("|                                   CADASTROS:                                 |\n"); 
        printf("|                                                                              |\n"); 
        printf("|   1   →   Cadastro de clientes.                                            |\n"); 
        printf("|                                                                              |\n");
        printf("|   2   →   Cadastro de produtos.                                            |\n"); 
        printf("|                                                                              |\n"); 
        printf("|   0   →   Retornar ao menu anterior. ↩                                       |\n"); 
        printf("|                                                                              |\n"); 
        printf("--------------------------------------------------------------------------------\n");
        opcao = solicitaInt();

        switch (opcao) {
            case 0:
                retornaMenuPrincipal();
            break;

            case 1: // Cadastrar novo cliente
                funcaoCliente();
            break;

            case 2: // Cadastrar novo produto
                funcaoProduto();
            break;

            default:
                printf("Opcao inválida\n");
            break;
        }
    }
}

void  moduloVendas() {
    while (opcao != -1){
        if (!total_clientes) {
            printf("-   %d clientes cadastrados. É necessário o cadastro de ao menos 1 cliente para realizar a venda.\n", total_clientes);
            retornaMenuPrincipal();
            return;
        }

        exibeSubMenu();
        printf("\nDigite o código do produto escolhido: ");
        opcao = solicitaInt();

        switch (opcao){
        case 0:
            retornaMenuPrincipal();
        break;
        
        default:
            int posicao_buscada = buscarIndice(opcao);

            // produto não encontrado
            if (posicao_buscada == -1) {
                printf("Codigo invalido!\n");
                Sleep(1000);
                break;
            }

            // sem estoque
            if (produtos[posicao_buscada].estoque<= 0) {
                printf("\nDesculpe, esse produto esta esgotado.\n");
                Sleep(1000);
                break;
            }

            // adiciona ao carrinho
            addProdutoCarrinho(produtos[posicao_buscada]);
        break;
        }
    }
}

void  moduloPagamentos() {
    if (opcao == -1) return;

    if(historico[total_historico].id <= 0) {
        printf("\nNenhuma compra realizada!\n");
        retornaMenuPrincipal();
        return;
    }
    
    float total;
    float valor_recebido_dinheiro;
    float valor_faltante;
    float desconto;
    float troco;

    if (total_pagamentos >= capacidade_pagamentos){

        capacidade_pagamentos *= 2;
        Pagamento *temp = realloc(pagamentos,sizeof(Pagamento)*capacidade_pagamentos);

        if(temp == NULL){
            printf("Erro de memória!\n");
            return;
        }
        pagamentos = temp;
    }

    total = calculaValorVenda(historico[total_historico].carrinho, historico[total_historico].total_itens, TODOS_TIPOS);

    printf("\n-------------------------------------------------------------------\n"); 
    printf("|                                                                 |\n"); 
    printf("|                             PAGAMENTO:                          |\n");
    printf("|                                                                 |\n"); 
    printf("|   1⃣   →   Dinheiro                                              |\n"); 
    printf("|            -Compras até R$ 50 = 5%% OFF                          |\n"); 
    printf("|            -Compras até R$ 200 = 10%% OFF                        |\n"); 
    printf("|            -Desconto personalizado para compras acima de R$ 200 |\n"); 
    printf("|                                                                 |\n"); 
    printf("|   2⃣   →   Cartão                                                |\n");
    printf("|                                                                 |\n");
    printf("|   3⃣   →   Pagamento Misto                                       |\n");
    printf("|                                                                 |\n");
    printf("|   4⃣   →   Resetar compra                                        |\n"); 
    printf("|                                                                 |\n"); 
    printf("|   0⃣   →   Voltar ao menu principal.   ↩                         |\n"); 
    printf("|                                                                 |\n"); 
    printf("-------------------------------------------------------------------\n");
    printf("\nDigite a opção desejada: ");
    opcao = solicitaInt();

    switch (opcao) {
        case 1:
            desconto = calculaDesconto(total);
            printf("\nDesconto: R$ %.2f\n", total * desconto);

            total -= total * desconto;

            printf("\nTotal com desconto: R$ %.2f\n", total);
            printf("\nInforme o valor recebido em dinheiro:\n");

            valor_recebido_dinheiro = solicitaFloat();

            while(valor_recebido_dinheiro < total) {

                printf("\nValor insuficiente!\n");
                valor_recebido_dinheiro = solicitaFloat();
            }

            troco = valor_recebido_dinheiro - total;

            printf("\nTroco: R$ %.2f\n", troco);

            caixa += total;

            pagamentos[total_pagamentos].pago_dinheiro = total;
            pagamentos[total_pagamentos].pago_cartao = 0;
            pagamentos[total_pagamentos].tipo = 'D';
            historico[total_historico].pago = 'P';

            total_pagamentos++;
            total_historico++;

            printf("\nPagamento confirmado!\n");
            retornaMenuPrincipal();
        break;

        case 2:
            printf("\nValor total: R$ %.2f\n", total);

            exibeConfirmacaoCartao();
            opcao = solicitaInt();

            switch(opcao) {
                case 1:
                    pagamentos[total_pagamentos].pago_dinheiro = 0;
                    pagamentos[total_pagamentos].pago_cartao = total;
                    pagamentos[total_pagamentos].tipo = 'C';
                    historico[total_historico].pago = 'P';

                    total_pagamentos++;
                    total_historico++;

                    printf("\nPagamento confirmado!\n");
                    retornaMenuPrincipal();
                break;

                case 0:
                    printf("\nPagamento recusado!\n");
                break;
            }

        break;

        case 3: // Pagamento misto

            printf("\nValor total: R$ %.2f\n", total);
            printf("\nInforme o valor em dinheiro:\n");

            valor_recebido_dinheiro = solicitaFloat();

            if(valor_recebido_dinheiro > total) {

                printf("\nValor maior que o total!\n");
                break;
            }

            valor_faltante = total - valor_recebido_dinheiro;

            printf("\nFaltam R$ %.2f no cartão\n", valor_faltante);

            exibeConfirmacaoCartao();
            opcao = solicitaInt();

            switch(opcao) {
                case 1:

                    pagamentos[total_pagamentos].pago_dinheiro = valor_recebido_dinheiro;
                    pagamentos[total_pagamentos].pago_cartao = valor_faltante;
                    pagamentos[total_pagamentos].tipo = 'M';
                    historico[total_historico].pago = 'P';

                    total_pagamentos++;
                    total_historico++;
                    caixa += valor_recebido_dinheiro;

                    printf("\nPagamento confirmado!\n");
                    retornaMenuPrincipal();
                break;

                case 0:
                    printf("\nPagamento recusado!\n");
                break;
            }
        break;

        case 4: // resetar

            for(int i = 0; i < historico[total_historico].total_itens; i++) {

                gestorEstoque(
                    historico[total_historico].carrinho[i].produto.codigo,
                    historico[total_historico].carrinho[i].quantidade
                );
            }

            historico[total_historico].id = 0;
            historico[total_historico].cliente = 0;
            historico[total_historico].pago = '\0';
            historico[total_historico].total_itens = 0;
            historico[total_historico].capacidade_carrinho = 0;
            free(historico[total_historico].carrinho);
            historico[total_historico].carrinho = NULL;

            printf("\nCompra cancelada!\n");

        break;

        case 0:
            retornaMenuPrincipal();
        break;

        default:
            printf("\nOpcao invalida!\n");
        break;
    }
}

void  moduloRelatorios() {
    while (opcao != -1){
        printf("\n-------------------------------------------------------------------\n");
        printf("|                                                                 |\n");
        printf("|                         RELATÓRIOS:                             |\n");
        printf("|                                                                 |\n");
        printf("|   1   →  Listagem de clientes.                                  |\n");
        printf("|                                                                 |\n");
        printf("|   2   →  Listagem de produtos.                                  |\n");
        printf("|                                                                 |\n");
        printf("|   3   →  Listagem de vendas.                                    |\n");
        printf("|                                                                 |\n");
        printf("|   0   →  Sair. ↩                                                |\n");
        printf("|                                                                 |\n");
        printf("-------------------------------------------------------------------\n\n");
        printf("\nDigite a opção desejada: ");  
        opcao = solicitaInt();

        switch (opcao) {
            case 0:
                retornaMenuPrincipal();
            break;

            case 1: // Relatorio de vendas
                exibirListaClientes();
                Sleep(2000);
            break;

            case 2: // Lista de produtos
                exibirListaProdutos();
                Sleep(2000);
            break;

            case 3:
                exibirListaVendas();
                Sleep(2000);
            break;
            
            default:
                printf("Opcao inválida.\n");
            break;
        }
    }
}

void  saida() {
    if (caixa_aberto) {
        printf("\nO caixa esta aberto!\nFeche o caixa para finalizar o programa.\n");
        retornaMenuPrincipal();
    } else {
        printf("\nVoce fechou a loja!\nAte a proxima!!\n");
    }
}
