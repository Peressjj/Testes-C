#include <stdio.h>
// ponteiro

typedef struct Pessoa {
    int idade;
} Pessoa;

Pessoa listapessoas[2] = {
    {10},
    {20}
};

int main() {

    Pessoa *p = listapessoas;

    printf("Idade 1: %d\n", p->idade);
    printf("Idade 2; %d\n", (p + 1)->idade);





return 0;
}