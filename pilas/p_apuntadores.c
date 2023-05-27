#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../headers/pilas.h"
#define TAMANIO_MAXIMO 1000

struct Nodo{
    TipoElemento datos; // concepto del nodo.
    struct Nodo *siguiente;
};

struct PilaRep{
    struct Nodo *tope;
};

// Inicializa la pila para dejarla en condiciones de ser utilizada. 
Pila p_crear(){
    Pila nuevaPila = (Pila)malloc(sizeof(struct PilaRep));
    nuevaPila->tope = NULL;
    return nuevaPila;
}

// Determina si la pila esta vacia. Retorna true cuando esto sucede, caso contrario retorna false.
bool p_es_vacia(Pila pila){
    return pila->tope == NULL;
}

int longitud(Pila pila){
    int i = 0;
    struct Nodo *n = pila->tope;
    while (n != NULL){
        i++;
        n = n->siguiente;
    }
    return i;
}

// Determina si la pila esta llena. Retorna true cuando esto sucede, caso contrario retorna false.
bool p_es_llena(Pila pila){
    return (longitud(pila) == TAMANIO_MAXIMO);
}

// Extrae el 'tipoelemento' del tope de la pila. En caso de error retorna un 'tipoelemento' vacio.
TipoElemento p_tope(Pila pila){
    struct Nodo *topeActual = pila->tope;
    return topeActual->datos;
}

// apila un elemento en el tope de la pila. Recibe como parametro el elemento a apilar. Controla que no este llena.
void p_apilar(Pila pila, TipoElemento elemento){
    if (p_es_llena(pila)) exit(1);
    struct Nodo *nuevoNodo = malloc(sizeof(struct Nodo));
    nuevoNodo->datos = elemento;
    nuevoNodo->siguiente = pila->tope;
    pila->tope = nuevoNodo;
}

// Retorna el elemento y elimina el tope de la pila. Controla que no este vacia.
TipoElemento p_desapilar(Pila pila){
    if (p_es_vacia(pila)) return NULL;
    struct Nodo *topeActual = pila->tope;
    TipoElemento elemento = topeActual->datos;
    pila->tope = topeActual->siguiente;
    free(topeActual);
    return elemento;
}

// Muestra por pantalla los elementos de la pila recibida como parámetro.
void p_mostrar(Pila pila){
    if (p_es_vacia(pila)){
        printf("La pila esta vacia!");
        return;
    }
    Pila Paux = p_crear();
    TipoElemento elemento = te_crear(0);

    printf("Contenido de la pila: ");
    // Muestro los valores de la pila original.
    while (!p_es_vacia(pila)){
        elemento = p_desapilar(pila);
        printf("%d", elemento->clave);
        p_apilar(Paux, elemento);
    }

    while (!p_es_vacia(Paux)){
        elemento = p_desapilar(Paux);
        p_apilar(pila, elemento);
    }
    printf("\n");
}