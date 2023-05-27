#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodo.h"

NodoArbol n_hijoizquierdo(NodoArbol N) {
    // Controlo si el nodo es vacio.
    if (N == NULL)
        return NULL;
    // Asigno el hijo izq.
    else
        return N->hi;
}

NodoArbol n_hijoderecho(NodoArbol N) {
    // Controlo si el nodo es vacio.
    if (N == NULL)
        return NULL;
    // Asigno el hijo derecho.
    else
        return N->hd;
}

NodoArbol n_crear(TipoElemento te) {
    NodoArbol na = (NodoArbol)malloc(sizeof(struct NodoArbolRep));
    na->datos = te;
    na->hi = NULL;
    na->hd = NULL;
    na->FE = 0;
    return na;
}

// Retorna el tipo elemento de un nodo o NULL si no existe.
TipoElemento n_recuperar(NodoArbol N) {
    TipoElemento x = te_crear(0);
    if (N == NULL)
        return NULL;
    else {
        x = N->datos;
        return x;
    }
}