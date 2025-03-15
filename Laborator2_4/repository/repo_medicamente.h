//
// Created by lupse on 3/13/2025.
//

#ifndef REPO_MEDICAMENTE_H
#define REPO_MEDICAMENTE_H
#include "../domain/lista.h"

/// Adauga un medicament validat in veectorul de medicamente v
/// @param v pointer catre structura VectorDynmic
/// @param el structura de tipul Medicament
/// @return 1 daca este adaugat un element nou in vector si 0 daca elementul exista deja si
///         creste doar cantitatea
int adaugaMedicament(VectorDynamic* v, Medicament el);

/// Actualizeaza un medicament cu un numeNou si concentratieNoua
/// @param v pointer catre structura VectorDynamic
/// @param codElementVechi numar natural ce reprezinta codul medicamentului de actualizat
/// @param numeNou pointer catre un sir de caractere
/// @param concentratieNoua numar real ce reprezinta concentratia noua a medicamentului
/// @return 1 daca actualizarea are loc cu succes si 0 daca nu exista elementul de actualizat
int actualizareMedicament(VectorDynamic* v,int codElementVechi, char* numeNou, float concentratieNoua);

/// Sterge medicamentul care are codul precizat
/// @param v pointer catre structura VectorDynamic
/// @param cod numar natural ce reprezinta codul elementuli de sters
/// @return 1 daca stergerea are loc cu succes si 0 daca nu exista elementul de sters
int stergeMedicament(VectorDynamic* v, int cod);

VectorDynamic copyListaMedicamente(VectorDynamic* v);
#endif //REPO_MEDICAMENTE_H
