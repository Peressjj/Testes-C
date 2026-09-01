#include <stdio.h>
#include <string.h>
// prototipo de funcoes
// o codigo conta quantas vogais tem na string

void contarvogais(int numero, char string1[], char string2[]);


int main() {

    int quantvogais = 0;
    char nome[] = {"Joao Vitor Peres dos Santos"};
    char vogais[20] = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
    contarvogais(quantvogais, nome, vogais);

}


void contarvogais(int numero, char string1[], char string2[]) {

    for (int j = 0; j < 11; j++) {
        for (int i = 0; i < strlen(string1); i++) {
                if (string1[i] == string2[j]) {
                    numero++;
                }
        }
    }

    printf("\n\nA quantidade de vogais é: %d", numero);
}
