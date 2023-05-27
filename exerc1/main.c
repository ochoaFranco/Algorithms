#include <stdlib.h>
#include <stdio.h>
#include "../pilas/p_arreglos.c"
#include "../utilidades/p_utilidades.c"
#include "../pilas/arbol_binario.c"

void preOrderTraversing(ArbolBinario T);
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
    preOrderTraversing(T);
}


void preOrderTraversing(ArbolBinario T) {
    TipoElemento root, temp;
    NodoArbol node, leftChild, rightChild;
    bool isNull;
    Pila st;  
    st = p_crear();
    // Push to the stack the root.
    root = te_crear_con_valor(0, a_raiz(T));
    p_apilar(st, root);
    
    // traverse in pre-order.
    while (!p_es_vacia(st)) {
        temp = p_desapilar(st);
        node = (NodoArbol)temp->valor;
        if (!a_es_rama_nula(node)) {
            printf("%d ", n_recuperar(node)->clave);
        
            leftChild = n_hijoizquierdo(node);
            rightChild = n_hijoderecho(node);
            
            if (!a_es_rama_nula(rightChild))
                p_apilar(st, te_crear_con_valor(0, rightChild));
            
            else if (a_es_rama_nula(leftChild))
                printf(".");

            if (!a_es_rama_nula(leftChild))
                p_apilar(st, te_crear_con_valor(0, leftChild));
            else
                printf(".");
        }
        else 
            printf(".");
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