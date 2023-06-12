#include <stdio.h>
#include <stdbool.h>

void imprimirLaberinto(int posicionFil, int posicionCol, int matriz[5][5])
{
    for (int fila = 0; fila < 5; fila++)
    {
        for (int col = 0; col < 5; col++)
        {
            if (posicionFil == fila && posicionCol == col)
            {
                printf("X");
            }
            else
            {
                printf("%d", matriz[fila][col]);
            }
        }
        printf("\n");
    }
}

bool revisarMovimiento(char movimiento, int posicionFil, int posicionCol, int matriz[5][5])
{
    bool movimientoValido = true;
    switch (movimiento)
    {
    case 'A':
        if (posicionCol - 1 < 0 || matriz[posicionFil][posicionCol - 1] == 1)
        {
            printf("Movimiento invalido\n");
            movimientoValido = false;
        }
        break;

    case 'S':
        if (posicionFil + 1 > 4 || matriz[posicionFil + 1][posicionCol] == 1)
        {
            printf("Movimiento invalido\n");
            movimientoValido = false;
        }
        break;

    case 'D':
        if (posicionCol + 1 > 4 || matriz[posicionFil][posicionCol + 1] == 1)
        {
            printf("Movimiento invalido\n");
            movimientoValido = false;
        }
        break;

    case 'W':
        if (posicionFil - 1 < 0 || matriz[posicionFil - 1][posicionCol] == 1)
        {
            printf("Movimiento invalido\n");
            movimientoValido = false;
        }
        break;

    default:
        printf("Movimiento invalido, ingrese otro movimiento\n");
        movimientoValido = false;
        break;
    }

    return movimientoValido;
}
