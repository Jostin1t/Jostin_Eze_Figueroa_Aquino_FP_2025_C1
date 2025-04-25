#include <stdio.h>
#include <string.h>

/* Ordena de menor a mayor.
El programa ordena de menor a mayor en función de la matrícula, creando un
nuevo archivo, un archivo de acceso directo compuesto por estructuras y
ordenado de mayor a menor. */
typedef struct /* Declaración de la estructura alumno. */
{
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

void ordena(FILE *, FILE *); /* Prototipo de función. */

void main(void)
{
    FILE *ar1, *ar2;
    ar1 = fopen("ad5.dat", "r");
    ar2 = fopen("ad6.dat", "w");

    if ((ar1 != NULL) && (ar2 != NULL))
    {
        ordena(ar1, ar2);
    }
    else
    {
        printf("\nEl o los archivos no se pudieron abrir");
    }

    fclose(ar1);
    fclose(ar2);
}

void ordena(FILE *ap1, FILE *ap2)
/* Esta función ordena de menor a mayor un archivo compuesto por estructuras,
en función de su matrícula, y genera un nuevo archivo. */
{
    alumno alu;
    int i, j, n;
    long int pos;

    // First, count the number of records
    fseek(ap1, 0, SEEK_END);
    n = ftell(ap1) / sizeof(alumno); // Number of records
    rewind(ap1); // Move the file pointer back to the beginning

    // Array to store records
    alumno alumnos[n];

    // Read all records into memory
    for (i = 0; i < n; i++)
    {
        fread(&alumnos[i], sizeof(alumno), 1, ap1);
    }

    // Sorting the records by matricula in ascending order (using bubble sort)
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (alumnos[i].matricula > alumnos[j].matricula)
            {
                // Swap the records
                alu = alumnos[i];
                alumnos[i] = alumnos[j];
                alumnos[j] = alu;
            }
        }
    }

    // Write the sorted records to the output file
    for (i = 0; i < n; i++)
    {
        fwrite(&alumnos[i], sizeof(alumno), 1, ap2);
    }
}
