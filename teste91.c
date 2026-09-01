#include <stdio.h>
// prototipo de funcao
// funcao verifica se o numero é par ou impar

void parouimpar(int n);

int main() {

    int numero = 0;
    printf("insira um numero: \n");
    scanf("%d", &numero);
    parouimpar(numero);
}

void parouimpar(int numero) {
    if (numero % 2 == 0) {
        printf("\nNumero par.\n\n");
    } else {
        printf("\nNumero impar.\n\n");
    }

}