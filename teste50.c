#include <stdio.h>
// usuario insere o valor da matriz e o sistema exibe qual é o maior

int main() {

int matriz1[2][2];

printf("\nInsira os valores da matriz: \n\n");

for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
        scanf("%d", &matriz1[i][j]);
    }
}


for (int i = 0; i < 2; i++) {
    printf("|\t%d\t%d\t|\n", matriz1[i][0], matriz1[i][1]);
}

int maior = 0;

for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
        if (matriz1[i][j] > maior) {
            maior = matriz1[i][j];
        }     
    }
}

printf("O maior numero é: %d\n", maior);





















return 0;
}