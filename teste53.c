#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//programa exibe diagonal principal do sistema

int main() {

    srand(time(NULL));

    int matriz[3][3] = {rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1};
    
    printf("\n\n");
    for (int i = 0; i < 3; i++) {
        printf("|\t%d\t%d\t%d|\n", matriz[i][0], matriz[i][1], matriz[i][2]);
    }

    int diagonalprincipal[3] = {0, 0, 0};

    for (int i = 0; i < 3; i++) {
        diagonalprincipal[i] += matriz[i][i];
    }

    printf("\n\nA diagonal principal é: \n");

    for (int i = 0; i < 3; i++) {
        printf("%d\t", diagonalprincipal[i]);
    }






















return 0;
}