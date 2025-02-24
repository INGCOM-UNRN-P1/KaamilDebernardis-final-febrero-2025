/*
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 */


#include "ejercicio.h"
#include <assert.h>
#include <stdio.h>

void prueba(char* cadena)
{
    int posicion_error = 0;
    
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
}

int main()
{
    //Prueba 1
    printf("Prueba 1 (se espera que diga que está balanceada):\n");
    prueba("(([)]){{}{{{}}}}");
    
    //Prueba 2
    printf("\nPrueba 2 (se espera que diga que no está balanceada):\n");
    prueba("([)])({{}{{{}}}}");
    
    //Prueba 3
    printf("\nPrueba 3 (se espera que diga que no hay caracteres para balancear):\n");
    prueba("Hola mundo");
}
