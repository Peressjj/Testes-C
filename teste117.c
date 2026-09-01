#include <stdio.h>

void reverse(char *);

int main() {

    char string[50];
    char texto[50];
    char c;
    int i = 0;

    printf("Insira um texto:\n");
    fgets(string, sizeof(string), stdin);

    printf("O reverso é:\n");
    reverse(string);

    printf("\n");

    printf("Digite um texto:\n");

    while ((c = getchar()) != '\n') {
        texto[i++] = c;
    }

    texto[i] = '\0';

    printf("O texto digitado foi:\n");
    puts(texto);

    return 0;
}

void reverse(char *s) {

    if (s[0] == '\0') {
        return;
    }

    reverse(&s[1]);
    putchar(s[0]);
}