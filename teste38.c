#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//mega sena simples

int main() {

    srand(time(NULL));

    int numero1 = rand() % 60 + 1;
    int numero2 = rand() % 60 + 1;
    int numero3 = rand() % 60 + 1; 
    int numero4 = rand() % 60 + 1;
    int numero5 = rand() % 60 + 1;
    int numero6 = rand() % 60 + 1;

    printf("%d\n%d\n%d\n%d\n%d\n%d\n", numero1, numero2, numero3, numero4, numero5, numero6);
















return 0;
}