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
    if (std::find_if(masiniSpalatorie.begin(), masiniSpalatorie.end(),
       [&masina](const Masina& m) {
           return masina == m;
       }) == masiniSpalatorie.end()) {
        masiniSpalatorie.push_back(masina);
        notifyObservers();
       }
}

void ServiceSpalatorie::golesteLista() {
    masiniSpalatorie.clear();
    notifyObservers();
}

void ServiceSpalatorie::exportCSV(const std::string& fileName) const {
    std::ofstream out(fileName+".csv");
    for (const auto& masina : masiniSpalatorie) {
        out << masina.getNrInmatriculare() <<',' << masina.getProducator() <<
            ','<< masina.getModel() << ','<< masina.getTip()<< std::endl;
    }
}

void ServiceSpalatorie::generareLista(int nrTotal) {
    std::vector masini{srv.getAllMasini()};
    if (masini.empty()) {
        throw ServiceException("Nu exista masini!");
    }
    std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution<int> dis{0, static_cast<int>(masini.size())-1};
    if (masini.size() == nrTotal) {
        masiniSpalatorie.clear();

        const auto seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(masini.begin(), masini.end(), std::default_random_engine(seed));
        masiniSpalatorie = masini;
        notifyObservers();
    } else if (masini.size() > nrTotal) {
        masiniSpalatorie.clear();

        while (nrMasini() < nrTotal) {
            const int rndNr = dis(gen);
            const Masina& masina = masini[rndNr];
            if (std::find(masiniSpalatorie.begin(), masiniSpalatorie.end(),masina) == masiniSpalatorie.end()) {
                if (std::find_if(masiniSpalatorie.begin(), masiniSpalatorie.end(),
                [&masina](const Masina& m) {
                     return masina == m;
                }) == masiniSpalatorie.end()) {
                    masiniSpalatorie.push_back(masini[rndNr]);
                }
            }
        }
        notifyObservers();
    } else {
        throw ServiceException("Nu exista masini destule!");
    }
}

void ServiceSpalatorie::exportHTML(const std::string& fileName) const {
    std::ofstream out(fileName+".html");
    out << "<!DOCTYPE html>\n<html>\n<head>\n<title>Masini Spalatorie</title>\n";
    out << "<style>table {border-collapse: collapse;} th, td {border: 1px solid black; padding: 8px;}</style>\n";
    out << "</head>\n<body>\n";
    out << "<h1>Lista masini spalatorie</h1>\n";
    out << "<table>\n";
    out << "<tr><th>Nr. Inmatriculare</th><th>Producator</th><th>Model</th><th>Tip</th></tr>\n";

    for (const auto& masina : masiniSpalatorie) {
        out << "<tr>";
        out << "<td>" << masina.getNrInmatriculare() << "</td>";
        out << "<td>" << masina.getProducator() << "</td>";
        out << "<td>" << masina.getModel() << "</td>";
        out << "<td>" << masina.getTip() << "</td>";
        out << "</tr>\n";
    }

    out << "</table>\n</body>\n</html>";
}

int ServiceSpalatorie::nrMasini() const {
    return static_cast<int>(masiniSpalatorie.size());
}

std::vector<Masina> ServiceSpalatorie::getAllMasini() const {
    return masiniSpalatorie;
}