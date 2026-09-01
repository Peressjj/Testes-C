#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//jogo de advinhacao

int main() {

    srand(time(NULL));

    int numeroaleatorio = rand() % 20 + 1;

    printf("Advinhe o numero aleatorio: \n  (Numero diferente de zero)\n");

    int opcao = -1;

    printf("Digite um número: \n");
    while (opcao != 0) {
        int tentativa;
        scanf("%d", &tentativa);
        if (tentativa == numeroaleatorio) {
            printf("Voce acertou!\n");
            break;
        } else if (tentativa > numeroaleatorio) {
            printf("O numero é menor.\n");
        } else if (tentativa < numeroaleatorio) {
            printf("O numero é maior.\n");
        } else {
        printf("ERRO!!!");
        }   
    }
    
    printf("Programa encerrado.\n");



















return 0;
}