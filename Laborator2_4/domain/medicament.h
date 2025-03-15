//
// Created by lupse on 3/11/2025.
//

#ifndef MEDICAMENT_H
#define MEDICAMENT_H
typedef struct {
    int cod;
    char* nume;
    float concentratie;
    int cantitate;
} Medicament;

/// Initializeaza structura Medicament cu datele cod,nume,concentratie,cantitate
/// @param cod Numar natural prin care este unic identificat un medicament
/// @param nume Sir de caractere care retine numele medicamentului , lungimea > 0
/// @param concentratie Numar real ce reprezinta concentratia medicamentului
/// @param cantitate Numar natural ce reprezinta cantitatea din stoc a medicamentului respectiv
/// @return un medicament cu cod,nume,concentratie,cantitate
Medicament initMedicament(int cod, char* nume, float concentratie, int cantitate);

/// Deep copy pentru structura Medicament
/// @param medicament 
/// @return 
Medicament copyMedicament(Medicament medicament);

/// Returneaza codul unui medicament
/// @param medicament structura de tip Medicament
/// @return numar intreg ce reprezinta codul
int getCod(Medicament medicament);

/// Returneaza numele unui medicament
/// @param medicament structura de tip Medicament
/// @return pointer la un sir de caractere - numele unui medicament
char* getNume(Medicament medicament);

/// Returneaza concentratia unui medicament
/// @param medicament structura de tip medicament
/// @return numar real - concentratia unui medicament
float getConcentratie(Medicament medicament);

/// Returneaza cantitatea din stoc a unui medicament
/// @param medicament structura de tip medicament
/// @return numar intreg - cantitatea din stoc a unui medicament
int getCantitate(Medicament medicament);

/// Seteaza codul unui medicament
/// @param medicament pointer catre o structura de tip medicament
/// @param cod noul cod valid
void setCod(Medicament *medicament, int cod);

/// Seteaza numele unui medicament
/// @param medicament pointer catre o structura de tip medicament
/// @param nume pointer catre un sir de caractere
void setNume(Medicament *medicament, char *nume);

/// Seteaza concentratia unui medicament
/// @param medicament pointer catre o structura de tip medicament
/// @param concentratie noua concentratie
void setConcentratie(Medicament *medicament, float concentratie);

/// Seteaza cantitatea unui medicament
/// @param medicament pointer catre o structura de tip medicament
/// @param cantitate noua cantitate
void setCantitate(Medicament *medicament, int cantitate);


#endif //MEDICAMENT_H
