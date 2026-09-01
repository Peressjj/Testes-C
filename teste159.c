// 25.05.26
#include <stdio.h>
#include <string.h>
// strcpy

/* O programa verifica se a condicao da string 2 estar vazia para fazer
uma copia da string 1 para a string 3 usando strcpy */

int main() {

    char string1[10] = {"Peres"};
    char string2[10] = {"Teste"};
    char string3[10] = "";

    printf("String 1: %s\n", string1);
    printf("String 2: %s\n", string2);
    printf("String 3: %s\n", string3);

    if (string2[0] == '\0') {
        strcpy(string3, string1);
    } else {
        strcpy(string3, "0");
    }

    printf("String 1: %s\n", string1);
    printf("String 2: %s\n", string2);
    printf("String 3: %s\n", string3);









    return 0; 
}