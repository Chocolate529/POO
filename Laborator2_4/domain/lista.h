//
// Created by lupse on 3/11/2025.
//

#ifndef LISTA_H
#define LISTA_H

#include "medicament.h"
///abstractizare lista si separare CRUD intr un repo
///schimbare perror in return
typedef struct {
    Medicament* medicamente;
    int size;
    int capacity;
} VectorDynamic;
///d
void initVector(VectorDynamic* v, int capacity);
void resizeVector(VectorDynamic* v);
void adaugaMedicament(VectorDynamic* v, int cod, char* nume, float concentratie, int cantitate);
void actualizeazaMedicament(VectorDynamic* v, int cod, char* numeNou, float concentratieNoua);
void stergeMedicament(VectorDynamic* v, int cod);
void freeVector(VectorDynamic* v);
Medicament getElement(VectorDynamic* v, int index);
void setElement(VectorDynamic* v, int index, Medicament m);
int size(VectorDynamic* v);

#endif //LISTA_H
