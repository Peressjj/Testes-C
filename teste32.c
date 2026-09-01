#include <stdio.h>

int main() {

char string1[6], string2[] = "String literal";
int i;

printf("Entre com uma string: \n");
scanf("%s", &string1);

printf("String é: %s\nString 2 é: %s\n", string1, string2);

for (int i = 0; string1[1] != '\0'; i++) {
    printf("%c", string1[i]);
}

printf("\n");


















return 0;
}