#include <stdio.h>

int main(void) {
    char p1;
    FILE *ar;

    // Se abre el archivo en modo lectura
    if ((ar = fopen("arc.txt", "r")) != NULL) {
        // Se lee cada carácter hasta llegar al final del archivo
        while ((p1 = fgetc(ar)) != EOF) {
            putchar(p1); // Imprimir el carácter en pantalla
        }
        fclose(ar); // Cerrar el archivo después de leerlo
    } else {
        printf("No se puede abrir el archivo\n");
    }

    return 0;
}
