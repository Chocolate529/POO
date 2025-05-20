//
// Created by lupse on 5/20/2025.
//

#ifndef MELODIE_H
#define MELODIE_H

#include <string>

class Melodie {
    private:
      int id;
      std::string titlu;
      std::string artist;
      int rank;

     public:
       Melodie(int id, std::string titlu, std::string artist, int rank): id{id}, titlu {titlu}, artist{artist}, rank{rank}{};

       [[nodiscard]] int getId() const;
       [[nodiscard]] std::string getTitlu() const;
       [[nodiscard]] std::string getArtist() const;
       [[nodiscard]] int getRank() const;

       void setTitlu(std::string titlu);
       void setRank(int rank);


};



#endif //MELODIE_H
