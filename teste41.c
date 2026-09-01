#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// classificacao de numeros aleatorios

int main() {

    srand(time(NULL));

    int opcao = -1;
    int comum = 0;
    int raro = 0;
    int lendario = 0;

    while (opcao != 0) {
        int numeroaleatorio = rand() % 100 + 1;
        printf("1 - Jogar.\n");
        printf("0 - Sair.\n");
        scanf("%d", &opcao);
        printf("O numero aleatório é: %d\n\n", numeroaleatorio);
        if (numeroaleatorio <= 60 && numeroaleatorio >= 0) {
            printf("O numero %d é comum.\n", numeroaleatorio);
            comum++;
        } else if (numeroaleatorio > 60 && numeroaleatorio < 90) {
            printf("O numero %d é raro.\n", numeroaleatorio);
            raro++;
        } else if (numeroaleatorio >= 90 && numeroaleatorio <= 100) {
            printf("O numero %d é LENDÁRIO.\n", numeroaleatorio);
            lendario++;
        } else {
            printf("ERRO!!!");
        }
    }

    printf("Resultado final:\n");
    printf("Numeros comuns: %d\n", comum);
    printf("Numeros raros: %d\n", raro);
    printf("Numeros LENDÁRIOS: %d\n\n", lendario);
    printf("Programa encerrado.\n");
    

















return 0;
}