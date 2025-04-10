//
// Created by kevin on 3/23/2025.
//


#ifndef REPO_H
#define REPO_H
///Stochează pointeri (void*) la elemente într-un vector care se redimensionează automat.
typedef struct {
    void** lista;
    int numar;
    int spatiu;
    void (*destroy_elem)(void*); // Functie ce dealocheaza memoria unui element din repo - void(void*)
    int (*get_id)(void*); // Functie care returneaza id-ul unui element - int(void*)
    void* (*copie_element)(void*); // Functie care returneaza id-ul unui element - int(void*)
}repository;


/// Copiaza un repo, copiind fiecare element in parte(pointerii elementelor din repo si repo-ul returnat nu pointeaza catre aceleasi elemente)
/// @param repo : pointer la catre repo - (repository*)
/// @return : pointer catre copia repo-ului
void* repo_copie_repo(const repository* repo);

/// Creeaza si aloca memorie pentru un repository gol
/// @param destroy_elem : Functie ce dealocheaza memoria unui element din repo - void(void*)
/// @param get_id : Functie care returneaza id-ul unui element - int(void*)
/// @param copie_element : Functie care returneaza id-ul unui element - int(void*)
/// @return pointer catre un repo (*repository)
repository* repo_creeaza(void (*destroy_elem)(void*), int (*get_id)(void*), void*(*copie_element)(void*));

/// Dealocheaza toata memoria dintr-un repo, inclusiv elementele din el
/// @param repo : pointer la catre repo - (repository*)
void repo_destroy(repository* repo);

/// Verifica daca exista in repo un element cu un id dat
/// @param repo : pointer la catre repo - (repository*)
/// @param id : Id-ul ce se cauta in repo - (int)
/// @return:
///          - 0: daca elementul este gasit - (int)
///          - -2: daca elementul nu este gasit - (int)
int repo_verifica_existenta_element_dupa_id(const repository* repo, int id);

/*
// Nu cred ca am nevoie sa il folosesc in afara layer-ului repo deci nu il pun in repo.h
/// Aloca spatiu pentru lista de elemente
/// @param repo : pointer la catre repo - (repository*)
void repo_aloca_spatiu(repository* repo);
*/

/// Adauga un element in repository
/// @param repo : pointer la catre repo - (repository*)
/// @param elem : pointer catre element - (void*)
void repo_adauga_element(repository* repo, void* elem);

/// Functie ce modifica un element
/// @param repo : pointer la catre repo - (repository*)
/// @param elem : pointer catre element - (void*)
void repo_modifica_element(const repository* repo, void* elem);

/// Cauta un element dupa id in repo si returneaza un pointer catre copia elementului
/// @param repo : pointer la catre repo - (repository*)
/// @param id : pointer catre element - (void*)
/// @return :
///     - pointer catre copia elementului daca acesta exista in repo
///     - NULL daca elemntul nu exista in repo
void* repo_cauta_element(const repository* repo, int id);

/// Sterge un element dupa id din repo
/// @param repo : pointer la catre repo - (repository*)
/// @param id : pointer catre element - (void*)
/// @return :
///     - -5 daca nu am gasit un element cu acelasi id
///     - 0 daca elementul a fost sters cu succes
int repo_sterge_element(repository* repo, int id);

#endif //REPO_H
