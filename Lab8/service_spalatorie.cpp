//
// Created by lupse on 4/15/2025.
//
#include "service_spalatorie.h"

#include <algorithm>
#include <chrono>

#include "exceptii.h"
#include <random>
void ServiceSpalatorie::adaugaMasina(const std::string &nrInmatriculare) {
    const Masina& masina = srv.cautaMasina(nrInmatriculare);
    masiniSpalatorie.push_back(masina);
}

void ServiceSpalatorie::golesteLista() {
    masiniSpalatorie.clear();
}

void ServiceSpalatorie::exportCSV(const std::string& fileName) const {
    std::ofstream out(fileName);
    for (const auto& masina : masiniSpalatorie) {
        out << masina.getNrInmatriculare() <<',' << masina.getProducator() <<
            ','<< masina.getModel() << ','<< masina.getTip()<< std::endl;
    }
}

void ServiceSpalatorie::generareLista(int nrTotal) {
    masiniSpalatorie.clear();
    std::vector masini{srv.getAllMasini()};
    if (masini.empty()) {
        throw ServiceException("Nu exista masini!");
    }
    std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution<int> dis{0, static_cast<int>(masini.size())-1};
    if (masini.size() == nrTotal) {
        const auto seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(masini.begin(), masini.end(), std::default_random_engine(seed));
        masiniSpalatorie = masini;
    } else if (masini.size() > nrTotal) {
        while (nrMasini() < nrTotal) {
            const int rndNr = dis(gen);
            if (std::find(masiniSpalatorie.begin(), masiniSpalatorie.end(),masini[rndNr]) == masiniSpalatorie.end()) {
                masiniSpalatorie.push_back(masini[rndNr]);
            }
        }
    } else {
        throw ServiceException("Nu exista masini destule!");
    }
}

int ServiceSpalatorie::nrMasini() const {
    return static_cast<int>(masiniSpalatorie.size());
}

