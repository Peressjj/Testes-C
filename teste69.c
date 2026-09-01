#include <stdio.h>
#include <string.h> // utilizada para a funcao strlen
// string literal
// strlen = conta quantos caracteres tem no array

int main() {

    char string[] = "Fora de forma, marchem!";
    int tam1 = strlen(string);
    printf("\nString 1: %s\nTamanho: %d\n\n\n\n", string, tam1);

    

    char string2[] = {'M', 'a', 'r', 'c', 'h', 'e', 'm'};
    int tam2 = strlen(string2);

    for (int i = 0; i < tam2; i++) {
        printf("Letra: %c\n", string2[i]);
    }























return 0;
}