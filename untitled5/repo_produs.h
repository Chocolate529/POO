//
// Created by lupse on 6/14/2025.
//

#ifndef REPO_PRODUS_H
#define REPO_PRODUS_H


#include "produs.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using std::vector;
class RepoProdus {
    private:
      vector<Produs> produse;
      string fileName;
      void loadFromFile();
      void writeToFile();
    public:
      explicit RepoProdus(string fileName) : fileName(fileName) {
        loadFromFile();
      }
      void add(Produs prod);
      vector<Produs> getAll();
};



#endif //REPO_PRODUS_H
