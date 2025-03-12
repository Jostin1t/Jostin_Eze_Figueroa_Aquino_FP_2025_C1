#include <stdio.h>
/* Promedio curso.
El programa,al recibir como dato el
promedio de un curso universitario,
escribe "Aprovado" si su promedio es
mayor o igual a 6.
PRO: variable de tipo real.
*/

int main(void) {
float PRO;
printf("Ingrese el promedio del alumno: ");
       scanf("%f", &PRO);
       if (PRO >= 6)
        printf("\nAprovado");
       return 0;
}
