#include <cassert>
#include "../domain/lista.h"
#include "../service/service_medicamente.h"
#include "test.h"

#include <cstdio>
#include <string.h>

void test_adaugaMedicamentService() {
    VectorDynamic v;
    initVector(&v, 2);
    adaugaMedicamentService(&v, 1, "Paracetamol", 500.0, 100);
    assert(v.size == 1);
    assert(v.medicamente[0].cod == 1);
    assert(strcmp(v.medicamente[0].nume, "Paracetamol") == 0);
    adaugaMedicamentService(&v, 2, "Aspirina", -100.0, -10);
    assert(v.size == 1);
    freeVector(&v);
}

void test_actualizeazaMedicamentService() {
    VectorDynamic v;
    initVector(&v, 2);
    adaugaMedicamentService(&v, 1, "Paracetamol", 500.0, 100);
    actualizeazaMedicamentService(&v, 1, "Ibuprofen", 400.0);
    assert(strcmp(v.medicamente[0].nume, "Ibuprofen") == 0);
    assert(v.medicamente[0].concentratie == 400.0);
    freopen("/dev/null", "w", stderr);
    actualizeazaMedicamentService(&v, 2, "Aspirina", 300.0);
    assert(strcmp(v.medicamente[0].nume, "Ibuprofen") == 0);
    freopen("/dev/tty", "w", stderr);
    freeVector(&v);
}

void test_stergeMedicamentService() {
    VectorDynamic v;
    initVector(&v, 2);
    adaugaMedicamentService(&v, 1, "Paracetamol", 500.0, 100);
    stergeMedicamentService(&v, 1);
    assert(v.size == 0);
    freopen("/dev/null", "w", stderr);
    stergeMedicamentService(&v, 2);
    freopen("/dev/tty", "w", stderr);
    assert(v.size == 0);
    freeVector(&v);
}

void test_sortMedicamenteDupaNume() {
    VectorDynamic v;
    initVector(&v, 2);
    adaugaMedicamentService(&v, 1, "Ibuprofen", 400.0, 100);
    adaugaMedicamentService(&v, 2, "Paracetamol", 500.0, 200);
    VectorDynamic sorted = sortMedicamenteDupaNume(&v);
    assert(strcmp(sorted.medicamente[0].nume, "Ibuprofen") == 0);
    assert(strcmp(sorted.medicamente[1].nume, "Paracetamol") == 0);
    freeVector(&v);
    freeVector(&sorted);
}

void test_sortMedicamenteCrescatorCantitate() {
    VectorDynamic v;
    initVector(&v, 2);
    adaugaMedicamentService(&v, 1, "Ibuprofen", 400.0, 300);
    adaugaMedicamentService(&v, 2, "Paracetamol", 500.0, 100);
    VectorDynamic sorted = sortMedicamenteCrescatorCantitate(&v);
    assert(sorted.medicamente[0].cantitate == 100);
    assert(sorted.medicamente[1].cantitate == 300);
    freeVector(&v);
    freeVector(&sorted);
}

void test_filtrareCantitate() {
    VectorDynamic v;
    initVector(&v, 2);
    adaugaMedicamentService(&v, 1, "Ibuprofen", 400.0, 300);
    adaugaMedicamentService(&v, 2, "Paracetamol", 500.0, 100);
    VectorDynamic filtered = filtrareCantitate(&v, 200);
    assert(filtered.size == 1);
    assert(filtered.medicamente[0].cantitate == 100);
    freeVector(&v);
    freeVector(&filtered);
}

void test_filtrareLitera() {
    VectorDynamic stoc;
    initVector(&stoc, 3);
    adaugaMedicament(&stoc, 1, "Aspirina", 500.0, 10);
    adaugaMedicament(&stoc, 2, "Paracetamol", 500.0, 5);
    adaugaMedicament(&stoc, 3, "Ibuprofen", 400.0, 20);
    VectorDynamic filtered = filtrareLitera(&stoc, 'P');
    assert(filtered.size == 1);
    assert(strcmp(filtered.medicamente[0].nume, "Paracetamol") == 0);
    freeVector(&stoc);
    freeVector(&filtered);
}

void test_sortMedicamenteDescrescatorCantitate() {
    VectorDynamic stoc;
    initVector(&stoc, 3);
    adaugaMedicament(&stoc, 1, "Aspirina", 500.0, 10);
    adaugaMedicament(&stoc, 2, "Paracetamol", 500.0, 5);
    adaugaMedicament(&stoc, 3, "Ibuprofen", 400.0, 20);
    VectorDynamic sorted = sortMedicamenteDescrescatorCantitate(&stoc);
    assert(sorted.medicamente[0].cantitate == 20);
    assert(sorted.medicamente[1].cantitate == 10);
    assert(sorted.medicamente[2].cantitate == 5);
    freeVector(&stoc);
    freeVector(&sorted);
}


