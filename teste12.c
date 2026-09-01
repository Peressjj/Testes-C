#include <stdio.h>

int main() {

    int numeroum = 0;
    
    do {
        printf("%d\n", numeroum);
    } while (numeroum++, numeroum > 10); // < >
    
    return 0;
}