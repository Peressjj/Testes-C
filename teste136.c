#include <stdio.h>
// Ponteiro
// Ponteiro duplo / ponteiro de ponteiro

int main() {

    int a = 5;
    int b = 10;

    int *p1;
    int **p2;

    p1 = &a;
    p2 = &p1;

    printf("\n\nNumero a: %d\n", a);
    printf("Numero b: %d\n", b);

    printf("\nEndereco p1: %p\n", p1);
    printf("Valor p1: %d\n", *p1);

    printf("\nEndereco p2: %p\n", p2);
    printf("Valor p2: %d\n", *p2);

    printf("\n\nEndereco **p2: %d\n\n\n", **p2);























    return 0;
}