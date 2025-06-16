//
// Created by lupse on 6/14/2025.
//

#ifndef TESTE_H
#define TESTE_H

#include <cassert>
#include "melodie.h"
#include "repo_melodie.h"
#include "service_melodie.h"
class teste {
    public:
      static void runAllTeste();

    private:
      static void testMelodie();
      static void testRepo();
      static void testSrv();
};



#endif //TESTE_H
