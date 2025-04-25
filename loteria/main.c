#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_JUGADORES 100
#define NUM_PREMIOS 3

typedef struct {
    char nombre[50];
    int numeroJugado;
    float cantidadDinero;
    int idJugada;
} Jugador;

int numerosPremiados[NUM_PREMIOS];
Jugador jugadores[MAX_JUGADORES];
int numJugadores = 0;
int idJugadaActual = 1;

void generarNumerosPremiados() {
    srand(time(NULL));
    for (int i = 0; i < NUM_PREMIOS; i++) {
        numerosPremiados[i] = rand() % 100;
        // Asegurar que los n�meros sean diferentes
        for (int j = 0; j < i; j++) {
            if (numerosPremiados[i] == numerosPremiados[j]) {
                numerosPremiados[i] = rand() % 100;
                j = -1; // Reiniciar el bucle interno
            }
        }
    }
}

void agregarJugador() {
    if (numJugadores < MAX_JUGADORES) {
        printf("Nombre del jugador: ");
        scanf("%s", jugadores[numJugadores].nombre);
        printf("Numero jugado (0-99): ");
        scanf("%d", &jugadores[numJugadores].numeroJugado);
        printf("Cantidad de dinero apostada: ");
        scanf("%f", &jugadores[numJugadores].cantidadDinero);
        jugadores[numJugadores].idJugada = idJugadaActual++;
        numJugadores++;
        printf("Jugador agregado con ID de jugada: %d\n", jugadores[numJugadores - 1].idJugada);
    } else {
        printf("No se pueden agregar mas jugadores.\n");
    }
}

void mostrarNumerosPremiados() {
    printf("Numeros premiados: %d, %d, %d\n", numerosPremiados[0], numerosPremiados[1], numerosPremiados[2]);
}

void mostrarJugadasJugadores() {
    printf("Lista de jugadas de jugadores:\n");
    for (int i = 0; i < numJugadores; i++) {
        printf("ID: %d, Nombre: %s, Numero: %d, Dinero: %.2f\n", jugadores[i].idJugada, jugadores[i].nombre, jugadores[i].numeroJugado, jugadores[i].cantidadDinero);
    }
}

void calcularPremios() {
    for (int i = 0; i < numJugadores; i++) {
        if (jugadores[i].numeroJugado == numerosPremiados[0]) {
            printf("%s gano %.2f (100x) con ID: %d. Felicidades has ganado!\n", jugadores[i].nombre, jugadores[i].cantidadDinero * 100, jugadores[i].idJugada);
        } else if (jugadores[i].numeroJugado == numerosPremiados[1]) {
            printf("%s gano %.2f (50x) con ID: %d. Felicidades has ganado!\n", jugadores[i].nombre, jugadores[i].cantidadDinero * 50, jugadores[i].idJugada);
        } else if (jugadores[i].numeroJugado == numerosPremiados[2]) {
            printf("%s gano %.2f (10x) con ID: %d. Felicidades has ganado!\n", jugadores[i].nombre, jugadores[i].cantidadDinero * 10, jugadores[i].idJugada);
        } else {
            printf("%s con ID: %d, para la proxima\n", jugadores[i].nombre, jugadores[i].idJugada);
        }
    }
}

int main(int argc, char *argv[]) {
    int opcion;

    do {
        printf("\nMenu:\n");
        printf("1. Jugador\n");
        printf("2. Loteria\n");
        printf("3. Lista de numeros premiados\n");
        printf("4. Lista de jugadas de jugadores\n");
        printf("5. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                generarNumerosPremiados(); // Generar n�meros nuevos cada vez
                agregarJugador();
                break;
            case 2:
                calcularPremios();
                break;
            case 3:
                mostrarNumerosPremiados();
                break;
            case 4:
                mostrarJugadasJugadores();
                break;
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while (opcion != 5);

    return 0;
}
