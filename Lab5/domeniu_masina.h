//
// Created by kevin on 3/23/2025.
//


#ifndef DOMENIU_MASINA_H
#define DOMENIU_MASINA_H

///Struct de tip masina cu:
///model,numar inmatriculare si categorie
typedef struct {
    int id;
    char *model;
    char *nr_inmatriculare;
    char *categorie;//mini, sport, suv, etc
    int inchiriata;
}struct_masina;

/* === Operatii === */


/// Creeaza o masina noua
/// @param id: numar natural unic asociat masinii (int)
/// @param model: modelul masinii (char*)
/// @param nr_inmatriculare: numarul de inmatriculare al masinii (char*)
/// @param categorie: categoria masinii (char*)
/// @param inchiriata: statusul inchirierii (int)
/// @return masina cu proprietatile de mai sus (struct_masina*)
struct_masina* creeaza_masina(int id, char* model, char* nr_inmatriculare, char* categorie, int inchiriata);

/// Dealocheaza memoria alocata unei masini
/// @param masina : masina cu id, model, nr_inmatriculare, categorie, inchiriata (struct_masina*)
void destroy_masina(struct_masina* masina);

/// Returneaza pointerul catre o copie a masinii date ca parametru
/// @param masina : pointer catre masina cu id, model, nr_inmatriculare, categorie, inchiriata (struct_masina*)
/// @return : pointer catre copia masinii
struct_masina* copiaza_masina(const struct_masina* masina);

/// Functie ce compara 2 masini
/// @param masina1 : pointer catre masina cu id, model, nr_inmatriculare, categorie, inchiriata (struct_masina*)
/// @param masina2 : pointer catre masina cu id, model, nr_inmatriculare, categorie, inchiriata (struct_masina*)
/// @return 1 daca sunt identice, 0 altfel
int compara_masini(const struct_masina* masina1, const struct_masina* masina2);

/* === Getters === */

/// Returneaza id-ul unic asociat masinii
/// @param masina : masina cu id, model, nr_inmatriculare, categorie, inchiriata (struct_masina*)
/// @return id: id-ul unic asociat masinii (int)
int get_id_masina(const struct_masina* masina);

/// Returneaza modelul masinii
/// @param masina : masina cu id, model, nr_inmatriculare, categorie, inchiriata (struct_masina*)
/// @return model: modelul masinii (char*)
char* get_model_masina(const struct_masina* masina);

/// Returneaza numarul de inmatriculare al masinii
/// @param masina : masina cu id, model, nr_inmatriculare, categorie, inchiriata (struct_masina*)
/// @return nr_inmatriculare: numarul de inmatriculare al masinii (char*)
char* get_nr_inmatriculare_masina(const struct_masina* masina);

/// Returneaza categoria masinii
/// @param masina : masina cu id, model, nr_inmatriculare, categorie, inchiriata (struct_masina*)
/// @return categorie : categoria masinii (char*)
char* get_categorie_masina(const struct_masina* masina);

/// Returneaza 1 daca masina e inchiriata si 0 daca masina nu e inchiriata
/// @param masina: masina cu id, model, nr_inmatriculare, categorie, inchiriata (struct_masina*)
/// @return 1 daca masina e inchiriata si 0 daca masina nu e inchiriata
int get_inchiriata_masina(const struct_masina* masina);

/* === Setters == */

/// Modifica modelul masinii
/// @param masina : masina cu id, model, nr_inmatriculare, categorie, inchiriata (struct_masina*)
/// @param model_nou : noul model al masinii (char*)
void set_model_masina(struct_masina* masina, char* model_nou);

/// Modifica categoria masinii
/// @param masina : masina cu id, model, nr_inmatriculare, categorie, inchiriata (struct_masina*)
/// @param categorie_noua : noua categorie a masinii (char*)
void set_categorie_masina(struct_masina* masina, char* categorie_noua);

/// Modifica numarul de inmatriculare al masinii
/// @param masina : masina cu id, model, nr_inmatriculare, categorie, inchiriata (struct_masina*)
/// @param nr_inmatriculare_nou : nou numar de inmatriculare al masinii (char*)
void set_nr_inmatriculare_masina(struct_masina* masina, char* nr_inmatriculare_nou);

/// Modifica statusul de inchiriere al masinii
/// @param masina : masina cu id, model, nr_inmatriculare, categorie, inchiriata (struct_masina*)
/// @param inchiriata_nou : nou status de inchiriere al masinii (int)
void set_inchiriata_masina(struct_masina* masina, int inchiriata_nou);
#endif //DOMENIU_MASINA_H