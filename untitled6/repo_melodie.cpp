//
// Created by lupse on 6/15/2025.
//

#include "repo_melodie.h"
repo_melodie::repo_melodie(string fileName): fileName(fileName){}

void repo_melodie::loadFromFile(){
  melodies.clear();
   ifstream file(fileName);
   if(!file.is_open()){
     throw std::invalid_argument("File does not exist");
   }
   string line;
   while(getline(file, line)){
     std::stringstream ss(line);
     string token;
     vector<string> tokens;
     while(getline(ss, token, ',')){
       tokens.push_back(token);
     }
     int id = std::stoi(tokens[0]);
      string name = tokens[1];
      string artist = tokens[2];
      int rank = std::stoi(tokens[3]);
      melodies.push_back(melodie(id, name, artist, rank));
   }

}

void repo_melodie::saveToFile(){
  ofstream file(fileName);
  for(const auto& melodie : melodies){
    file << melodie.getId() << ","
    << melodie.getName() << ","
    << melodie.getArtist() << ","
    << melodie.getRank() << endl;
  }
}

vector<melodie> repo_melodie::getAll(){
  loadFromFile();
  return melodies;
}

void repo_melodie::update(int id, string artist, int rank){
  loadFromFile();
  auto it = std::find_if(melodies.begin(), melodies.end(),[=](const melodie &m){
    return m.getId() == id;
  });
  if(it != melodies.end()){
    it->setArtist(artist);
    it->setRank(rank);
    saveToFile();
  } else {
    throw std::invalid_argument("No such id");
  }
}
void repo_melodie::del(int id){
  loadFromFile();
  auto it = std::find_if(melodies.begin(), melodies.end(),[=](const melodie &m){
    return m.getId() == id;
  });
  if(it != melodies.end()){
    melodies.erase(it);
    saveToFile();
  } else {
    throw std::invalid_argument("No such id");
  }
}