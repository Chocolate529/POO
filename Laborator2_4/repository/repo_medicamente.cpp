#include "repo_medicamente.h"
#include "../domain/lista.h"
#include "../domain/medicament.h"
//
// Created by lupse on 3/13/2025.
//

int adaugaMedicament(VectorDynamic* v, Medicament el) {
    for (int i = 0; i < size(v); i++) {
        if (getCod(*getElement(v,i)) == getCod(el)) {
            int cantitate = getCantitate(*getElement(v,i));
            setCantitate(getElement(v,i), cantitate + getCantitate(el));
            return 0;
        }
    }
    adaugaTElement(v, el);
    return 1;
}

int actualizareMedicament(VectorDynamic *v, int codElementVechi, char* numeNou, float concentratieNoua) {
    for (int i = 0; i < size(v); i++) {
        if (getCod(*getElement(v,i)) == codElementVechi) {
            setNume(getElement(v,i), numeNou);
            setConcentratie(getElement(v,i), concentratieNoua);
            return 1;
        }
    }
    return 0;
}

int stergeMedicament(VectorDynamic* v, int cod) {
    for (int i = 0; i < size(v); i++) {
        if (getCod(*getElement(v,i)) == cod) {
            stergeTElement(v, i);
            return 1;
        }
    }
    return 0;
}

VectorDynamic copyListaMedicamente(VectorDynamic* v) {
    VectorDynamic v2;
    initVector(&v2, capacity(v));
    for (int i = 0; i < size(v); i++) {
        Medicament m1 = *getElement(v, i);
        Medicament copy = copyMedicament(m1);

        adaugaTElement(&v2, copy);
    }
    return v2;
}