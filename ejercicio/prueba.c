/*
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 */
 
#include "ejercicio.h"
#include <stdio.h>

void prueba_archivo(const char* nombre_archivo)
{
    int posicion_error = 0;

    FILE *archivo = fopen(nombre_archivo, "r");
    if (archivo != NULL)
    {
        printf("Probando archivo: %s\n", nombre_archivo);

        int resultado = verificador_balanceado(archivo, &posicion_error);

        if (resultado == 1)
        {
            printf("La cadena está balanceada\n");
        }
        else if (resultado == 0)
        {
            printf("La cadena no está balanceada. Se rompió en la posición %d\n", posicion_error);

            rewind(archivo);
            char contenido[1024] = {0};
            size_t bytes_leidos = fread(contenido, 1, sizeof(contenido) - 1, archivo);
            if (bytes_leidos > 0)
            {
                contenido[bytes_leidos] = '\0';
                printf("%s\n", contenido);
                for (int i = 0; i < posicion_error; i++) printf(" ");
                printf("^\n");
            }
        }
        else if (resultado == 2)
        {
            printf("No hay caracteres que puedan o no estar balanceados\n");
        }
        else
        {
            printf("Error al verificar el archivo\n");
        }

        fclose(archivo);
        printf("--------------------------------------------------\n\n");
    }
    else
    {
        printf("Error: No se pudo abrir el archivo '%s'\n", nombre_archivo);
    }
}

int main()
{
    prueba_archivo("prueba1.txt");
    prueba_archivo("prueba2.txt");
    prueba_archivo("prueba3.txt");

    return 0;
}
