//
// Created by lupse on 6/14/2025.
//
/*
* Header pentru un produs ce are id unic, nume(nevid), tip, pret(intre 1.0 si 100.0)
 * */
#ifndef PRODUS_H
#define PRODUS_H

#include <algorithm>
#include <string.h>
#include <string>
using std::string;

class Produs {
    private:
      int id;
      string name;
      string tip;
      double pret;
      int nrVocale = 0;
    public:

      /*
      * Creaza un poruds cu id unic, nume(nevid), tip, pret(intre 1.0 si 100.0)
      * */
      explicit Produs(int id, string name, string tip, double pret):
      id(id), name(name), tip(tip), pret(pret) {
          for (auto c : name) {
              if (strchr("aeiouAEIOU", c)) {
                  nrVocale++;
              }
          }
      };

      [[nodiscard]] string getName() const;
      [[nodiscard]] string getTip() const;
      [[nodiscard]] double getPret() const;
      [[nodiscard]] int getId() const;
      [[nodiscard]] int getNrVocale() const;

};



#endif //PRODUS_H
