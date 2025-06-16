//
// Created by lupse on 6/15/2025.
//

#ifndef TESTE_H
#define TESTE_H


#include <iostream>
#include "student.h"
#include <cassert>
#include "repo_student.h"
#include "service_student.h"
#include <filesystem>
class teste {
    public:
      void runAllTests();
    private:
      static void testStudent();
      static void testRepo();
      static void testSrv();
};



#endif //TESTE_H
