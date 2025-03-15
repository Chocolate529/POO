//
// Created by lupse on 3/11/2025.
//
#include "service_medicamente.h"
#include <string.h>
#include "../validator/validator_medicament.h"
#include "../domain/medicament.h"

int adaugaMedicamentService(VectorDynamic* v, int cod, char* nume, float concentratie, int cantitate) {
    if (valideazaMedicament(cod, nume, concentratie, cantitate)) {
        Medicament medicament;
        medicament = initMedicament(cod, nume, concentratie, cantitate);
        return adaugaMedicament(v, medicament);
    }
    return 2;
}

int actualizeazaMedicamentService(VectorDynamic* v, int cod, char* numeNou, float concentratieNoua) {
    if (valideazaCod(cod) && valideazaNume(numeNou) && valideazaConcentratie(concentratieNoua)) {
        return actualizareMedicament(v, cod, numeNou, concentratieNoua);
    }
    return 2;
}

int stergeMedicamentService(VectorDynamic* v, int cod) {
    if (valideazaCod(cod)) {
        return stergeMedicament(v, cod);
    }
    return 2;
}

VectorDynamic sortMedicamenteDupaNume(VectorDynamic* v) {
    VectorDynamic sorted = copyListaMedicamente(v);


    for (int i = 0; i < size(&sorted) - 1; i++) {
        for (int j = i + 1; j < size(&sorted); j++) {
            Medicament* m1 = getElement(&sorted, i);
            Medicament* m2 = getElement(&sorted, j);

            if (strcmp(getNume(*m1),getNume(*m2)) > 0 ){
                Medicament temp = *m1;
                *m1 = *m2;
                *m2 = temp;
            }

        }
    }
    return sorted;
}


VectorDynamic sortMedicamenteCrescatorCantitate(VectorDynamic* v) {
    VectorDynamic sorted = copyListaMedicamente(v);
    for (int i = 0; i < size(&sorted) - 1; i++) {
        for (int j = i + 1; j < size(&sorted); j++) {
            Medicament* m1 = getElement(&sorted, i);
            Medicament* m2 = getElement(&sorted, j);

            if (getCantitate(*m1) > getCantitate(*m2)) {
                Medicament temp = *m1;
                *m1 = *m2;
                *m2 = temp;
            }

        }
    }
    return sorted;
}

VectorDynamic sortMedicamenteDescrescatorCantitate(VectorDynamic* v) {
    VectorDynamic sorted = copyListaMedicamente(v);
    for (int i = 0; i < size(&sorted) - 1; i++) {
        for (int j = i + 1; j < size(&sorted); j++) {
            Medicament* m1 = getElement(&sorted, i);
            Medicament* m2 = getElement(&sorted, j);

            if (getCantitate(*m1) < getCantitate(*m2)) {
                Medicament temp = *m1;
                *m1 = *m2;
                *m2 = temp;
            }

        }
    }
    return sorted;
}

VectorDynamic filtrareCantitate(VectorDynamic* v, int cantitate_max) {
    VectorDynamic filtered;
    initVector(&filtered, capacity(v));
    for (int i = 0; i < v->size; i++) {
        if (getCantitate(*getElement(v,i)) < cantitate_max) {
            Medicament medicament;
            int cod = getCod(*getElement(v, i));
            char* nume = getNume(*getElement(v, i));
            float concentratie = getConcentratie(*getElement(v, i));
            int cantitate = getCantitate(*getElement(v, i));
            medicament = initMedicament(cod, nume, concentratie, cantitate);
            adaugaMedicament(&filtered, medicament);
        }
    }
    return filtered;
}

VectorDynamic filtrareLitera( VectorDynamic* v, char litera) {
    VectorDynamic filtered;
    initVector(&filtered, v->capacity);
    for (int i = 0; i < v->size; i++) {
        if (getNume(*getElement(v,i))[0] == litera) {
            Medicament medicament;
            int cod = getCod(*getElement(v, i));
            char* nume = getNume(*getElement(v, i));
            float concentratie = getConcentratie(*getElement(v, i));
            int cantitate = getCantitate(*getElement(v, i));
            medicament = initMedicament(cod, nume, concentratie, cantitate);
            adaugaMedicament(&filtered, medicament);
        }
    }
    return filtered;
}


