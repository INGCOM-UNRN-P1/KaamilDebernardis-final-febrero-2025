/*
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 */
 
#include "ejercicio.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int verificador_balanceado(char *cadena, int *posicion_error)
{
    bool verificador_existencia = false;
    bool desbalanceado = false;
    int verificador_parentesis = 0;
    int verificador_llaves = 0;
    int verificador_corchetes = 0;
    int verificador_definitivo = -1;
    int posicion = 0;
    
    if (*cadena != '\0')
    {
        verificador_definitivo = 0;
        
        while (*cadena)
        {
            if (desbalanceado == false)
            {
                if (*cadena == '(')
                {
                    verificador_parentesis = verificador_parentesis + 1;
                    verificador_existencia = true;
                }
                else if (*cadena == ')')
                {
                    if (verificador_parentesis > 0)
                    {
                        verificador_parentesis = verificador_parentesis - 1;
                    }
                    else
                    {
                        desbalanceado = true;
                        *posicion_error = posicion;
                    }
                    verificador_existencia = true;
                }
                else if (*cadena == '{')
                {
                    verificador_llaves = verificador_llaves + 1;
                    verificador_existencia = true;
                }
                else if (*cadena == '}')
                {
                    if (verificador_llaves > 0)
                    {
                        verificador_llaves = verificador_llaves - 1;
                    }
                    else
                    {
                        desbalanceado = true;
                        *posicion_error = posicion;
                    }
                    verificador_existencia = true;
                }
                else if (*cadena == '[')
                {
                    verificador_corchetes = verificador_corchetes + 1;
                    verificador_existencia = true;
                }
                else if (*cadena == ']')
                {
                    if (verificador_corchetes > 0)
                    {
                        verificador_corchetes = verificador_corchetes - 1;
                    }
                    else
                    {
                        desbalanceado = true;
                        *posicion_error = posicion;
                    }
                    verificador_existencia = true;
                }
            }
            cadena++;
            posicion++;
        }
        
        if (verificador_existencia == false)
        {
            verificador_definitivo = 2;
        }
        else if (verificador_parentesis == 0 && verificador_llaves == 0 &&
            verificador_corchetes == 0 && desbalanceado == false)
        {
            verificador_definitivo = 1;
        }
        else if (!desbalanceado && (verificador_parentesis > 0 || verificador_llaves > 0 || verificador_corchetes > 0))
        {
            *posicion_error = posicion - 1;
        }
    }
    
    return verificador_definitivo;
}