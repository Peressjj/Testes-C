// 28.05.26
#include <stdio.h>
#include <string.h>
// strcat

int main() {

    char nome3[] = {"Peres"};
    char nome4[] = {"dos"};
    char nome1[] = {"Joao"};
    char nome5[] = {"Santos"};
    char nome2[] = {"Vitor"};
    char completo[30];

    printf("Nome: %s %s %s %s %s\n", nome1, nome2, nome3, nome4, nome5);

    strcat(completo, nome1);
    strcat(completo, " ");
    strcat(completo, nome2);
    strcat(completo, " ");
    strcat(completo, nome3);
    strcat(completo, " ");
    strcat(completo, nome4);
    strcat(completo, " ");
    strcat(completo, nome5);

    printf("\nCompleto: ");
    puts(completo);

    for (int i = 0; i < 30; i++) {
        printf("[%d] = %c\n", i, completo[i]);
    }














    return 0;
}