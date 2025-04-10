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
    for (const auto& m : service.getAllMasini()) {
        std::cout << m.getNrInmatriculare() << " " << m.getProducator()
                  << " " << m.getModel() << " " << m.getTip() << "\n";
    }
}

void MasinaUI::run() {
    while (true) {
        std::cout << "\n1.Adauga\n2.Sterge\n3.Modifica\n4.Cauta\n5.Afiseaza\n0.Exit\n";
        int cmd;
        std::cout << "\nEnter your command: "; std::cin >> cmd;
        switch (cmd) {
            case 1: adaugaUI(); break;
            case 2: stergeUI(); break;
            case 3: modificaUI(); break;
            case 4: cautaUI(); break;
            case 5: afiseazaToate(); break;
            case 0: return;
            default: std::cout << "Comanda invalida!\n";
        }
    }
}
