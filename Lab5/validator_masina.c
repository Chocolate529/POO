#include <string.h>
#include "validator_masina.h"

int validator_masina(const struct_masina* masina) {
    if (masina->id < 0)
        return -1;
    if (strlen(masina->model) < 1)
        return -1;
    if (strlen(masina->nr_inmatriculare) < 1)
        return -1;
    if (strcmp(masina->categorie, "mini") != 0 && strcmp(masina->categorie, "sport") != 0 && strcmp(masina->categorie, "suv") != 0)
        return -1;
    if (masina->inchiriata != 0 && masina->inchiriata != 1)
        return -1;
    return 0;
}
