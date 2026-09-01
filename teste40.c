#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// cara ou coroa

int main() {

    srand(time(NULL));
    int cara = 1;
    int coroa = 2;
    int contcara = 0;
    int contcoroa = 0;
    int numero[100];

    for (int i = 0; i < 100; i++) {
        numero[i] = rand() % 2 + 1;
        if (numero[i] == 1) {
            contcara++;
        } else if (numero[i] == 2) {
            contcoroa++;
        } else {
            printf("ERRO!!!");
            break;
        }
    }

    for (int i = 0; i < 10; i++) {
        printf("Jogada %d: %d\n", i, numero[i]);
    }

    printf("Cara: %d\n", contcara);
    printf("Coroa: %d\n", contcoroa);













return 0;
}