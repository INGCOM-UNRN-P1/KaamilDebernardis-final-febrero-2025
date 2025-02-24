/*
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 */

#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

#include "ejercicio.h"

#define LARGO_MAXIMO 100000

int main()
{
    char cadena[LARGO_MAXIMO];
    int posicion_error = 0;
    
    printf("Ingresá la cadena, así te digo si está balanceada o no\n");
    scanf("%s", cadena);
    
    int resultado = verificador_balanceado(cadena, &posicion_error);
    
    if (resultado != -1)
    {
        if (resultado == 1)
        {
            printf("La cadena está balanceada\n");
        }
        else if (resultado == 0)
        {
            printf("La cadena no está balanceada. Se rompió el balanceo en la posición %d\n", posicion_error);
            printf("%s\n", cadena);
            for (int i=0; i<posicion_error; i++)
            {
                printf(" ");
            }
            printf("^");
        }
        else if (resultado == 2)
        {
            printf("No hay nada que pueda estar o no estar balanceado, ¿qué querés que te diga?\n");
        }
    }
    else
    {
        printf("Error al leer cadena, su valor es nulo\n");
    }
    
    return 0;
}