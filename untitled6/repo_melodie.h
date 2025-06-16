//
// Created by lupse on 6/15/2025.
//

#ifndef REPO_MELODIE_H
#define REPO_MELODIE_H

#include "melodie.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <iostream>
using std::endl;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::getline;
class repo_melodie {
    private:
      vector<melodie> melodies;
      string fileName;

      void loadFromFile();
      void saveToFile();

    public:
      repo_melodie(string fileName);
      vector<melodie> getAll();
      void update(int id, string artist, int rank);
        void del(int id);
};



#endif //REPO_MELODIE_H
