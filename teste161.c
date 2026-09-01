//28.05.26
#include <stdio.h>
#include <string.h>
// strcat

/* a funcao strcat junta duas strings em uma variavel so */

int main() {

    char nome[] = {"Joao "};
    char sobrenome[] = {"Peres"};

    printf("Nome: %s\n", nome);
    printf("Sobrenome: %s\n", nome);

    strcat(nome, sobrenome);

    puts("\n// strcat(nome, sobrenome);\n");

    puts("Nome: ");
    puts(nome);
    puts("Sobrenome: ");
    puts(sobrenome);














    return 0; 
}