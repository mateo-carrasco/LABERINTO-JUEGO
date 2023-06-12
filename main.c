#include <stdio.h>
#include <stdbool.h>
#include "maze.h"
#include "player.h"

int main()
{
    int opcion;
    do
    {
        printf("Bienvenido al juego del laberinto!\n");
        printf("1. Jugar\n");
        printf("2. Creditos\n");
        printf("3. Salir\n");
        printf("Presione un numero\n");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            juegoNuevo();
            break;
        case 2:
            printf("Sebastian Carrasco\n");
            printf("A00108304\n");
            break;
        case 3:
            printf("Grascias por participar!\n");
            printf("Usted salio del programa\n");
            break;
        default:
            printf("Entre las opciones solo estan los numeros 1, 2 y 3\n");
            break;
        }
    } while (opcion != 3);
}

int juegoNuevo()
{
    int matriz[5][5] = {

        {0, 1, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {1, 0, 0, 1, 0}

    };

    int posicionFil = 0;
    int posicionCol = 0;
    bool impresionMatriz = true;
    int movimientos = 0;

    imprimirLaberinto(posicionFil, posicionCol, matriz);

    do
    {

        char movimiento;
        getchar();
        printf("Ingrese su movimiento:");
        scanf("%c", &movimiento);
        impresionMatriz = true;

        bool movimientoValido = revisarMovimiento(movimiento, posicionFil, posicionCol, matriz);
        if (movimientoValido)
        {
            posicionCol = realizarMovimientoJugadorColumnas(posicionCol, movimiento);
            posicionFil = realizarMovimientoJugadorFilas(posicionFil, movimiento);
            imprimirLaberinto(posicionFil, posicionCol, matriz);
            movimientos++;
        }

    } while (verificarGano(posicionFil, posicionCol) == false);
    printf("Movimientos: %d\n", movimientos);
    printf("Felicidades, has ganado!\n");
    if (movimientos <= 8)
    {
        printf("Eres un pro!\n");
    }
    else if (movimientos < 15)
    {
        printf("Eres novato\n");
    }
    else
    {
        printf("Eres un noob!\n");
    }
}
