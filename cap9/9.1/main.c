#include <stdio.h>

int main(void) {
    char p1;
    FILE *ar;

    ar = fopen("arc.txt", "w"); // Se abre el archivo en modo escritura

    if (ar != NULL) {
        while ((p1 = getchar()) != '\n') {
            fputc(p1, ar); // Escribimos el carácter en el archivo
        }
        fclose(ar); // Se cierra el archivo correctamente después del bucle
    } else {
        printf("No se puede abrir el archivo\n");
    }

    return 0;
}
