//
// Created by lupse on 3/11/2025.
//
#include "lista.h"
#include <cstdlib>
#include <cstdio>

void initVector(VectorDynamic* v, int capacity) {
    v->element = (TElement*)malloc(capacity * sizeof(TElement));
    v->size = 0;
    v->capacity = capacity;
}
void resizeVector(VectorDynamic* v) {
    v->capacity *= 2;


    auto temp = (TElement*)realloc(v->element, v->capacity * sizeof(TElement));

    if (temp == nullptr) {  // realloc failed
        printf("Error: Out of memory while resizing vector\n");
        exit(EXIT_FAILURE);
    }

    v->element = temp;
}


void adaugaTElement(VectorDynamic* v, TElement element) {
    if (v->size == v->capacity) {
        resizeVector(v);
    }
    v->element[v->size] = element;
    v->size++;
}

void stergeTElement(VectorDynamic* v, int index) {
    for (int j = index; j < v->size - 1; j++) {
        v->element[j] = v->element[j + 1];
    }
    v->size--;
}

TElement* getElement(VectorDynamic* v, int index) {
    return &v->element[index];
}

// void setElement(VectorDynamic* v, int index, TElement m) {
//     v->element[index] = m;
// }

int size(VectorDynamic* v) {
    return v->size;
}

int capacity(VectorDynamic *v) {
    return v->capacity;
}

void freeVector(VectorDynamic* v) {
    for (int i = 0; i < size(v); i++) {
        free(getNume(*getElement(v,i)));

    }
    free(v->element);
    v->element = nullptr;
    v->size = 0;
    v->capacity = 0;
}


