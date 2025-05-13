//
// Created by lupse on 4/8/2025.
//
#include "teste.h"
#include "list.h"
#include <iostream>
#include <vector>
#include "service_spalatorie.h"
#include "repo_masina.h"
#include "service_masina.h"
#include <cassert>
#include <fstream>
#include "exceptii.h"

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
    assert(repo.getAll().size() == 2);

    // Căutăm o mașină existentă
    const Masina& found = repo.cauta("B123XYZ");
    assert(found.getNrInmatriculare() == "B123XYZ");

    // Căutăm o mașină inexistentă (ar trebui să arunce excepție)
    try {
        auto& dump = repo.cauta("X999XXX");
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
    assert(repo.getAll().size() == 1);

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
    service.adaugaMasina("B567DEF", "Ford", "Focus", "SUV");
    service.adaugaMasina("B678HIJ", "Bmw", "Seria5", "Coupe");
    service.adaugaMasina("B899KLM", "Dacia", "Papuc", "Pickup");

    // Verificăm dacă mașinile sunt adăugate corect
    assert(service.getAllMasini().size() == 5);

    // Căutăm mașina
    const Masina& found = service.cautaMasina("B123XYZ");
    assert(found.getNrInmatriculare() == "B123XYZ");

    // Modificăm o mașină
    service.modificaMasina("B456ABC", "Ford", "Focus", "Sedan");
    const Masina& modified = service.cautaMasina("B456ABC");
    assert(modified.getProducator() == "Ford");

    // Ștergem o mașină
    service.stergeMasina("B123XYZ");
    assert(service.getAllMasini().size() == 4);

    //filtrare
    std::vector m = service.getFilteredMasiniByProducator("Ford");
    assert(m.size() == 2);
    auto it = m.begin();
    assert(it->getNrInmatriculare() == "B456ABC");
    ++it;
    assert(it->getNrInmatriculare() == "B567DEF");

    m = service.getFilteredMasiniByTip("Coupe");
    assert(m.size() == 1);
    it = m.begin();
    assert(it->getNrInmatriculare() == "B678HIJ");


    //sortare
    m = service.sorteazaMasiniNrInmatriculare();
    assert(m.size() == 4);
    it = m.begin();
    assert(it->getNrInmatriculare() == "B456ABC");
    ++it;
    assert(it->getNrInmatriculare() == "B567DEF");
    ++it;
    assert(it->getNrInmatriculare() == "B678HIJ");
    ++it;
    assert(it->getNrInmatriculare() == "B899KLM");

    m = service.sorteazaMasiniTip();
    assert(m.size() == 4);
    it = m.begin();
    assert(it->getNrInmatriculare() == "B678HIJ");
    ++it;
    assert(it->getNrInmatriculare() == "B899KLM");
    ++it;
    assert(it->getNrInmatriculare() == "B567DEF");
    ++it;
    assert(it->getNrInmatriculare() == "B456ABC");

    m = service.sorteazaMasiniProducatorModel();
    assert(m.size() == 4);
    it = m.begin();
    assert(it->getNrInmatriculare() == "B678HIJ");
    ++it;
    assert(it->getNrInmatriculare() == "B899KLM");
    ++it;
    assert(it->getNrInmatriculare() == "B456ABC");
    ++it;
    assert(it->getNrInmatriculare() == "B567DEF");

    std::cout << "Test MasinaService passed!\n";
}
// ------------------ Teste spalatorie ------------------
// void Teste::testServiceSpalatorie() {
//     MasinaRepo repo;
//     repo.adauga(Masina("B123XYZ", "Toyota", "Corolla", "Sedan"));
//     repo.adauga(Masina("CJ45ABC", "Honda", "Civic", "Coupe"));
//     repo.adauga(Masina("MS99XYZ", "Dacia", "Duster", "SUV"));
//     MasinaService service{repo};
//     ServiceSpalatorie spalatorie{service};
//
//     // Test adaugare masina
//     spalatorie.adaugaMasina("B123XYZ");
//     assert(spalatorie.nrMasini() == 1);
//
//     // Test golire
//     spalatorie.golesteLista();
//     assert(spalatorie.nrMasini() == 0);
//
//     // Test generare aleatorie
//     spalatorie.generareLista(2);
//     assert(spalatorie.nrMasini() == 2);
//
//     // Test export CSV
//     spalatorie.exportCSV("test_export.csv");
//     std::ifstream in("test_export.csv");
//     assert(in.is_open());
//     in.close();
//
//     // Test eroare la adaugare cu numar inexistent
//     // bool exceptie = false;
//     // try {
//     //     service.adaugaMasina("INVALID");
//     // } catch (
// }



