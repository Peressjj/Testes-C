#include <stdio.h>
// constantes simbólicas usando CONST

const int LIMITE = 2500;
const float IMPOSTO = 0.035;

int main() {

    float salario = 0;
    float salariofinal = 0;

    printf("\nInsira seu salario: ");
    scanf("%f", &salario);

    if (salario > LIMITE) {
        salariofinal = salario - (salario * IMPOSTO);
        printf("Salario: R$%.2f\n", salario);
        printf("Imposto: 3,5%%");
        printf("Desconto: R$%.2f\n\n", (salario * IMPOSTO));
        printf("Salario final: R$%.2f\n\n", salariofinal);
    } else {
        salariofinal = salario;
        printf("Salario: R$%.2f\n", salario);
        printf("Limite de salario: R$%d\n", LIMITE);
        printf("Imposto: 0%%\n");
        printf("Salario total: R$%.2f\n\n", salariofinal);
    }
























return 0;
}