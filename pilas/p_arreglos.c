#include <stdio.h>
#include <stdlib.h>
#include "../headers/pilas.h"

#define TAMANIO_MAXIMO 1000

struct PilaRep{
    TipoElemento *valores; // Arreglo tipo elemento.
    unsigned int tope;
};

// Inicializa la pila para dejarla en condiciones de ser utilizada. 
Pila p_crear(){
    Pila nuevaPila = (Pila)malloc(sizeof(struct PilaRep));
    nuevaPila->valores = calloc(TAMANIO_MAXIMO + 1, sizeof(TipoElemento));
    nuevaPila->tope = 0;
    return nuevaPila;
}

// Determina si la pila esta vacia. Retorna true cuando esto sucede, caso contrario retorna false.
bool p_es_vacia(Pila pila){
    return pila->tope == 0;
}

// Determina si la pila esta llena. Retorna true cuando esto sucede, caso contrario retorna false.
bool p_es_llena(Pila pila){
    return pila->tope == TAMANIO_MAXIMO;
}

// Extrae el 'tipoelemento' del tope de la pila. En caso de error retorna un 'tipoelemento' vacio.
TipoElemento p_tope(Pila pila){
    if (p_es_vacia(pila)) return NULL;
    return pila->valores[pila->tope];
}

// apila un elemento en el tope de la pila. Recibe como parametro el elemento a apilar. Controla que no este llena.
void p_apilar(Pila pila, TipoElemento elemento){
    // Controlo si esta llena.
    if (p_es_llena(pila)){
        printf("La pila esta llena!");
        exit(1);
    }
    pila->tope++;
    pila->valores[pila->tope] = elemento;
}

// Retorna el elemento y elimina el tope de la pila. Controla que no este vacia.
TipoElemento p_desapilar(Pila pila){
    if (p_es_vacia(pila)){
        printf("La pila esta vacia!");
        exit(1);
    }
    TipoElemento elemActual = pila->valores[pila->tope];
    pila->tope--; // Decremento el tope.
    return elemActual;
}

// Muestra en pantalla el contenido de la Pila.
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
        printf("%d ", elemento->clave);
        p_apilar(Paux, elemento);
    }

    while (!p_es_vacia(Paux)){
        elemento = p_desapilar(Paux);
        p_apilar(pila, elemento);
    }
    printf("\n");
}