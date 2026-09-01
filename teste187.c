// 11.06.26
#include <stdio.h>

// recursao
// funcao recursiva

int cont = 0;

int soma(int n) {
    printf("%d --> %d\n", cont, n);
    cont++;
    if (n == 0) {
        return 0;
    } else {
        return n + soma(n - 1);
    }
}

int main() {

    printf("%d\n", soma(3));





    return 0;
}