#include <stdlib.h>
#include <stdio.h>
#include "../pilas/arbol_binario.c"
#include "../tipo_elemento_F/tipo_elemento.c"

void preOrder(NodoArbol);

int moreThanTwoChildren(ArbolBinario);

int main () {
    // Hardcoding a tree.
    ArbolBinario tree = a_crear();
    TipoElemento element = te_crear(1);
    a_establecer_raiz(tree, element);
    element = te_crear(2);
    NodoArbol nodoB2 = a_conectar_hi(tree, a_raiz(tree), element);
    element = te_crear(3);
    NodoArbol nodoC2 = a_conectar_hd(tree, nodoB2, element);
    element = te_crear(4);
    NodoArbol nodoD2 = a_conectar_hd(tree, nodoC2, element);
    element = te_crear(5);
    NodoArbol nodoE2 = a_conectar_hd(tree, nodoD2, element);
    element = te_crear(6);
    NodoArbol nodoF2 = a_conectar_hd(tree, nodoE2, element);
    element = te_crear(7);
    NodoArbol nodoG2 = a_conectar_hd(tree, nodoF2, element);
    element = te_crear(8);
    NodoArbol nodoH2 = a_conectar_hi(tree, nodoB2, element);
    element = te_crear(9);
    NodoArbol nodoI2 = a_conectar_hd(tree, nodoH2, element);
    element = te_crear(10);
    NodoArbol nodoJ2 = a_conectar_hd(tree, nodoI2, element);
    element = te_crear(14);
    NodoArbol nodoN2 = a_conectar_hi(tree, nodoH2, element);
    element = te_crear(15);
    NodoArbol nodoO2 = a_conectar_hd(tree, nodoN2, element);
    element = te_crear(11);
    NodoArbol nodoK2 = a_conectar_hi(tree, nodoE2, element);
    element = te_crear(12);
    NodoArbol nodoL2 = a_conectar_hd(tree, nodoK2, element);
    element = te_crear(16);
    NodoArbol nodoP2 = a_conectar_hi(tree, nodoK2, element);
    element = te_crear(17);
    NodoArbol nodoQ2 = a_conectar_hi(tree, nodoL2, element);
    element = te_crear(13);
    NodoArbol nodoM2 = a_conectar_hi(tree, nodoG2, element);

    preOrder(a_raiz(tree));

    printf("\nAmount of nodes that have at least two children: %d\n", moreThanTwoChildren(tree));
    return 0;
}

void preOrder(NodoArbol current) {
    TipoElemento node;
    if (a_es_rama_nula(current))
        printf(".");
    else {
        node = n_recuperar(current);
        printf("%d ", node->clave);
        preOrder(n_hijoizquierdo(current));
        preOrder(n_hijoderecho(current));
    }
}


//TODO Create a recursive algorithm that counts all the nodes that have more than one children in a non-binary tree.

void amountChildrenAux(NodoArbol current, int *children) {
    NodoArbol leftChild, rightChild;
    if (!a_es_rama_nula(current)) {
        leftChild = n_hijoizquierdo(current);
        rightChild = n_hijoderecho(leftChild);
        if (!a_es_rama_nula(leftChild) && !a_es_rama_nula(rightChild))
            *children += 1;

        // traverse in pre-order.
        amountChildrenAux(n_hijoizquierdo(current), children);
        amountChildrenAux(n_hijoderecho(current), children);
    }
}


int moreThanTwoChildren(ArbolBinario T) {
    int children;
    NodoArbol root;

    children = 0;
    if (a_es_vacio(T)) {
        printf("The tree is empty.");
        return children;
    }
    root = a_raiz(T);
    amountChildrenAux(root, &children);

    return children;
}