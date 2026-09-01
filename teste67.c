#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Calculadora de salário

int main() {
    
    struct soldo {
        char nomefuncionario[50][50];
        float valorhora;
        float horastrabalhadas;
        float valorvendas;
        float comissao;
    };
    
    struct soldo funcionarios[50];
    

    printf("\nInsira o nome do funcionario:\n");
    scanf("%s", &funcionarios->nomefuncionario[0]);

    printf("\nInsira o valor da hora de %s: \n", funcionarios->nomefuncionario[0]);
    scanf("%f", &funcionarios->valorhora);

    printf("\nInsira a quantidade de horas trabalhadas: \n");
    scanf("%f", &funcionarios->horastrabalhadas);

    printf("\nInsira o valor de vendas mensais: \n");
    scanf("%f", &funcionarios->valorvendas);

    printf("\nInsira o percentual de comissao deste funcionario:");
    scanf("%f", &funcionarios->comissao);

    float horassoldo = 0;
    horassoldo += funcionarios->valorhora * funcionarios->horastrabalhadas;

    float comissaosoldo = 0;
    comissaosoldo += funcionarios->comissao * funcionarios->valorvendas;

    printf("O salario de %s é: \n", funcionarios->nomefuncionario);
    printf("Horas trabalhadas x valor da hora: %f\n", horassoldo);
    printf("Comissao x valor de vendas: %f\n", comissaosoldo);
    printf("\n\nTotal: R$%.2f\n", (horassoldo + comissaosoldo));








return 0;
}