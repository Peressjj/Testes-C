#include <stdio.h>
#include <time.h>
#include <stdlib.h>

    


int main() {

    srand(time(NULL)); 
    int numero[5];

    for (int posicao = 0; posicao < 5; posicao++) {
        numero[posicao] = rand() % 10 + 5;
    }

    for (int posicao = 0; posicao < 5; posicao++) {
        printf("%d\n", numero[posicao]);
    }


    















return 0;
}