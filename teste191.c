// 14.06.26
#include <stdio.h>
#include <string.h>
// arquivo

/* abertura e leitura de arquivo.txt */

int main() {

    FILE *arq;

    char texto[100];

    arq = fopen("teste193.txt", "r");

    if (arq == NULL) {
        printf("Falha ao abrir arquivo!\n\n");
        return 1;
    } else {
        printf("Arquivo aberto!\n\n");
    }

    fgets(texto, sizeof(texto), arq);

    puts(texto);

    fclose(arq);







    return 0;
}