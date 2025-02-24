/*
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 */

#ifndef EJERCICIO_H
#define EJERCICIO_H

/**
 * Verifica si una cadena de caracteres tiene los paréntesis, llaves y corchetes balanceados.
 * @param cadena es la cadena de caracteres a verificar.
 * @param posicion_error es el puntero donde se almacena la posición del primer error de desbalanceo.
 * @returns 1 si los paréntesis, llaves y corchetes están balanceados.
 *          0 si hay un desbalanceo en alguno de los símbolos.
 *          2 si no hay ningún símbolo para balancear.
 * Precondiciones: `cadena` es una cadena de caracteres que no puede ser nula y tiene que terminar en \0.
 * Postcondiciones: Si la cadena no está balanceada, posicion_error dice la posición del primer "error".
 */
int verificador_balanceado(char *cadena, int *posicion_error);

#endif