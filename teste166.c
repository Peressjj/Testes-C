// 30.05.26
#include <stdio.h>
#include <string.h>
// sizeof

/* a funcao sizeof mostra a quantidade de bytes que a variavel ocupa  */

int main() {

    int num_int1 = 10;
    float num_float1 = 1.5;

    int num_int2 = 10000000;
    float num_float2 = 1000000.500000;

    char letra = 'a';
    char nome[] = {"Peres"};

    printf("\n\nMemoria int 1: %zu bytes.\n", sizeof(num_int1));
    printf("Memória float 1: %zu bytes.\n", sizeof(num_float1));

    printf("Memoria int 2: %zu bytes.\n", sizeof(num_int2));
    printf("Memória float 2: %zu bytes.\n", sizeof(num_float2));

    printf("Memória char letra: %zu bytes.\n\n", sizeof(letra));
    for (int i = 0; i < strlen(nome); i++) {
        printf("Nome[%d] = %c - Memória: %zu\n", i, nome[i], sizeof(nome[i]));
    }
    printf("\nMemória char nome: %zu bytes.\n\n", sizeof(nome));

    // Memória int 1: 4 bytes.
    // Memória float 1: 4 bytes.
    // Memória int 2: 4 bytes.
    // Memória float 2: 4 bytes.
    // Memória char letra: 1 bytes.

    // Nome[0] = P - Memória: 1
    // Nome[1] = e - Memória: 1
    // Nome[2] = r - Memória: 1
    // Nome[3] = e - Memória: 1
    // Nome[4] = s - Memória: 1

    // Memória char nome: 6 bytes.



    return 0;
}