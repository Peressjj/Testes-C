// Bibliotecas
#include   <stdio.h> // De entrada e saída de dados
#include  <stdlib.h> // Usada em strtof(), para converter string em float, e em rand() e srand(), para gerar números aleatórios
#include    <time.h> // Usada para a função time(), que gera um número inteiro baseado no horário do sistema, utilizado para gerar um número aleatório
#include <windows.h> // Usada para a função Sleep(), que pausa o programa por um tempo determinado

// Constantes simbólicas definidas
#define MAX_DESCRICAO 26
#define  MAX_CARRINHO 21
#define MAX_HISTORICO 500
#define QTDE_PRODUTOS 21
#define  TIPO_LIMPEZA 1
#define TIPO_ALIMENTO 2
#define  TIPO_PADARIA 3
#define   TODOS_TIPOS 0
#define   MAXCLIENTES 50

// Tipos de estruturas definidas
typedef struct Produto {
    int   codigo_produto;
    char  descricao_produto[MAX_DESCRICAO];
    float preco_produto;
    int   tipo_produto; //1 para limpeza, 2 para alimentos e 3 para padaria
    int   estoque_produto; //Quantidade disponível do produto em estoque
} Produto;
    Produto lista_produtos[QTDE_PRODUTOS] = {
        {101,       "Detergente"      ,  1.99,  TIPO_LIMPEZA, 0},
        {102,   "Sabao em po (1Kg)"   ,  8.99,  TIPO_LIMPEZA, 0},
        {103,        "Esponja"        ,  1.50,  TIPO_LIMPEZA, 0},
        {104,     "Amaciante (1L)"    , 15.00,  TIPO_LIMPEZA, 0},
        {105, "Bucha de Pia (kit c/3)",  4.99,  TIPO_LIMPEZA, 0},
        {106,   "Desinfetante(1Lt)"   ,  7.99,  TIPO_LIMPEZA, 0},
        {107,   "Sabao em Barra(Un)"  ,  1.00,  TIPO_LIMPEZA, 0},
        {201,          "Cafe"         , 19.99, TIPO_ALIMENTO, 0},
        {202,       "Leite (1L)"      ,  5.90, TIPO_ALIMENTO, 0},
        {203,      "Arroz (1Kg)"      ,  4.50, TIPO_ALIMENTO, 0},
        {204,   "Feijao preto (1Kg)"  ,  8.00, TIPO_ALIMENTO, 0},
        {205,     "Acucar (1Kg)"      ,  5.00, TIPO_ALIMENTO, 0},
        {206,       "Sal (1kg)"       ,  2.00, TIPO_ALIMENTO, 0},
        {207, "Farinha de Trigo (1kg)",  5.00, TIPO_ALIMENTO, 0},
        {301,      "Pao de Forma"     ,  9.50,  TIPO_PADARIA, 0},
        {302,      "Pao Integral"     , 12.50,  TIPO_PADARIA, 0},
        {303,   "Pao Frances (Unid)"  ,  1.90,  TIPO_PADARIA, 0},
        {304,         "Sonho"         ,  8.50,  TIPO_PADARIA, 0},
        {305,      "Biscoito(kg)"     , 12.50,  TIPO_PADARIA, 0},
        {306,     "Pao Doce (Un)"     ,  2.50,  TIPO_PADARIA, 0},
        {307,      "Salgado (Un)"     , 17.50,  TIPO_PADARIA, 0}
    };


typedef struct Venda {
    Produto produto_venda;
    int     quantidade_venda;
    float   valor_venda;
} Venda;

Venda historico[MAX_HISTORICO];
Venda carrinho[MAX_CARRINHO];


typedef struct CadastroClientes {
    int codigocliente;
    char nomecliente[50];
    char cpfcliente[50];
    char enderecocliente[50];
    char telefonecliente[50];
} CadastroClientes;

CadastroClientes listaclientes[MAXCLIENTES];


// Variáveis declaradas
    int sub_menu_buscado;
    int posicao_buscada;
    int posicao_final_historico = 0;
    int posicao_final_carrinho = 0;
    int caixa_aberto = 0;
    int opcao = -1;
    int clientescadastrados = 0;

    float total;
    float valor_recebido;
    float fundo_caixa_ini;
    float caixa;
    float desconto;
    float troco;


