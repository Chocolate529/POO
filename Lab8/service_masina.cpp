//
// Created by lupse on 4/7/2025.
//
#include "service_masina.h"

#include <algorithm>
using std::copy_if;
using std::sort;
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
//
// const Masina& MasinaService::cautaMasinaByIndex(int index) const {
//     return repo.cautaIndex(index);
// }

const std::vector<Masina>& MasinaService::getAllMasini() const {
    return repo.getAll();
}

std::vector<Masina> MasinaService::getFilteredMasiniByProducator(const std::string& producator) const {
    std::vector Masini{getAllMasini()};
    std::vector<Masina> filteredMasini;
    copy_if(std::begin(Masini), std::end(Masini), std::back_inserter(filteredMasini),
        [&producator](const Masina& m) {
            return m.getProducator() == producator;
    });
    return filteredMasini;
}

std::vector<Masina> MasinaService::getFilteredMasiniByTip(const std::string& tip) const {
    std::vector Masini{getAllMasini()};
    std::vector<Masina> filteredMasini;
    copy_if(std::begin(Masini), std::end(Masini), std::back_inserter(filteredMasini),
        [&tip](const Masina& m) {
            return m.getTip() == tip;
    });
    return filteredMasini;
}

std::vector<Masina> MasinaService::sorteazaMasini(bool (*cmp)(const Masina&, const Masina&)) const {
    std::vector sortedList{getAllMasini()};
    sort(std::begin(sortedList), std::end(sortedList), cmp);
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

std::vector<Masina> MasinaService::sorteazaMasiniNrInmatriculare() const {
    return sorteazaMasini(cmpNrInmatriculare);
}
std::vector<Masina> MasinaService::sorteazaMasiniTip() const {
    return sorteazaMasini(cmpTip);
}
std::vector<Masina> MasinaService::sorteazaMasiniProducatorModel() const {
    return sorteazaMasini(cmpProducatorModel);
}