#include <stdio.h>

/* Mezcla.
El programa mezcla, respetando el orden, dos archivos que se encuentran
ordenados en forma ascendente considerando la matrícula de los alumnos. */
void mezcla(FILE *, FILE *, FILE *); /* Prototipo de función. */

int main(void)
{
    FILE *ar, *ar1, *ar2;
    ar = fopen("arc9.dat", "r");  /* Se abre el archivo arc9.dat para lectura. */
    ar1 = fopen("arc10.dat", "r"); /* Se abre el archivo arc10.dat para lectura. */
    ar2 = fopen("arc11.dat", "w"); /* Se abre el archivo arc11.dat para escritura. */

    if (ar != NULL && ar1 != NULL && ar2 != NULL)
    {
        mezcla(ar, ar1, ar2);
        fclose(ar);
        fclose(ar1);
        fclose(ar2);
    }
    else
    {
        printf("No se pueden abrir los archivos");
    }

    return 0;  // Added return statement for main.
}

void mezcla(FILE *ar, FILE *ar1, FILE *ar2)
{
    int i, mat, mat1;
    float ca[3], ca1[3];

    /* Leer y mezclar datos mientras haya datos en ambos archivos */
    while (fscanf(ar, "%d", &mat) == 1 && fscanf(ar1, "%d", &mat1) == 1)
    {
        for (i = 0; i < 3; i++)  // Leer calificaciones de ar
            fscanf(ar, "%f", &ca[i]);
        for (i = 0; i < 3; i++)  // Leer calificaciones de ar1
            fscanf(ar1, "%f", &ca1[i]);

        /* Compara las matrículas y escribe en el archivo de salida */
        while (mat <= mat1)
        {
            fprintf(ar2, "%d\t", mat);
            for (i = 0; i < 3; i++)
                fprintf(ar2, "%f\t", ca[i]);
            fputs("\n", ar2);
            if (fscanf(ar, "%d", &mat) != 1)
                break;
            for (i = 0; i < 3; i++)
                fscanf(ar, "%f", &ca[i]);
        }
        while (mat1 < mat)
        {
            fprintf(ar2, "%d\t", mat1);
            for (i = 0; i < 3; i++)
                fprintf(ar2, "%f\t", ca1[i]);
            fputs("\n", ar2);
            if (fscanf(ar1, "%d", &mat1) != 1)
                break;
            for (i = 0; i < 3; i++)
                fscanf(ar1, "%f", &ca1[i]);
        }
    }

    /* Si alguno de los archivos aún tiene datos, escribe esos datos */
    while (fscanf(ar, "%d", &mat) == 1)
    {
        fprintf(ar2, "%d\t", mat);
        for (i = 0; i < 3; i++)
            fscanf(ar, "%f", &ca[i]);
        for (i = 0; i < 3; i++)
            fprintf(ar2, "%f\t", ca[i]);
        fputs("\n", ar2);
    }

    while (fscanf(ar1, "%d", &mat1) == 1)
    {
        fprintf(ar2, "%d\t", mat1);
        for (i = 0; i < 3; i++)
            fscanf(ar1, "%f", &ca1[i]);
        for (i = 0; i < 3; i++)
            fprintf(ar2, "%f\t", ca1[i]);
        fputs("\n", ar2);
    }
}
