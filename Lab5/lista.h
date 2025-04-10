//
// Created by lupse on 4/1/2025.
//

#ifndef LISTA_H
#define LISTA_H
typedef struct {
    void** elems;
    int numar;
    int capacitate;
    void (*destroy_elem)(void*); // Functie ce dealocheaza memoria unui element din repo - void(void*)
    void* (*copie_elem)(void*); // Functie ce returneaza un pointer catre o copie a unui element
}lista;

/// Creeaza o lista
/// @param destroy_elem : functie ce distruge un element din lista
/// @return : pointer catre lista creata
lista* lista_creeaza(void (*destroy_elem)(void*), void* (*copie_elem)(void*));

/// Distruge o lista
/// @param l : lista ce se distruge(se dealoca memoria)
void lista_destroy(lista* l);

/// Aloca memorie suplimentara pentru lista(o dubleaza)
/// @param list : pointer catre lista
void lista_aloca_memorie(lista *list);

/// Dealoca memorie dintr-o lista(o injumatateste)
/// @param list : pointer catre lista
void lista_dealoca_memorie(lista *list);

/// Adauga un element in capatul listei
/// @param list : pointer catre o lista
/// @param elem : pointer catre un element
void lista_push_back(lista* list, void* elem);

/// Returneaza o copie a ultimului element din lista
/// @param list : pointer catre o lista
/// @return : pointer catre o copie a ultimului element din lista
void* lista_top(lista* list);

/// Sterge ultimul element din lista
/// @param list : pointer catre o lista
/// @return :
///     - 1 daca lista e goala
///     - 0 daca s-a sters elementul cu succes
int lista_pop(lista* list);

/// Verifica daca lista e goala
/// @param list : pointer catre o lista
/// @return :
///     - 1 daca lista e goala
///     - 0 daca lista nu e goala
int lista_empty(const lista* list);
#endif //LISTA_H
