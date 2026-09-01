#include <stdio.h>
// ponteiro

/* um ponteiro que aponta para duas variáveis
susbtituicao da variavel do ponteiro */

int main() {

    int idade1;
    printf("Insira uma idade 1: ");
    scanf("%d", &idade1);

    int *Ptridade;

    Ptridade = &idade1;

    printf("Idade: %d\n", idade1);
    printf("Endereco de memória de idade 1: %p\n", Ptridade);
    printf("Numero armazenado em Ptridade: %d\n\n", *Ptridade);


    int idade2;
    printf("Insira idade2: ");\
    scanf("%d", &idade2);

    Ptridade = &idade2;
    int *Ptridade2;
    Ptridade2 = &idade2;

    printf("\n\nPtridade = &idade2\n\n");

    printf("Idade 1: %d\n", idade1);
    printf("Idade 2: %d\n\n", idade2);

    printf("Endereco de idade 1: %p\n", Ptridade);
    printf("Endereco de idade 2: %p\n\n", Ptridade2);

    printf("Valor armazenado em Ptr1: %d\n", *Ptridade);
    printf("Valor armazenado em Ptr2: %d\n\n", *Ptridade2);








    return 0;
}