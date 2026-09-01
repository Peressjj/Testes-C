#include <stdio.h>
// inversao de array

int main() {

    int teste[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    printf("\nOrdem normal:\n\n");
    for (int i = 0; i < 10; i++) {
        printf("Posicao %d: [%d]\n", (i + 1), teste[i]);
    }   

    printf("\n\nOrdem invertida: \n\n");
    for (int i = 9; i >= 0; i--) {
        printf("Posicao %d: [%d]\n", i, teste[i]);
    }























return 0;
}