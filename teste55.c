#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// O sistema encontra na matriz o numero que o usuario escolheu

int main() {

    int matriz[3][3] = {
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8}
    };

    for (int i = 0; i < 3; i++) {
        printf("|\t%d\t%d\t%d\t|\n", matriz[i][0], matriz[i][1], matriz[i][2]);
    }

    int resp = 0;
    int endlin = 0;
    int endcolun = 0;

    printf("\nInsira qual valor vc quer localizar na matriz: \n");
    scanf("%d", &resp);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (resp == matriz[i][j]) {
                endlin += i;
                endcolun += j;
            } 
        }
    }

    printf("\n\nO endereco do numero [%d] é: posicao %d x %d: \n", resp, endlin, endcolun);





















return 0;
}