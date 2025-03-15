#include "medicament.h"

#include <stdlib.h>
#include <string.h>
//
// Created by lupse on 3/13/2025.
//
Medicament initMedicament(int cod, char* nume, float concentratie, int cantitate) {
    Medicament medicament;
    medicament.cod = cod;
    medicament.nume = (char*)malloc(strlen(nume)+1);
    strcpy(medicament.nume, nume);
    medicament.concentratie = concentratie;
    medicament.cantitate = cantitate;
    return medicament;
}

Medicament copyMedicament(Medicament medicament) {
    Medicament copy;
    int cod = getCod(medicament);
    char* nume = getNume(medicament);
    int cantitate = getCantitate(medicament);
    float concentratie = getConcentratie(medicament);
    return initMedicament(cod, nume, concentratie, cantitate);
}

int getCod(Medicament medicament) {
    return medicament.cod;
}

char* getNume(Medicament medicament) {
    return medicament.nume;
}

float getConcentratie(Medicament medicament) {
    return medicament.concentratie;
}

int getCantitate(Medicament medicament) {
    return medicament.cantitate;
}

void setNume(Medicament* medicament, char* nume) {
    free(medicament->nume);
    medicament->nume = (char*)malloc(strlen(nume) +1);
    strcpy(medicament->nume, nume);
}

void setConcentratie(Medicament *medicament, float concentratie) {
    medicament->concentratie = concentratie;
}

void setCantitate(Medicament *medicament, int cantitate) {
    medicament->cantitate = cantitate;
}