void Teste::testServiceSpalatorie() {
    MasinaRepo repo;
    MasinaService srv{repo};
    ServiceSpalatorie spalatorie{srv};
    bool  exceptiePrinsa = false;
    try {
        spalatorie.generareLista(2);
    } catch (const std::exception&) {
        exceptiePrinsa = true;
    }
    assert(exceptiePrinsa);
    srv.adaugaMasina("CJ01ABC", "Dacia", "Logan", "sedan");
    srv.adaugaMasina("CJ02DEF", "VW", "Golf", "hatchback");
    srv.adaugaMasina("CJ03XYZ", "Audi", "A4", "sedan");


    // Test adaugare masina
    spalatorie.adaugaMasina("CJ01ABC");
    assert(spalatorie.nrMasini() == 1);

    // Test golire
    spalatorie.golesteLista();
    assert(spalatorie.nrMasini() == 0);
    spalatorie.generareLista(1);
    assert(spalatorie.nrMasini() == 1);
    spalatorie.golesteLista();

    // Test generare lista (când numărul este egal cu numărul total)
    spalatorie.generareLista(3);
    assert(spalatorie.nrMasini() == 3);

    // Test export CSV
    spalatorie.exportCSV("test_export.csv");

    std::ifstream in("test_export.csv");
    int lineCount = 0;
    std::string line;
    while (std::getline(in, line)) {
        lineCount++;
    }
    assert(lineCount == 3);  // ar trebui să fie 3 linii în fișier
    in.close();

    // Test generare lista cu număr prea mare
    exceptiePrinsa = false;
    try {
        spalatorie.generareLista(100);
    } catch (const std::exception&) {
        exceptiePrinsa = true;
    }
    assert(exceptiePrinsa);
    std::cout << "Test ServiceSpalatorie passed!\n";

}

void Teste::testServiceUndo() {
    MasinaRepo repo;
    MasinaService service{repo};
    try {
        service.undo();
        assert(false);
    } catch (const ServiceException& e) {
        std::string text = e.what();
        assert(text == "Nothing to undo");
    }

    service.adaugaMasina("B123XYZ", "Toyota", "Corolla", "Sedan");
    service.adaugaMasina("B456ABC", "Honda", "Civic", "Hatchback");
    service.adaugaMasina("B567DEF", "Ford", "Focus", "SUV");

    service.undo();
    auto m = service.getAllMasini();
    assert(m.size() == 2);
    assert(m[0].getNrInmatriculare() == "B123XYZ");
    assert(m[1].getNrInmatriculare() == "B456ABC");

    service.undo();
    m = service.getAllMasini();
    assert(m.size() == 1);
    assert(m[0].getNrInmatriculare() == "B123XYZ");


    service.stergeMasina("B123XYZ");
    m = service.getAllMasini();
    assert(m.empty());
    service.undo();
    m = service.getAllMasini();
    assert(m.size() == 1);
    assert(m[0].getNrInmatriculare() == "B123XYZ");

    service.modificaMasina("B123XYZ", "Ford", "Focus", "SUV");
    m = service.getAllMasini();
    assert(m[0].getProducator() == "Ford");
    assert(m[0].getModel() == "Focus");
    assert(m[0].getTip() == "SUV");
   service.undo();
    m = service.getAllMasini();
    std::cout << m[0].getProducator() << m[0].getModel() << m[0].getTip();
    assert(m[0].getProducator() == "Toyota");
    assert(m[0].getModel() == "Corolla");
    assert(m[0].getTip() == "Sedan");

    std::cout << "Test ServiceUndo passed!\n";
}


