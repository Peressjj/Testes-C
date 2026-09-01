#include <stdio.h>
// getchar

/* armazenamento de palavras com getchar usando loop for */

int main() {

    char palavra[10];

    printf("Insira uma palavra: \n");

    for (int i = 0; i < 10; i++) {
        palavra[i] = getchar();
    }

    palavra[10] = '\0';
    
    for (int i = 0; i < 10; i++) {
        printf("[%d] = %c\n", i, palavra[i]);
    }












    return 0;
}