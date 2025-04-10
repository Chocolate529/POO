#include "domeniu_masina.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct_masina* creeaza_masina(int id, char* model, char* nr_inmatriculare, char* categorie, int inchiriata) {
    struct_masina* masina = (struct_masina*)malloc(sizeof(struct_masina));
    masina->id = id;
    masina->nr_inmatriculare = nr_inmatriculare;
    masina->categorie = categorie;
    masina->model = model;
    masina->inchiriata = inchiriata;
    return masina;
}

void destroy_masina(struct_masina* masina) {
    free(masina->model);
    free(masina->nr_inmatriculare);
    free(masina->categorie);
    free(masina);
}

struct_masina* copiaza_masina(const struct_masina* masina) {
    struct_masina* copie_masina = (struct_masina*)malloc(sizeof(struct_masina));
    copie_masina->id = masina->id;
    copie_masina->model = malloc(strlen(masina->model) + 1);
    if (copie_masina->model == NULL) {
        printf("Allocation Error");
        return NULL;
    }
    strcpy(copie_masina->model, masina->model);
    copie_masina->nr_inmatriculare =  malloc(strlen(masina->nr_inmatriculare) + 1);
    if (copie_masina->nr_inmatriculare == NULL) {
        printf("Allocation Error");
        return NULL;
    }
    strcpy(copie_masina->nr_inmatriculare, masina->nr_inmatriculare);
    copie_masina->categorie = malloc(strlen(masina->categorie) + 1);
    if (copie_masina->categorie == NULL) {
        printf("Allocation Error");
        return NULL;
    }
    strcpy(copie_masina->categorie, masina->categorie);
    copie_masina->inchiriata =  masina->inchiriata;

    return copie_masina;
}

int compara_masini(const struct_masina* masina1, const struct_masina* masina2) {
    if ((masina1->id != masina2->id) ||
       (masina1->inchiriata != masina2->inchiriata) ||
       (strcmp(masina1->model, masina2->model) != 0) ||
       (strcmp(masina1->nr_inmatriculare, masina2->nr_inmatriculare) != 0) ||
       (strcmp(masina1->categorie, masina2->categorie) != 0))
        return 0;
    return 1;
}

int get_id_masina(const struct_masina* masina) {
    return masina->id;
}

char* get_model_masina(const struct_masina* masina) {
    return masina->model;
}

char* get_nr_inmatriculare_masina(const struct_masina* masina) {
    return masina->nr_inmatriculare;
}

char* get_categorie_masina(const struct_masina* masina) {
    return masina->categorie;
}

int get_inchiriata_masina(const struct_masina* masina) {
    return masina->inchiriata;
}

void set_model_masina(struct_masina* masina, char* model_nou) {
    free(masina->model);
    masina->model = model_nou;
}

void set_categorie_masina(struct_masina* masina, char* categorie_noua) {
    free(masina->categorie);
    masina->categorie = categorie_noua;
}

void set_nr_inmatriculare_masina(struct_masina* masina, char* nr_inmatriculare_nou) {
    free(masina->nr_inmatriculare);
    masina->nr_inmatriculare = nr_inmatriculare_nou;
}

void set_inchiriata_masina(struct_masina* masina, const int inchiriata_nou) {
    masina->inchiriata = inchiriata_nou;
}
