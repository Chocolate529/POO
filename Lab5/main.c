/*
    --- Erori ---

-operatie efectuata cu succes: 0
-erori validare: -1
-erori repo: -id-ul exista in repo: 0 daca ezista si -2 daca nu exista
            -adaugare element: -3
            -modificare element: -4
            -cautare element: NULL
            -stergere element: -5
-erori service:
               - adauga element: -6
               - modifica element: -7
               - cauta element: NULL
               - sterge element: -8
               -inchiriere masina: -9
               -returnare masina: -10
               -vizualizare: NULL
               -sortare: -11
-ui: -comanda invalida: -12
     -tip date invalid: -13
*/

#include "domeniu_masina.h"
#include "repo.h"
#include "service_masini.h"
#include "test_masini.h"
#include "ui.h"
#include "validator_masina.h"

int main(void) {
    runAllTests();
    repository* repo_masina = repo_creeaza((void*)destroy_masina, (void*)get_id_masina, (void*)copiaza_masina);
    service_masina* serv_masina = service_creeaza(repo_masina, (void*)validator_masina, (void*)repo_destroy, (void*)repo_copie_repo);
    run(serv_masina);
    return 0;
}
