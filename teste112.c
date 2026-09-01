#include <stdio.h>
// recursao / funcao recursiva / recursividade

/* o codigo conta quantos caracteres tem uma string sem utilizar strlen */

void contador(char nome[], int total);

int main() {

    char nome1[10] = {"Peres"};
    int total = 0;

    printf("Nome 1: %s\n", nome1);
    contador(nome1, total);
    printf("\n\n");
    
    char nome2[] = {"Joao Vitor Peres dos Santos."};
    printf("Nome 2: %s\n", nome2);
    contador(nome2, total);

    printf("\n\n");
    char nome3[50];
    printf("Insira um nome: \n");
    scanf("%s", &nome3);
    printf("Nome 3: %s\n", nome3);
    contador(nome3, total);
}

void contador(char nome[], int total) {
    
    if (nome[total] == '\0') {
        printf("Total de letras: %d\n", total);
        return;
    } else {
        printf("%d = [%c]\n", (total + 1), nome[total]);
        ++total;
        contador(nome, total);
    }
    

}

