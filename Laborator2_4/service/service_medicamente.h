//
// Created by lupse on 3/11/2025.
//

#ifndef SERVICE_MEDICAMENTE_H
#define SERVICE_MEDICAMENTE_H

#include "../repository/repo_medicamente.h"

typedef int (*ComapreFunction)(Medicament* a, Medicament* b);
VectorDynamic sortMedicamente(VectorDynamic* v, ComapreFunction cmp);
int criteriuDupaNume(Medicament* m1, Medicament* m2);
int criteriuDupaCantitateCrescator(Medicament* m1, Medicament* m2);
int criteriuDupaCantitateDescrescator(Medicament* m1, Medicament* m2);


/// Adaugă un medicament nou în vectorul dinamic, dacă este valid.
/// @param v Pointer către structura VectorDynamic.
/// @param cod Codul medicamentului.
/// @param nume Numele medicamentului.
/// @param concentratie Concentrația medicamentului.
/// @param cantitate Cantitatea medicamentului.
/// @return 0 daca medicamentul exista deja, se adauga cantitatea
///         1 daca se adauga medicamentul nou
///         2 daca sunt erori la validare
int adaugaMedicamentService(VectorDynamic* v, int cod, char* nume, float concentratie, int cantitate);

/// Actualizează numele și concentrația unui medicament existent.
/// @param v Pointer către structura VectorDynamic.
/// @param cod Codul medicamentului ce trebuie actualizat.
/// @param numeNou Noul nume al medicamentului.
/// @param concentratieNoua Noua concentrație a medicamentului.
/// @return 0 daca medicamentul nu exista
///         1 daca se actualizeaza medicamentul
///         2 daca sunt erori la validare
int actualizeazaMedicamentService(VectorDynamic* v, int cod, char* numeNou, float concentratieNoua);

/// Șterge un medicament din vectorul dinamic, dacă codul este valid.
/// @param v Pointer către structura VectorDynamic.
/// @param cod Codul medicamentului ce trebuie șters.
/// @return 0 daca medicamentul nu exista
///         1 daca se sterge medicamentul
///         2 daca sunt erori la validare
int stergeMedicamentService(VectorDynamic* v, int cod);

/// Sortează medicamentele din vector în ordine alfabetică după nume.
/// @param v Pointer către structura VectorDynamic.
/// @return Un nou VectorDynamic sortat după nume.
VectorDynamic sortMedicamenteDupaNume(VectorDynamic* v);

/// Sortează medicamentele în ordine crescătoare după cantitate.
/// @param v Pointer către structura VectorDynamic.
/// @return Un nou VectorDynamic sortat crescător după cantitate.
VectorDynamic sortMedicamenteCrescatorCantitate(VectorDynamic* v);

/// Sortează medicamentele în ordine descrescătoare după cantitate.
/// @param v Pointer către structura VectorDynamic.
/// @return Un nou VectorDynamic sortat descrescător după cantitate.
VectorDynamic sortMedicamenteDescrescatorCantitate( VectorDynamic* v);

/// Filtrează medicamentele care au cantitatea mai mică decât o valoare dată.
/// @param v Pointer către structura VectorDynamic.
/// @param cantitate_max Valoarea maximă a cantității pentru filtrare.
/// @return Un nou VectorDynamic conținând doar medicamentele cu cantitate mai mică decât cantitate_max.
VectorDynamic filtrareCantitate(VectorDynamic* v, int cantitate_max);

/// Filtrează medicamentele al căror nume începe cu o literă specificată.
/// @param v Pointer către structura VectorDynamic.
/// @param litera Litera cu care trebuie să înceapă numele medicamentului.
/// @return Un nou VectorDynamic conținând doar medicamentele care încep cu litera specificată.
VectorDynamic filtrareLitera( VectorDynamic* v, char litera);
#endif //SERVICE_MEDICAMENTE_H

