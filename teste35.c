#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//gera um numero e diz se é par ou impar

int main() {
    
    srand(time(NULL));


    int opcao;
    while (opcao != 0) {
        printf("1 - Continuar. \n0 - Sair.\n");
        scanf("%d", &opcao);
        int numeroaleatorio = rand() % 50 + 1;
        printf("O numero aleatorio da rodada é: %d\n", numeroaleatorio);
        if (numeroaleatorio % 2 == 0) {
            printf("Numero %d é par.\n", numeroaleatorio);
        } else {
            printf("Numero aleatorio %d é impar.\n", numeroaleatorio);
        }
        printf("\n");
    }
    
    printf("Programa encerrado. \n");











return 0;
}