#include <stdio.h>

int main(void) {
    int i, j, n, mat;
    float cal, pro;
    FILE *ar;

    if ((ar = fopen("arc9.txt", "r")) != NULL) {
        fscanf(ar, "%d", &n); /* Se lee el número de alumnos */

        for (i = 0; i < n; i++) {
            fscanf(ar, "%d", &mat); /* Se lee la matrícula de cada alumno */
            printf("%d\t", mat);

            pro = 0;  // Reseteamos el promedio a 0 para cada alumno

            for (j = 0; j < 5; j++) {
                fscanf(ar, "%f", &cal); /* Se leen las cinco calificaciones del alumno */
                pro += cal;
            }

            printf("\t%.2f\n", pro / 5); /* Se escribe el promedio de cada alumno */
        }

        fclose(ar);  // Cerrar el archivo
    } else {
        printf("No se puede abrir el archivo\n");
    }

    return 0;
}
