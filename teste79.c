#include <stdio.h>
// calculo de media com for 

int main() {

    int notas[3];

    printf("\nInsira as notas:  ");

    for (int i = 0; i < 3; i++) {
        scanf("%d", &notas[i]);
    }

    for (int i = 0; i < 3; i++) {
        printf("Nota %d: %d\n", i, notas[i]);
    }

    float soma = 0;

    for (int i = 0; i < 3; i++) {
        soma += notas[i];
    }

    printf("Soma: %.2f\n", soma);
    printf("Resultado final: %.2f\n", (soma / 3));






















return 0;
}