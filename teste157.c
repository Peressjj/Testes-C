// 25/05/2026
#include <stdio.h>
#include <string.h>
// puts
// fgets
// strcpy

/* A funcao fgets recebe e armazena uma string nome na variavel, cuja é feita uma 
cópia utilizando a funcao strcpy, sendo exibida as duas variaveis no final com a 
funcao puts */

int main() {

    char nome1[50];
    char nome2[50];

    puts("Insira um nome: ");
    fgets(nome1, 50, stdin);

    strcpy(nome2, nome1);

    puts(nome1);
    puts(nome2);












    return 0; 
}