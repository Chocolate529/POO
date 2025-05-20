//
// Created by lupse on 5/20/2025.
//

#ifndef REPO_TRACTOR_H
#define REPO_TRACTOR_H

#include "tractor.h"
#include <vector>
class repo_tractor {
    private:
      std::vector<Tractor> tractors;
      std::string file_name;
      void loadFromFile();
        void saveToFile();
    public:
      repo_tractor(const std::string& file_name) : file_name(file_name) {;
          loadFromFile();
      }
      void add_tractor(const Tractor& tractor);
    std::vector<Tractor> get_all_tractors() const;

};



#endif //REPO_TRACTOR_H
