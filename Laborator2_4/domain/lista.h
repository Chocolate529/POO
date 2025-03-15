//
// Created by lupse on 3/11/2025.
//

#ifndef LISTA_H
#define LISTA_H

#include "medicament.h"

typedef Medicament TElement;
typedef struct {
    TElement* element;
    int size;
    int capacity;
} VectorDynamic;

/// Inițializează un vector dinamic cu o capacitate dată.
/// @param v Pointer către structura VectorDynamic.
/// @param capacity Capacitatea inițială a vectorului.
void initVector(VectorDynamic* v, int capacity);

/// Redimensionează vectorul dinamic atunci când acesta își atinge capacitatea.
/// Se dublează capacitatea alocată.
/// @param v Pointer către structura VectorDynamic.
void resizeVector(VectorDynamic* v);


/// Adaugă un element în vectorul dinamic. Dacă este necesar, redimensionează vectorul.
/// @param v Pointer către structura VectorDynamic.
/// @param element Elementul de adăugat.
void adaugaTElement(VectorDynamic* v, TElement element);

/// Șterge un element din vectorul dinamic la o poziție specificată, mutând elementele rămase.
/// @param v Pointer către structura VectorDynamic.
/// @param index Indexul elementului care trebuie șters.
void stergeTElement(VectorDynamic* v, int index);

/// Returnează un pointer la elementul aflat la o anumită poziție în vector.
/// @param v Pointer către structura VectorDynamic.
/// @param index Indexul elementului dorit.
/// @return Pointer către elementul aflat la poziția index.
TElement* getElement(VectorDynamic* v, int index);

/// Setează valoarea unui element la o poziție dată în vector.
/// @param v Pointer către structura VectorDynamic.
/// @param index Indexul elementului care trebuie modificat.
/// @param m Noua valoare a elementului.
void setElement(VectorDynamic* v, int index, TElement m);

/// Returnează dimensiunea curentă a vectorului.
/// @param v Pointer către structura VectorDynamic.
/// @return Numărul de elemente din vector.
int size(VectorDynamic* v);

/// Returnează capacitatea curentă a vectorului.
/// @param v Pointer către structura VectorDynamic.
/// @return Capacitatea vectorului.
int capacity(VectorDynamic* v);

// /// Copiază conținutul unui vector într-un alt vector.
// /// @param v Pointer către vectorul sursă.
// /// @param v2 Pointer către vectorul destinație.
// void copyVector(VectorDynamic* v, VectorDynamic* v2);

/// Eliberează memoria ocupată de vectorul dinamic și resetează valorile sale.
/// @param v Pointer către structura VectorDynamic.
void freeVector(VectorDynamic* v);

/// Eliberează memoria unui element de tip TElement.
/// @param element Pointer către elementul care trebuie eliberat.
void freeTElement(TElement** element);
#endif //LISTA_H
