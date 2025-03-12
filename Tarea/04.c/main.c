#include <stdio.h>
#include <stdlib.h>

/* incremento de precio.
El programa, al recibir como dato el precio de un producto, incrementa al
mismo 11% si es menor a 1500$ y 8% en caso contrario (mayor o igual).

PRE y NPR: variables de tipo real. */

void main(void)
{

float PRE, NPR;
printf("Ingrese el precio del producto: ");
scanf ("%f", &PRE);
if (PRE < 1500)
    NPR = PRE * 1.11;
else NPR = PRE * 1.8;
printf("\nNuevo precio del producto: %8.2f",NPR);
}
