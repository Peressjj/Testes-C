#include <stdio.h>
// funcao recursiva / recursividade
// prototipo de funcao

/* a funcao pega dois numeros, e vai exibindo e somando um deles até que se tornem iguais
usando uma funcao recursiva pra isso, verificando se há diferenca e chamando ela mesma enquanto
houver essa diferenca
*/

void somarnumeros(int x, int y);

int main() {

    int numero1 = 0;
    int numero2 = 0;
    printf("Insira o valor do numero 1 e 2:\n");
    scanf("%d", &numero1);
    scanf("%d", &numero2);
    somarnumeros(numero1, numero2);

}

void somarnumeros(int x, int y) {
    printf("%d          %d\n", x, y);
    if (y > x) {
        x++;
        somarnumeros(x, y);
    } else if (x > y) {
        y++;
        somarnumeros(x, y);
    }
    else if (x = y) {
        printf("\n\nNumeros iguais.\n");
        return;
    }
}