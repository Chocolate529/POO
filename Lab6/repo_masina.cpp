//
// Created by lupse on 4/7/2025.
//
#include "repo_masina.h"

void MasinaRepo::adauga(const Masina& m) {
    for (const auto& masina : masini)
        if (masina == m)
            throw std::runtime_error("Masina deja existenta.");
    masini.push_back(m);
}

void MasinaRepo::sterge(const std::string& nrInmatriculare) {
    for (auto it = masini.begin(); it != masini.end(); ++it) {
        if (it->getNrInmatriculare() == nrInmatriculare) {
            masini.erase(it);
            return;
        }
    }
    throw std::runtime_error("Masina inexistenta.");
}

void MasinaRepo::modifica(const Masina& m) {
    for (auto& masina : masini) {
        if (masina == m) {
            masina.setProducator(m.getProducator());
            masina.setModel(m.getModel());
            masina.setTip(m.getTip());
            return;
        }
    }
    throw std::runtime_error("Masina inexistenta.");
}

const Masina& MasinaRepo::cauta(const std::string& nrInmatriculare) const {
    for (const auto& masina : masini)
        if (masina.getNrInmatriculare() == nrInmatriculare)
            return masina;
    throw std::runtime_error("Masina inexistenta.");
}

const std::vector<Masina>& MasinaRepo::getAll() const {
    return masini;
}
