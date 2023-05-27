#include <stdio.h>
#include <stdlib.h>
#include "../utilidades/p_utilidades.h"
#include <time.h>


#define TAMANIO_MAXIMO_P 1000

void intercambiar(Pila pila, Pila pAux){
    TipoElemento elemento = te_crear(0);
    while (!p_es_vacia(pAux)){
        elemento = p_desapilar(pAux);
        p_apilar(pila, elemento);
    }
}



int contarElementos(Pila pila){
    int cantidad = 0;
    Pila pAux = p_crear();
    TipoElemento valor = te_crear(0);
    // Cuento elementos.
    while (!p_es_vacia(pila)){
        valor = p_desapilar(pila);
        p_apilar(pAux, valor);
        cantidad++;
    }
    // Recupero la pila.
    intercambiar(pila, pAux);
    free(pAux);
    return cantidad;
}

void cargarAleatorio(Pila pila, int rango, int cantidad){
    if (cantidad > TAMANIO_MAXIMO_P)
        exit(1);

    srand(time(NULL));
    int i = 0;
    TipoElemento valor;
    while (i < cantidad){
        int numeroRandom = (rand() % rango) + 1;
        valor = te_crear(numeroRandom);
        p_apilar(pila, valor);
        i++;
    }
}
