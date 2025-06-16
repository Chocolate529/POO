//
// Created by lupse on 6/14/2025.
//

#ifndef SERVICE_MELODIE_H
#define SERVICE_MELODIE_H

#include <map>
#include "repo_melodie.h"
class service_melodie {
    private:
      repo_melodie& rp;

    public:
      explicit service_melodie(repo_melodie& r);
      vector<Melodie> getAllMelodii();
      std::map<int, int> getAllByRank();
};



#endif //SERVICE_MELODIE_H
