#include <stdio.h>

int main() {

    char palavra[50];
    int cont = 0;

    printf("Insira uma palavra.\n");

    while ((palavra[cont] = getchar()) != '\n') {
        cont++;
    }

    for (int i = 0; i < 50; i++) {
        printf("[%d] = %c\n", i, palavra[i]);
    }
    printf("cont: %d.\n", cont);















return 0;
}