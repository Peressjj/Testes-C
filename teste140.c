#include <stdio.h> 
// getchar

/* Armazenamento de palavras com gechar usando loop while, o loop para ao
utilizar entre (\n) */

int main() {

    char nome[10];
    int i = 0;

    printf("Insira um nome: \n");
    while ((nome[i] = getchar()) != '\n') {
        i++;
    }

    nome[i] = '\0';

    for (int i = 0; i < 10; i++) {
        printf("[%d] = %c\n", i, nome[i]);
    }
    















    return 0;
}