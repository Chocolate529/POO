//
// Created by lupse on 4/1/2025.
//

#include "lista.h"

#include <stdio.h>
#include <stdlib.h>
#define ALPHA 0.7
#define BETA 0.3

/// Creeaza o lista
/// @param destroy_elem : functie ce distruge un element din lista
/// @return : pointer catre lista creata
lista* lista_creeaza(void (*destroy_elem)(void*), void* (*copie_elem)(void*)) {
    lista* l = (lista*)malloc(sizeof(lista));
    if (l == NULL) {
        printf("Allocation error!\n");
        return NULL;
    }
    l->elems = (void**)malloc(sizeof(void*));
    if (l->elems == NULL) {
        printf("Allocation error!\n");
        return NULL;
    }
    l->numar = 0;
    l->capacitate = 1;
    l->destroy_elem = destroy_elem;
    l->copie_elem = copie_elem;
    return l;
}

/// Distruge o lista
/// @param l : lista ce se distruge(se dealoca memoria)
void lista_destroy(lista* l) {
    for (int i = 0; i < l->numar; i++) {
        l->destroy_elem(l->elems[i]);
        l->elems[i] = NULL;
    }
    free(l->elems);
    l->elems=NULL;
    free(l);
    l=NULL;
}

/// Aloca memorie suplimentara pentru lista(o dubleaza)
/// @param list : pointer catre lista
void lista_aloca_memorie(lista *list) {
    void** temp = malloc(list->capacitate*2*sizeof(void*));
    if (temp==NULL) {
        printf("Allocation Error!\n");
        return;
    }
    for (int i = 0; i < list->numar; i++) {
        temp[i] = list->elems[i];
    }
    free(list->elems);
    list->elems = temp;
    list->capacitate *= 2;
}

/// Dealoca memorie dintr-o lista(o injumatateste)
/// @param list : pointer catre lista
void lista_dealoca_memorie(lista *list) {
    void** temp = malloc(list->capacitate*sizeof(void*));
    if (temp==NULL) {
        printf("Allocation Error!\n");
        return;
    }
    for (int i = 0; i < list->numar; i++) {
        temp[i] = list->elems[i];
    }
    free(list->elems);
    list->elems = temp;
    list->capacitate /= 2;
}

/// Adauga un element in capatul listei
/// @param list : pointer catre o lista
/// @param elem : pointer catre un element
void lista_push_back(lista* list, void* elem) {
    if (list->numar >= ALPHA * list->capacitate)
        lista_aloca_memorie(list);
    list->elems[list->numar] = list->copie_elem(elem);
    list->numar++;
}

/// Returneaza o copie a ultimului element din lista
/// @param list : pointer catre o lista
/// @return : pointer catre o copie a ultimului element din lista
void* lista_top(lista* list) {
    if (list->numar == 0)
        return NULL;
    return list->copie_elem(list->elems[list->numar-1]);
}

/// Sterge ultimul element din lista
/// @param list : pointer catre o lista
/// @return :
///     - 1 daca lista e goala
///     - 0 daca s-a sters elementul cu succes
int lista_pop(lista* list) {
    if (list->numar == 0)
        return 1;
    list->destroy_elem(list->elems[list->numar-1]);
    list->elems[list->numar-1] = NULL;
    list->numar--;
    if (list->numar <= BETA * list->capacitate && list->capacitate > 5)
        lista_dealoca_memorie(list);
    return 0;
}

/// Verifica daca lista e goala
/// @param list : pointer catre o lista
/// @return :
///     - 1 daca lista e goala
///     - 0 daca lista nu e goala
int lista_empty(const lista* list) {
    if (list->numar == 0)
        return 1;
    return 0;
}

