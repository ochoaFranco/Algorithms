#include <stdlib.h>
#include <string.h>
#include "../headers/arbol-binario.h"
#include "../nodo_F/nodo.h"
#include "../nodo_F/nodo.c"

static const int TAMANIO_MAXIMO_A = 100;

struct ArbolBinarioRep {
    NodoArbol raiz;
    int cantidadElementos;
};

ArbolBinario a_crear() {
    ArbolBinario nuevoArbol = (ArbolBinario)malloc(sizeof(struct ArbolBinarioRep));
    nuevoArbol->raiz = NULL;
    nuevoArbol->cantidadElementos = 0;
    return nuevoArbol;
}

bool a_es_vacio(ArbolBinario a) {
    return a->raiz == NULL;
}

bool a_es_lleno(ArbolBinario a) {
    return (a->cantidadElementos == TAMANIO_MAXIMO_A);
}

int a_cantidad_elementos(ArbolBinario a) {
    return a->cantidadElementos;
}

bool a_es_rama_nula(NodoArbol pa) {
    return pa == NULL;
}

NodoArbol a_raiz(ArbolBinario a) {
    return a->raiz;
}

NodoArbol a_establecer_raiz(ArbolBinario a, TipoElemento te) {
    // Controlo si ya tiene una raiz.
    if (a->raiz != NULL)
        return a->raiz;

    NodoArbol na = n_crear(te);
    a->raiz = na;
    a->cantidadElementos++;
    return na;
}

NodoArbol a_conectar_hi(ArbolBinario a, NodoArbol pa, TipoElemento te) {
    // Controlo que el nodo no sea nulo.
    if (pa == NULL)
        return NULL;

    // Controlo si ya posee un hijo izq.
    if (pa->hi != NULL)
        return pa->hi;

    NodoArbol na = n_crear(te);
    a->cantidadElementos++;
    pa->hi = na;

    return na;
}


NodoArbol a_conectar_hd(ArbolBinario a, NodoArbol pa, TipoElemento te) {
    // Controlo que el nodo no sea nulo.
    if (pa == NULL)
        return NULL;

    // Controlo si ya posee un hijo derecho.
    if (pa->hd != NULL)
        return pa->hd;

    NodoArbol na = n_crear(te);
    a->cantidadElementos++;
    pa->hd = na;

    return na;
}

