#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// programa exibe diagonal secundária da matriz

int main() {

    srand(time(NULL));

    int matriz[3][3] = {
        {rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1},
        {rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1},
        {rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1}
    };

    printf("\n\n");
    for (int i = 0; i < 3; i++) {
        printf("|\t%d\t%d\t%d\t|\n", matriz[i][0], matriz[i][1], matriz[i][2]);
    }

    int diagonalsecundaria[3] = {0, 0, 0};

    for (int i = 0; i < 3; i++) {
        diagonalsecundaria[i] = matriz[i][2 - i];
    }

    printf("\n\nA diagonal secundária é: \n");
    for (int i = 0; i < 3; i++) {
        printf("%d\t", diagonalsecundaria[i]);
    }

    printf("\n\n");

















return 0;
}