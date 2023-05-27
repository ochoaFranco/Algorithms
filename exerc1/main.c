#include <stdlib.h>
#include <stdio.h>
#include "../pilas/p_arreglos.c"
#include "../utilidades/p_utilidades.c"
#include "../pilas/arbol_binario.c"

void traverseLeftSubtree(NodoArbol current, Pila S);
void preOrderTraversing(NodoArbol, Pila);
void preOrderR(NodoArbol);
int main() {
    Pila S;
    ArbolBinario T;
    TipoElemento x;
    NodoArbol N, P;

    // Hardcoding a binary tree.
    T = a_crear();
    S = p_crear();

    // Setting root.
    x = te_crear(3);
    a_establecer_raiz(T, x);
    
    // Insert element to the right.
    x = te_crear(2);
    a_conectar_hd(T, a_raiz(T), x);
    
    // Insert element to the left.
    x = te_crear(7);
    N = a_conectar_hi(T, a_raiz(T), x);

    // Insert element to the left.
    x = te_crear(5);
    a_conectar_hi(T, N, x);

    // Insert element to the right.
    x = te_crear(9);
    P = a_conectar_hd(T, N, x);
    
    // insert element to the left.
    x = te_crear(10);
    a_conectar_hi(T, P, x);
    
    printf("Recursive:\n");
    preOrderR(a_raiz(T));
    
    printf("\n");
    printf("Iterative:\n");
    // Displaying tree in pre-order.
    preOrderTraversing(a_raiz(T), S);
}


void traverseLeftSubtree(NodoArbol current, Pila S) {
    TipoElemento rightChild;
    TipoElemento temp;
    do {
        // Check if it is a null branch.
        if (a_es_rama_nula(current))
            printf(".");
        else {
            temp = n_recuperar(current);
            printf("%d ", temp->clave);
        }
        // Update node's value.
        current = n_hijoizquierdo(current);
        // Push the right child.
        rightChild = n_recuperar(n_hijoderecho(current));
        p_apilar(S, te_crear_con_valor(0, n_hijoderecho(current))); 
    
    } while (!a_es_rama_nula(current));
}

void preOrderTraversing(NodoArbol current, Pila S) {
    TipoElemento temp;
    NodoArbol value;
    // Traverse left subtree.
    traverseLeftSubtree(current, S);
    // Traverse rigth subtree.
    while (!p_es_vacia(S)) {
        temp = p_desapilar(S);
        
        // Check if it's a null branch.
        value = ((NodoArbol)temp->valor);
        if (a_es_rama_nula(value))
            printf(".");
        else
            printf("%d ", n_recuperar(value)->clave);
        
        
        traverseLeftSubtree(n_hijoizquierdo(value), S);
    }
}


void preOrderR(NodoArbol current) {
    TipoElemento temp;
    if (a_es_rama_nula(current))
        printf(".");
    
    else {
        temp = n_recuperar(current);
        printf("%d ", temp->clave);
        // Traverse in pre-order.
        preOrderR(n_hijoizquierdo(current));
        preOrderR(n_hijoderecho(current));
    }
}