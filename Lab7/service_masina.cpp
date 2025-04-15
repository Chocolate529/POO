//
// Created by lupse on 4/7/2025.
//
#include "service_masina.h"

void MasinaService::adaugaMasina(const std::string& nr, const std::string& prod,
                                 const std::string& mod, const std::string& tip) const{
    Masina m{nr, prod, mod, tip};
    repo.adauga(m);
}

void MasinaService::stergeMasina(const std::string& nr) const{
    repo.sterge(nr);
}

void MasinaService::modificaMasina(const std::string& nr, const std::string& prod,
                                   const std::string& mod, const std::string& tip) const{
    Masina m{nr, prod, mod, tip};
    repo.modifica(m);
}

const Masina& MasinaService::cautaMasina(const std::string& nr) const {
    return repo.cauta(nr);
}

const List<Masina>& MasinaService::getAllMasini() const {
    return repo.getAll();
}

List<Masina> MasinaService::getFilteredMasiniByProducator(const std::string& producator) const {
    List Masini{getAllMasini()};
    List<Masina> filteredMasini;
    IteratorList it{Masini};

    while (it.valid()) {
        if ((*it).getProducator() == producator) {
            filteredMasini.add(*it);
        }
        ++it;
    }
    return filteredMasini;
}

List<Masina> MasinaService::getFilteredMasiniByTip(const std::string& tip) const {
    List Masini{getAllMasini()};
    List<Masina> filteredMasini;
    IteratorList it{Masini};

    while (it.valid()) {
        if ((*it).getTip() == tip) {
            filteredMasini.add(*it);
        }
        ++it;
    }
    return filteredMasini;
}

List<Masina> MasinaService::sorteazaMasini(bool (*cmp)(const Masina&, const Masina&)) const {
    List sortedList{getAllMasini()};

    for (size_t i = 0; i < sortedList.getSize() - 1; i++) {
        for (size_t j = i + 1; j < sortedList.getSize(); j++) {
            if (!cmp(sortedList.get(i), sortedList.get(j))) {

                Masina aux = sortedList.get(i);
                sortedList.set(i, sortedList.get(j));
                sortedList.set(j, aux);
            }
        }
    }

    return sortedList;
}

bool MasinaService::cmpNrInmatriculare(const Masina& masina1, const Masina& masina2) {
    return masina1.getNrInmatriculare() < masina2.getNrInmatriculare();
}
bool MasinaService::cmpTip(const Masina& masina1, const Masina& masina2){
    return masina1.getTip() < masina2.getTip();
}
bool MasinaService::cmpProducatorModel(const Masina& masina1, const Masina& masina2) {
    if (masina1.getProducator() == masina2.getProducator()) {
        return masina1.getModel() < masina2.getModel();
    }
    return masina1.getProducator() < masina2.getProducator();
}

List<Masina> MasinaService::sorteazaMasiniNrInmatriculare() const {
    return sorteazaMasini(cmpNrInmatriculare);
}
List<Masina> MasinaService::sorteazaMasiniTip() const {
    return sorteazaMasini(cmpTip);
}
List<Masina> MasinaService::sorteazaMasiniProducatorModel() const {
    return sorteazaMasini(cmpProducatorModel);
}