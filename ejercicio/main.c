/*
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 */

#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

#include "ejercicio.h"

int main()
{
    int posicion_error = 0;
    
    FILE *cadena = fopen("archivo.txt", "r");
    
    if (cadena != NULL)
    {
        int resultado = verificador_balanceado(cadena, &posicion_error);
        
        if (resultado == 1)
        {
            printf("La cadena está balanceada\n");
        }
        else if (resultado == 0)
        {
            printf("La cadena no está balanceada. Se rompió el balanceo en la posición %d\n", posicion_error);
            
            rewind(cadena);
            
            char contenido[1024] = {0};
            size_t bytes_leidos = fread(contenido, 1, sizeof(contenido) - 1, cadena);
            if (bytes_leidos > 0)
            {
                contenido[bytes_leidos] = '\0';
                printf("%s\n", contenido);
                
                for (int i = 0; i < posicion_error; i++)
                {
                    printf(" ");
                }
                printf("^\n");
            }
        }
        else if (resultado == 2)
        {
            printf("No hay nada que pueda estar o no estar balanceado\n");
        }
        else
        {
            printf("Error al verificar el balanceo\n");
        }
        
        fclose(cadena);
    }
    else
    {
        printf("No se pudo leer el archivo\n");
    }
    
    return 0;
}