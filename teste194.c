// 14.06.26
#include <stdio.h>
// arquivos

int main() {

    FILE *arq1;

    arq1 = fopen("teste193.txt", "a");

    if (arq1 == NULL) {
        printf("Falha ao abrir arquivo!\n");
        return 1;
    } else {
        printf("arquivo aberto!\n");
    }

    fprintf(arq1, "\n...A roupa do rei de roma.");

    fclose(arq1);

    char texto1[100];
    char texto2[100];

    arq1 = fopen("teste193.txt", "r");

    if (arq1 == NULL) {
        printf("Falha ao abrir arquivo!\n");
        return 1;
    } else {
        printf("arquivo aberto!\n");
    }

    fgets(texto1, sizeof(texto1), arq1);
    fgets(texto2, sizeof(texto2), arq1);

    puts(texto1);
    puts(texto2);

    fclose(arq1);
    
    arq1 = fopen("teste194.txt", "w");

    if (arq1 == NULL) {
        printf("Falha ao abrir aquivo!\n");
        return 1;
    } else {
        printf("Arquivo aberto!\n");
    }

    fprintf(arq1, texto1);
    fprintf(arq1, texto2);

    fclose(arq1);






    return 0;
}