#include <stdio.h>
// getchar

/* O programa pega o texto que o usuario digitou e o mostra 
sem espacos */

int main() {

    char texto[50];
    int i = 0;
    char c;

    printf("Digite uma frase: \n");
    while ((c = getchar()) != '\n' && i < 49) {
        if (c != ' ') {
            texto[i] = c;
            i++;
        }    
    }
    
    texto[i] = '\0';

    printf("Texto sem espaco: \n");
    printf("%s", texto);












    return 0;
}