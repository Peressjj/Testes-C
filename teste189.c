// 11.06.26
#include <stdio.h>
// ponteiro

int soma(int v) {
    v = v + 10;
}

int psoma(int *v) {

    *v = *v + 10;

}

int main() {

    int valor1 = 10;
    int valor2 = 10;

    soma(valor1);
    psoma(&valor2);

    printf("Valor normal: %d\n", valor1);
    printf("Valor com ponteiro: %d\n", valor2);









    return 0;
}