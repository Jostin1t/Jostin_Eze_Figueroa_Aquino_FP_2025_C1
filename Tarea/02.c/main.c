#include <stdio.h>

int main(void) {
    float PRE, NPR;

    printf("Ingrese el precio del producto: ");
    if (scanf("%f", &PRE) != 1) {
        printf("Error al ingresar el precio.\n");
        return 1;
    }

    printf("Precio ingresado: %.2f\n", PRE);


    if (PRE <= 1500) {
        NPR = PRE * 1.11;
        printf("Nuevo precio: %.2f\n", NPR);
    } else {
        printf("El precio no requiere incremento.\n");
    }

    return 0;
}


