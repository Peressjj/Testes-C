#include <stdio.h>
/* Acessando elementos com notacao */

int main() {
    
    int offset;
    int arr[] = {1, 2, 3, 4};
    int *arrPtr = arr;

    printf("Notacao subscrito: \n");
    for (int i = 0; i < 4; i++) {
        printf("arr: [%d] = %d\n", i, arr[i]);
    }

    printf("\n\n");

    printf("Notacao ponteiro offset: \n");
    for (int offset = 0; offset < 4; offset++) {
        printf("*(arr + %d) = %d\n", offset, *(arr + offset));
    }

    printf("\n\n");

    printf("Notacao subscrito de ponteiro: \n");
    for (int i = 0; i < 4; i++) {
        printf("arrPtr[%d] = %d\n", i, arrPtr[i]);
    }

    printf("\n\n");

    printf("Notacao ponteiro offset: \n");
    for (int offset = 0; offset < 4; offset++) {
        printf("*(arrPtr + %d) = %d\n", offset, *(arrPtr + offset));
    }

    printf("\n\n");

    return 0;

}