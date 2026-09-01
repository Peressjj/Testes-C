#include <stdio.h>
#include <string.h>
// prototipo de funcoes 
// o codigo inverte a ordem dos indices na hora de exibir a string

void inverterstring(char string[]);

int main() {

    char nome[] = {"peres"};
    inverterstring(nome);

}

void inverterstring(char string[]) {
    for (int i = strlen(string); i >= 0; i--) {
        printf("[%c]\t", string[i]);
    }

}