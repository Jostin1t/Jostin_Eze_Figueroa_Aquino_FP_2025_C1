#include <stdio.h>

/* Estructura alumno */
typedef struct {
    int clave;
    char nombre[20];
    int carrera;
    float promedio;
    float examen;
    char telefono[12];
} alumno;

/* Prototipos de funciones */
float F1(FILE *);
void F2(FILE *, FILE *, FILE *, FILE *, FILE *, FILE *);
void F3(FILE *, FILE *, FILE *, FILE *, FILE *);

int main(void) {
    float pro;
    FILE *ap, *c1, *c2, *c3, *c4, *c5;

    /* Apertura de archivos */
    ap = fopen("alu1.dat", "r");
    c1 = fopen("car1.dat", "w+");
    c2 = fopen("car2.dat", "w+");
    c3 = fopen("car3.dat", "w+");
    c4 = fopen("car4.dat", "w+");
    c5 = fopen("car5.dat", "w+");

    if (ap != NULL && c1 != NULL && c2 != NULL && c3 != NULL && c4 != NULL && c5 != NULL) {
        pro = F1(ap);
        printf("\nPROMEDIO EXAMEN DE ADMISIÓN: %.2f\n", pro);

        rewind(ap); // Reiniciar puntero de archivo antes de leer de nuevo
        F2(ap, c1, c2, c3, c4, c5);
        F3(c1, c2, c3, c4, c5);
    } else {
        printf("\nEl o los archivos no se pudieron abrir\n");
    }

    /* Cierre de archivos */
    if (ap) fclose(ap);
    if (c1) fclose(c1);
    if (c2) fclose(c2);
    if (c3) fclose(c3);
    if (c4) fclose(c4);
    if (c5) fclose(c5);

    return 0;
}

/* Función para obtener el promedio del examen de admisión */
float F1(FILE *ap) {
    alumno alu;
    float sum = 0;
    int i = 0;

    while (fread(&alu, sizeof(alumno), 1, ap) == 1) {
        sum += alu.examen;
        i++;
    }

    return (i > 0) ? (sum / i) : 0;
}

/* Función para generar archivos de alumnos admitidos por carrera */
void F2(FILE *ap, FILE *c1, FILE *c2, FILE *c3, FILE *c4, FILE *c5) {
    alumno alu;
    rewind(ap); // Volver al inicio del archivo

    while (fread(&alu, sizeof(alumno), 1, ap) == 1) {
        /* Evaluar si el alumno es admitido */
        if (((alu.examen >= 1300) && (alu.promedio >= 8)) || ((alu.examen >= 1400) && (alu.promedio >= 7))) {
            switch (alu.carrera) {
                case 1: fwrite(&alu, sizeof(alumno), 1, c1); break;
                case 2: fwrite(&alu, sizeof(alumno), 1, c2); break;
                case 3: fwrite(&alu, sizeof(alumno), 1, c3); break;
                case 4: fwrite(&alu, sizeof(alumno), 1, c4); break;
                case 5: fwrite(&alu, sizeof(alumno), 1, c5); break;
            }
        }
    }
}

/* Función para calcular el promedio de admitidos en cada carrera */
void F3(FILE *c1, FILE *c2, FILE *c3, FILE *c4, FILE *c5) {
    alumno alu;
    float cal[5] = {0}; // Inicializar en 0
    FILE *archivos[5] = {c1, c2, c3, c4, c5};

    for (int i = 0; i < 5; i++) {
        int count = 0;
        float sum = 0;
        rewind(archivos[i]); // Reiniciar puntero del archivo

        while (fread(&alu, sizeof(alumno), 1, archivos[i]) == 1) {
            sum += alu.examen;
            count++;
        }

        cal[i] = (count > 0) ? (sum / count) : 0;
        printf("\nPromedio carrera %d: %.2f", i + 1, cal[i]);
    }
}