// Prototipagem de Funções
    int solicitaInt();    
    float solicitaFloat();
    float calculaDesconto(float valor);
    void abreCaixa();
    float calculaTotal(Venda lista[], int posicao_final_lista, int tipo_buscado);
    int buscarIndice(int codigo);
    void gestorEstoque(int codigo, int quantidade);
    void zerarLista(Venda lista[], int *posicao_final_lista);
    void addVendaCarrinho(Produto produto); 
    void addVendaHistorico(float percent);
    void exibeMenuPrincipal();
    void retornaMenuPrincipal();
    void exibeSubMenu(int tipo_menu);
    void exibeMenuCarrinho();
    void exibeMenuPagamento();
    void exibeConfirmacaoCartao();
    void exibeRelatorio();
    void geradordenumeros();
    void exibemenucliente();
    void cadastrarcliente();
    void exibirlistaclientes();
    void removercliente();
    void funcaocadastro();


// Função principal: mantém o programa rodando enquanto o usuário não escolher '0 - Sair'.
int main() {

    while (opcao != 0) { //Enquanto a opção for diferente de zero exibe o menu principal ( 0 para sair do programa)
        exibeMenuPrincipal();
        opcao = solicitaInt(); //Lê a opção do produto escolhido

        if (opcao == TIPO_LIMPEZA || opcao == TIPO_ALIMENTO || opcao == TIPO_PADARIA) { //Se a opção for 1, 2 ou 3 exibe os menus de venda
            if (!caixa_aberto) {
                printf("Abra o caixa para acessar os menus de venda!\n");
                retornaMenuPrincipal();
            }

            sub_menu_buscado = opcao;

            while (opcao != -1) { //Enquanto a opção for diferente de -1 exibe os menus de venda
                exibeSubMenu(sub_menu_buscado);
                opcao = solicitaInt(); //Lê a opção do produto escolhido

                switch (opcao) {
                    case 0: 
                        retornaMenuPrincipal();
                    break;
                    
                    default:
                        posicao_buscada = buscarIndice(opcao); //Verifica se o codigo digitado corresponde a um produto
                        if (posicao_buscada == -1 || lista_produtos[posicao_buscada].tipo_produto != sub_menu_buscado) {
                            printf("Codigo invalido!\n"); // Se o produto não for encontrado ou não ser desse menu
                            Sleep(1000); //Pausa de 1 seg
                            break;
                        }
                        if (lista_produtos[posicao_buscada].estoque_produto <= 0) { //Se não tiver estoque disponível do produto
                            printf("\nDesculpe, esse produto está esgotado no momento.\n");
                            Sleep(1000); //Pausa de 1 seg
                            break;
                        }
                        addVendaCarrinho(lista_produtos[posicao_buscada]); //Se tudo certo adiciona o produto ao carrinho atual
                        Sleep(1000); //Pausa de 1 seg
                    break; 
                }
            }
        } else if (opcao == 4) { //Exibe o carrinho da venda atual apenas se o caixa estiver aberto
            if (caixa_aberto) { 
                exibeMenuCarrinho();
                retornaMenuPrincipal();
            } else {
                printf("Abra o caixa para acessar o carrinho!\n");
                retornaMenuPrincipal();
            }
        } else if (opcao == 5) { //Exibe o menu de pagamento e finaliza a venda
            if (!caixa_aberto) {
                printf("Abra o caixa para acessar o menu de pagamento!\n");
                retornaMenuPrincipal();
            }
            while (opcao !=-1) {
                exibeMenuPagamento();
                opcao = solicitaInt();
                switch(opcao) {
                    case 1://Pagamento em dinheiro, com desconto
                        exibeMenuCarrinho(); //Exibe o carrinho da venda atual antes de finalizar
                        
                        total = calculaTotal(carrinho, posicao_final_carrinho, TODOS_TIPOS);
                        desconto = calculaDesconto(total); //Calcula o desconto
                        printf("Desconto: R$ %.2f\n\n", total * desconto); //Mostra o desconto

                        total -= total * desconto; //Subtrai o desconto do total da venda
                        printf("A pagar: R$ %.2f\n\n", total); //Mostra o valor a pagar após o desconto
                        
                        printf("Informe o valor recebido em dinheiro!\n");
                        valor_recebido = solicitaFloat();

                        while (valor_recebido < total || valor_recebido - total > caixa) {
                            printf("\nValor ou troco em caixa insuficiente!\nPor favor, solicite um valor entre R$ %.2f e R$ %.2f.\nObs: use ponto para separar casas decimais!\n", total, caixa + total);
                            valor_recebido = solicitaFloat();
                        }

                        troco = valor_recebido - total; //Calcula o troco
                        printf("\nTroco: R$ %.2f\n", troco);

                        caixa += total; //Adiciona o valor da venda ao caixa, já com o desconto aplicado
                        addVendaHistorico(desconto); //Adiciona o carrinho ao "histórico de vendas"
                        printf("\nPagamento confirmado!\n");

                        zerarLista(carrinho, &posicao_final_carrinho); // Zerar o "carrinho" da venda atual para a próxima compra
                        retornaMenuPrincipal(); // Voltar ao menu principal
                    break; 
                                        
                    case 2: //Pagamento no cartão, sem desconto
                        exibeMenuCarrinho(); //Exibe o carrinho da venda atual antes de finalizar
                        printf("Valor total a pagar: R$ %.2f\n", total);

                        exibeConfirmacaoCartao(); //Confirmação de pagamento no cartão
                        opcao = solicitaInt();

                        switch(opcao) {
                            case 1:
                                addVendaHistorico(0); //Adiciona o carrinho ao histórico de vendas sem desconto por ser pagamento c/ cartão
                                printf("\nPagamento confirmado!\n");

                                zerarLista(carrinho, &posicao_final_carrinho); // Zera o carrinho para a próxima compra
                                retornaMenuPrincipal();
                            break;
                            
                            case 0: 
                                printf("\nErro no pagamento!\n");
                                Sleep(1000); //Pausa de 1 seg
                            break;    
                        }
                    break; 
                        
                    case 3: //Resetar compra, zerando o carrinho e voltando para o menu principal
                        for (int i = 0; i < posicao_final_carrinho; i++) {
                            gestorEstoque(carrinho[i].produto_venda.codigo_produto, carrinho[i].quantidade_venda); //Devolve a quantidade do produto vendida para o estoque
                        }
                        zerarLista(carrinho, &posicao_final_carrinho); // Zerar o "carrinho" da venda atual para a próxima compra
                        retornaMenuPrincipal();// Voltar ao menu principal
                    break;
                    
                    case 0:  //Retorna para o menu principal
                        retornaMenuPrincipal();
                    break;
                    
                    default: //Caso a opção não exista no menu
                        printf("\nDigite uma opcao valida!\n");
                        Sleep(1000); //Pausa de 1 seg
                    break;    
                } 
            }
        } else if (opcao == 6) { //Abertura de caixa
            if (caixa_aberto) printf("O caixa ja esta aberto!\n");
            else abreCaixa();
            Sleep(1000); //Pausa de 1 seg
        } else if (opcao == 7) { //Fechamento de caixa
            if (caixa_aberto){ 
                exibeRelatorio();
                caixa_aberto = 0;
                printf("\nCaixa fechado!\nAbra novamente caso queira realizar uma venda!!\n");
            } else {
                printf("O caixa ja esta fechado!\n");
                Sleep(1000); //Pausa de 1 seg
            }
        } else if (opcao == 8) {
            funcaocadastro();
        } else if (opcao == 0) { //Encerra o programa (no menu principal 0 - Sair)
            if (caixa_aberto) {
                printf("\nO caixa esta aberto!\nFeche o caixa para finalizar o programa.\n");
                retornaMenuPrincipal();
            } else {
                printf("\nVoce fechou a loja!\nAte a proxima!!\n");
            }
        }
    }
    return 0;
}

