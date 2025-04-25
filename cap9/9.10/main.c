#include <stdio.h>
/* Alumnos.
El programa pregunta al usuario el número de registro que desea
modificar, obtiene el nuevo promedio del alumno y modifica tanto el
registro como el archivo correspondiente. */
typedef struct /* Declaración de la estructura alumno. */
{
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

void modifica(FILE *); /* Prototipo de función. */

void main(void)
{
    FILE *ar;
    if ((ar = fopen("ad1.dat", "r+")) != NULL)  // Corrected quotation marks
        modifica(ar);
    else
        printf("\nEl archivo no se puede abrir");
    fclose(ar);
}

void modifica(FILE *ap)
/* Esta función se utiliza para modificar el promedio de un alumno. */
{
    int d;
    alumno alu;

    printf("\nIngrese el número de registro que desea modificar: ");
    scanf("%d", &d);

    // Move the file pointer to the correct record position (d-1)
    fseek(ap, (d - 1) * sizeof(alumno), SEEK_SET);

    // Read the record to ensure it exists
    if (fread(&alu, sizeof(alumno), 1, ap) != 1) {
        printf("\nError al leer el registro. El número de registro es inválido.");
        return;  // Exit if the read fails
    }

    // Modify the student's promedio
    printf("\nIngrese el promedio correcto del alumno: ");
    scanf("%f", &alu.promedio);

    // Position the file pointer back to the correct record position to overwrite it
    fseek(ap, (d - 1) * sizeof(alumno), SEEK_SET);

    // Write the modified record back to the file
    fwrite(&alu, sizeof(alumno), 1, ap);
    printf("\nRegistro modificado correctamente.");
}
