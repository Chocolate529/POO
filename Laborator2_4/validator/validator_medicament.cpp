//
// Created by lupse on 3/11/2025.
//
#include "validator_medicament.h"
#include <string.h>

int valideazaMedicament(int cod, char* nume, float concentratie, int cantitate) {
    if (cod <= 0 || concentratie <= 0 || cantitate < 0 || strlen(nume) == 0) {
        return 0;
    }
    return 1;
}