//
// Created by lupse on 4/8/2025.
//
#include "teste.h"
#include "list.h"
#include <iostream>

// ------------------ Test pentru Domain ------------------

void Teste::testMasina() {
    Masina m("B123XYZ", "Toyota", "Corolla", "Sedan");

    // Testăm getterele
    assert(m.getNrInmatriculare() == "B123XYZ");
    assert(m.getProducator() == "Toyota");
    assert(m.getModel() == "Corolla");
    assert(m.getTip() == "Sedan");

    // Testăm setterele
    m.setProducator("Honda");
    m.setModel("Civic");
    m.setTip("Hatchback");

    assert(m.getProducator() == "Honda");
    assert(m.getModel() == "Civic");
    assert(m.getTip() == "Hatchback");

    std::cout << "Test Masina passed!\n";
}

// ------------------ Test pentru Repository ------------------

void Teste::testMasinaRepo() {
    MasinaRepo repo;

    Masina m1("B123XYZ", "Toyota", "Corolla", "Sedan");
    Masina m2("B456ABC", "Honda", "Civic", "Hatchback");

    // Adăugăm mașini în repo
    repo.adauga(m1);
    repo.adauga(m2);

    // Verificăm dacă mașinile sunt adăugate corect
    assert(repo.getAll().getSize() == 2);

    // Căutăm o mașină existentă
    const Masina& found = repo.cauta("B123XYZ");
    assert(found.getNrInmatriculare() == "B123XYZ");

    // Căutăm o mașină inexistentă (ar trebui să arunce excepție)
    try {
        repo.cauta("X999XXX");
        assert(false && "Excepția nu a fost aruncată pentru cautarea unei mașini inexistente");
    } catch (const std::runtime_error& e) {
        assert(std::string(e.what()) == "Masina inexistenta.");
    }

    // Adăugăm din nou mașina m1, ceea ce ar trebui să arunce o excepție
    try {
        repo.adauga(m1);
        assert(false && "Excepția nu a fost aruncată pentru adăugarea unei mașini deja existente");
    } catch (const std::runtime_error& e) {
        assert(std::string(e.what()) == "Masina deja existenta.");
    }

    // Modificăm o mașină existentă
    m2.setProducator("Ford");
    repo.modifica(m2);
    const Masina& modified = repo.cauta("B456ABC");
    assert(modified.getProducator() == "Ford");

    // Modificăm o mașină inexistentă (ar trebui să arunce excepție)
    Masina m3("X999XXX", "BMW", "X5", "SUV");
    try {
        repo.modifica(m3);
        assert(false && "Excepția nu a fost aruncată pentru modificarea unei mașini inexistente");
    } catch (const std::runtime_error& e) {
        assert(std::string(e.what()) == "Masina inexistenta.");
    }

    // Ștergem o mașină existentă
    repo.sterge("B123XYZ");
    assert(repo.getAll().getSize() == 1);

    // Ștergem o mașină inexistentă (ar trebui să arunce excepție)
    try {
        repo.sterge("B123XYZ");
        assert(false && "Excepția nu a fost aruncată pentru ștergerea unei mașini inexistente");
    } catch (const std::runtime_error& e) {
        assert(std::string(e.what()) == "Masina inexistenta.");
    }

    std::cout << "Test MasinaRepo passed!\n";
}

// ------------------ Test pentru Service ------------------

void Teste::testMasinaService() {
    MasinaRepo repo;
    MasinaService service(repo);

    Masina m1("B123XYZ", "Toyota", "Corolla", "Sedan");
    Masina m2("B456ABC", "Honda", "Civic", "Hatchback");

    // Adăugăm mașini
    service.adaugaMasina("B123XYZ", "Toyota", "Corolla", "Sedan");
    service.adaugaMasina("B456ABC", "Honda", "Civic", "Hatchback");

    // Verificăm dacă mașinile sunt adăugate corect
    assert(service.getAllMasini().getSize() == 2);

    // Căutăm mașina
    const Masina& found = service.cautaMasina("B123XYZ");
    assert(found.getNrInmatriculare() == "B123XYZ");

    // Modificăm o mașină
    service.modificaMasina("B456ABC", "Ford", "Focus", "Sedan");
    const Masina& modified = service.cautaMasina("B456ABC");
    assert(modified.getProducator() == "Ford");

    // Ștergem o mașină
    service.stergeMasina("B123XYZ");
    assert(service.getAllMasini().getSize() == 1);

    std::cout << "Test MasinaService passed!\n";
}


// ------------------ Funcție principală pentru a rula testele ------------------

void Teste::runTests() {
    testMasina();
    testMasinaRepo();
    testMasinaService();
    std::cout << "Toate testele au trecut cu succes!\n";
}
