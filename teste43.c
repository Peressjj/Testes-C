#include <stdio.h>

int numero(int);


int main() {

    int x = 0;

    for (x = 0; x < 10; x++)
        printf("%d\n", numero(x));

        

return 0;
}


int numero(int valor) {
    return valor * valor;
}