#include <stdio.h>

/* Prototipo de la función. Se pasa un archivo como parámetro. */
void promedio(FILE *);

int main(void) {
    FILE *ar;

    if ((ar = fopen("arc9.txt", "r")) != NULL) {
        promedio(ar); /* Se llama a la función promedio. */
        fclose(ar);   /* Se cierra el archivo después de procesarlo. */
    } else {
        printf("No se puede abrir el archivo\n");
    }

    return 0;
}

void promedio(FILE *ar1) {
    int i, j, n, mat;
    float pro, cal;

    fscanf(ar1, "%d", &n); /* Se lee el número de alumnos */

    for (i = 0; i < n; i++) {
        fscanf(ar1, "%d", &mat); /* Se lee la matrícula de cada alumno */
        printf("%d\t", mat);     /* Imprime la matrícula */

        pro = 0;  /* Inicializa el promedio para cada alumno */

        for (j = 0; j < 5; j++) {
            fscanf(ar1, "%f", &cal); /* Se leen las calificaciones */
            pro += cal;               /* Acumula las calificaciones */
        }

        printf("\t%.2f\n", pro / 5); /* Imprime el promedio del alumno */
    }
}
