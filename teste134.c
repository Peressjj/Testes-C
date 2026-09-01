#include <stdio.h>

int main() {

    char nome[10];
    int idade;

    printf("Insira um nome: \n");
    scanf("%s", &nome);
    getchar();
    printf("Insira uma idade: \n");
    scanf("%d", &idade);
    getchar();

    printf("Nome: %s\nIdade: %d\n", nome, idade);




















    return 0;
}