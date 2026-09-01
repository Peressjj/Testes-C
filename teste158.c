// 25/05/2026
#include <stdio.h>
#include <string.h>
// puts
// fgets
// strcpy

/* O programa recebe dois nomes, que sao armazenados em duas variaveis diferentes, 
depois, as variaveis invertem seus nomes, a inversao é feita com strcpy e uma 
variavel temporaria para recebimento do nome */

int main() {

    char nome1[50], nome2[50], temp[50];

    puts("Insira o nome 1:");
    fgets(nome1, 50, stdin);

    puts("Insira o nome 2:");
    fgets(nome2, 50, stdin);

    printf("Nome 1: %s\n", nome1);
    printf("Nome 2: %s\n", nome2);

    puts("Troca de nomes\n");

    strcpy(temp, nome1);
    strcpy(nome1, nome2);
    strcpy(nome2, temp);

    printf("Nome 1: %s\n", nome1);
    printf("Nome 2: %s\n", nome2);













    return 0; 
}