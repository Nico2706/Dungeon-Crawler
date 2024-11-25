#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILAS 5
#define COLUMNAS 5

#define VACIA 0
#define SALIDA 4

#define ENEMIGO 1
#define TESORO 2
#define TRAMPA 3

typedef struct Nodo {
    int fila;
    int columna;
    int tipo; // ENEMIGO, TESORO, TRAMPA
    struct Nodo *siguiente;
} Nodo;

typedef struct {
    int vida;
    int puntos;
    int fila;
    int columna;
    char nombre[50];
} Jugador;

// Prototipos
void generarMazmorra(Nodo **elementos, int mazmorra[FILAS][COLUMNAS]);
void mostrarMazmorra(int mazmorra[FILAS][COLUMNAS], Nodo *elementos, Jugador jugador);
void moverJugador(Jugador *jugador, char movimiento);
void procesarCasilla(Jugador *jugador, Nodo **elementos, int mazmorra[FILAS][COLUMNAS]);
void agregarElemento(Nodo **lista, int fila, int columna, int tipo);
Nodo *buscarElemento(Nodo *lista, int fila, int columna);
void eliminarElemento(Nodo **lista, int fila, int columna);
void enfrentarEnemigo(Jugador *jugador);
void recogerTesoro(Jugador *jugador);
void activarTrampa(Jugador *jugador);
void guardarPuntuacion(const char *nombreArchivo, Jugador jugador);

int main() {
    srand(time(NULL));

    int mazmorra[FILAS][COLUMNAS] = {0};
    Nodo *elementos = NULL;
    Jugador jugador = {100, 0, 0, 0, ""};

   printf("**************************************\n");
printf("*        ¡Dungeon Crawler RPG!       *\n");
printf("**************************************\n");
printf("\n");
printf("Te encuentras frente a la entrada de una antigua mazmorra,\n");
printf("repleta de trampas, enemigos y tesoros olvidados.\n");
printf("La leyenda dice que solo los más valientes sobreviven.\n");
printf("\n");
printf("En el mapa:\n");
printf("  'e' - Enemigos: Responde preguntas o perderás vida.\n");
printf("  't' - Tesoros: ¡Recompensas que aumentan tus puntos!\n");
printf("  'x' - Trampas: Cuidado, te harán perder vida.\n");
printf("\n");
printf("¡Prepárate para enfrentar los desafíos!\n");
printf("\n");
printf("Por favor, aventurero, ingresa tu nombre: ");
scanf("%49s", jugador.nombre);


    generarMazmorra(&elementos, mazmorra);
    mazmorra[FILAS - 1][COLUMNAS - 1] = SALIDA;

    printf("Presiona Enter para iniciar la aventura...\n");
    getchar(); // Limpiar buffer
    getchar();

    while (jugador.vida > 0) {
        mostrarMazmorra(mazmorra, elementos, jugador);

        printf("Vida: %d, Puntos: %d\n", jugador.vida, jugador.puntos);
        printf("Moverse (w/a/s/d): ");
        char movimiento;
        scanf(" %c", &movimiento);

        moverJugador(&jugador, movimiento);
        procesarCasilla(&jugador, &elementos, mazmorra);

      if (mazmorra[jugador.fila][jugador.columna] == SALIDA) {
             printf("\n");
       printf("\n");
    printf("**************************************\n");
    printf("*           ¡Felicidades!            *\n");
    printf("**************************************\n");
    printf("Has encontrado la salida de la mazmorra y\n");
    printf("lograste sobrevivir a sus peligrosos desafíos.\n");
    printf("\n");
    printf("Tu valentía será recordada entre los aventureros.\n");
    printf("\n");
    guardarPuntuacion("puntuaciones.txt", jugador);
    break;
}

if (jugador.vida <= 0) {
     printf("\n");
 printf("\n");
    printf("**************************************\n");
    printf("*           GAME OVER                *\n");
    printf("**************************************\n");
    printf("Tus fuerzas te han abandonado en la mazmorra.\n");
    printf("No lograste escapar de sus trampas y enemigos.\n");
    printf("\n");
    printf("Que tu sacrificio sirva de advertencia a otros.\n");
    printf("\n");
    guardarPuntuacion("puntuaciones.txt", jugador);
}
}

    printf("Presiona Enter para salir...\n");
    while (getchar() != '\n');
    getchar();

    return 0;
}

// Generar la mazmorra y los elementos
void generarMazmorra(Nodo **elementos, int mazmorra[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            int contenido = rand() % 4;
            if (contenido != VACIA) {
                agregarElemento(elementos, i, j, contenido);
            }
        }
    }
    mazmorra[0][0] = VACIA; // Posición inicial vacía
}

