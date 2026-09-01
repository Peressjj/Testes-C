#include <stdio.h>
// Putchar

/* O programa usa putchar para exibir cada caractere do array com loop for */

int main() {

    char nome[6] = {'P', 'e', 'r', 'e', 's'};

    for (int i = 0; i < 6; i++) {
        putchar(nome[i]);
    }




return 0;
}