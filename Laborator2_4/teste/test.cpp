#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "../service/service_medicamente.h"
#include "../domain/lista.h"
#include "test.h"
void testAdaugaMedicamentService() {
    VectorDynamic v;
    initVector(&v, 2);
    int response = adaugaMedicamentService(&v, 1, "Paracetamol", 500, 10);
    assert(response == 1);
    assert(size(&v) == 1);
    assert(strcmp(getNume(*getElement(&v, 0)), "Paracetamol") == 0);

    response = adaugaMedicamentService(&v, 1, "Paracetamol", 500, 10);
    assert(response == 0);
    assert(size(&v) == 1);
    assert(getCantitate(*getElement(&v, 0))== 20);

    response = adaugaMedicamentService(&v, -1, "", -1, -1);
    assert(response == 2);
    freeVector(&v);
}

void testActualizeazaMedicamentService() {
    VectorDynamic v;
    initVector(&v, 2);
    adaugaMedicamentService(&v, 1, "Paracetamol", 500, 10);
    int response = actualizeazaMedicamentService(&v, 1, "Ibuprofen", 400);
    assert(response == 1);
    assert(strcmp(getNume(*getElement(&v, 0)), "Ibuprofen") == 0);

    response = actualizeazaMedicamentService(&v, 2, "Ibuprofen", 400);
    assert(response == 0);

    response = actualizeazaMedicamentService(&v, -1, "", -4);
    assert(response == 2);
    freeVector(&v);
}

void testStergeMedicamentService() {
    VectorDynamic v;
    initVector(&v, 2);
    adaugaMedicamentService(&v, 1, "Paracetamol", 500, 10);
    adaugaMedicamentService(&v, 2, "Paracetamol", 500, 10);
    adaugaMedicamentService(&v, 3, "Paracetamol", 500, 10);
    int response = stergeMedicamentService(&v, 1);

    assert(response == 1);
    assert(size(&v) == 2);
    response = stergeMedicamentService(&v, 1);
    assert(response == 0);

    response = stergeMedicamentService(&v, -1);
    assert(response == 2);
    freeVector(&v);
}

void testSortMedicamenteDupaNume() {
    VectorDynamic v;
    initVector(&v, 2);
    adaugaMedicamentService(&v, 1, "Ibuprofen", 400, 10);
    adaugaMedicamentService(&v, 2, "Paracetamol", 500, 20);
    adaugaMedicamentService(&v, 3, "Parasinus", 600, 30);
    adaugaMedicamentService(&v, 4, "Algocalmin", 700, 40);
    VectorDynamic sorted = sortMedicamenteDupaNume(&v);
    assert(strcmp(getNume(*getElement(&sorted, 0)), "Algocalmin") == 0);
    assert(strcmp(getNume(*getElement(&sorted, 1)), "Ibuprofen") == 0);
    assert(strcmp(getNume(*getElement(&sorted, 2)), "Paracetamol") == 0);
    assert(strcmp(getNume(*getElement(&sorted, 3)), "Parasinus") == 0);
    freeVector(&sorted);
    freeVector(&v);
}

void testSortMedicamenteCrescatorCantitate() {
    VectorDynamic v;
    initVector(&v, 2);
    adaugaMedicamentService(&v, 1, "Paracetamol", 500, 20);
    adaugaMedicamentService(&v, 2, "Ibuprofen", 400, 10);
    VectorDynamic sorted = sortMedicamenteCrescatorCantitate(&v);
    assert(getCantitate(*getElement(&sorted, 0)) == 10);
    assert(getCantitate(*getElement(&sorted, 1)) == 20);
    freeVector(&sorted);
    freeVector(&v);
}

void testSortMedicamenteDescrescatorCantitate() {
    VectorDynamic v;
    initVector(&v, 2);
    adaugaMedicamentService(&v, 1, "Paracetamol", 500, 10);
    adaugaMedicamentService(&v, 2, "Ibuprofen", 400, 20);
    VectorDynamic sorted = sortMedicamenteDescrescatorCantitate(&v);
    assert(getCantitate(*getElement(&sorted, 0)) == 20);
    assert(getCantitate(*getElement(&sorted, 1)) == 10);
    freeVector(&sorted);
    freeVector(&v);
}

void testFiltrareCantitate() {
    VectorDynamic v;
    initVector(&v, 2);
    adaugaMedicamentService(&v, 1, "Paracetamol", 500, 20);
    adaugaMedicamentService(&v, 2, "Ibuprofen", 400, 10);
    VectorDynamic filtered = filtrareCantitate(&v, 15);
    assert(size(&filtered) == 1);
    assert(getCantitate(*getElement(&filtered, 0)) == 10);
    freeVector(&filtered);
    freeVector(&v);
}

void testFiltrareLitera() {
    VectorDynamic v;
    initVector(&v, 2);
    adaugaMedicamentService(&v, 1, "Paracetamol", 500, 20);
    adaugaMedicamentService(&v, 2, "Ibuprofen", 400, 10);
    VectorDynamic filtered = filtrareLitera(&v, 'I');
    assert(size(&filtered) == 1);
    assert(strcmp(getNume(*getElement(&filtered, 0)), "Ibuprofen") == 0);
    freeVector(&filtered);
    freeVector(&v);
}

void runTests() {
    testAdaugaMedicamentService();
    testActualizeazaMedicamentService();
    testStergeMedicamentService();
    testSortMedicamenteDupaNume();
    testSortMedicamenteCrescatorCantitate();
    testSortMedicamenteDescrescatorCantitate();
    testFiltrareCantitate();
    testFiltrareLitera();
    printf("All tests passed!\n");
}
