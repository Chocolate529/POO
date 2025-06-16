//
// Created by lupse on 6/15/2025.
//

#include "melodie.h"
melodie::melodie(int id, string name, string artist, int rank):
 id(id), rank(rank), name(name), artist(artist) {}
int melodie::getId() const{
  return id;
}
int melodie::getRank() const{
  return rank;
}
string melodie::getName() const{
  return name;
}
string melodie::getArtist() const{
  return artist;
}
void melodie::setArtist(string a){
  artist = a;
}
void melodie::setRank(int r){
  rank = r;
}