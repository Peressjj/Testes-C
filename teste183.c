#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));
    
    int temp = 0;
    int matriz1[3][3] = {
    {rand() % 50 + 1, rand() % 50 + 1, rand() % 50 + 1},
    {rand() % 50 + 1, rand() % 50 + 1, rand() % 50 + 1},
    {rand() % 50 + 1, rand() % 50 + 1, rand() % 50 + 1},
    };
    
    printf("Matriz 1:\n");
    for (int i = 0; i < 3; i++) {
        printf("|\t%d\t%d\t%d\t|\n", matriz1[i][0], matriz1[i][1], matriz1[i][2]);
    }

    printf("Reordenacao:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matriz1[i][j] > matriz1[i][(j + 1)]) {
                temp = matriz1[i][j];
                matriz1[i][j] = matriz1[i][(j + 1)];
                matriz1[i][(j + 1)] = temp;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        printf("|\t%d\t%d\t%d\t|\n", matriz1[i][0], matriz1[i][1], matriz1[i][2]);
    }












    return 0;
}