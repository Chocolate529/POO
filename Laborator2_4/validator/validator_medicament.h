//
// Created by lupse on 3/11/2025.
//

#ifndef VALIDATOR_MEDICAMENT_H
#define VALIDATOR_MEDICAMENT_H

/// Verifică dacă un cod de medicament este valid.
/// Un cod este considerat valid dacă este un număr pozitiv.
/// @param cod Codul medicamentului.
/// @return 1 dacă codul este valid, 0 în caz contrar.
int valideazaCod(int cod);

/// Verifică dacă un nume de medicament este valid.
/// Un nume este considerat valid dacă are cel puțin 2 caractere.
/// @param nume Pointer către șirul de caractere care reprezintă numele.
/// @return 1 dacă numele este valid, 0 în caz contrar.
int valideazaNume(char* nume);

/// Verifică dacă o concentrație de medicament este validă.
/// O concentrație este considerată validă dacă este un număr pozitiv.
/// @param concentratie Concentrația medicamentului.
/// @return 1 dacă concentrația este validă, 0 în caz contrar.
int valideazaConcentratie(float concentratie);

/// Verifică dacă o cantitate de medicament este validă.
/// O cantitate este considerată validă dacă este un număr pozitiv.
/// @param cantitate Cantitatea medicamentului.
/// @return 1 dacă cantitatea este validă, 0 în caz contrar.
int valideazaCantitate(int cantitate);

/// Validează toate câmpurile unui medicament.
/// Medicamentul este considerat valid dacă toate valorile sunt valide:
/// - codul este pozitiv,
/// - numele are cel puțin 2 caractere,
/// - concentrația este pozitivă,
/// - cantitatea este pozitivă.
/// @param cod Codul medicamentului.
/// @param nume Pointer către șirul de caractere care reprezintă numele medicamentului.
/// @param concentratie Concentrația medicamentului.
/// @param cantitate Cantitatea medicamentului.
/// @return 1 dacă toate datele sunt valide, 0 în caz contrar.
int valideazaMedicament(int cod, char* nume, float concentratie, int cantitate);
#endif //VALIDATOR_MEDICAMENT_H
