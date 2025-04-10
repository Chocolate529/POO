//
// Created by lupse on 4/7/2025.
//
#include "service_masina.h"

void MasinaService::adaugaMasina(const std::string& nr, const std::string& prod,
                                 const std::string& mod, const std::string& tip) {
    Masina m{nr, prod, mod, tip};
    repo.adauga(m);
}

void MasinaService::stergeMasina(const std::string& nr) {
    repo.sterge(nr);
}

void MasinaService::modificaMasina(const std::string& nr, const std::string& prod,
                                   const std::string& mod, const std::string& tip) {
    Masina m{nr, prod, mod, tip};
    repo.modifica(m);
}

const Masina& MasinaService::cautaMasina(const std::string& nr) const {
    return repo.cauta(nr);
}

const std::vector<Masina>& MasinaService::getAllMasini() const {
    return repo.getAll();
}
