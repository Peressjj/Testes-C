#include <stdio.h>
#include <stdlib.h>
// funcao strtof

int main() {

    char texto[50] = "119371439,70";

    float numero = strtof(texto, NULL);

    printf("Texto: %s\n", texto);
    printf("Numero %.2f", numero); //119371440.00























return 0;
}