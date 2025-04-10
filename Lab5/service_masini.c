#include "service_masini.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "domeniu_masina.h"
#include "repo.h"

void* service_creeaza(repository* repo, int (*validator)(void*), void (*destroy_elem_lista)(void*), void* (*copie_elem_lista)(void*)) {
    service_masina* serv = malloc(sizeof(service_masina));
    if (serv == NULL) {
        printf("Allocation error!\n");
        return NULL;
    }
    serv->lista_repos_undo = lista_creeaza(destroy_elem_lista, copie_elem_lista);
    serv->lista_repos_redo = lista_creeaza(destroy_elem_lista, copie_elem_lista);
    serv->repo = repo;
    serv->validator = validator;
    return serv;
}

void service_destroy(service_masina* serv) {
    repo_destroy(serv->repo);
    serv->repo = NULL;
    lista_destroy(serv->lista_repos_undo);
    lista_destroy(serv->lista_repos_redo);
    free(serv);
    serv = NULL;
}

int service_adauga_element(const service_masina* serv, void* elem) {
    if (elem==NULL) {
        printf("Element NULL!\n");
        return -1;
    }
    int ret = repo_verifica_existenta_element_dupa_id(serv->repo, serv->repo->get_id(elem));
    if (ret == 0) {
        return -6;
    }
    ret = serv->validator(elem);
    if (ret == -1) {
        return -1;
    }
    lista_push_back(serv->lista_repos_undo, serv->repo);
    repo_adauga_element(serv->repo, elem);
    return 0;
}

int service_modifica_element(const service_masina* serv, void* elem) {
    if (elem==NULL) {
        printf("Element NULL!\n");
        return 1;
    }
    int ret = repo_verifica_existenta_element_dupa_id(serv->repo, serv->repo->get_id(elem));
    if (ret == -2) {
        return -7;
    }
    ret = serv->validator(elem);
    if (ret == -1) {
        return -1;
    }
    lista_push_back(serv->lista_repos_undo, serv->repo);
    repo_modifica_element(serv->repo, elem);
    return 0;
}

void* service_cauta_element(const service_masina* serv, int id) {
    void* elem = repo_cauta_element(serv->repo, id);
    if (elem == NULL)
        return NULL;
    return elem;
}

int service_sterge_element(const service_masina* serv, const int id){
    int ret = repo_verifica_existenta_element_dupa_id(serv->repo, id);
    if (ret == -2) {
        return -8;
    }
    lista_push_back(serv->lista_repos_undo, serv->repo);
    ret = repo_sterge_element(serv->repo, id);
    if (ret == -5) {
        lista_pop(serv->lista_repos_undo);
        return -8;
    }
    return 0;
}

int service_inchiriaza_masina(const service_masina* serv, const int id) {
    for (int i=0; i<serv->repo->numar; i++) {
        if (serv->repo->get_id(serv->repo->lista[i]) == id) {
            if (get_inchiriata_masina(serv->repo->lista[i]) == 0) {
                lista_push_back(serv->lista_repos_undo, serv->repo);
                set_inchiriata_masina(serv->repo->lista[i], 1);
                return 0;
            }
        }
    }
    return -6;
}

int service_returneaza_masina(const service_masina* serv, const int id) {
    for (int i=0; i<serv->repo->numar; i++) {
        if (serv->repo->get_id(serv->repo->lista[i]) == id) {
            if (get_inchiriata_masina(serv->repo->lista[i])== 1) {
                lista_push_back(serv->lista_repos_undo, serv->repo);
                set_inchiriata_masina(serv->repo->lista[i], 0);
                return 0;
            }
        }
    }
    return -7;
}

repository* service_vizualizare_dupa_categorie(const service_masina* serv, const char* categorie) {
    if (strcmp(categorie, "suv") != 0 && strcmp(categorie, "sport") != 0 && strcmp(categorie, "mini") != 0)
        return NULL;
    repository* repo_masini_cat = repo_creeaza((void*)destroy_masina, (void*)get_id_masina, (void*)copiaza_masina);
    for (int i = 0; i < serv->repo->numar; i++)
        if (strcmp(get_categorie_masina(serv->repo->lista[i]), categorie) == 0)
            repo_adauga_element(repo_masini_cat, repo_masini_cat->copie_element(serv->repo->lista[i]));
    return repo_masini_cat;
}

void service_sortare(const service_masina* serv, const int crescator, const int mod) {
    lista_push_back(serv->lista_repos_undo, serv->repo);
    for (int i=0; i<serv->repo->numar-1; i++) {
        for (int j=i+1; j<serv->repo->numar; j++)
            if ((mod == 0 && crescator == 1 && strcmp(get_categorie_masina(serv->repo->lista[j]),get_categorie_masina(serv->repo->lista[i])) < 0) ||
                (mod == 0 && crescator == 0 && strcmp(get_categorie_masina(serv->repo->lista[i]),get_categorie_masina(serv->repo->lista[j])) < 0) ||
                (mod == 1 && crescator == 1 && strcmp(get_model_masina(serv->repo->lista[j]),get_model_masina(serv->repo->lista[i])) < 0) ||
                (mod == 1 && crescator == 0 && strcmp(get_model_masina(serv->repo->lista[i]),get_model_masina(serv->repo->lista[j])) < 0)){
                    void* aux = serv->repo->lista[i];
                    serv->repo->lista[i] = serv->repo->lista[j];
                    serv->repo->lista[j] = aux;
            }
    }
}

int service_undo(service_masina* serv) {
    if (lista_empty(serv->lista_repos_undo))
        return -99;
    lista_push_back(serv->lista_repos_redo, serv->repo);
    repo_destroy(serv->repo);
    serv->repo = lista_top(serv->lista_repos_undo);
    lista_pop(serv->lista_repos_undo);
    return 0;
}

int service_redo(service_masina* serv) {
    if (lista_empty(serv->lista_repos_redo))
        return -99;
    lista_push_back(serv->lista_repos_undo, serv->repo);
    repo_destroy(serv->repo);
    serv->repo = lista_top(serv->lista_repos_redo);
    lista_pop(serv->lista_repos_redo);
    return 0;
}