//---------------------------------------------------------------------------------------------------------||
// Corpo das Funções
int solicitaInt(){
    int numero;

    while (scanf("%d", &numero) != 1) {
        printf("Entrada inválida. Digite um número inteiro: ");
        getchar();
    }

    return numero;
}

float solicitaFloat(){
    float valor;
    char *nao_float, texto[10];

    do{
        printf("\nDigite um valor real (Formato: 0.00): ");
        scanf("%s", texto);
        valor = strtof(texto, &nao_float); //Converte a string de texto para float, armazenando o valor convertido em valor e o endereço do primeiro caractere inválido em nao_float
    }while(*nao_float != '\0');

    return valor;
}

float calculaDesconto(float valor){ //Calcula o desconto a ser aplicado no pagamento em dinheiro
    float percent = (valor <= 50) ? 0.05 : (valor < 200) ? 0.10 : 0; //Operador ternário para calcular o desconto com base no valor da compra

    if (percent != 0) return percent; //Se o ternário retornar 0 é porque o usuário deve informar desconto personalizado
    
    do{
        printf("\nVoce deve inserir o percentual de desconto a ser aplicado (entre 10 e 100)! ");
        percent = solicitaFloat()/100;
    }while(percent < 0.10 || percent > 1.00);
    
    return percent;
}

