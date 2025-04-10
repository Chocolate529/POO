//
// Created by kevin on 3/23/2025.
//

#include "ui.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "domeniu_masina.h"
#include "repo.h"
#include "service_masini.h"
void initializare_comenzi(const int* nr_comenzi, char** comenzi) {
    for (int i = 0; i < *nr_comenzi; i++) {
        comenzi[i] = malloc(15 * sizeof(char));
    }
    strcpy(comenzi[0], "adauga\0");
    strcpy(comenzi[1], "modifica\0");
    strcpy(comenzi[2], "cauta\0");
    strcpy(comenzi[3], "sterge\0");
    strcpy(comenzi[4], "inchiriaza");
    strcpy(comenzi[5], "returneaza");
    strcpy(comenzi[6], "vizualizare");
    strcpy(comenzi[7], "sortare");
    strcpy(comenzi[8], "afis");
    strcpy(comenzi[9], "undo");
    strcpy(comenzi[10], "redo");
    strcpy(comenzi[11], "exit");
}

int id_comanda(int nr_comenzi, char** comenzi, const char* comanda) {
    for (int i = 0; i < nr_comenzi; i++) {
        if (strcmp(comenzi[i], comanda) == 0) {
            return i;
        }
    }
    return -10;
}


void ui_afiseaza_masina(const struct_masina* masina) {
    printf("Id: %d\n", masina->id);
    printf("Model: %s\n", masina->model);
    printf("Numar inmatriculare: %s\n", masina->nr_inmatriculare);
    printf("Categorie: %s\n", masina->categorie);
    printf("Status inchiriere: %d\n", masina->inchiriata);
}


void ui_adauga_masina(const service_masina* serv) {
    int id;
    printf("Introduceti id-ul masinii: ");
    scanf("%d", &id);

    int inchiriata;
    printf("Introduceti statusul inchirierii(0/1): ");
    scanf("%d", &inchiriata);

    char *model = malloc(15 * sizeof(char));
    printf("Introduceti modelul masinii: ");
    scanf("%s", model);


    char* nr_inmatriculare = malloc(15 * sizeof(char));
    printf("Introduceti numarul de inmatriculare: ");
    scanf("%s", nr_inmatriculare);

    char* categorie = malloc(15 * sizeof(char));
    printf("Introduceti categoria masinii: ");
    scanf("%s", categorie);

    struct_masina* masina = creeaza_masina(id, model, nr_inmatriculare, categorie, inchiriata);
    const int ret = service_adauga_element(serv, masina);
    if (ret == -1) {
        printf("App: Masina are date invalide!\n");
        destroy_masina(masina);
        return;
    }
    if (ret == -6) {
        printf("App: Nu s-a putut adauga masina(id-ul trebuie sa fie unic, iar categoria sa fie suv,sport sau mini!\n");
        destroy_masina(masina);
        return;
    }
    printf("App: Masina adaugata cu succes!\n");
}


void ui_modifica_masina(const service_masina* serv) {
    int id;
    printf("Introduceti id-ul masinii: ");
    scanf("%d", &id);

    int inchiriata;
    printf("Introduceti statusul inchirierii(0/1): ");
    scanf("%d", &inchiriata);

    char *model = malloc(15 * sizeof(char));
    printf("Introduceti modelul masinii: ");
    scanf("%s", model);


    char* nr_inmatriculare = malloc(15 * sizeof(char));
    printf("Introduceti numarul de inmatriculare: ");
    scanf("%s", nr_inmatriculare);

    char* categorie = malloc(15 * sizeof(char));
    printf("Introduceti categoria masinii: ");
    scanf("%s", categorie);

    struct_masina* masina = creeaza_masina(id, model, nr_inmatriculare, categorie, inchiriata);
    int ret = service_modifica_element(serv, masina);
    if (ret == -1) {
        printf("App: Masina are date invalide!\n");
        destroy_masina(masina);
        return;
    }
    if (ret == -7) {
        printf("App: Nu s-a putut modifica masina(id-ul trebuie sa existe, iar categoria sa fie suv,sport sau mini!\n");
        destroy_masina(masina);
        return;
    }
    printf("Masina modificata cu succes!\n");
}

void ui_cauta_masina(const service_masina* serv) {
    int id;
    printf("Introduceti id-ul masinii: ");
    scanf("%d", &id);
    for (int i = 0; i < serv->repo->numar; i++) {
        if (get_id_masina(serv->repo->lista[i]) == id) {
            ui_afiseaza_masina(serv->repo->lista[i]);
            return;
        }
    }
    printf("App: Masina cu id-ul %d nu a fost gasita!\n", id);
}

