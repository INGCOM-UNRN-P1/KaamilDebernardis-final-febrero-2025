/*
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 */
 
#include "ejercicio.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

Pila* crear_pila()
{
    Pila *nueva_pila = (Pila*) malloc(sizeof(Pila));
    Pila *retorno = NULL;
    
    if (nueva_pila != NULL)
    {
        nueva_pila->tope = NULL;
        nueva_pila->tamano = 0;
        retorno = nueva_pila;
    }

    return retorno;
}

void liberar_pila(Pila *pila)
{
    while (!esta_vacia(pila))
    {
        desapilar(pila);
    }
    
    free(pila);
}

int apilar(Pila *pila, char simbolo, int posicion)
{
    int resultado = 0;
    
    if (pila != NULL)
    {
        Nodo *nuevo_nodo = (Nodo*) malloc(sizeof(Nodo));
        if (nuevo_nodo != NULL)
        {
            nuevo_nodo->simbolo = simbolo;
            nuevo_nodo->posicion = posicion;
            nuevo_nodo->siguiente = pila->tope;
            pila->tope = nuevo_nodo;
            pila->tamano++;
            resultado = 1;
        }
    }
    
    return resultado;
}

int desapilar(Pila *pila)
{
    int resultado = 0;
    
    if (pila != NULL && !esta_vacia(pila))
    {
        Nodo *nodo_a_eliminar = pila->tope;
        pila->tope = pila->tope->siguiente;
        free(nodo_a_eliminar);
        pila->tamano--;
        resultado = 1;
    }
    
    return resultado;
}

char tope(Pila *pila)
{
    char resultado = '\0';
    
    if (pila != NULL && !esta_vacia(pila))
    {
        resultado = pila->tope->simbolo;
    }
    
    return resultado;
}

int tope_posicion(Pila *pila)
{
    int resultado = -1;
    
    if (pila != NULL && !esta_vacia(pila))
    {
        resultado = pila->tope->posicion;
    }
    
    return resultado;
}

int esta_vacia(Pila *pila)
{
    int resultado = 1;
    
    if (pila != NULL && pila->tope != NULL)
    {
        resultado = 0;
    }
    
    return resultado;
}

int verificador_balanceado(FILE *archivo, int *posicion_error)
{
    int resultado = -1;
    
    if (archivo != NULL && posicion_error != NULL)
    {
        Pila *pila = crear_pila();
        if (pila != NULL)
        {
            bool simbolos_encontrados = false;
            int posicion = 0;
            int caracter;
            bool error_encontrado = false;
            bool fin_archivo = false;
            
            while (!error_encontrado && !fin_archivo)
            {
                caracter = fgetc(archivo);
                
                if (caracter == EOF)
                {
                    fin_archivo = true;
                }
                else
                {
                    if (caracter == '(' || caracter == '{' || caracter == '[')
                    {
                        apilar(pila, caracter, posicion);
                        simbolos_encontrados = true;
                    }
                    else if (caracter == ')' || caracter == '}' || caracter == ']')
                    {
                        simbolos_encontrados = true;
                        
                        if (esta_vacia(pila))
                        {
                            *posicion_error = posicion;
                            resultado = 0;
                            error_encontrado = true;
                        }
                        else
                        {
                            char ultimo_simbolo = tope(pila);
                            bool coincide = false;
                            
                            if (caracter == ')' && ultimo_simbolo == '(')
                            {
                                coincide = true;
                            }
                            else if (caracter == '}' && ultimo_simbolo == '{')
                            {
                                coincide = true;
                            }
                            else if (caracter == ']' && ultimo_simbolo == '[')
                            {
                                coincide = true;
                            }
                            
                            if (coincide)
                            {
                                desapilar(pila);
                            }
                            else
                            {
                                *posicion_error = posicion;
                                resultado = 0;
                                error_encontrado = true;
                            }
                        }
                    }
                    
                    posicion++;
                }
            }
            
            if (!error_encontrado)
            {
                if (!simbolos_encontrados)
                {
                    resultado = 2;
                }
                else if (esta_vacia(pila))
                {
                    resultado = 1;
                }
                else
                {
                    *posicion_error = tope_posicion(pila);
                    resultado = 0;
                }
            }
            
            liberar_pila(pila);
        }
    }
    
    return resultado;
}