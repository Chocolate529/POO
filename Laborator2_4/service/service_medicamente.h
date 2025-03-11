//
// Created by lupse on 3/11/2025.
//

#ifndef SERVICE_MEDICAMENTE_H
#define SERVICE_MEDICAMENTE_H

#include "../domain/lista.h"

void adaugaMedicamentService(VectorDynamic* v, int cod, char* nume, float concentratie, int cantitate);
void actualizeazaMedicamentService(VectorDynamic* v, int cod, char* numeNou, float concentratieNoua);
void stergeMedicamentService(VectorDynamic* v, int cod);
VectorDynamic sortMedicamenteDupaNume(const VectorDynamic* v);
VectorDynamic sortMedicamenteCrescatorCantitate(const VectorDynamic* v);
VectorDynamic sortMedicamenteDescrescatorCantitate(const VectorDynamic* v);
VectorDynamic filtrareCantitate(const VectorDynamic* v, int cantitate);
VectorDynamic filtrareLitera(const VectorDynamic* v, char litera);
#endif //SERVICE_MEDICAMENTE_H