void test_initVector() {
    VectorDynamic v;
    initVector(&v, 2);
    assert(v.size == 0);
    assert(v.capacity == 2);
    freeVector(&v);
}

void test_resizeVector() {
    VectorDynamic v;
    initVector(&v, 2);
    adaugaMedicament(&v, 1, "Medicament1", 500.0, 100);
    adaugaMedicament(&v, 2, "Medicament2", 400.0, 150);
    adaugaMedicament(&v, 3, "Medicament2", 400.0, 150);
    assert(v.capacity == 4);
    freeVector(&v);
}

void test_adaugaMedicament() {
    VectorDynamic v;
    initVector(&v, 2);

    adaugaMedicament(&v, 1, "Paracetamol", 500.0, 100);
    assert(v.size == 1);
    assert(v.medicamente[0].cod == 1);
    assert(strcmp(v.medicamente[0].nume, "Paracetamol") == 0);

    adaugaMedicament(&v, 2, "Ibuprofen", 400.0, 200);
    assert(v.size == 2);
    assert(v.medicamente[1].cod == 2);
    assert(strcmp(v.medicamente[1].nume, "Ibuprofen") == 0);

    adaugaMedicament(&v, 1, "Aspirina", 300.0, 50);
    assert(v.size == 2);
    assert(v.medicamente[0].cantitate == 150);

    freeVector(&v);
}

void test_actualizeazaMedicament() {
    VectorDynamic v;
    initVector(&v, 2);

    adaugaMedicament(&v, 1, "Paracetamol", 500.0, 100);
    actualizeazaMedicament(&v, 1, "Aspirina", 200.0);
    assert(strcmp(v.medicamente[0].nume, "Aspirina") == 0);
    assert(v.medicamente[0].concentratie == 200.0);
    freopen("/dev/null", "w", stderr);
    actualizeazaMedicament(&v, 2, "Ibuprofen", 400.0);
    assert(v.size == 1);
    freopen("/dev/tty", "w", stderr);
    freeVector(&v);
}

void test_stergeMedicament() {
    VectorDynamic v;
    initVector(&v, 2);

    adaugaMedicament(&v, 1, "Paracetamol", 500.0, 100);
    stergeMedicament(&v, 1);
    assert(v.size == 0);
    freopen("/dev/null", "w", stderr);
    stergeMedicament(&v, 2);
    assert(v.size == 0);
    freopen("/dev/tty", "w", stderr);
    freeVector(&v);
}

void test_getElement() {
    VectorDynamic v;
    initVector(&v, 2);
    adaugaMedicament(&v, 1, "Paracetamol", 500.0, 100);

    Medicament m = getElement(&v, 0);
    assert(m.cod == 1);
    assert(strcmp(m.nume, "Paracetamol") == 0);

    freeVector(&v);
}

void test_setElement() {
    VectorDynamic v;
    initVector(&v, 2);
    adaugaMedicament(&v, 1, "Paracetamol", 500.0, 100);

    Medicament newMedicament = {2, "Ibuprofen", 400.0, 150};
    setElement(&v, 0, newMedicament);
    assert(v.medicamente[0].cod == 2);
    assert(strcmp(v.medicamente[0].nume, "Ibuprofen") == 0);
    assert(v.medicamente[0].concentratie == 400.0);
    assert(v.medicamente[0].cantitate == 150);

    freeVector(&v);
}

void test_size() {
    VectorDynamic v;
    initVector(&v, 2);
    adaugaMedicament(&v, 1, "Paracetamol", 500.0, 100);
    adaugaMedicament(&v, 2, "Ibuprofen", 400.0, 200);
    assert(size(&v) == 2);
    freeVector(&v);
}

void run_all_tests() {
    test_adaugaMedicamentService();
    test_actualizeazaMedicamentService();
    test_stergeMedicamentService();
    test_filtrareCantitate();
    test_filtrareLitera();
    test_sortMedicamenteDescrescatorCantitate();
    test_sortMedicamenteCrescatorCantitate();
    test_sortMedicamenteDupaNume();
    test_initVector();
    test_resizeVector();
    test_adaugaMedicament();
    test_actualizeazaMedicament();
    test_stergeMedicament();
    test_getElement();
    test_setElement();
    test_size();
}
