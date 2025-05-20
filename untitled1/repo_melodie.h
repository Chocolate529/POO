//
// Created by lupse on 5/20/2025.
//

#ifndef REPO_MELODIE_H
#define REPO_MELODIE_H

#include <vector>
#include "melodie.h"

class FileRepoMelodie {
    private:
      std::vector<Melodie> melodii;
      void loadFromFile();
      void saveToFile();
    public:
      FileRepoMelodie() = default;
      explicit FileRepoMelodie(const std::vector<Melodie>& melodii): melodii{melodii} {
        loadFromFile();
      };

      void removeMelodie(int id);
      void updateMelodie(int id, const std::string& titlu, int rank);

      [[nodiscard]] std::vector<Melodie> getAll();

};



#endif //REPO_MELODIE_H
