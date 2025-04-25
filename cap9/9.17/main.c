#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Reemplaza palabras.
El programa lee cadenas de caracteres de un archivo y cada vez que
encuentra la palabra México escrita en forma incorrecta —la primera con
minúscula— la reemplaza por su forma correcta y escribe la cadena en otro
archivo. */
void cambia(FILE *, FILE *); /* Prototipo de función. Se pasan dos archivos como parámetros. */

int main(void)
{
    FILE *ar;
    FILE *ap;
    ar = fopen("arc.txt", "r");  /* Se abre el archivo arc.txt para lectura. */
    ap = fopen("arc1.txt", "w"); /* Se abre el archivo arc1.txt para escritura. */
    if ((ar != NULL) && (ap != NULL))
    {
        cambia(ar, ap);
        fclose(ar);
        fclose(ap);
    }
    else
        printf("No se pueden abrir los archivos");
    return 0;  // Added return statement for main.
}

void cambia(FILE *ap1, FILE *ap2)
{
    /* Esta función reemplaza en la cadena de caracteres la palabra méxico escrita
    con minúsculas —la primera letra— por su forma correcta y escribe la cadena
    de caracteres en un nuevo archivo. */
    char cad[256], *cad2;  // Increased buffer size to 256
    while (fgets(cad, sizeof(cad), ap1) != NULL)  // Changed feof to fgets() check
    {
        cad2 = strstr(cad, "méxico");  // Localiza la subcadena "méxico"
        while (cad2 != NULL)
        {
            cad2[0] = 'M';  // Reemplaza la 'm' por 'M'
            cad2 = strstr(cad2 + 1, "méxico");  // Busca la siguiente ocurrencia
        }
        fputs(cad, ap2);  // Escribe la línea modificada en el archivo ap2
    }
}
