#include <stdio.h>
#include <string.h>

int main(void) {
    char cad[50];
    int res;
    FILE *ar;

    if ((ar = fopen("arc.txt", "w")) != NULL) {
        printf("\n¿Desea ingresar una cadena de caracteres? Sí-1 No-0: ");
        scanf("%d", &res);
        getchar(); // Consumir el salto de línea pendiente

        while (res) {
            printf("Ingrese la cadena: ");
            fgets(cad, sizeof(cad), stdin);

            // Eliminar el salto de línea que deja fgets
            cad[strcspn(cad, "\n")] = 0;

            fputs(cad, ar);

            printf("\n¿Desea ingresar otra cadena de caracteres? Sí-1 No-0: ");
            scanf("%d", &res);
            getchar(); // Consumir el salto de línea pendiente

            if (res) {
                fputs("\n", ar); // Agregar salto de línea entre cadenas
            }
        }
        fclose(ar);
    } else {
        printf("No se puede abrir el archivo\n");
    }

    return 0;
}
