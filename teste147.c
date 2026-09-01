#include <stdio.h>

int main() {

    char letra;
    printf("Insira uma letra: ");
    letra = getchar();
    for (int i = 0; i < 5; i++) {
        putchar(letra);
    }

    printf("\n\n");

    for (int i = 0; i < 10; i++) {
        putchar(i + '0');
    }








return 0;
}