//
// Created by lupse on 6/14/2025.
//

#include "repo_produs.h"

void RepoProdus::loadFromFile(){
    produse.clear();
    std::ifstream in(fileName);
    if(!in.is_open()){
      throw std::runtime_error("Could not open file");
    }
    string line;
    while(std::getline(in, line)){
      std::stringstream ss(line);
      string value;
      vector<string> tokens;
      while(getline(ss, value, ',')){
        tokens.push_back(value);
      }
      int id = stoi(tokens[0]);
      string name = tokens[1];
      string tip = tokens[2];
      double price = stod(tokens[3]);

      produse.push_back(Produs{id, name, tip, price});
    }
}
void RepoProdus::writeToFile(){
    std::ofstream out(fileName);
    for(const auto& p: produse){
      out << p.getId() << "," << p.getName() << "," << p.getTip() << "," << p.getPret() << std::endl;
    }
}
void RepoProdus::add(Produs prod){
    if(std::find_if(produse.begin(), produse.end(), [&prod](Produs p){
        return p.getId() == prod.getId();
    })!= produse.end()){
          throw std::runtime_error("Produs already exists");
    }
    produse.push_back(prod);
    writeToFile();
}
vector<Produs> RepoProdus::getAll(){
    loadFromFile();
    return produse;
}
