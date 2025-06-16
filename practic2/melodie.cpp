//
// Created by lupse on 6/14/2025.
//

#include "melodie.h"
Melodie::Melodie(int id, string name, string artist, int rank):
 id(id), name(name), artist(artist), rank(rank) {}
int Melodie::getId() const{
  return id;
};
string Melodie::getName() const{
  return name;
};
string Melodie::getArtist() const{
  return artist;
};
int Melodie::getRank() const{
   return rank;
};
void Melodie::setName(string n) {
  name =n;
}
void Melodie::setArtist(string a) {
  artist = a;
}
void Melodie::setRank(int r) {
  rank = r;
}