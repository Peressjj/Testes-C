#include <stdio.h>
// sistema de calculo de salario com funcao e menu automático

    typedef struct funcionarios {
        int codigofuncionario;
        char nomefuncionario[50];
        float valorhora;
        float horastrabalhadas;
        float comissao;
        float valorvendas;
    } funcionarios;
    funcionarios listafuncionarios[30] = {
        {0, "", 0, 0, 0, 0},
        {1, "Carla Rocha", 300, 0, 0.015, 0},
        {2, "Willian Thuler", 300, 0, 0.012, 0},
        {3, "Andréia Rosa", 250, 0, 0.010, 0},
        {4, "Amanda Nunez", 250, 0, 0.010, 0},
        {5, "Cynthia Lopez", 250, 0, 0.010, 0},
        {6, "Alessandro Antunes", 200, 0, 0.008, 0},
        {7, "Thyffani Andriele", 200, 0, 0.008, 0},
        {8, "Keilla Araújo", 150, 0, 0.007, 0},
        {9, "Rebeca Guimaraes", 150, 0, 0.006, 0}
    };


void menu() {

    printf("-------------------------------------------------\n");
    printf("                                                 \n");
    printf("    1 - Calcular salario.                        \n");
    printf("                                                 \n");
    printf("    2 - Exibir lista de funcionários.            \n");
    printf("                                                 \n");
    printf("    0 - Sair.                                    \n");
    printf("                                                 \n");
    printf("-------------------------------------------------\n");

};

float calcularsalario(int i) {

    float horas = listafuncionarios[i].valorhora * listafuncionarios[i].horastrabalhadas;
    float comis = listafuncionarios[i].comissao * listafuncionarios[i].valorvendas;

    return horas + comis;
}

void menucalcularsalario() {

    int op1 = -1;

    printf("Selecione o venderor:\n");
    for (int i = 0; i < 9; i++) {
        printf("%d  -   %s\n", listafuncionarios[i].codigofuncionario, listafuncionarios[i].nomefuncionario);
    }
    scanf("%d", &op1);
    
    if (op1 >= 1 && op1 <= 9) {
        printf("Nome: %s\n", listafuncionarios[op1].nomefuncionario);
        printf("Valor da hora: %.2f\n", listafuncionarios[op1].valorhora);
        printf("Comissao: %.2f\n", listafuncionarios[op1].comissao);

        printf("Insira o valor das vendas mensal de %s: ", listafuncionarios[op1].nomefuncionario);
        scanf("%f", &listafuncionarios[op1].valorvendas);

        printf("\n\nInsira a quantidade de horas trabalhadas de %s: ", listafuncionarios[op1].nomefuncionario);
        scanf("%f", &listafuncionarios[op1].horastrabalhadas);
        
        float total = calcularsalario(op1);
        printf("Salario total: %.2f\n", total);
    } else {
        printf("Opção inválida.\n");
    }
}

void menulistafuncionarios() {

    int lixo = 0;
    printf("-------------------------------------------------\n");
    for (int i = 1; i < 9; i++) {
        printf("\n\n");
        printf("Nome:\t%s", listafuncionarios[i].nomefuncionario);
        printf("\n");
        printf("Valor da hora: %.1f", listafuncionarios[i].valorhora);
        printf("\n");
        printf("Percentual de comissao de %s: %.3f", listafuncionarios[i].nomefuncionario, listafuncionarios[i].comissao);
    }
    scanf("%d", &lixo);
}

void limpartela() {
        /* #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif */
        
        printf("\n\n (LIMPAR TELA) \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }


int main() {

    int opcao = -1;
        
    while (opcao != 0) {
        limpartela();
        menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                limpartela();
                menucalcularsalario();
            break;

            case 2:
                limpartela();
                menulistafuncionarios();
            break;

            default:
                printf("Opcao invalida.\n");
            break;
        }
    }
    
    
    


























return 0;
}