#include <stdio.h>
// prototipo de funcoes
// funcao soma dois numeros

void somadoisnumeros(int x, int y);

int main() {

    int numero1;
    int numero2;
    printf("Insira os valores de x e y: \n");
    scanf("%d", &numero1);
    scanf("%d", &numero2);
    somadoisnumeros(numero1, numero2);

}

void somadoisnumeros(int numero1, int numero2) {
    printf("Numero 1: %d\n", numero1);
    printf("Numero 2: %d\n", numero2);

    printf("\nA soma entre os dois numeros: %d", (numero1 + numero2));
}