void ui_sterge_masina(const service_masina* serv) {
    int id;
    printf("Introduceti id-ul masinii: ");
    scanf("%d", &id);
    int ret = service_sterge_element(serv, id);
    if (ret==-8) {
        printf("App: Nu s-a putut sterge masina!(Ori nu exista ori eroare la dealocare\n");
        return;
    }
    printf("App: Masina stearsa cu succes!\n");
}

void ui_afis(const repository* repo) {
    for (int i = 0; i < repo->numar; i++) {
        ui_afiseaza_masina(repo->lista[i]);
    }
}

void ui_inchiriaza_masina(const service_masina* serv) {
    int id;
    printf("Introduceti id-ul masinii: ");
    scanf("%d", &id);
    int ret = service_inchiriaza_masina(serv, id);
    if (ret == -6) {
        printf("App: Masina nu a putut fi inchiriata!(fie este inchiriata deja fie nu exista o masina cu acest id)\n");
        return;
    }
    printf("App: Masina inchiriata cu succes!\n");
}

void ui_returneaza_masina(const service_masina* serv) {
    int id;
    printf("Introduceti id-ul masinii: ");
    scanf("%d", &id);
    int ret = service_returneaza_masina(serv, id);
    if (ret == -6) {
        printf("App: Masina nu a putut fi returnata!(fie este nu este inchiriata fie nu exista o masina cu acest id)\n");
        return;
    }
    printf("App: Masina returnata cu succes!\n");
}

void ui_vizualizeaza_dupa_categorie(const service_masina* serv) {
    char* categorie = malloc(15 * sizeof(char));
    printf("Introduceti categoria masinii: ");
    scanf("%s", categorie);
    repository* masini_cat = service_vizualizare_dupa_categorie(serv, categorie);
    if (masini_cat==NULL) {
        printf("App: Categorie invalida!\n");
        return;
    }
    if (masini_cat->numar == 0) {
        printf("App: Nu exista masini cu categoria %s!\n", categorie);
        return;
    }
    ui_afis(masini_cat);
    free(categorie);
    repo_destroy(masini_cat);
}

void ui_undo(service_masina* serv) {
    int ret = service_undo(serv);
    if (ret == -99) {
        printf("App: Nu exista operatii salvate pentru undo!\n");
        return;
    }
    printf("App: Undo efectuat cu succes!\n");
}

void ui_redo(service_masina* serv) {
    int ret = service_redo(serv);
    if (ret == -99) {
        printf("App: Nu exista operatii salvate pentru redo!\n");
        return;
    }
    printf("App: Redo efectuat cu succes!\n");
}

void ui_sortare(const service_masina* serv) {
    int crescator;
    printf("Introduceti sa se sorteze crescator(1) sau descrescator(0): ");
    scanf("%d", &crescator);

    int mod;
    printf("Introduceti sa se sorteze dupa categorie(0) sau dupa model(1): ");
    scanf("%d", &mod);
    service_sortare(serv, crescator, mod);
    ui_afis(serv->repo);
}
/// Porneste aplicatia
void run(service_masina* serv) {
    int nr_comenzi = 12;
    char** comenzi = malloc(nr_comenzi * sizeof(char*));
    initializare_comenzi(&nr_comenzi, comenzi);

    printf("nr comenzi: %d\n", nr_comenzi);
    for (int i = 0; i < nr_comenzi; i++) {
        printf("comanda[%d]: %s\n", i, comenzi[i]);
    }

    char* comanda = malloc(15 * sizeof(char));
    while (1) {
        printf(">>> ");
        scanf("%s", comanda);
        switch (id_comanda(nr_comenzi, comenzi, comanda)) {
            case 0:
                ui_adauga_masina(serv);
                break;
            case 1:
                ui_modifica_masina(serv);
                break;
            case 2:
                ui_cauta_masina(serv);
                break;
            case 3:
                ui_sterge_masina(serv);
                break;
            case 4:
                ui_inchiriaza_masina(serv);
                break;
            case 5:
                ui_returneaza_masina(serv);
                break;
            case 6:
                ui_vizualizeaza_dupa_categorie(serv);
                break;
            case 7:
                ui_sortare(serv);
                break;
            case 8:
                ui_afis(serv->repo);
                break;
            case 9:
                ui_undo(serv);
                break;
            case 10:
                ui_redo(serv);
                break;
            case 11:
                //dealocare memorie
                free(comanda);
                service_destroy(serv);
                for (int i=0; i<nr_comenzi; i++) {
                    free(comenzi[i]);
                }
                free(comenzi);
                return;
            default:
                printf("App: Comanda invalida!\n");
                break;
        }


    }
}