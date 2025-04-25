#include <stdio.h>
#include <stdlib.h>

/* Suma reales.
El programa lee cadenas de caracteres de un archivo, detecta aquellas que
comienzan con números, los suma y calcula el promedio de los mismos. */

void sumypro(FILE *); /* Prototipo de función. */

int main(void)
{
    FILE *ap;
    if ((ap = fopen("arc2.txt", "r")) != NULL)  // Fixed quotation marks
    {
        sumypro(ap);
        fclose(ap);
    }
    else
        printf("No se puede abrir el archivo");  // Fixed quotation marks
    return 0;  // Added return statement for main.
}

void sumypro(FILE *ap1)
{
    /* Esta función lee cadenas de caracteres de un archivo, detecta aquellas
    que comienzan con números, y obtiene la suma y el promedio de dichos
    números. */
    char cad[30];
    int i = 0;
    float sum = 0.0, r;
    while (fgets(cad, sizeof(cad), ap1) != NULL)  // Fixed fgets loop
    {
        r = atof(cad);  // Convert string to float
        if (r != 0.0)   // If the number is valid (not 0)
        {
            i++;
            sum += r;
        }
    }
    printf("\nSuma: %.2f", sum);
    if (i)  // If at least one valid number was found
        printf("\nPromedio: %.2f", sum / i);
}
