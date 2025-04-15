//
// Created by lupse on 4/7/2025.
//
#include "ui.h"
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
    List m{service.getAllMasini()};
    IteratorList<Masina> it = m.begin();
    for (; it.valid(); ++it) {
        std::cout << (*it).getNrInmatriculare() << " " << (*it).getProducator()
                  << " " << (*it).getModel() << " " << (*it).getTip() << "\n";
    }
}

void MasinaUI::filtrareUI() const {
    List<Masina> filteredMasini;
    IteratorList<Masina> it = filteredMasini.begin();
    int cmd;
    std::cout << "1.Dupa Producator\n2.Dupa Tip\n0.Exit\n"; std::cin >> cmd;
    switch (cmd) {
        case 1: {
            std::string producator;
            std::cout << "Producator: "; std::cin >> producator;
            filteredMasini = service.getFilteredMasiniByProducator(producator);
            it.prim();
            for (; it.valid(); ++it) {
                std::cout << (*it).getNrInmatriculare() << " " << (*it).getProducator()
                 << " " << (*it).getModel() << " " << (*it).getTip() << "\n";
            }
            break;
        }
        case 2: {
            std::string tip;
            std::cout << "Tip: "; std::cin >> tip;
            filteredMasini = service.getFilteredMasiniByTip(tip);
            it.prim();
            for (; it.valid(); ++it) {
                std::cout << (*it).getNrInmatriculare() << " " << (*it).getProducator()
                 << " " << (*it).getModel() << " " << (*it).getTip() << "\n";
            }
            break;
        }
        case 0:
            return;
        default: std::cout << "Comanda invalida!\n";

    }
}

void MasinaUI::sortareUI() const {
    List<Masina> sortedMasini;
    IteratorList<Masina> it = sortedMasini.begin();
    int cmd;
    std::cout << "1.Dupa NrInmatriculare\n2.Dupa Tip\n3.Dupa Producator+model\n0.Exit\n"; std::cin >> cmd;
    switch (cmd) {
        case 1: {
            sortedMasini = service.sorteazaMasiniNrInmatriculare();
            it.prim();
            for (; it.valid(); ++it) {
                std::cout << (*it).getNrInmatriculare() << " " << (*it).getProducator()
                 << " " << (*it).getModel() << " " << (*it).getTip() << "\n";
            }
            break;
        }
        case 2: {
            sortedMasini = service.sorteazaMasiniTip();
            it.prim();
            for (; it.valid(); ++it) {
                std::cout << (*it).getNrInmatriculare() << " " << (*it).getProducator()
                 << " " << (*it).getModel() << " " << (*it).getTip() << "\n";
            }
            break;
        }
        case 3: {
            sortedMasini = service.sorteazaMasiniProducatorModel();
            it.prim();
            for (; it.valid(); ++it) {
                std::cout << (*it).getNrInmatriculare() << " " << (*it).getProducator()
                 << " " << (*it).getModel() << " " << (*it).getTip() << "\n";
            }
            break;
        }
        case 0:
            return;
        default: std::cout << "Comanda invalida!\n";

    }
}

void MasinaUI::run() {
    while (true) {
        std::cout << "\n1.Adauga\n2.Sterge\n3.Modifica\n4.Cauta\n5.Afiseaza\n6.Filtrare\n7.Sortare\n0.Exit\n";
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
            case 0: return;
            default: std::cout << "Comanda invalida!\n";
        }
    }
}
