//
// Created by lupse on 6/14/2025.
//

#include "repo_melodie.h"

#include <algorithm>

repo_melodie::repo_melodie(string fileName): fileName(fileName) {
        loadFromFile();
};

void repo_melodie::loadFromFile(){
       melodies.clear();
      std::ifstream file(fileName);
      if(!file.is_open()){
        throw std::runtime_error("file not found");
      }
      string line;
      while(std::getline(file,line)){
            std::stringstream ss(line);
            string token;
            vector<string> tokens;
            while (std::getline(ss, token,',')){
              tokens.push_back(token);
            }
            Melodie melodie(stoi(tokens[0]),tokens[1],tokens[2],stoi(tokens[3]));
            melodies.push_back(melodie);
      }
}

void repo_melodie::saveToFile() {
  std::ofstream file(fileName);
  if(!file.is_open()) {
    throw std::runtime_error("file not found");
  }
  for (const auto& melodie : melodies) {
    file << melodie.getId() << ","
    << melodie.getName() << ","
    << melodie.getArtist() << ","
    << melodie.getRank() << "\n";
  }
}

void repo_melodie::modifica(Melodie melodie) {
  auto m = std::find_if(melodies.begin(),
    melodies.end(), [&](const Melodie& m) {
    return m.getId() == melodie.getId();
  });
  if (m != melodies.end()) {
      m->setName(melodie.getName());
       m->setArtist(melodie.getArtist());
      m->setRank(melodie.getRank());
      saveToFile();
  } else {
    throw std::invalid_argument("No such melodie");
  }
}


vector<Melodie> repo_melodie::getAll(){
  loadFromFile();
  return melodies;
}