void abreCaixa(){

    printf("\nPara a abertura do caixa, informe o valor do suprimento inicial: \n");
    fundo_caixa_ini = solicitaFloat();

    caixa = fundo_caixa_ini; //Inicializa o fundo de caixa com o valor do suprimento inicial informado
    
    printf("\nCaixa aberto com suprimento inicial de R$ %.2f\n", fundo_caixa_ini);

    caixa_aberto = 1;

    srand(time(NULL)); //Inicializa a semente do gerador de números aleatórios para a determinação dos estoques

    printf("\nAntes de registrar as vendas voce deve informar manualmente o estoque atual da padaria!\n");

    for (int i = 0; i < QTDE_PRODUTOS; i++ ){
        if (lista_produtos[i].tipo_produto != TIPO_PADARIA){ //Se não for de padaria, determina um estoque aleatório pro produto e continua o loop
            lista_produtos[i].estoque_produto = rand() % 100 + 1;
            continue;
        }
        
        printf("\nDigite a quantidade de %s em estoque: ",lista_produtos[i].descricao_produto);
        lista_produtos[i].estoque_produto = solicitaInt();
    }
}

float calculaTotal(Venda lista[], int posicao_final_lista, int tipo_buscado){ //Calcula um total de acordo com o tipo informado
    float valor;

    for (int i = 0; i < posicao_final_lista; i++) {
        if (lista[i].produto_venda.tipo_produto == tipo_buscado || tipo_buscado == TODOS_TIPOS)
            valor += lista[i].valor_venda; //É executado caso o tipo do produto seja o tipo buscado. sempre é executado quando tipo_buscado == TODOS_TIPOS.
    }

    return valor;
}

int buscarIndice(int codigo){
    for (int indice = 0; indice < QTDE_PRODUTOS; indice++){
        if (lista_produtos[indice].codigo_produto == codigo)
            return indice;
    }
    return -1; //Caso o código do produto não seja encontrado na lista_produtos
}

void gestorEstoque(int codigo, int quantidade){ //Atualiza o estoque do produto, somando a quantidade devolvida ou subtraindo a quantidade vendida
    lista_produtos[buscarIndice(codigo)].estoque_produto += quantidade;
}

void zerarLista(Venda lista[], int *posicao_final_lista){ //Apaga todas as informações de uma lista de vendas
    for (int i = 0; i < *posicao_final_lista; i++) {
        lista[i] = (Venda){
            {0, "", 0.00, 0, 0}, //Zera produto
            0,                   //Zera quantidade vendida
            0.00,                //Zera valor da venda
        };
    }
    *posicao_final_lista = 0; //Zera o índice da lista
}

