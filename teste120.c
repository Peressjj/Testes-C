#include <stdio.h>
// ponteiro

/* alteracao do valor da variavel pelo ponteiro */

int main() {

    int x = 7;

    int *p = &x;

    printf("%d\n", *p);

    *p = 30;

    printf("%d\n", x);

























return 0;
}