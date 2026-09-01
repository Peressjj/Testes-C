// 14.06.26
#include <stdio.h>

int main() {

    FILE *arq;

    arq = fopen("teste193.txt", "w");

    if (arq == NULL) {
        printf("Falha ao abrir arquivo!\n");
        return 1;
    } else {
        printf("Arquivo aberto!\n");
    }

    fprintf(arq, "O rato roeu a...\n");

    fclose(arq);










    return 0;
}