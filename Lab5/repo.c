#include "repo.h"
#include <stdio.h>
#include <stdlib.h>

#define ALPHA 0.7
#define BETA 0.3

void* repo_copie_repo(const repository* repo) {
    repository* repo_aux = (repository*)malloc(repo->spatiu * sizeof(repository));
    repo_aux->lista = (void**)malloc(repo->spatiu * sizeof(void*));
    for (int i = 0; i < repo->numar; i++)
        repo_aux->lista[i] = repo->copie_element(repo->lista[i]);
    repo_aux->numar = repo->numar;
    repo_aux->spatiu = repo->spatiu;
    repo_aux->destroy_elem = repo->destroy_elem;
    repo_aux->get_id = repo->get_id;
    repo_aux->copie_element = repo->copie_element;
    return repo_aux;
}

int repo_verifica_existenta_element_dupa_id(const repository* repo, int id) {
    for (int i = 0; i < repo->numar; i++) {
        if (id == repo->get_id(repo->lista[i]))
            return 0;
    }
    return -2;
}

repository* repo_creeaza(void (*destroy_elem)(void*), int (*get_id)(void*), void* (*copie_element)(void*)) {
    repository* repo = malloc(sizeof(repository));
    if (repo == NULL) {
        printf("Allocation error!\n");
        return NULL;
    }
    repo->numar = 0;
    repo->spatiu = 1;
    repo->lista = (void**)malloc(repo->spatiu * sizeof(void*));
    if (repo->lista == NULL) {
        printf("Allocation error!\n");
        return NULL;
    }
    repo->destroy_elem = destroy_elem;
    repo->get_id = get_id;
    repo->copie_element = copie_element;
    return repo;
}

void repo_destroy(repository* repo) {
    if (repo == NULL) {
        printf("Destruction error!\n");
        return;
    }
    for (int i = 0; i < repo->numar; i++) {
        repo->destroy_elem(repo->lista[i]);
        repo->lista[i] = NULL;
    }
    free(repo->lista);
    repo->lista = NULL;
    free(repo);
    repo = NULL;
}

void repo_aloca_spatiu(repository* repo) {
    void** lista_noua_elemente = (void**)malloc((repo->spatiu * 2) * sizeof(void*));
    if (lista_noua_elemente == NULL) {
        printf("Allocation error!\n");
        return;
    }
    for (int i = 0; i < repo->numar; i++)
        lista_noua_elemente[i] = repo->lista[i];
    free(repo->lista);
    repo->lista = lista_noua_elemente;
    repo->spatiu *= 2;
}

void repo_dealoca_spatiu(repository* repo) {
    void** temp = malloc(repo->spatiu / 2 * sizeof(void*));
    for (int i = 0; i < repo->numar; i++)
        temp[i] = repo->lista[i];
    free(repo->lista);
    if (temp == NULL) {
        printf("Reallocation error!\n");
        return;
    }
    repo->lista = temp;
    repo->spatiu /= 2;
}

void repo_adauga_element(repository* repo, void* elem) {
    if (elem == NULL) {
        printf("Element NULL!\n");
        return;
    }
    if (repo->numar >= ALPHA * repo->spatiu)
        repo_aloca_spatiu(repo);
    repo->lista[repo->numar] = elem;
    repo->numar++;
}

void repo_modifica_element(const repository* repo, void* elem) {
    if (elem == NULL) {
        printf("Element NULL!\n");
        return;
    }
    for (int i = 0; i < repo->numar; i++)
        if (repo->get_id(repo->lista[i]) == repo->get_id(elem)) {
            repo->destroy_elem(repo->lista[i]);
            repo->lista[i] = elem;
        }
}

void* repo_cauta_element(const repository* repo, const int id) {
    for (int i = 0; i < repo->numar; i++)
        if (id == repo->get_id(repo->lista[i]))
            return repo->copie_element(repo->lista[i]);
    return NULL;
}

int repo_sterge_element(repository* repo, const int id) {
    for (int i = 0; i < repo->numar; i++)
        if (repo->get_id(repo->lista[i]) == id) {
            repo->destroy_elem(repo->lista[i]);
            for (int j = i; j < repo->numar - 1; j++)
                repo->lista[j] = repo->lista[j + 1];
        }
    repo->numar--;
    if (repo->numar <= BETA * repo->spatiu && repo->spatiu > 1)
        repo_dealoca_spatiu(repo);
    return 0;
}
