#include <stdio.h>
// prototipo de funcoes

void palavra(void);
char teste;

int main() {

    printf("Digite uma palavra: \n");
    scanf("%c", &teste);
    palavra();
}

void palavra(void) {
    printf("%c", teste);
}