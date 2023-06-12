#include <stdio.h>
#include <stdbool.h>

int realizarMovimientoJugadorColumnas(int posicionCol, char movimiento)
{
    switch (movimiento)
    {
    case 'A':
        posicionCol--;
        break;

    case 'D':
        posicionCol++;
        break;
    }
    return posicionCol;
}

int realizarMovimientoJugadorFilas(int posicionFil, char movimiento)
{
    switch (movimiento)
    {

    case 'S':
        posicionFil++;
        break;

    case 'W':
        posicionFil--;
        break;
    }

    return posicionFil;
}

bool verificarGano(int posicionFil, int posicionCol)
{
    bool gano = posicionFil == 4 && posicionCol == 4;
    return gano;

}
