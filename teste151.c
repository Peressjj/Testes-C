#include <stdio.h>
#include <string.h>
// fgets

/* O programa recebe uma frase e faz uma contagem da quantidade de caracteres dela */

int main() {

    char frase[50];

    printf("Digite uma frase: ");
    fgets(frase, 50, stdin);

    printf("\nCaracteres: %d\nFrase: %s", strlen(frase), frase);


    printf("Insira a frase 2 e 3 também: ");
    char frase2[50], frase3[50];

    fgets(frase2, 50, stdin);
    printf("\n");
    fgets(frase3, 50, stdin);

    printf("Frase 2: %s\n", frase2);
    printf("Frase 3: %s\n", frase3);








    return 0;
}