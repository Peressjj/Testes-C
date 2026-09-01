#include <stdio.h>
// Conversor de letras de minusculo para maiusculo
// Ponteiro

/* O programa pegaa a string e transforma ela em letras maiusculas*/


void conversao(char *);

int main() {


    char string[] = "peres";
    printf("A string antes da alteracao: %s\n\n", string);
    
    conversao(string);
    printf("A string depois da alteracao: %s\n", string);
    
return 0;
}

void conversao(char *s) {
    while (*s != '\0') {
        if (*s >= 'a' && *s <= 'z') {
            *s -= 32;
        }
        ++s;
    }


}