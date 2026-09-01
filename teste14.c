#include <stdio.h> 

int main() {

    int numero;
    int resultado;
    int menu;

    do { printf("Insira um numero diferente de 0: \n");
      scanf("%d", &numero);
      (numero % 2 == 0) ? printf("Numero par\n") : printf("Numero impar.\n");
         
      
    } while (numero == 0); {
      printf("Programa encerrado.");
    }    


    return 0;
}