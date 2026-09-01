#include <stdio.h>
// Valores de matriz
// matriz 3x3 basica
// Matriz no formato linha x coluna
// Matriz transposta


int main() {

int matriz[3][3];

matriz[0][0] = 1;
matriz[0][1] = 2;
matriz[0][2] = 3;
matriz[1][0] = 4;
matriz[1][1] = 5;
matriz[1][2] = 6;
matriz[2][0] = 7;
matriz[2][1] = 8;
matriz[2][2] = 9;


    printf("\n\nMostrando o valor de cada posicao: \n");
    for (int i = 0; i < 3; i++) {   // i = linhas
        for (int j = 0; j < 3; j++) {   // j = colunas
            printf("Posicao %d x %d: [%d]\n", (i + 1), (j + 1), matriz[i][j]);
        }
    }

    printf("\n\n\n\n");

    printf("Matriz no formato linha x coluna:   \n");
    for (int i = 0; i < 3; i++) {   // o loop passa pelas 3 linhas, já teendo o valor de cada coluna
        printf("|   %d  %d  %d  |\n", matriz[i][0], matriz[i][1], matriz[i][2]); 
    }


    printf("\n\n\n\n");

    printf("Matriz transposta:   \n");
    for (int j = 0; j < 3; j++) { // trocando o "i" e o "j" de posicao, invertemos a ordem da matriz, tornando a transposta
        printf("|   %d  %d  %d  |\n", matriz[0][j], matriz[1][j], matriz[2][j]);
    }

















return 0;
}