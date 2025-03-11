//
// Created by lupse on 3/11/2025.
//
#include "lista.h"
#include <stdlib.h>
#include <string.h>

/// @param v Vectorul care va fi initializat.
/// @param capacity Capacitatea initiala a vectorului.
///
/// Functia aloca memorie pentru vectorul de medicamente si seteaza dimensiunea si capacitatea acestuia.
void initVector(VectorDynamic* v, int capacity) {
    v->medicamente = (Medicament*)malloc(capacity * sizeof(Medicament));
    v->size = 0;
    v->capacity = capacity;
}

/// @param v Vectorul ce va fi redimensionat.
///
/// Functia dubleaza capacitatea vectorului si realoca memoria necesara pentru a tine mai multe elemente.
void resizeVector(VectorDynamic* v) {
    v->capacity *= 2;
    v->medicamente = (Medicament*)realloc(v->medicamente, v->capacity * sizeof(Medicament));
}

/// @param v Vectorul in care va fi adaugat medicamentul.
/// @param cod Codul unic al medicamentului.
/// @param nume Numele medicamentului.
/// @param concentratie Concentratia medicamentului.
/// @param cantitate Cantitatea de medicament care va fi adaugata.
///
/// Functia adauga un medicament in vector, verificand daca exista deja un medicament cu acelasi cod si actualizand cantitatea in caz afirmativ.
void adaugaMedicament(VectorDynamic* v, int cod, char* nume, float concentratie, int cantitate) {
    for (int i = 0; i < v->size; i++) {
        if (v->medicamente[i].cod == cod) {
            v->medicamente[i].cantitate += cantitate;
            return;
        }
    }
    if (v->size == v->capacity) {
        resizeVector(v);
    }
    v->medicamente[v->size].cod = cod;
    strcpy(v->medicamente[v->size].nume, nume);
    v->medicamente[v->size].concentratie = concentratie;
    v->medicamente[v->size].cantitate = cantitate;
    v->size++;
}

/// @param v Vectorul ce contine medicamentele.
/// @param cod Codul unic al medicamentului ce va fi actualizat.
/// @param numeNou Noul nume pentru medicament.
/// @param concentratieNoua Noua concentratie pentru medicament.
///
/// Functia cauta medicamentul in vector si actualizeaza detaliile acestuia daca este gasit.
void actualizeazaMedicament(VectorDynamic* v, int cod, char* numeNou, float concentratieNoua) {
    int found = 0;
    for (int i = 0; i < v->size; i++) {
        if (v->medicamente[i].cod == cod) {
            strcpy(v->medicamente[i].nume, numeNou);
            v->medicamente[i].concentratie = concentratieNoua;
            found = 1;
            break;
        }
    }
    if (!found) {
        perror("Medicamentul cu acest cod nu a fost gasit pentru actualizare");
    }
}

/// @param v Vectorul din care va fi sters medicamentul.
/// @param cod Codul unic al medicamentului ce va fi sters.
///
/// Functia cauta medicamentul dupa cod si il sterge din vector. Daca nu este gasit, se va afisa un mesaj de eroare.
void stergeMedicament(VectorDynamic* v, int cod) {
    int found = 0;
    for (int i = 0; i < v->size; i++) {
        if (v->medicamente[i].cod == cod) {
            for (int j = i; j < v->size - 1; j++) {
                v->medicamente[j] = v->medicamente[j + 1];
            }
            v->size--;
            found = 1;
            break;
        }
    }
    if (!found) {
        perror("Medicamentul cu acest cod nu a fost gasit pentru stergere");
    }
}

/// @param v Vectorul care contine medicamentele.
/// @param index Indexul elementului dorit.
/// @return Medicamentul aflat la pozitia index din vector.
///
/// Functia returneaza medicamentul de la pozitia specificata in vector.
Medicament getElement(VectorDynamic* v, int index) {
    return v->medicamente[index];
}

/// @param v Vectorul in care se va seta elementul.
/// @param index Indexul la care se va seta elementul.
/// @param m Medicamentul care va fi setat la index-ul respectiv.
///
/// Functia inlocuieste medicamentul de la pozitia specificata cu medicamentul dat ca argument.
void setElement(VectorDynamic* v, int index, Medicament m) {
    v->medicamente[index] = m;
}

/// @param v Vectorul al carui numar de elemente se doreste a fi obtinut.
/// @return Dimensiunea vectorului.
///
/// Functia returneaza numarul de medicamente din vector.
int size(VectorDynamic* v) {
    return v->size;
}

/// @param v Vectorul ce trebuie eliberat.
///
/// Functia elibereaza memoria alocata pentru vectorul de medicamente si reseteaza dimensiunea si capacitatea acestuia.
void freeVector(VectorDynamic* v) {
    free(v->medicamente);
    v->medicamente = NULL;
    v->size = 0;
    v->capacity = 0;
}