// Mostrar la mazmorra
void mostrarMazmorra(int mazmorra[FILAS][COLUMNAS], Nodo *elementos, Jugador jugador) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (i == jugador.fila && j == jugador.columna) {
                printf("J "); // Mostrar la posición del jugador
            } else if (mazmorra[i][j] == SALIDA) {
                printf("s "); // Mostrar la salida
            } else if (buscarElemento(elementos, i, j) != NULL) {
                Nodo *elemento = buscarElemento(elementos, i, j);
                switch (elemento->tipo) {
                    case ENEMIGO: printf("e "); break;
                    case TESORO: printf("t "); break;
                    case TRAMPA: printf("x "); break;
                }
            } else {
                printf(". "); // Espacios vacíos
            }
        }
        printf("\n");
    }
}
// Mover al jugador
void moverJugador(Jugador *jugador, char movimiento) {
    if (movimiento == 'w' && jugador->fila > 0) jugador->fila--;
    else if (movimiento == 's' && jugador->fila < FILAS - 1) jugador->fila++;
    else if (movimiento == 'a' && jugador->columna > 0) jugador->columna--;
    else if (movimiento == 'd' && jugador->columna < COLUMNAS - 1) jugador->columna++;
    else printf("Movimiento no válido.\n");
}

// Procesar la casilla actual
void procesarCasilla(Jugador *jugador, Nodo **elementos, int mazmorra[FILAS][COLUMNAS]) {
    Nodo *elemento = buscarElemento(*elementos, jugador->fila, jugador->columna);
    if (elemento != NULL) {
        switch (elemento->tipo) {
            case ENEMIGO: enfrentarEnemigo(jugador); break;
            case TESORO: recogerTesoro(jugador); break;
            case TRAMPA: activarTrampa(jugador); break;
        }
        eliminarElemento(elementos, jugador->fila, jugador->columna);
    }
}

// Funciones para manejar la lista enlazada
void agregarElemento(Nodo **lista, int fila, int columna, int tipo) {
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->fila = fila;
    nuevo->columna = columna;
    nuevo->tipo = tipo;
    nuevo->siguiente = *lista;
    *lista = nuevo;
}

Nodo *buscarElemento(Nodo *lista, int fila, int columna) {
    while (lista != NULL) {
        if (lista->fila == fila && lista->columna == columna) {
            return lista;
        }
        lista = lista->siguiente;
    }
    return NULL;
}

void eliminarElemento(Nodo **lista, int fila, int columna) {
    Nodo *actual = *lista, *anterior = NULL;

    while (actual != NULL) {
        if (actual->fila == fila && actual->columna == columna) {
            if (anterior == NULL) {
                *lista = actual->siguiente;
            } else {
                anterior->siguiente = actual->siguiente;
            }
            free(actual);
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
}

// Enfrentamiento, tesoro y trampa
void enfrentarEnemigo(Jugador *jugador) {
    printf("Te enfrentas a un enemigo. Responde correctamente para ganar puntos.\n");
    int correcta = rand() % 20;
    int respuesta;
    printf("¿Cuánto es %d + %d? ", correcta, correcta);
    scanf("%d", &respuesta);

    if (respuesta == 2 * correcta) {
        printf("¡Correcto! Ganas 10 puntos.\n");
        jugador->puntos += 10;
    } else {
        printf("Incorrecto. Pierdes 20 de vida.\n");
        jugador->vida -= 20;
    }
}

void recogerTesoro(Jugador *jugador) {
    printf("Encontraste un tesoro. Ganas 20 puntos.\n");
    jugador->puntos += 20;
}

void activarTrampa(Jugador *jugador) {
    printf("¡Caiste en una trampa! Pierdes 15 de vida.\n");
    jugador->vida -= 15;
}

// Guardar puntuación y mostrar la más alta
void guardarPuntuacion(const char *nombreArchivo, Jugador jugador) {
    FILE *archivo = fopen(nombreArchivo, "a+");
    if (archivo == NULL) {
        printf("Error al manejar el archivo de puntuaciones.\n");
        return;
    }

    // Leer la puntuación más alta
    int puntuacionMasAlta = 0;
    char nombreMasAlto[50] = "";
    int puntos, vidaRestante;
    char nombre[50];
    while (fscanf(archivo, "%49s %d %d", nombre, &puntos, &vidaRestante) != EOF) {
        if (puntos > puntuacionMasAlta) {
            puntuacionMasAlta = puntos;
            strcpy(nombreMasAlto, nombre);
        }
    }

    // Mostrar comparación con la puntuación más alta
    printf("\nPuntuación más alta: %s con %d puntos.\n", nombreMasAlto, puntuacionMasAlta);
    printf("Tu puntuación: %d\n", jugador.puntos);
    if (jugador.puntos > puntuacionMasAlta) {
        printf("¡Felicidades! Superaste la puntuación más alta previa.\n");
    } else {
        printf("No superaste la puntuación más alta.\n");
    }

    // Guardar la puntuación actual
    fprintf(archivo, "%s %d %d\n", jugador.nombre, jugador.puntos, jugador.vida);
    fclose(archivo);

    printf("Puntuación guardada exitosamente.\n");
}
