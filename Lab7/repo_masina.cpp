#include "repo_masina.h"
#include <stdexcept>

// Adăugăm o mașină în lista repo-ului
void MasinaRepo::adauga(const Masina& m) {
    // Verificăm dacă mașina există deja în listă
    for (size_t i = 0; i < masini.getSize(); ++i) {
        if (masini.get(i) == m) {
            throw std::runtime_error("Masina deja existenta.");
        }
    }
    masini.add(m);  // Adăugăm mașina în lista dinamică
}

// Ștergem o mașină după numărul de înmatriculare
void MasinaRepo::sterge(const std::string& nrInmatriculare) {
    for (size_t i = 0; i < masini.getSize(); ++i) {
        if (masini.get(i).getNrInmatriculare() == nrInmatriculare) {
            masini.remove(masini.get(i));  // Ștergem mașina din listă
            return;
        }
    }
    throw std::runtime_error("Masina inexistenta.");
}

// Modificăm detaliile unei mașini
void MasinaRepo::modifica(const Masina& m) const{
    for (size_t i = 0; i < masini.getSize(); ++i) {
        if (masini.get(i) == m) {
            masini.get(i).setProducator(m.getProducator());
            masini.get(i).setModel(m.getModel());
            masini.get(i).setTip(m.getTip());
            return;
        }
    }
    throw std::runtime_error("Masina inexistenta.");
}

// Căutăm o mașină după numărul de înmatriculare
const Masina& MasinaRepo::cauta(const std::string& nrInmatriculare) const{
    for (size_t i = 0; i < masini.getSize(); ++i) {
        if (masini.get(i).getNrInmatriculare() == nrInmatriculare) {
            return masini.get(i);
        }
    }
    throw std::runtime_error("Masina inexistenta.");
}

// Returnăm toate mașinile
const List<Masina>& MasinaRepo::getAll() const {
    return masini;  // Returnăm lista de mașini ca referință constantă
}
