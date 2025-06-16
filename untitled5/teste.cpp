//
// Created by lupse on 6/14/2025.
//

#include "teste.h"

#include <iostream>
#include <ostream>

void Teste::testProdus(){
      Produs p{1,"masa","obiect",32.2};
      assert(p.getName() == "masa");
      assert(p.getTip() == "obiect");
      assert(abs(p.getPret()-32.2) <= 0.01);
};
void Teste::testValidator() {
    ValidatorProdus v;
    Produs valid{1,"masa","obiect",32.2};
    Produs invalidName{1,"","obiect",32.2};
    Produs invalidTip{1,"masa","",32.2};
    Produs invalidPret{1,"masa","obiect",123};
    v.valideaza(valid);
    try {
        v.valideaza(invalidName);
        assert(false);
    } catch (const std::invalid_argument& e) {
        assert(string(e.what()) == "Produs name is empty\n");
    }
    try {
        v.valideaza(invalidTip);
        assert(false);
    } catch (const std::invalid_argument& e) {
        assert(string(e.what()) == "Produs tip is empty\n");
    }
    try {
        v.valideaza(invalidPret);
        assert(false);
    } catch (const std::invalid_argument& e) {
        assert(string(e.what()) == "Produs pret is invalid(must be between 1 and 100)\n");
    }
}
void Teste::testRepo() {
    std::ofstream out;
    out.open("../test_produse.txt", std::ios::trunc);
    RepoProdus rp{"../test_produse.txt"};
    auto prod = rp.getAll();
    assert(prod.size() == 0);

    rp.add(Produs{10,"Pijamale","Haine",41.2});
    prod = rp.getAll();
    assert(prod.size() == 1);
    assert(prod[0].getName() == "Pijamale");
    assert(prod[0].getTip() == "Haine");
    assert(abs(prod[0].getPret()-41.2) <= 0.01);

    try {
        rp.add(Produs{10,"Pijamale","Haine",41.2});
        assert(false);
    } catch (const std::runtime_error& e) {
        assert(string(e.what()) == "Produs already exists");
    }

}
void Teste::testSrv() {
    std::ofstream out;
    out.open("../test_produse.txt", std::ios::trunc);
    RepoProdus rp{"../test_produse.txt"};
    ValidatorProdus v;
    ServiceProduse srv(rp,v);
    auto prod = srv.getAllProduse();
    assert(prod.size() == 0);

    srv.addProdus(10,"Pijamale","Haine",41.2);
    prod = srv.getAllProduse();
    assert(prod.size() == 1);
    assert(prod[0].getName() == "Pijamale");
    assert(prod[0].getTip() == "Haine");
    assert(abs(prod[0].getPret()-41.2) <= 0.01);

    try {
        srv.addProdus(10,"Pijamale","Haine",41.2);
        assert(false);
    } catch (const std::exception& e) {
        assert(string(e.what()) == "Produs already exists");
    }

    srv.addProdus(2,"masa","obiect",32.2);

    try {
       srv.addProdus(2,"","obiect",32.2);
        assert(false);
    } catch (const std::exception& e) {
        assert(string(e.what()) == "Produs name is empty\n");
    }
    try {
        srv.addProdus(2,"masa","",32.2);
        assert(false);
    } catch (const std::exception& e) {
        assert(string(e.what()) == "Produs tip is empty\n");
    }
    try {
        srv.addProdus(2,"masa","obiect",123);
        assert(false);
    } catch (const std::exception& e) {
        assert(string(e.what()) == "Produs pret is invalid(must be between 1 and 100)\n");
    }
}
void Teste::runAllTests(){
    testProdus();
    testValidator();
    testRepo();
    testSrv();
    std::cout << "teste rulate cu succes!" << std::endl;
}