void Teste::testMasinaRepoFile() {
    std::string fileName = "test_masini.csv";
    std::ofstream out(fileName);
    MasinaRepoFile repo{fileName};

    assert(repo.getAll().empty());

    // Adăugăm o mașină
    Masina m1{"CJ01ABC", "BMW", "X5", "SUV"};
    repo.adauga(m1);
    assert(repo.getAll().size() == 1);
    assert(repo.getAll()[0].getNrInmatriculare() == "CJ01ABC");

    // Adăugăm altă mașină
    Masina m2{"B123XYZ", "Audi", "A4", "Sedan"};
    repo.adauga(m2);
    assert(repo.getAll().size() == 2);

    // Modificăm prima mașină
    Masina m1Modificat{"CJ01ABC", "BMW", "X6", "SUV"};
    repo.modifica(m1Modificat);
    assert(repo.getAll()[0].getModel() == "X6");

    // Ștergem a doua mașină
    repo.sterge("B123XYZ");
    assert(repo.getAll().size() == 1);


    const auto& masini = repo.getAll();
    assert(masini.size() == 1);
    assert(masini[0].getNrInmatriculare() == "CJ01ABC");
    assert(masini[0].getModel() == "X6");
    std::cout << "Test MasinaRepoFile passed!\n";
}

// ------------------ Teste din VectorDinamicCPP ------------------
template <typename MyVector>
MyVector testCopyIterate(MyVector v) {
    for (auto& el : v) {
        std::string concat = el.getNrInmatriculare() + el.getProducator();
        (void)concat;
    }
    Masina m{ "XX00YYY", "Total", "Concat", "Test" };
    v.add(m);
    return v;
}

template <typename MyVector>
void addMasini(MyVector& v, int cate) {
    for (int i = 0; i < cate; i++) {
        Masina m{
            "B" + std::to_string(i) + "XYZ",
            "Prod" + std::to_string(i),
            "Model" + std::to_string(i),
            "Tip" + std::to_string(i)
        };
        v.add(m);
    }
}

template <typename MyVector>
void testCreateCopyAssign() {
    MyVector v; // default constructor
    addMasini(v, 100);
    assert(v.getSize() == 100);
    assert(v.get(50).getProducator() == "Prod50");

    MyVector v2{ v }; // copy constructor
    assert(v2.getSize() == 100);
    assert(v2.get(50).getProducator() == "Prod50");

    MyVector v3; // default constructor
    v3 = v; // assignment
    assert(v3.getSize() == 100);
    assert(v3.get(50).getProducator() == "Prod50");

    auto v4 = testCopyIterate(v3);
    assert(v4.getSize() == 101);
    assert(v4.get(50).getProducator() == "Prod50");

    std::cout << "Test copy, assignment, and iteration passed.\n";
}

template <typename MyVector>
void testMoveConstrAssgnment() {
    std::vector<MyVector> v;
    v.push_back(MyVector{});
    v.insert(v.begin(), MyVector{});

    assert(v.size() == 2);

    MyVector v2;
    addMasini(v2, 50);
    v2 = MyVector{}; // move assignment
    assert(v2.getSize() == 0);

    std::cout << "Test move constructor and assignment passed.\n";
}
// ------------------ Funcție principală pentru a rula testele ------------------

void Teste::runTests() {
    testCreateCopyAssign<List<Masina>>();
    testMoveConstrAssgnment<List<Masina>>();
    testMasina();
    testMasinaRepo();
    testMasinaService();
    testServiceSpalatorie();
    testMasinaRepoFile();
    testServiceUndo();
    std::cout << "Toate testele au trecut cu succes!\n";
}
