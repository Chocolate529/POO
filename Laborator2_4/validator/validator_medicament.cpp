//
// Created by lupse on 3/11/2025.
//
#include "validator_medicament.h"
#include <string.h>

int valideazaCod(int cod) {
    return cod > 0;
}

int valideazaNume(char* nume) {
    return strlen(nume) >= 2;
}

int valideazaConcentratie(float concentratie) {
    return concentratie > 0;
}

int valideazaCantitate(int cantitate) {
    return cantitate > 0;
}

int valideazaMedicament(int cod, char* nume, float concentratie, int cantitate) {
    return valideazaCod(cod) && valideazaNume(nume) && valideazaConcentratie(concentratie) && valideazaCantitate(cantitate);
}