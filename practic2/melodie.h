//
// Created by lupse on 6/14/2025.
//

#ifndef MELODIE_H
#define MELODIE_H

#include <string>
using std::string;
class Melodie {
    private:
      int id;
      string name, artist;
      int rank;

    public:
      Melodie(int id, string name, string artist, int rank);
      int getId() const;
      string getName() const;
      string getArtist() const;
      int getRank() const;
      void setName(string n);
      void setArtist(string a) ;
      void setRank(int r) ;
};

#endif //MELODIE_H
