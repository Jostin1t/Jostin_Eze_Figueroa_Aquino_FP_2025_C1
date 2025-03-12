#include <stdio.h>
#include <stdlib.h>

/*Promedio curso.
El programa, al recibir como dato el promedio de un alumno en un curso
universitario, escribe aprobado si su promedio es mayor o igual a 6, o
reprobado en caso contrario.

PRO: varible de tipo real. */

void main(void)
{

float PRO;
printf ("ingrese el promedio del alumno:  ");
scanf ("%f", &PRO);
if (PRO >= 6.0)
    printf ("\nAprovado");
else
    printf("\nReprovado");
}
