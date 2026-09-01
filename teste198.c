// 22.06.26
#include <stdio.h>
// arquivos

/* modos de abertura de arquivos */

int main() {

    FILE *arq;

    arq = fopen("teste198.txt", "w");

    if (arq == NULL) {
        printf("Falha ao abrir arquivo!\n");
    } else {
        printf("Arquivo aberto com sucesso!\n");
    }

    fprintf(arq, "Arquivo 01:\n\nW - Escreve arquivos;\nSe o arquivo já existir, apaga tudo;\n\n");
    fclose(arq);

    arq = fopen("teste198.txt", "a");
    fprintf(arq, "A - Le e escreve;\nSe o arquivo nao existir, nao cria outro nem apaga;\n\n");
    fclose(arq);

    arq = fopen("teste198.txt", "a");
    fprintf(arq, "r+ - Le e acrescenta mais informacoes;\n\n");
    fclose(arq);

    arq = fopen("teste198.txt", "a");
    fprintf(arq, "w+ - Leitura e escrita;\nApaga tudo;\n\n");
    fclose(arq);

    arq = fopen("teste198.txt", "a");
    fprintf(arq, "a+ - Leitura e escrita;\nSempre escreve no final;\n\n");
    fclose(arq);

    printf("Programa encerrado.\n");

    return 0;
}