//
// Created by lupse on 6/15/2025.
//

#ifndef TESTE_H
#define TESTE_H
#include <iostream>
#include <filesystem>
#include <cassert>
#include "melodie.h"
#include "repo_melodie.h"
#include "service_melodii.h"

using std::cout;
using std::endl;

class teste {
    private:
      static void testMelodie();
      static void testRepo();
      static void testSrv();

    public:
      void runAllTests();
};



#endif //TESTE_H
