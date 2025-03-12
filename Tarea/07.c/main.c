#include <stdio.h>
#include <stdlib.h>

/* Ventas descendentes.
El programa, al recibir como datos tres valores que representan las ventas
de los vendedores de una tienda de discos, escribe las ventas en orden descendente.
P, S y R: variables de tipo real. */

void main(void) {
    float P, S, R;

    printf("\nIngrese las ventas de los tres vendedores: ");
    scanf("%f %f %f", &P, &S, &R);

    if (P >= S && P >= R) {
        if (S >= R)
            printf("\n\nEl orden es P, S y R: %.2f %.2f %.2f", P, S, R);
        else
            printf("\n\nEl orden es P, R y S: %.2f %.2f %.2f", P, R, S);
    }
    else if (S >= P && S >= R) {
        if (P >= R)
            printf("\n\nEl orden es S, P y R: %.2f %.2f %.2f", S, P, R);
        else
            printf("\n\nEl orden es S, R y P: %.2f %.2f %.2f", S, R, P);
    }
    else {
        if (P >= S)
            printf("\n\nEl orden es R, P y S: %.2f %.2f %.2f", R, P, S);
        else
            printf("\n\nEl orden es R, S y P: %.2f %.2f %.2f", R, S, P);
    }
}
