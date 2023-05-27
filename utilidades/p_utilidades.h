#ifndef P_UTILIDADES
#define P_UTILIDADES
#include "../headers/pilas.h"
/**
 * intercambia los valores de la pAux con los de la pila.
 *
 * @param pila - una instancia de tipo Pila.
 * @param pAux - una instacia de tipo Pila.
 */
void intercambiar(Pila pila, Pila pAux);


/**
 * Carga aleatoriamente una pila en el campo clave.
 *
 * @param pila - una instancia de tipo Pila.
 * @param rango - valor max de numeros aleatorios.
 * @param cantidad - cantidad max de elementos a cargar.
 */
void cargarAleatorio(Pila pila, int rango, int cantidad);



/**
 * Cuenta la cantidad de elementos de una pila.
 *
 * @param pila - una instancia de tipo Pila.
 * @return int
 */
int contarElementos(Pila pila);

#endif