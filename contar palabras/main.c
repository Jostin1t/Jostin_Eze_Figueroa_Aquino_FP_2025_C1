#include <stdio.h>
#include <ctype.h>

#define NUM_LETRAS 26

int main() {
    FILE *archivo;
    char nombreArchivo[] = "C:\\Users\\kevin\\Downloads\\eBook - 23 Hábitos Anti-Procrastinación Cómo dejar de ser perezoso y tener resultados en tu vida. By S.J. Scott.txt";
    char caracter;
    int letras[NUM_LETRAS] = {0};
    int enPalabra = 0;
    int totalPalabras = 0;

    archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    while ((caracter = fgetc(archivo)) != EOF) {
        // Contador de letras
        if (isalpha(caracter)) {
            letras[tolower(caracter) - 'a']++;
        }

        // Contador de palabras
        if (isspace(caracter) || ispunct(caracter)) {
            if (enPalabra) {
                totalPalabras++;
                enPalabra = 0;
            }
        } else if (isalnum(caracter)) {
            enPalabra = 1;
        }
    }

    // Si el archivo termina con una palabra sin espacio final
    if (enPalabra) {
        totalPalabras++;
    }

    fclose(archivo);

    printf("Total de palabras: %d\n", totalPalabras);
    printf("Frecuencia de letras:\n");
    for (int i = 0; i < NUM_LETRAS; i++) {
        printf("%c: %d\n", 'a' + i, letras[i]);
    }

    return 0;
}
