#include <stdio.h>
#include <string.h>
// protoripo de funcao 
// strlen 


    void exibirnome(char nome[]);
    
int main() {
    
    char nomejoao[] = "Joao Vitor Peres dos Santos";
    exibirnome(nomejoao);

}

    void exibirnome(char nome[]) {
        for (int i = 0; i < strlen(nome); i++) {
            printf("%d\t[%c]\n", (i + 1), nome[i]);
        }
        printf("\nQuantidade final de caracteres: %d\n", strlen(nome));
    }