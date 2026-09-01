#include <stdio.h>

int main() {
    int k, soma = 0;

for (k = 2; k <= 10; k += 2) {
    soma += k;
    printf("Estou no índice: %d\n", k);
    
}
    
printf("Valor do K: %d\n Soma: %d\n", k, soma);

return 0;
}