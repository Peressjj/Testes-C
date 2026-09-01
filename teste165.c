// 28.05.26
#include <stdio.h>
#include <string.h>
// strcat
// strncat
// strcpy
// fgets

int main() {

    char nome[10];
    char sobrenome[10];
    char nomecompleto[20];

    printf("Insira um nome: ");
    fgets(nome, 10, stdin);
    strcpy(nomecompleto, nome);
    printf("Insira o sobrenome: ");
    fgets(sobrenome, 10, stdin);
    strcat(nomecompleto, sobrenome);

    printf("Nome completo: %s\n", nomecompleto);














    return 0;
}