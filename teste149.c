#include <stdio.h>
// fgest

/* O programa recebe um nome, depois o exibe na tela */

int main() {

    char nome[50];
    printf("Insira um nome: ");
    fgets(nome, 50, stdin);

    printf("%s\n", nome);














    return 0;
}