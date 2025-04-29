//
// Created by lupse on 4/8/2025.
//

#ifndef TESTE_H
#define TESTE_H

#include "domeniu_masina.h"
#include "repo_masina.h"
#include "service_masina.h"
#include "ui.h"
#include <cassert>

class Teste {
public:
    static void runTests();

private:
    // Teste pentru Domain
    static void testMasina();

    // Teste pentru Repository
    static void testMasinaRepo();
    static void testMasinaRepoFile();
    // Teste pentru Service
    static void testMasinaService();
    static void testServiceUndo();
    static void testServiceSpalatorie();
};

#endif //TESTE_H