void addVendaCarrinho(Produto produto){ //Adiciona uma saída de produto (realiza uma 'venda'), atualizando o 'histórico' de vendas
    printf("\nVocê escolheu %s.\nQuantos você deseja? ", produto.descricao_produto);

    int posicao = posicao_final_carrinho;
    int quantidade_vendida = solicitaInt();

    if (quantidade_vendida < 0){ //Valida se a quantidade é positiva
        printf("A quantidade deve ser positiva!");
        Sleep(1000); //Pausa de 1 seg
        return;
    }

    if (quantidade_vendida > produto.estoque_produto){ //Valida se tem disponível em estoque a quantidade desejada
        printf("\nDesculpe, não temos essa quantidade em estoque. Temos apenas %d unidades disponíveis.\n", produto.estoque_produto);
        Sleep(1000); //Pausa de 1 seg
        return;
    }

    gestorEstoque(produto.codigo_produto, -quantidade_vendida); //Atualiza o estoque do produto, subtraindo a quantidade escolhida

    for (int i = 0; i < posicao_final_carrinho; i++){
        if (carrinho[i].produto_venda.codigo_produto != produto.codigo_produto) continue; //Verifica se o produto já foi adicionado ao carrinho anteriormente
        
        quantidade_vendida += carrinho[i].quantidade_venda; //Somar a quantidade anterior com a quantidade adicional
        posicao = i; //Atualiza a posicao que o produto deve ser adicionado/atualizado no carrinho
    }

    carrinho[posicao] = (Venda){ //Atualiza as informações da venda no carrinho
        produto,
        quantidade_vendida,
        produto.preco_produto * quantidade_vendida
    };

    printf("\nTotal: R$ %.2f\n", carrinho[posicao].valor_venda); //Mostra o valor total da venda do produto escolhido
    
    if (posicao == posicao_final_carrinho)
        posicao_final_carrinho++; //Incrementa o índice do carrinho no caso de ser um novo produto
}

void addVendaHistorico(float percent){//Adiciona o carrinho ao "histórico de vendas"
    for (int i = 0; i < posicao_final_carrinho; i++) {
        carrinho[i].valor_venda -= carrinho[i].valor_venda * percent; //Aplica o desconto no valor de cada item do carrinho, caso haja desconto por pagamento em dinheiro
        historico[posicao_final_historico] = carrinho[i];
        posicao_final_historico++; //Incrementa o índice do "histórico de vendas"
    }
}

void exibeMenuPrincipal(){
    printf("\n-------------------------------------------------------------------\n");
    printf("|                                                                 |\n");
    printf("|                           LOJA DA BERE                          |\n");
    printf("|                                                                 |\n");
    printf("|   1   →  Material de limpeza.                                   |\n");
    printf("|                                                                 |\n");
    printf("|   2   →  Venda de alimentos.                                    |\n");
    printf("|                                                                 |\n");
    printf("|   3   →  Padaria.                                               |\n");
    printf("|                                                                 |\n");
    printf("|   4   →  Mostrar carrinho.                                      |\n");
    printf("|                                                                 |\n");
    printf("|   5   →  Pagamento.                                             |\n");
    printf("|                                                                 |\n");
    printf("|   6   →  Abertura de Caixa.                                     |\n");
    printf("|                                                                 |\n");
    printf("|   7   →  Fechamento de Caixa.                                   |\n");
    printf("|                                                                 |\n");
    printf("|   8   →  Cadastro de clientes.                                  |\n");
    printf("|                                                                 |\n");
    printf("|   0   →  Sair. ↩                                                |\n");
    printf("|                                                                 |\n");
    printf("-------------------------------------------------------------------\n\n");
    printf("\nDigite a opção desejada: ");
}

void retornaMenuPrincipal(){
    printf("\n----------------- Retornando ao menu principal! ↩ -----------------\n");
    opcao=-1;
    Sleep(2000); //Pausa o programa por 2 segundos
}

