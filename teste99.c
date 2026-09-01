#include <stdio.h>
// sizeof - mostra o tamanho dos dados da variavel ocupados na memoria

int main() {

    int numero = 1;
    float numerofloat = 1.5;
    char letra = 'k';
    char nome[] = {"Peres"};
    char nome2[10] = {'P', 'e', 'r', 'e', 's'};

    printf("Tamano do int: %zu\n", sizeof(numero));
    printf("Tamanho do float: %zu\n", sizeof(numerofloat));
    printf("Tamanho do char: %zu\n", sizeof(letra));
    printf("Tamanho da string literal: %zu\n", sizeof(nome));
    printf("Tamanho da string normal: %zu\n", sizeof(nome2));





}