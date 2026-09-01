#include <stdio.h>
// ponteiro

/*
P = valor em hexadecimal
D =  valor em decimal
*/

int main() {

    int num;
    int *numptr;

    num = 10;
    numptr = &num;

    printf("\n\n\n\n\n\n\nVariavel numero: %d\n", num);

    printf("\nPonteiro %%d: %p\n", numptr);  // Ponteiro %d: 00000000005FFE7C
    printf("Ponteiro %%p: %d\n\n", numptr);  // Ponteiro %p: 6291068

    printf("%%p &num: %p\n", &num);          // %p &num: 00000000005FFE7C
    printf("%%p &numptr: %p\n", &numptr);    // %p &numptr: 00000000005FFE70
    printf("%%d &num: %d\n", &num);          // %d &num: 6291068
    printf("%%d &numptr: %d\n", &numptr);    // %d &numptr: 6291056



    









}