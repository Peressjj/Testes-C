#include <stdio.h>

int main() {

    int numeros[5];
    int maior;
    int menor;

    printf("Insira 5 numero pro array: \n");
    for (int posicao = 0; posicao < 5; posicao++) {
        scanf("%d", &numeros[posicao]);
    }

    maior = numeros[0];
    menor = numeros[0];

    for (int posicao = 0; posicao < 5; posicao++) {
        printf("%d\n\n", numeros[posicao]);
    }

    for (int posicao = 0; posicao < 5; posicao++) {
        if (numeros[posicao] > maior)
        maior = numeros[posicao];

        if (numeros[posicao] < menor)
        menor = numeros[posicao];
    }

    printf("O numero maior é %d\n", maior);
    printf("O numero menor é %d\n", menor);













return 0;
}