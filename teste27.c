#include <stdio.h>

int main() {

    int array[5];
    int posicao;
    int posicao2;
    char olamundo[3][7] = {"Ola"," ","Mundo!"};

    printf("%s", olamundo[0]);
    printf("%s", olamundo[1]);
    printf("%s\n\n", olamundo[2]);

    printf("Insira 5 numero pro array: \n");
    
    for (posicao = 0; posicao < 5; posicao++){
        scanf("%d", &array[posicao]);
    }

    printf("\n\n");
    for (posicao2 = 0; posicao2 < 5; posicao2++) {
        printf("\n%d\n", array[posicao2]);
    }










return 0;
}