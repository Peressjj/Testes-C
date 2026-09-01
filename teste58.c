#include <stdio.h>
// string literal
// codigo de letra

int main() {

    char nome[] = "Peres";

    for (int i = 0; i < 6; i++) {
        printf("Código: %d\tLetra: %c\n", nome[i], nome[i]);
    }

    char *nomes[] = {"Neto", "Jefferson", "Pacheco"};

    printf("\n\n");
    for (int i = 0; i < 3; i++) {
        printf("Nome %d: %s\n", (i + 1), nomes[i]);
    }







    /*int x = 10;
    int *y = &x;

    printf("\n\nValor de x: %d\nVAlor de y: %d\n", x, *y);*/


























return 0;
}