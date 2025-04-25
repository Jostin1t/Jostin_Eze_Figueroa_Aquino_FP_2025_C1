#include <stdio.h>
/* Incorpora caracteres.
El programa agrega caracteres al archivo libro.txt. */
void main(void)
{
    char p1;
    FILE *ar;

    // Open the file in append mode ('a')
    ar = fopen("libro.txt", "a");

    /* Se abre el archivo con la opción para incorporar caracteres. */
    if (ar != NULL)
    {
        printf("Ingrese texto para agregar al archivo (presione Enter para finalizar):\n");

        // Read characters from user input until newline is encountered
        while ((p1 = getchar()) != '\n')  // Corrected to use standard single quotes
            fputc(p1, ar);  // Write each character to the file

        fclose(ar);  // Close the file after writing
        printf("Texto agregado al archivo libro.txt.\n");
    }
    else
    {
        printf("No se puede abrir el archivo libro.txt.\n");
    }
}
