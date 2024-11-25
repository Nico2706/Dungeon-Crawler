
# Dungeon Crawler RPG

Este es un juego tipo **Dungeon Crawler RPG** donde el jugador explora una mazmorras generadas aleatoriamente, enfrentándose a enemigos, recogiendo tesoros y evitando trampas. El objetivo es llegar a la salida de la mazmorra, todo mientras se va acumulando puntos y perdiendo vida por las interacciones con los distintos elementos.

## Características

- **Exploración aleatoria**: La mazmora está compuesta por una matriz de habitaciones generadas de forma aleatoria. Cada habitación puede contener un enemigo, un tesoro, una trampa o estar vacía.
- **Interacciones**: El jugador puede enfrentarse a enemigos respondiendo preguntas matemáticas. También puede recoger tesoros o caer en trampas que afectan su vida.
- **Puntuaciones**: Se guarda la puntuación del jugador en un archivo externo. Además, el jugador puede ver si ha superado la puntuación más alta previamente guardada.
- **Desarrollo en consola**: El juego se ejecuta en la terminal o consola, sin gráficos complejos, pero con una interfaz sencilla para interactuar.

## Instalación

Este proyecto está desarrollado en **C**. Para compilar y ejecutar el juego, sigue estos pasos:

1. Clona este repositorio:
   
   ```bash
   git clone https://github.com/tuusuario/dungeon-crawler-rpg.git

2. Entra en el directorio del proyecto:

   ```bash
   cd dungeon-crawler-rpg


3. Compila el código con el siguiente comando (asegúrate de tener un compilador de C instalado):

   ```bash
   gcc -o dungeon_crawler main.c


4. Ejecuta el juego:

   ```bash
   ./dungeon_crawler
