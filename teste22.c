#include <stdio.h>
#include <string.h>

int main() {

struct Carro {
    char nome[50];
    int ano;
    float motor;
};

    struct Carro c1; 

    printf("Insira o nome do carro: ");
    scanf("%s", c1.nome);

    printf("Insira o ano do carro: ");
    scanf("%d", &c1.ano);

    printf("Insira a motorização do motor: ");
    scanf("%f", &c1.motor);

    printf("Nome: %s\n", c1.nome);
    printf("Ano: %d\n", c1.ano);
    printf("Motor:%.1f\n", c1.motor);


return 0;
}