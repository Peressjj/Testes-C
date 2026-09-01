#include <stdio.h>
// prototipo de funcoes

    float pi(float);
    float numeropi = 3.14;

int main() {

    pi(numeropi);

}

    float pi(float) {
        printf("\nNumero pi: %.2f\n", numeropi);
    }