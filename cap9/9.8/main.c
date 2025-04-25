#include <stdio.h>
/* Alumnos.
El programa almacena variables de tipo estructura alumno en un archivo. */
typedef struct /* Declaración de la estructura alumno. */
{
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

void escribe(FILE *); /* Prototipo de función. */

void main(void)
{
    FILE *ar;
    if ((ar = fopen("ad1.dat", "w")) != NULL)  // Corrected quotation marks
        escribe(ar);
    else
        printf("\nEl archivo no se puede abrir");
    fclose(ar);
}

void escribe(FILE *ap)
{
    alumno alu;
    int i = 0, r;
    printf("\n¿Desea ingresar información sobre alumnos? (Sí-1 No-0): ");
    scanf("%d", &r);

    while (r)
    {
        i++;
        printf("Matrícula del alumno %d: ", i);
        scanf("%d", &alu.matricula);

        printf("Nombre del alumno %d: ", i);
        // Clear input buffer before reading strings
        getchar(); // To consume the newline character left by previous scanf
        fgets(alu.nombre, sizeof(alu.nombre), stdin);
        alu.nombre[strcspn(alu.nombre, "\n")] = '\0'; // Remove the newline character

        printf("Carrera del alumno %d: ", i);
        scanf("%d", &alu.carrera);

        printf("Promedio del alumno %d: ", i);
        scanf("%f", &alu.promedio);

        fwrite(&alu, sizeof(alumno), 1, ap); // Save student data to file

        printf("\n¿Desea ingresar información sobre más alumnos? (Sí-1 No-0): ");
        scanf("%d", &r);
    }
}
