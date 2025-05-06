//
// Created by lupse on 4/7/2025.
//
#include "console_ui.h"
#include <iostream>

void MasinaUI::adaugaUI() {
    std::string nr, prod, mod, tip;
    std::cout << "Nr inmatriculare: "; std::cin >> nr;
    std::cout << "Producator: "; std::cin >> prod;
    std::cout << "Model: "; std::cin >> mod;
    std::cout << "Tip: "; std::cin >> tip;
    try {
        service.adaugaMasina(nr, prod, mod, tip);
    } catch (const std::exception& e) {
        std::cout << "Eroare: " << e.what() << "\n";
    }
}

void MasinaUI::stergeUI() {
    std::string nr;
    std::cout << "Nr inmatriculare: "; std::cin >> nr;
    try {
        service.stergeMasina(nr);
    } catch (const std::exception& e) {
        std::cout << "Eroare: " << e.what() << "\n";
    }
}

void MasinaUI::modificaUI() {
    std::string nr, prod, mod, tip;
    std::cout << "Nr inmatriculare: "; std::cin >> nr;
    std::cout << "Noul producator: "; std::cin >> prod;
    std::cout << "Noul model: "; std::cin >> mod;
    std::cout << "Noul tip: "; std::cin >> tip;
    try {
        service.modificaMasina(nr, prod, mod, tip);
    } catch (const std::exception& e) {
        std::cout << "Eroare: " << e.what() << "\n";
    }
}

void MasinaUI::cautaUI() {
    std::string nr;
    std::cout << "Nr inmatriculare: "; std::cin >> nr;
    try {
        const auto& m = service.cautaMasina(nr);
        std::cout << m.getNrInmatriculare() << " " << m.getProducator()
                  << " " << m.getModel() << " " << m.getTip() << "\n";
    } catch (const std::exception& e) {
        std::cout << "Eroare: " << e.what() << "\n";
    }
}

void MasinaUI::afiseazaToate() const {
    for (const auto& m : service.getAllMasini()) {
        std::cout << m.getNrInmatriculare() << " " << m.getProducator()
                  << " " << m.getModel() << " " << m.getTip() << "\n";
    }
}

void MasinaUI::filtrareUI() const {
    std::vector<Masina> filteredMasini;
    int cmd;
    std::cout << "1.Dupa Producator\n2.Dupa Tip\n0.Exit\n"; std::cin >> cmd;
    switch (cmd) {
        case 1: {
            std::string producator;
            std::cout << "Producator: "; std::cin >> producator;
            filteredMasini = service.getFilteredMasiniByProducator(producator);
            for (const auto& m : filteredMasini) {
                std::cout << m.getNrInmatriculare() << " " << m.getProducator()
                          << " " << m.getModel() << " " << m.getTip() << "\n";
            }
            break;
        }
        case 2: {
            std::string tip;
            std::cout << "Tip: "; std::cin >> tip;
            filteredMasini = service.getFilteredMasiniByTip(tip);
            for (const auto& m : filteredMasini) {
                std::cout << m.getNrInmatriculare() << " " << m.getProducator()
                          << " " << m.getModel() << " " << m.getTip() << "\n";
            }
            break;
        }
        case 0:
            return;
        default: std::cout << "Comanda invalida!\n";

    }
}

void MasinaUI::sortareUI() const {
    std::vector<Masina> sortedMasini;
    int cmd;
    std::cout << "1.Dupa NrInmatriculare\n2.Dupa Tip\n3.Dupa Producator+model\n0.Exit\n";
    std::cout << "\nEnter your command: "; std::cin >> cmd;
    switch (cmd) {
        case 1: {
            sortedMasini = service.sorteazaMasiniNrInmatriculare();
            for (const auto& m : sortedMasini) {
                std::cout << m.getNrInmatriculare() << " " << m.getProducator()
                          << " " << m.getModel() << " " << m.getTip() << "\n";
            }
            break;
        }
        case 2: {
            sortedMasini = service.sorteazaMasiniTip();
            for (const auto& m : sortedMasini) {
                std::cout << m.getNrInmatriculare() << " " << m.getProducator()
                          << " " << m.getModel() << " " << m.getTip() << "\n";
            }
            break;
        }
        case 3: {
            sortedMasini = service.sorteazaMasiniProducatorModel();
            for (const auto& m : sortedMasini) {
                std::cout << m.getNrInmatriculare() << " " << m.getProducator()
                          << " " << m.getModel() << " " << m.getTip() << "\n";
            }
            break;
        }
        case 0:
            return;
        default: std::cout << "Comanda invalida!\n";

    }
}

void MasinaUI::spalatorieUI() const {
    std::cout << "\n1.Adauga in lista\n2.Goleste lista\n3.Genereaza lista\n4.Export CSV\n0.Exit\n";
    int cmd;
    std::cout << "\nEnter your command: "; std::cin >> cmd;
    switch (cmd) {
        case 1: {
            std::string nr;
            std::cout << "Nr inmatriculare: "; std::cin >> nr;
            try {
                spalatorie.adaugaMasina(nr);
            } catch (const std::exception& e) {
                std::cout << "Eroare: " << e.what() << "\n";
            }
            break;
        }
        case 2: {
            spalatorie.golesteLista();
            break;
        }
        case 3: {
            int nrTotal;
            std::cout<<"Introduceti un numar:"; std::cin >> nrTotal;
            spalatorie.generareLista(nrTotal);
            break;
        }
        case 4: {
            std::string fileName;
            std::cout << "Introduceti un nume de fisier:"; std::cin >> fileName;
            spalatorie.exportCSV(fileName);
            break;
        }
        case 0: return;
        default: std::cout << "Comanda invalida!\n";
    }
}

void MasinaUI::run() {
    while (true) {
        std::cout << "\n1.Adauga\n2.Sterge\n3.Modifica\n4.Cauta\n5.Afiseaza\n6.Filtrare\n7.Sortare\n8.Spalatorie\n0.Exit\n";
        int cmd;
        std::cout << "\nEnter your command: "; std::cin >> cmd;
        switch (cmd) {
            case 1: adaugaUI(); break;
            case 2: stergeUI(); break;
            case 3: modificaUI(); break;
            case 4: cautaUI(); break;
            case 5: afiseazaToate(); break;
            case 6: filtrareUI(); break;
            case 7: sortareUI(); break;
            case 8: spalatorieUI(); break;
            case 0: return;
            default: std::cout << "Comanda invalida!\n";
        }
    }
}
