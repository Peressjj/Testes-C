// 11.06.26
#include <stdio.h>
// ponteiro

/* O programa acessa o valor da struc por membro e por ponteiro */


typedef struct Pessoa {
    int idade;
} Pessoa;
    

int main() {

    Pessoa pessoa1 = {20};
    Pessoa *Ptr = &pessoa1;
    
    printf("Membro: %d\n", pessoa1.idade);
    printf("Ponteiro: %d\n", Ptr->idade);








    return 0;
}