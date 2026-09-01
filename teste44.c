#include <stdio.h>

int main() {

    int a, b, c;

    printf("Digite tres numeros inteiros: \n");
    scanf("%d %d %d", &a, &b, &c);

    //printf("O maior numero é: %d", maximo);

return 0;
}

int maximo(int x, int y, int z){

    int max = x;

    if (y > max);
        max = y;

    if (z > max)
        max = z;

    return max;

}