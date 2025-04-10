//
// Created by kevin on 3/23/2025.
//


#ifndef VALIDATOR_MASINA_H
#define VALIDATOR_MASINA_H



#include "domeniu_masina.h"

/// Valideaza o masina
/// @param masina : masina cu id, model, nr_inmatriculare, categorie, inchiriata (struct_masina*)
/// @return -1 daca masina este invalida si 0 daca masina este valida
int validator_masina(const struct_masina* masina);
#endif //VALIDATOR_MASINA_H