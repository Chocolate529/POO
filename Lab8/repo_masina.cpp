#include "repo_masina.h"

#include <algorithm>
#include "exceptii.h"
// Adăugăm o mașină în lista repo-ului
void MasinaRepo::adauga(const Masina& m) {
    // Verificăm dacă mașina există deja în listă
    if (std::find_if(masini.begin(), masini.end(),
        [&m](const Masina& masina) {
            return masina == m;
        }) != masini.end()) {
            throw RepositoryException("Masina deja existenta.");
        }
    masini.push_back(m);  // Adăugăm mașina în lista dinamică
}

// Ștergem o mașină după numărul de înmatriculare
void MasinaRepo::sterge(const std::string& nrInmatriculare) {
    const auto it = std::find_if(masini.begin(), masini.end(),
        [&nrInmatriculare](const Masina& m) {
                return m.getNrInmatriculare() == nrInmatriculare;
        });
    if (it != masini.end()) {
        masini.erase(it);
    } else {
        throw RepositoryException("Masina inexistenta.");
    }
}

// Modificăm detaliile unei mașini
void MasinaRepo::modifica(const Masina& m){
    const auto it = std::find_if(masini.begin(), masini.end(),
        [&m](const Masina& masina) {
            return masina == m;
        });
    if (it != masini.end()) {
            it->setProducator(m.getProducator());
            it->setModel(m.getModel());
            it->setTip(m.getTip());
    } else {
        throw RepositoryException("Masina inexistenta.");

    }
}

// Căutăm o mașină după numărul de înmatriculare
const Masina& MasinaRepo::cauta(const std::string& nrInmatriculare) const{

    auto it = std::find_if(masini.begin(), masini.end(),
        [&nrInmatriculare](const Masina& masina) {
            return masina.getNrInmatriculare() == nrInmatriculare;
        });
    if (it != masini.end()) {
        return *it;
    }
    throw RepositoryException("Masina inexistenta.");
}

// const Masina &MasinaRepo::cautaIndex(int index) const {
//     if (index >= (int)masini.size() || index < 0) {
//         throw RepositoryException("Index inexistenta.");
//     }
//     return masini[index];
// }

// Returnăm toate mașinile
const std::vector<Masina>& MasinaRepo::getAll() const {
    return masini;  // Returnăm lista de mașini ca referință constantă
}
