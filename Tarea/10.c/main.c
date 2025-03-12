#include <stdio.h>
#include <stdlib.h>

void main(void) {
    int NUM;
    printf("Ingrese el numero: ");
    scanf("%d", &NUM);

    if (NUM == 0) {
        printf("\nNulo");
    } else if (NUM % 2 == 0) {
        printf("\nPar");
    } else {
        printf("\nImpar");
    }
}
