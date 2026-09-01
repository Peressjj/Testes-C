#include <stdio.h>
// protoripo de funcoes simples
// funcao exibe um numero

void exibirnumero(int n);

int main() {

    int numero = 0;
    printf("Insira um numero: \n");
    scanf("%d", &numero);
    exibirnumero(numero);
}

void exibirnumero(int numero) {
    printf("\nO numero inserido foi: %d\n\n", numero);

}