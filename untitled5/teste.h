//
// Created by lupse on 6/14/2025.
//

#ifndef TESTE_H
#define TESTE_H

#include "produs.h"
#include "validator_produs.h"
#include "repo_produs.h"
#include "service_produse.h"
#include <cassert>
class Teste {
    private:
      static void testProdus();
      static void testValidator();
      static void testRepo();
      static void testSrv();

    public:
      static void runAllTests();
};




#endif //TESTE_H
