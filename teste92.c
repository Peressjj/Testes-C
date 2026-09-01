#include <stdio.h>
// prototipo de funcao
// funcao verifica qual numero é maior

void verific(int x, int y);

int main() {

    int numero1, numero2 = 0;
    printf("Insira dois numeros: \n");
    scanf("%d", &numero1);
    scanf("%d", &numero2);
    verific(numero1, numero2);

}

void verific(int numero1, int numero2) {

    int maior = 0;
    if (numero1 > numero2) {
        maior += numero1;
    } else if (numero2 > numero1) {
        maior += numero2;
    } else {
        printf("Erro!!!");
    }

    printf("O maior numero é: %d\n\n", maior);

}