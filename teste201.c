// 24.06.26
#include <stdio.h>
// arquivos

int main() {

    FILE *origem, *destino;

    char c;

    origem = fopen("teste200.txt", "r");

    if (origem == NULL) {
        printf("Falha ao abrir arquivo!\n");
    } else {
        printf("Arquivo 'teste200.txt' aberto!\n");
    }

    destino = fopen("teste201.txt", "w");

    if (destino == NULL) {
        printf("Falha ao abrir arquivo!\n");
    } else {
        printf("Arquivo 'teste201.txt' aberto!\n");
    }

    while ((c = fgetc(origem)) != EOF) {
        fputc(c, destino);
    }
    printf("Arquivo copiado com sucesso!\n");
    
    fclose(origem);
    fclose(destino);

    printf("Programa encerrado!\n");










    return 0;
}