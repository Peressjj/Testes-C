// 14.06.26
#include <stdio.h>
#include <string.h>
// arquivo

/* Abertura e leitura de arquivo txt */

int main() {

    FILE *arquivo;

    char linha[100];

    arquivo = fopen("teste191.txt", "r");

    if (arquivo == NULL) {
        printf("Falha ao abrir arquivo.\n");
        return 1;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        for (int i = 0; i < strlen(linha); i++) {
            printf("Linha[%d] = %c\n", i, linha[i]);
        }
    }
    
    fclose(arquivo);














    return 0;
}