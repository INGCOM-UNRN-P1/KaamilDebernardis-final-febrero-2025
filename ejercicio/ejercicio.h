/*
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 */

#ifndef EJERCICIO_H
#define EJERCICIO_H

#include <stdio.h>

/**
 * Estructura para representar un nodo en la pila
 */
typedef struct Nodo
{
    char simbolo;
    int posicion;
    struct Nodo *siguiente;
} Nodo;

/**
 * Estructura para representar la pila
 */
typedef struct
{
    Nodo *tope;
    int tamano;
} Pila;

/**
 * Crea una nueva pila vacía
 * 
 * @return Puntero a la nueva pila
 */
Pila* crear_pila();

/**
 * Libera la memoria utilizada por la pila
 * 
 * @param pila Pila a liberar
 */
void liberar_pila(Pila *pila);

/**
 * Añade un símbolo a la pila
 * 
 * @param pila Pila donde añadir
 * @param simbolo Símbolo a añadir
 * @param posicion Posición del símbolo en el archivo
 * @return 1 si se añadió correctamente, 0 en caso de error
 */
int apilar(Pila *pila, char simbolo, int posicion);

/**
 * Elimina el símbolo del tope de la pila
 * 
 * @param pila Pila de donde eliminar
 * @return 1 si se eliminó correctamente, 0 si la pila está vacía
 */
int desapilar(Pila *pila);

/**
 * Obtiene el símbolo del tope de la pila sin eliminarlo
 * 
 * @param pila Pila a consultar
 * @return El símbolo del tope, o '\0' si la pila está vacía
 */
char tope(Pila *pila);

/**
 * Obtiene la posición del símbolo en el tope de la pila
 * 
 * @param pila Pila a consultar
 * @return La posición del símbolo del tope, o -1 si la pila está vacía
 */
int tope_posicion(Pila *pila);

/**
 * Verifica si la pila está vacía
 * 
 * @param pila Pila a verificar
 * @return 1 si está vacía, 0 si no
 */
int esta_vacia(Pila *pila);

/**
 * Verifica si los símbolos de agrupación ( ), { }, [ ] están balanceados en un archivo
 * 
 * @param archivo Archivo a verificar
 * @param posicion_error Si hay error, guarda la posición donde se encontró
 * @return 0 si no está balanceado, 1 si está balanceado, 2 si no hay símbolos
 */
int verificador_balanceado(FILE *archivo, int *posicion_error);

#endif