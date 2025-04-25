#include <stdio.h>
/* Alumnos.
El programa lee bloques —variables de tipo estructura alumno— de un archivo
de acceso directo. */
typedef struct { /* Declaración de la estructura alumno. */
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

void lee(FILE *); /* Prototipo de función. */

void main(void)
{
    FILE *ar;
    if ((ar = fopen("ad1.dat", "r")) != NULL)  // Corrected quotation marks
        lee(ar);  // Corrected function call
    else
        printf("\nEl archivo no se puede abrir");
    fclose(ar);
}

void lee(FILE *ap)
{
    alumno alu;

    // Read the first record before entering the loop
    if (fread(&alu, sizeof(alumno), 1, ap) != 1) {
        printf("\nNo se pudo leer datos del archivo.");
        return;  // Exit if the first read fails
    }

    // Now enter the loop, reading subsequent records
    while (fread(&alu, sizeof(alumno), 1, ap) == 1) {
        printf("\nMatrícula: %d", alu.matricula);
        printf("\tCarrera: %d", alu.carrera);
        printf("\tPromedio: %f\t", alu.promedio);
        puts(alu.nombre);
    }
}
