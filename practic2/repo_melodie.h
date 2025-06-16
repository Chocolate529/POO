//
// Created by lupse on 6/14/2025.
//

#ifndef REPO_MELODIE_H
#define REPO_MELODIE_H

#include "melodie.h"
#include <vector>
#include <sstream>
#include <fstream>
using std::vector;
class repo_melodie {
    private:
      vector<Melodie> melodies;
      string fileName;
      void loadFromFile();
      void saveToFile();
    public:
      explicit repo_melodie(string fileName);
      vector<Melodie> getAll();
      void modifica(Melodie melodie);
};



#endif //REPO_MELODIE_H
