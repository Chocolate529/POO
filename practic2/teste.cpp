//
// Created by lupse on 6/14/2025.
//

#include "teste.h"

#include <iostream>

void teste::testMelodie() {
    Melodie m(1,"m1","a1",2);
    assert(m.getId() == 1);
    assert(m.getName() == "m1");
    assert(m.getArtist() == "a1");
    assert(m.getRank() == 2);
    m.setName("m2");
    assert(m.getName() == "m2");
    m.setArtist("a2");
    assert(m.getArtist() == "a2");
    m.setRank(3);
    assert(m.getRank() == 3);
}

void teste::testRepo() {
    repo_melodie rp{"../test_repo"};
    auto p = rp.getAll();
    assert(p.size() == 10);
    assert(p[0].getId() == 1);
    assert(p[0].getName() == "M1");
    assert(p[0].getArtist() == "A1");
    assert(p[0].getRank() == 0);

    rp.modifica(Melodie (1,"m","a",9));
    p = rp.getAll();
    assert(p[0].getId() == 1);
    assert(p[0].getName() == "m");
    assert(p[0].getArtist() == "a");
    assert(p[0].getRank() == 9);
    rp.modifica(Melodie (1,"M1","A1",0));
}

void teste::testSrv() {
    repo_melodie rp{"../test_service"};
    service_melodie srv{rp};
    auto p = srv.getAllMelodii();
    assert(p.size() == 10);
    assert(p[0].getId() == 1);
    assert(p[0].getName() == "M1");
    assert(p[0].getArtist() == "A1");
    assert(p[0].getRank() == 0);

    auto m = srv.getAllByRank();
    assert(m.size() == 10);
    int i = 0;
    for (auto [rank, times]: m) {
        assert(rank == i && times == 1);
        i++;
    }
}

void teste::runAllTeste() {
    testMelodie();
    testRepo();
    testSrv();
    std::cout << "teste rulate cu succes";
}
