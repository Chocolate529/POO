//
// Created by kevin on 3/23/2025.
//

#ifndef SERVICE_MASINI_H
#define SERVICE_MASINI_H
#include "domeniu_masina.h"
#include "lista.h"
#include "repo.h"
typedef struct {
    repository* repo;

    lista* lista_repos_undo;
    lista* lista_repos_redo;

    int (*validator)(void*);
}service_masina;

/// Undo la ultima operatie
/// @param serv : un pointer catre service (service_masina*)
/// @return :
///     - -99 daca lista de undo cu ultimele stari ale repo-ului e goala
///     - 0 daca undo s-a efectuat cu succes
int service_undo(service_masina* serv);

/// Redo la ultima operatie
/// @param serv : un pointer catre service (service_masina*)
/// @return :
///     - -99 daca lista de redo cu ultimele stari ale repo-ului e goala
///     - 0 daca redo s-a efectuat cu succes
int service_redo(service_masina* serv);

/// Creeaza si aloca memorie pentru service
/// @param repo : pointer la catre repo - (repository*)
/// @param validator : Functie care valideaza o masina - int(void*)
/// @return : pointer catre service - (service_masina*)
void* service_creeaza(repository* repo, int (*validator)(void*), void (*destroy_elem_lista)(void*), void* (*copie_elem_lista)(void*));

/// Dealoca memoria alocata unui service
/// @param serv : un pointer catre service (service_masina*)
void service_destroy(service_masina* serv);

/// Adauga un element
/// @param serv : un pointer catre service (service_masina*)
/// @param elem : un pointer catre elementu ce se adauga (void*)
/// @return :
///     - -6 daca elementul exista deja
///     - -1 daca elementul este invalid
///     - 0 daca elementul a fost adaugat cu succes
int service_adauga_element(const service_masina* serv, void* elem);

/// Modifica un element
/// @param serv : un pointer catre service (service_masina*)
/// @param elem : un pointer catre elementu ce se adauga (void*)
/// @return :
///     - -7 daca elementul nu exista
///     - -1 daca elementul este invalid
///     - 0 daca elementul a fost modificat cu succes
int service_modifica_element(const service_masina* serv, void* elem);

/// Cauta un element
/// @param serv : un pointer catre service (service_masina*)
/// @param id : numar natural prin care un element e unic identificabil
/// @return :
///     - pointer catre copia unui element daca este gasit cu succes
///     - NULL daca elementul nu a fost gasit
void* service_cauta_element(const service_masina* serv, int id);

/// Sterge un element
/// @param serv : un pointer catre service (service_masina*)
/// @param id : numar natural prin care un element e unic identificabil
/// @return :
///     - -8 daca elementul nu exista sau eroare la realocare
///     - 0 daca elementul a fost sters cu succes
int service_sterge_element(const service_masina* serv, int id);

/// Inchiriaza o masina dupa id
/// @param serv : un pointer catre service (service_masina*)
/// @param id : numar natural unic asociat masinii (int)
/// @return 0 daca masina a fost inchiriata cu succes; -6 daca masina nu a putut fi inchiriata sau nu exista masina cu acest id
int service_inchiriaza_masina(const service_masina* serv, int id);

/// Returneaza o masina dupa id
/// @param serv : un pointer catre service (service_masina*)
/// @param id : numar natural unic asociat masinii (int)
/// @return 0 daca masina a fost returnata cu succes; -6 daca masina nu a putut fi returnara sau nu exista masina cu acest id
int service_returneaza_masina(const service_masina* serv, int id);

/// ATENTIE!!! MEMORIA LISTEI RETURNATE TREBUIE ELIBERATA DE APELANT!!!\n
/// Returneaza un struct de tip struct_masini ce contine lista de masini cu categoria ceruta
/// @param serv : un pointer catre service (service_masina*)
/// @param categorie : categoria masinii (char*)
/// @return NULL daca categoria este invalida, un struct de tip struct_masini ce contine lista de masini cu categoria ceruta
repository* service_vizualizare_dupa_categorie(const service_masina* serv, const char* categorie);

/// Permite sortarea masinilor dupa: model sau categorie (crescator/descrescator)
/// @param serv : un pointer catre service (service_masina*)
/// @param crescator : 1 pentru ca functia sa sorteze crescator, 0 pentru ca functia sa sorteze descrescator
/// @param mod : 0 pentru ca functia sa sorteze dupa categorie, 1 pentru ca functia sa sorteze dupa model
void service_sortare(const service_masina* serv, int crescator, int mod);

#endif //SERVICE_MASINI_H
