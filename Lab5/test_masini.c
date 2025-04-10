//
// Created by kevin on 3/23/2025.
//

#include <assert.h>
#include <string.h>
#include "test_masini.h"

#include <stdio.h>
#include <stdlib.h>

#include "domeniu_masina.h"
#include "validator_masina.h"
#include "repo.h"
#include "service_masini.h"

/// Teste pentru functiile din domeniu_masina.c
void test_domeniu_masina() {
    /* --- Test creere masina --- */
    int id=1;
    char* model = malloc(10*sizeof(char));
    strcpy(model, "Nissan");
    char* nr_inmatriculare = malloc(10*sizeof(char));
    strcpy(nr_inmatriculare, "BH07DMY");
    char* categorie = malloc(10*sizeof(char));
    strcpy(categorie, "suv");
    int inchiriata=0;
    struct_masina* masina = creeaza_masina(id, model, nr_inmatriculare, categorie, inchiriata);
    assert(masina->id==1);
    assert(masina->inchiriata==0);
    assert(strcmp(masina->model, model)==0);
    assert(strcmp(masina->nr_inmatriculare, nr_inmatriculare)==0);
    assert(strcmp(masina->categorie, categorie)==0);

    /* --- Teste Getters --- */

    //Test get_id
    assert(get_id_masina(masina)==id);
    //Test get_model
    assert(strcmp(get_model_masina(masina),model)==0);
    //Test get_nr_inmatriculare
    assert(strcmp(get_nr_inmatriculare_masina(masina),nr_inmatriculare)==0);
    //Test get_categorie
    assert(strcmp(get_categorie_masina(masina),categorie)==0);
    //Test get_inchiriata
    assert(get_inchiriata_masina(masina)==inchiriata);

    /* --- Teste Setters --- */

    char* model_nou = malloc(10*sizeof(char));
    strcpy(model_nou, "Ford");
    char* nr_inmatriculare_nou = malloc(10*sizeof(char));
    strcpy(nr_inmatriculare_nou, "CJ19MCR");
    char* categorie_nou = malloc(10*sizeof(char));
    strcpy(categorie_nou, "mini");
    int inchiriata_nou=1;

    //Test set_model
    set_model_masina(masina, model_nou);
    assert(strcmp(get_model_masina(masina),model_nou)==0);

    //Test set_nr_inmatriculare
    set_nr_inmatriculare_masina(masina, nr_inmatriculare_nou);
    assert(strcmp(get_nr_inmatriculare_masina(masina),nr_inmatriculare_nou)==0);

    //Test set_categorie
    set_categorie_masina(masina, categorie_nou);
    assert(strcmp(get_categorie_masina(masina),categorie_nou)==0);

    //Test set_inchiriata
    set_inchiriata_masina(masina, inchiriata_nou);
    assert(get_inchiriata_masina(masina)==inchiriata_nou);

    /* --- Test comparare masini --- */
    int id2=3;
    char* model2 = malloc(10*sizeof(char));
    strcpy(model2, "Ford");
    char* nr_inmatriculare2 = malloc(10*sizeof(char));
    strcpy(nr_inmatriculare2, "banana");
    char* categorie2 = malloc(10*sizeof(char));
    strcpy(categorie2, "mini");
    int inchiriata2=0;
    struct_masina* masina2 = creeaza_masina(id2, model2, nr_inmatriculare2, categorie2, inchiriata2);
    assert(compara_masini(masina, masina2)==0);
    assert(compara_masini(masina, masina)==1);

    /* --- Test copiere masina --- */
    struct_masina* masina_copiata = copiaza_masina(masina);
    assert(compara_masini(masina_copiata, masina)==1);

    destroy_masina(masina);
    destroy_masina(masina2);
    destroy_masina(masina_copiata);
}
/// Teste pentru functiile din validator_masina.c
void test_validator_masina() {
    /* --- Test cu date corecte --- */
    int id_corect=1;
    char* model_corect = malloc(10*sizeof(char));
    strcpy(model_corect, "Nissan");
    char* nr_inmatriculare_corect = malloc(10*sizeof(char));
    strcpy(nr_inmatriculare_corect, "BH07DMY");
    char* categorie_corecta = malloc(10*sizeof(char));
    strcpy(categorie_corecta, "suv");
    int inchiriata_corect=0;
    struct_masina* masina_corecta = creeaza_masina(id_corect, model_corect, nr_inmatriculare_corect, categorie_corecta, inchiriata_corect);
    assert(validator_masina(masina_corecta)==0);
    destroy_masina(masina_corecta);

    /* --- Test cu id gresit --- */
    int id_gresit=-1;
    char* model_id = malloc(10*sizeof(char));
    strcpy(model_id, "Nissan");
    char* nr_inmatriculare_id = malloc(10*sizeof(char));
    strcpy(nr_inmatriculare_id, "BH07DMY");
    char* categorie_id = malloc(10*sizeof(char));
    strcpy(categorie_id, "suv");
    int inchiriata_id=0;
    struct_masina* masina_gresita_id = creeaza_masina(id_gresit, model_id, nr_inmatriculare_id, categorie_id, inchiriata_id);
    assert(validator_masina(masina_gresita_id)==-1);
    destroy_masina(masina_gresita_id);

    /* --- Test cu model gresit --- */
    int id_model = 1;
    char* model_gresit = malloc(10*sizeof(char));
    strcpy(model_gresit, "");
    char* nr_inmatriculare_model = malloc(10*sizeof(char));
    strcpy(nr_inmatriculare_model, "BH07DMY");
    char* categorie_model = malloc(10*sizeof(char));
    strcpy(categorie_model, "suv");
    int inchiriata_model=0;
    struct_masina* masina_gresita_model = creeaza_masina(id_model, model_gresit, nr_inmatriculare_model, categorie_model, inchiriata_model);
    assert(validator_masina(masina_gresita_model)==-1);
    destroy_masina(masina_gresita_model);

    /* --- Test cu numar de inmatriculare gresit --- */
    int id_nr_inmatriculare = 1;
    char* model_nr_inmatriculare = malloc(10*sizeof(char));
    strcpy(model_nr_inmatriculare, "Nissan");
    char* nr_inmatriculare_gresit = malloc(10*sizeof(char));
    strcpy(nr_inmatriculare_gresit, "");
    char* categorie_nr_inmatriculare = malloc(10*sizeof(char));
    strcpy(categorie_nr_inmatriculare, "suv");
    int inchiriata_nr_inmatriculare = 0;
    struct_masina* masina_gresita_nr_inmatriculare = creeaza_masina(id_nr_inmatriculare, model_nr_inmatriculare, nr_inmatriculare_gresit, categorie_nr_inmatriculare, inchiriata_nr_inmatriculare);
    assert(validator_masina(masina_gresita_nr_inmatriculare)==-1);
    destroy_masina(masina_gresita_nr_inmatriculare);

    /* --- Test cu categorie gresit --- */
    int id_categorie = 1;
    char* model_categorie = malloc(10*sizeof(char));
    strcpy(model_categorie, "Nissan");
    char* nr_inmatriculare_categorie = malloc(10*sizeof(char));
    strcpy(nr_inmatriculare_categorie, "BH07DMY");
    char* categorie_gresita = malloc(10*sizeof(char));
    strcpy(categorie_gresita, "supercar");
    int inchiriata_categorie=5;
    struct_masina* masina_gresita_categorie = creeaza_masina(id_categorie, model_categorie, nr_inmatriculare_categorie, categorie_gresita, inchiriata_categorie);
    assert(validator_masina(masina_gresita_categorie)==-1);
    destroy_masina(masina_gresita_categorie);

    /* --- Test cu status inchiriere gresit --- */
    int id_inchiriata = 1;
    char* model_inchiriata = malloc(10*sizeof(char));
    strcpy(model_inchiriata, "Nissan");
    char* nr_inmatriculare_inchiriata = malloc(10*sizeof(char));
    strcpy(nr_inmatriculare_inchiriata, "BH07DMY");
    char* categorie_inchiriata = malloc(10*sizeof(char));
    strcpy(categorie_inchiriata, "suv");
    int inchiriata_gresit = 2;
    struct_masina* masina_gresita_inchiriata = creeaza_masina(id_inchiriata, model_inchiriata, nr_inmatriculare_inchiriata, categorie_inchiriata, inchiriata_gresit);
    assert(validator_masina(masina_gresita_inchiriata)==-1);
    destroy_masina(masina_gresita_inchiriata);

}
/// Teste pentru functiile din repo_masini.c
void test_repo_masini() {
    repository* repo_masini = repo_creeaza((void*)destroy_masina, (void*)get_id_masina, (void*)copiaza_masina);

    /* --- Teste adaugare --- */

    //Test adaugare fara alocare
    int id1=0;
    char* model1 = malloc(10*sizeof(char));
    strcpy(model1, "Nissan");
    char* nr_inmatriculare1 = malloc(10*sizeof(char));
    strcpy(nr_inmatriculare1, "BH07DMY");
    char* categorie1 = malloc(10*sizeof(char));
    strcpy(categorie1, "suv");
    int inchiriata1=0;
    struct_masina* masina1 = creeaza_masina(id1, model1, nr_inmatriculare1, categorie1, inchiriata1);
    assert(repo_masini->numar==0);
    repo_adauga_element(repo_masini, masina1);
    assert(repo_masini->numar==1);
    assert(compara_masini(repo_masini->lista[0], masina1)==1);

    //Test adaugare cu alocare
    int id2=2;
    char* model2 = malloc(10*sizeof(char));
    strcpy(model2, "Opel");
    char* nr_inmatriculare2 = malloc(10*sizeof(char));
    strcpy(nr_inmatriculare2, "CJ69XXX");
    char* categorie2 = malloc(10*sizeof(char));
    strcpy(categorie2, "mini");
    int inchiriata2=0;
    struct_masina* masina2 = creeaza_masina(id2, model2, nr_inmatriculare2, categorie2, inchiriata2);
    assert(repo_masini->numar==1);
    repo_adauga_element(repo_masini, masina2);
    assert(repo_masini->numar==2);
    assert(compara_masini(repo_masini->lista[1], masina2)==1);

    /* --- Teste cautare --- */

    //Test cautare cu masina existenta
    struct_masina* masina_cautata = repo_cauta_element(repo_masini, get_id_masina(masina1));
    assert(compara_masini(masina_cautata, masina1)==1);

    //Test cautare cu masina inexistenta
    struct_masina* masina_cautata2 = repo_cauta_element(repo_masini, 3);
    assert(masina_cautata2==NULL);

    /* --- Test modificare --- */
    int id4=2;
    char* model4 = malloc(10*sizeof(char));
    strcpy(model4, "Suzuki");
    char* nr_inmatriculare4 = malloc(10*sizeof(char));
    strcpy(nr_inmatriculare4, "HR00AAA");
    char* categorie4 = malloc(10*sizeof(char));
    strcpy(categorie4, "sport");
    int inchiriata4=0;
    struct_masina* masina4 = creeaza_masina(id4, model4, nr_inmatriculare4, categorie4, inchiriata4);
    repo_modifica_element(repo_masini, masina4);
    assert(compara_masini(repo_masini->lista[1], masina4)==1);

    /* --- Teste stergere ---*/

    int id5=3;
    char* model5 = malloc(10*sizeof(char));
    strcpy(model5, "Suzuki");
    char* nr_inmatriculare5 = malloc(10*sizeof(char));
    strcpy(nr_inmatriculare5, "HR00AAA");
    char* categorie5 = malloc(10*sizeof(char));
    strcpy(categorie5, "sport");
    int inchiriata5=0;
    struct_masina* masina5 = creeaza_masina(id5, model5, nr_inmatriculare5, categorie5, inchiriata5);
    repo_adauga_element(repo_masini, masina5);
    //Test stergere fara dealocare
    assert(repo_masini->numar==3);
    repo_sterge_element(repo_masini, get_id_masina(masina1));
    assert(repo_masini->numar==2);

    //Test stergere cu dealocare
    repo_sterge_element(repo_masini, get_id_masina(masina4));
    assert(repo_masini->numar==1);
    repo_sterge_element(repo_masini, get_id_masina(masina5));
    assert(repo_masini->numar==0);

    /* --- Test verifica_existenta_dupa_id --- */
    repo_adauga_element(repo_masini, masina_cautata);
    assert(repo_verifica_existenta_element_dupa_id(repo_masini, get_id_masina(masina_cautata))==0);
    assert(repo_verifica_existenta_element_dupa_id(repo_masini,5)==-2);
    repo_destroy(repo_masini);
}
/// Teste pentru functiile din service_masini.c
void teste_service_masini(){
    repository* repo_masini = repo_creeaza((void*)destroy_masina, (void*)get_id_masina, (void*)copiaza_masina);
    service_masina* serv_masini = service_creeaza(repo_masini, (void*)validator_masina, (void*)repo_destroy, (void*)repo_copie_repo);

    /* --- Teste adaugare element --- */

    //Test adaugare element valid cu id unic
    int id1=1;
    char* model1 = malloc(10*sizeof(char));
    strcpy(model1, "Opel");
    char* nr_inmatriculare1 = malloc(10*sizeof(char));
    strcpy(nr_inmatriculare1, "BH07DMY");
    char* categorie1 = malloc(10*sizeof(char));
    strcpy(categorie1, "mini");
    int inchiriata1 = 1;
    struct_masina* masina1 = creeaza_masina(id1, model1, nr_inmatriculare1, categorie1, inchiriata1);
    assert(serv_masini->repo->numar==0);
    assert(service_adauga_element(serv_masini, masina1)==0);
    assert(serv_masini->repo->numar==1);
    assert(compara_masini(serv_masini->repo->lista[0], masina1) == 1);
    //test undo si redo
    service_undo(serv_masini);
    assert(service_undo(serv_masini)==-99);
    assert(serv_masini->repo->numar==0);
    service_redo(serv_masini);
    assert(service_redo(serv_masini)==-99);
    assert(serv_masini->repo->numar==1);

    //Test adaugare element valid fara id unic
    assert(service_adauga_element(serv_masini, masina1)==-6);
    assert(serv_masini->repo->numar==1);

    //Test adaugare element invalid
    int id2=-1;
    char* model2 = malloc(10*sizeof(char));
    strcpy(model2, "");
    char* nr_inmatriculare2 = malloc(10*sizeof(char));
    strcpy(nr_inmatriculare2, "");
    char* categorie2 = malloc(10*sizeof(char));
    strcpy(categorie2, "");
    int inchiriata2 = 2;
    struct_masina* masina2 = creeaza_masina(id2, model2, nr_inmatriculare2, categorie2, inchiriata2);
    assert(serv_masini->repo->numar==1);
    assert(service_adauga_element(serv_masini, masina2)==-1);
    assert(serv_masini->repo->numar==1);
    destroy_masina(masina2);

    /* --- Teste modifica element --- */

    //Test modificare element existent cu element valid
    int id3=1;
    char* model3 = malloc(10*sizeof(char));
    strcpy(model3, "Ford");
    char* nr_inmatriculare3 = malloc(10*sizeof(char));
    strcpy(nr_inmatriculare3, "BV99BBB");
    char* categorie3 = malloc(10*sizeof(char));
    strcpy(categorie3, "sport");
    int inchiriata3 = 0;
    struct_masina* masina3 = creeaza_masina(id3, model3, nr_inmatriculare3, categorie3, inchiriata3);
    assert(service_modifica_element(serv_masini, masina3)==0);
    assert(compara_masini(serv_masini->repo->lista[0], masina3) == 1);

    //Test modificare element existent cu element invalid
    int id4=1;
    char* model4 = malloc(10*sizeof(char));
    strcpy(model4, "");
    char* nr_inmatriculare4 = malloc(10*sizeof(char));
    strcpy(nr_inmatriculare4, "");
    char* categorie4 = malloc(10*sizeof(char));
    strcpy(categorie4, "");
    int inchiriata4 = 3;
    struct_masina* masina4 = creeaza_masina(id4, model4, nr_inmatriculare4, categorie4, inchiriata4);
    assert(service_modifica_element(serv_masini, masina4)==-1);
    destroy_masina(masina4);

    //Test modificare element inexistent
    int id5=5;
    char* model5 = malloc(10*sizeof(char));
    strcpy(model5, "Porche");
    char* nr_inmatriculare5 = malloc(10*sizeof(char));
    strcpy(nr_inmatriculare5, "MM90BAI");
    char* categorie5 = malloc(10*sizeof(char));
    strcpy(categorie5, "suv");
    int inchiriata5 = 1;
    struct_masina* masina5 = creeaza_masina(id5, model5, nr_inmatriculare5, categorie5, inchiriata5);
    assert(service_modifica_element(serv_masini, masina5)==-7);
    destroy_masina(masina5);

    /* --- Teste cautare element --- */

    //Test cautare element existent
    struct_masina* masina6 = service_cauta_element(serv_masini, id3);
    assert(compara_masini(masina6, masina3)==1);
    destroy_masina(masina6);

    //Test cautare element inexistent
    struct_masina* masina7 = service_cauta_element(serv_masini, id5);
    assert(masina7==NULL);

    /* --- Teste stergere element --- */

    //Test stergere element existent
    assert(serv_masini->repo->numar==1);
    assert(service_sterge_element(serv_masini, id3)==0);
    assert(serv_masini->repo->numar==0);
    //Test stergere element inexistent
    assert(serv_masini->repo->numar==0);
    assert(service_sterge_element(serv_masini, id3)==-8);
    assert(serv_masini->repo->numar==0);

    /* --- Teste inchiriere masina --- */

    //Test inchiriere masina existenta neinchiriata
    int id8=1;
    char* model8 = malloc(10*sizeof(char));
    strcpy(model8, "Opel");
    char* nr_inmatriculare8 = malloc(10*sizeof(char));
    strcpy(nr_inmatriculare8, "BH07DMY");
    char* categorie8 = malloc(10*sizeof(char));
    strcpy(categorie8, "mini");
    int inchiriata8 = 0;
    struct_masina* masina8 = creeaza_masina(id8, model8, nr_inmatriculare8, categorie8, inchiriata8);
    service_adauga_element(serv_masini, masina8);
    assert(get_inchiriata_masina(serv_masini->repo->lista[0])==inchiriata8);
    service_inchiriaza_masina(serv_masini, id8);
    assert(get_inchiriata_masina(serv_masini->repo->lista[0])==1);

    //Test inchiriere masina existenta inchiriata
    assert(service_inchiriaza_masina(serv_masini, id8)==-6);

    //Test inchiriere masina inexistenta
    assert(service_inchiriaza_masina(serv_masini, 10)==-6);

    /* --- Teste returnare masina --- */

    //Test returnare masina existenta inchiriata
    assert(get_inchiriata_masina(serv_masini->repo->lista[0])==1);
    assert(service_returneaza_masina(serv_masini, id8)==0);
    assert(get_inchiriata_masina(serv_masini->repo->lista[0])==0);

    //Test returnare masina existenta neinchiriata
    assert(service_returneaza_masina(serv_masini, id8)==-7);

    //Test returnare masina inexistenta
    assert(service_returneaza_masina(serv_masini, 10)==-7);

    service_sterge_element(serv_masini, id8);
    /* --- Teste vizualizare dupa categorie --- */
    int id9=1;
    char* model9 = malloc(10*sizeof(char));
    strcpy(model9, "Opel");
    char* nr_inmatriculare9 = malloc(10*sizeof(char));
    strcpy(nr_inmatriculare9, "BH07DMY");
    char* categorie9 = malloc(10*sizeof(char));
    strcpy(categorie9, "mini");
    int inchiriata9 = 0;
    struct_masina* masina9 = creeaza_masina(id9, model9, nr_inmatriculare9, categorie9, inchiriata9);
    service_adauga_element(serv_masini, masina9);

    int id10=2;
    char* model10 = malloc(10*sizeof(char));
    strcpy(model10, "Ford");
    char* nr_inmatriculare10 = malloc(10*sizeof(char));
    strcpy(nr_inmatriculare10, "SM99DDD");
    char* categorie10 = malloc(10*sizeof(char));
    strcpy(categorie10, "sport");
    int inchiriata10 = 0;
    struct_masina* masina10 = creeaza_masina(id10, model10, nr_inmatriculare10, categorie10, inchiriata10);
    service_adauga_element(serv_masini, masina10);

    int id11=3;
    char* model11 = malloc(10*sizeof(char));
    strcpy(model11, "Nissan");
    char* nr_inmatriculare11 = malloc(10*sizeof(char));
    strcpy(nr_inmatriculare11, "B999XXX");
    char* categorie11 = malloc(10*sizeof(char));
    strcpy(categorie11, "suv");
    int inchiriata11 = 1;
    struct_masina* masina11 = creeaza_masina(id11, model11, nr_inmatriculare11, categorie11, inchiriata11);
    service_adauga_element(serv_masini, masina11);

    char* categorie_invalida = malloc(10*sizeof(char));
    strcpy(categorie_invalida, "supercar");

    //Test vizualizare dupa categorie invalida
    repository* repo_cautat_1 = service_vizualizare_dupa_categorie(serv_masini, categorie_invalida);
    assert(repo_cautat_1==NULL);
    free(categorie_invalida);

    //Test vizualizare dupa categorie 'suv'
    repository* repo_cautat_2 = service_vizualizare_dupa_categorie(serv_masini, categorie11);
    assert(repo_cautat_2!=NULL);
    assert(compara_masini(repo_cautat_2->lista[0], masina11)==1);
    assert(repo_cautat_2->numar==1);
    repo_destroy(repo_cautat_2);

    //Test vizualizare dupa categorie 'mini'
    repository* repo_cautat_3 = service_vizualizare_dupa_categorie(serv_masini, categorie9);
    assert(repo_cautat_3!=NULL);
    assert(compara_masini(repo_cautat_3->lista[0], masina9)==1);
    assert(repo_cautat_3->numar==1);
    repo_destroy(repo_cautat_3);

    //Test vizualizare dupa categorie 'sport'
    repository* repo_cautat_4 = service_vizualizare_dupa_categorie(serv_masini, categorie10);
    assert(repo_cautat_4!=NULL);
    assert(compara_masini(repo_cautat_4->lista[0], masina10)==1);
    assert(repo_cautat_4->numar==1);
    repo_destroy(repo_cautat_4);

    /* --- Teste sortare --- */

    //Test sortare crescatoare dupa categorie
    service_sortare(serv_masini, 1, 0);
    assert(compara_masini(serv_masini->repo->lista[0], masina9)==1);
    assert(compara_masini(serv_masini->repo->lista[1], masina10)==1);
    assert(compara_masini(serv_masini->repo->lista[2], masina11)==1);

    //Test sortare descrescatoare dupa categorie
    service_sortare(serv_masini, 0, 0);
    assert(compara_masini(serv_masini->repo->lista[0], masina11)==1);
    assert(compara_masini(serv_masini->repo->lista[1], masina10)==1);
    assert(compara_masini(serv_masini->repo->lista[2], masina9)==1);

    //Test sortare crescatoare dupa model
    service_sortare(serv_masini, 1, 1);
    assert(compara_masini(serv_masini->repo->lista[0], masina10)==1);
    assert(compara_masini(serv_masini->repo->lista[1], masina11)==1);
    assert(compara_masini(serv_masini->repo->lista[2], masina9)==1);

    //Test sortare descrescatoare dupa model
    service_sortare(serv_masini, 0, 1);
    assert(compara_masini(serv_masini->repo->lista[0], masina9)==1);
    assert(compara_masini(serv_masini->repo->lista[1], masina11)==1);
    assert(compara_masini(serv_masini->repo->lista[2], masina10)==1);


    service_destroy(serv_masini);
}

///Ruleaza toate testele
void runAllTests() {
    test_domeniu_masina();
    test_validator_masina();
    test_repo_masini();
    teste_service_masini();
    printf("Teste rulate cu succes!\n");
}