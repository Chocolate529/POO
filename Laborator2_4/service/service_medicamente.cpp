//
// Created by lupse on 3/11/2025.
//
#include "service_medicamente.h"
#include <string.h>
#include "../validator/validator_medicament.h"

/// @param v Vectorul in care va fi adaugat medicamentul.
/// @param cod Codul unic al medicamentului.
/// @param nume Numele medicamentului.
/// @param concentratie Concentratia medicamentului.
/// @param cantitate Cantitatea de medicament care va fi adaugata.
///
/// Functia verifica daca datele medicamentului sunt valide folosind functia `valideazaMedicament`.
/// Daca sunt valide, adauga medicamentul in vector folosind `adaugaMedicament`.
void adaugaMedicamentService(VectorDynamic* v, int cod, char* nume, float concentratie, int cantitate) {
    if (valideazaMedicament(cod, nume, concentratie, cantitate)) {
        adaugaMedicament(v, cod, nume, concentratie, cantitate);
    }
}

/// @param v Vectorul care contine medicamentele.
/// @param cod Codul unic al medicamentului ce va fi actualizat.
/// @param numeNou Noul nume pentru medicament.
/// @param concentratieNoua Noua concentratie pentru medicament.
///
/// Functia actualizeaza detaliile medicamentului (nume si concentratie) in vector folosind `actualizeazaMedicament`.
void actualizeazaMedicamentService(VectorDynamic* v, int cod, char* numeNou, float concentratieNoua) {
    actualizeazaMedicament(v, cod, numeNou, concentratieNoua);
}

/// @param v Vectorul din care va fi sters medicamentul.
/// @param cod Codul unic al medicamentului ce va fi sters.
///
/// Functia sterge medicamentul din vector dupa codul acestuia folosind `stergeMedicament`.
void stergeMedicamentService(VectorDynamic* v, int cod) {
    stergeMedicament(v, cod);
}

/// @param v Vectorul ce va fi sortat.
/// @return Un `VectorDynamic` sortat continand medicamentele sortate dupa numele lor in ordine crescatoare.
///
/// Functia sorteaza medicamentele pe baza numelui lor folosind un algoritm simplu de sortare prin selectie.
VectorDynamic sortMedicamenteDupaNume(const VectorDynamic* v) {
    VectorDynamic sorted;
    initVector(&sorted, v->capacity);
    for (int i = 0; i < v->size; i++) {
        adaugaMedicament(&sorted, v->medicamente[i].cod, v->medicamente[i].nume, v->medicamente[i].concentratie, v->medicamente[i].cantitate);
    }
    for (int i = 0; i < sorted.size - 1; i++) {
        for (int j = i + 1; j < sorted.size; j++) {
            if (strcmp(sorted.medicamente[i].nume, sorted.medicamente[j].nume) > 0) {
                Medicament temp = sorted.medicamente[i];
                sorted.medicamente[i] = sorted.medicamente[j];
                sorted.medicamente[j] = temp;
            }
        }
    }
    return sorted;
}

/// @param v Vectorul ce va fi sortat.
/// @return Un `VectorDynamic` sortat continand medicamentele sortate dupa cantitatea lor in ordine crescatoare.
///
/// Functia sorteaza medicamentele pe baza cantitatii folosind un algoritm simplu de sortare prin selectie.
VectorDynamic sortMedicamenteCrescatorCantitate(const VectorDynamic* v) {
    VectorDynamic sorted;
    initVector(&sorted, v->capacity);
    for (int i = 0; i < v->size; i++) {
        adaugaMedicament(&sorted, v->medicamente[i].cod, v->medicamente[i].nume, v->medicamente[i].concentratie, v->medicamente[i].cantitate);
    }
    for (int i = 0; i < sorted.size - 1; i++) {
        for (int j = i + 1; j < sorted.size; j++) {
            if (sorted.medicamente[i].cantitate > sorted.medicamente[j].cantitate) {
                Medicament temp = sorted.medicamente[i];
                sorted.medicamente[i] = sorted.medicamente[j];
                sorted.medicamente[j] = temp;
            }
        }
    }
    return sorted;
}

/// @param v Vectorul ce va fi sortat.
/// @return Un `VectorDynamic` sortat continand medicamentele sortate dupa cantitatea lor in ordine descrescatoare.
///
/// Functia sorteaza medicamentele pe baza cantitatii folosind un algoritm simplu de sortare prin selectie.
VectorDynamic sortMedicamenteDescrescatorCantitate(const VectorDynamic* v) {
    VectorDynamic sorted;
    initVector(&sorted, v->capacity);
    for (int i = 0; i < v->size; i++) {
        adaugaMedicament(&sorted, v->medicamente[i].cod, v->medicamente[i].nume, v->medicamente[i].concentratie, v->medicamente[i].cantitate);
    }
    for (int i = 0; i < sorted.size - 1; i++) {
        for (int j = i + 1; j < sorted.size; j++) {
            if (sorted.medicamente[i].cantitate < sorted.medicamente[j].cantitate) {
                Medicament temp = sorted.medicamente[i];
                sorted.medicamente[i] = sorted.medicamente[j];
                sorted.medicamente[j] = temp;
            }
        }
    }
    return sorted;
}

/// @param v Vectorul ce va fi filtrat.
/// @param cantitate Pragul de cantitate.
/// @return Un nou `VectorDynamic` continand doar medicamentele cu cantitate mai mica decat pragul specificat.
///
/// Functia filtreaza medicamentele pe baza cantitatii si returneaza un nou vector.
VectorDynamic filtrareCantitate(const VectorDynamic* v, int cantitate) {
    VectorDynamic filtered;
    initVector(&filtered, v->capacity);
    for (int i = 0; i < v->size; i++) {
        if (v->medicamente[i].cantitate < cantitate) {
            adaugaMedicament(&filtered, v->medicamente[i].cod, v->medicamente[i].nume, v->medicamente[i].concentratie, v->medicamente[i].cantitate);
        }
    }
    return filtered;
}

/// @param v Vectorul ce va fi filtrat.
/// @param litera Prima litera a numelui medicamentului.
/// @return Un nou `VectorDynamic` continand doar medicamentele al caror nume incepe cu litera specificata.
///
/// Functia filtreaza medicamentele pe baza primei litere a numelui lor.
VectorDynamic filtrareLitera(const VectorDynamic* v, char litera) {
    VectorDynamic filtered;
    initVector(&filtered, v->capacity);
    for (int i = 0; i < v->size; i++) {
        if (v->medicamente[i].nume[0] == litera) {
            adaugaMedicament(&filtered, v->medicamente[i].cod, v->medicamente[i].nume, v->medicamente[i].concentratie, v->medicamente[i].cantitate);
        }
    }
    return filtered;
}


