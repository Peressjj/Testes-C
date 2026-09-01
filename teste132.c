#include <stdio.h>
#include <string.h>
// fgets

int main() {

    char palavra[50];

    printf("Insira uma palavra: \n");
    fgets(palavra, 50, stdin);

    for (int i = 0; i < strlen(palavra); i++) {
        printf("%c\n", palavra[i]);
    }









    return 0;
}