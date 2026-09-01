#include <stdio.h>
// getchar

/* O programa le apenas um caractere e depos o exibe na tela */

int main() {

    char numero;

    printf("Digite um numero:\n");

    numero = getchar() - '0';

    printf("Numero: %d\n", numero);

    while (getchar() != '\n');

    char letra;

    printf("Digite uma letra: \n");

    letra = getchar();

    printf("Letra: %c\n", letra);







return 0;
}