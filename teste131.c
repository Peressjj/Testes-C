#include <stdio.h>
// getchar

int main() {

    char texto[50];

    printf("Insira o texto:\n");

    fgets(texto, 50, stdin);

    for (int i = 0; texto[i] != '\0'; i++) {
        printf("%c ", texto[i]);
    }

    printf("\n\n");

    printf("%s", texto);

    return 0;
    
    










}