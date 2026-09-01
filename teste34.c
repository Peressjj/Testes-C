#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//o usuario insere dois numeros, o programa irar gerar numeros aleatorios entre eles;

int main() {

    srand(time(NULL));

    int numero1, numero2;

    printf("Escreva dois numeros, e farei uma selecao de numeros aleatorios entre eles: \n");
    printf("Numero 1: ");
    scanf("%d", &numero1);

    printf("Numero 2: ");
    scanf("%d", &numero2);

    printf("Numero 1: %d\n", numero1);
    printf("Numero 2: %d\n", numero2);

    printf("\n");
    int maior = 0;
    int menor = 0;

    if (numero1 > numero2) {
        maior = numero1;
        menor = numero2;
    } else if (numero1 < numero2) {
        maior = numero2;
        menor = numero1;
    } else {
        printf("Erro.\n");
    }

    printf("O maior numero é: %d\n", maior);
    printf("O menor numero é: %d\n", menor);
    
    int opcao;
    while (opcao != 0) {
        scanf("%d", &opcao);
        int numeroaleatorio = rand() % (menor - maior) + menor;
        printf("Numero aleatorio entre %d e %d: \n", menor, maior);
        printf("O seu numero aleatorio é: %d\n", numeroaleatorio);
    }
    
    printf("Programa encerrado.\n");






    return 0;
}