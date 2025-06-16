//
// Created by lupse on 6/15/2025.
//

#ifndef SERVICE_MELODII_H
#define SERVICE_MELODII_H

#include "repo_melodie.h"
#include <map>
#include <algorithm>
using std::map;
class service_melodii {
    private:
      repo_melodie& repo;
      map<string,int> artist_mel;
    public:
      service_melodii(repo_melodie& repo_melodie);
      vector<melodie> getMelodii();
      vector<melodie> getMelodiiSorted();
      map<int,int> getMelodiiMap();
      void updateMelodie(int id, string a, int r);
    void delMelodie(int id,string artist);
};



#endif //SERVICE_MELODII_H
