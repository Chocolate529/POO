//
// Created by lupse on 6/15/2025.
//

#ifndef MELODIE_H
#define MELODIE_H

#include <string>
using std::string;

class melodie {
    private:
      int id, rank;
      string name, artist;

    public:
      melodie(int id, string name, string artist, int rank);
      int getId() const;
      int getRank() const;
      string getName() const;
      string getArtist() const;
      void setArtist(string a);
      void setRank(int r);
};



#endif //MELODIE_H
