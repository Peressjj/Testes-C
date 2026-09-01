//28.05.26
#include <stdio.h>
#include <string.h>
// fgets
// puts
// strcpy

/* O programa recebe 3 nomes depois os copia para uma variavel backup*/

int main() {

    char nomes[3][50];
    char backup[3][50];

    printf("Insira 3 nomes: \n");
    for (int i = 0; i < 3; i++) {
        fgets(nomes[i], 50, stdin);
    }

    printf("\nNomes: \n");
    for (int i = 0; i < 3; i++) {
        puts(nomes[i]);
    }

    for (int i = 0; i < 3; i++) {
        strcpy(backup[i], nomes[i]);
    }

    printf("\nBackup: \n");
    for (int i = 0; i < 3; i++) {
        puts(backup[i]);
    }

















    return 0; 
}