void exibeSubMenu(int tipo_menu){
    char titulo_sub_menu[3][66] = {
        "                      MATERIAL DE LIMPEZA:                       ",
        "                           ALIMENTOS:                            ",
        "                            PADARIA:                             "
    };

    printf("\n-------------------------------------------------------------------\n"); 
    printf("|                                                                 |\n"); 
    printf("|%s|\n", titulo_sub_menu[tipo_menu - 1]);
    printf("|                                                                 |\n");
    printf("|   Código    Descrição                  Estoque    Vlr Unit      |\n"); 
    printf("|                                                                 |\n"); 
    for (int i = 0; i < QTDE_PRODUTOS; i++){
        if (lista_produtos[i].tipo_produto != tipo_menu) continue;

        printf("|   %-6d →  %-26s %-7d    R$ %-11.2f|\n", lista_produtos[i].codigo_produto, lista_produtos[i].descricao_produto, lista_produtos[i].estoque_produto, lista_produtos[i].preco_produto);
        printf("|                                                                 |\n");
    }
    printf("|   0⃣   →   Voltar ao menu principal.   ↩                         |\n"); 
    printf("|                                                                 |\n"); 
    printf("-------------------------------------------------------------------\n");
    printf("\nDigite o código do produto escolhido: ");
}

void exibeMenuCarrinho(){
    printf("\n-------------------------------------------------------------------\n"); 
    printf("|                                                                 |\n"); 
    printf("|                             CARRINHO:                           |\n");
    printf("|                                                                 |\n");
    printf("|   Qtde      Produto                              Vlr Total      |\n");  
    printf("|                                                                 |\n");
    for (int i = 0; i < posicao_final_carrinho; i++) {
        printf("|   %-4d   →  %-36s R$ %-12.2f|\n", carrinho[i].quantidade_venda, carrinho[i].produto_venda.descricao_produto, carrinho[i].valor_venda);
        printf("|                                                                 |\n");
    }
    printf("|  --  --  --  --  --  --  --  --  --  --  --  --  --  --  --  -- |\n");
    printf("|                                                                 |\n");
    printf("|                              RESUMO:                            |\n");
    printf("|                                                                 |\n");
    printf("|  Materiais de limpeza: R$ %-38.2f|\n", calculaTotal(carrinho, posicao_final_carrinho, TIPO_LIMPEZA)); 
    printf("|                                                                 |\n"); 
    printf("|  Alimentos: R$ %-49.2f|\n", calculaTotal(carrinho, posicao_final_carrinho, TIPO_ALIMENTO)); 
    printf("|                                                                 |\n"); 
    printf("|  Padaria: R$ %-51.2f|\n", calculaTotal(carrinho, posicao_final_carrinho, TIPO_PADARIA));  
    printf("|                                                                 |\n"); 
    printf("|  Compra total: R$ %-46.2f|\n", calculaTotal(carrinho, posicao_final_carrinho, TODOS_TIPOS));
    printf("|                                                                 |\n");
    printf("-------------------------------------------------------------------\n");
}

void exibeMenuPagamento(){
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
    printf("|   3⃣   →   Resetar compra                                        |\n"); 
    printf("|                                                                 |\n"); 
    printf("|   0⃣   →   Voltar ao menu principal.   ↩                         |\n"); 
    printf("|                                                                 |\n"); 
    printf("-------------------------------------------------------------------\n");
    printf("\nDigite a opção desejada: ");
}

void exibeConfirmacaoCartao(){
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

void exibeRelatorio(){
    printf("\n-------------------------------------------------------------------\n"); 
    printf("|                                                                 |\n"); 
    printf("|                      RELATÓRIO DO DIA                           |\n"); 
    printf("|                                                                 |\n"); 
    printf("|  1. Valor (R$) de Abertura – R$ %-32.2f|\n", fundo_caixa_ini);
    printf("|  2. Faturamento Total – R$ %-37.2f|\n", calculaTotal(historico, posicao_final_historico, TODOS_TIPOS));
    printf("|  3. Faturamento por categoria                                   |\n");
    printf("|      a. Material de Limpeza – R$ %-31.2f|\n", calculaTotal(historico, posicao_final_historico, TIPO_LIMPEZA));
    printf("|      b. Venda de Alimentos – R$ %-32.2f|\n", calculaTotal(historico, posicao_final_historico, TIPO_ALIMENTO));
    printf("|      c. Padaria - R$ %-43.2f|\n", calculaTotal(historico, posicao_final_historico, TIPO_PADARIA));
    printf("-------------------------------------------------------------------\n");
    Sleep(3000);
}

void geradordenumeros() {
    srand(time(NULL));
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