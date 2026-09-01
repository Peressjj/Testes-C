#include <stdio.h>
// Ponteiro // getchar // funcao recursiva // recursividade // recursao

/* O programa utiliza getchar par armazenar uma palavra em array, um ponteiro para apontar'
para esse array e exibi-lo antes da conversao, depois há um prototipo de funcao recursiva que 
transforma todas as letras gravadas no array em maiusculas */

void conversor(char *);

int main() {

    char palavra[50];
    int cont = 0;

    char *Ptr;

    Ptr = &palavra[0];

    printf("Digite uma palavra: \n");
    while ((palavra[cont] = getchar()) != '\n') {
        cont++;
    }
    
    printf("Antes da converção: \n");
    for (int i = 0; i < 50; i++) {
        printf("[%d] = %c \n", i, *(Ptr + i));
    }

    printf("Depois. \n");
    conversor(palavra);
    printf("%s.\n", palavra);

    



return 0;
}

void conversor(char *p) {

    while (*p != '\0') {
        if (*p >= 'a' && *p <= 'z') {
            *p -= 32;
        }
        ++p;
    }





}