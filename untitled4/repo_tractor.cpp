//
// Created by lupse on 5/20/2025.
//

#include "repo_tractor.h"
#include <fstream>
#include <sstream>
void repo_tractor::loadFromFile(){
    std::ifstream file(file_name);
    tractors.clear();
    if (file.is_open()){
      std::string line;
      std::string values[4];
        while (std::getline(file, line)){
            std::stringstream ss(line);
            for (int i = 0; i < 4; ++i){
                std::getline(ss, values[i], ',');
            }
            int id = std::stoi(values[0]);
            std::string name = values[1];
            std::string type = values[2];
            int nr_of_wheels = std::stoi(values[3]);
            Tractor tractor(id, name, type, nr_of_wheels);
            tractors.push_back(tractor);
        }
    }
}
void repo_tractor::saveToFile(){
    std::ofstream file(file_name);
    if (file.is_open()){
        for (const auto& tractor : tractors){
            file << tractor.getId() << "," << tractor.getName() << "," << tractor.getType() << "," << tractor.getNrOfWheels() << "\n";
        }
    }
}

void repo_tractor::add_tractor(const Tractor& tractor){
     loadFromFile();
     if(std::ranges::find_if(tractors.begin(), tractors.end(), [&](const Tractor& t) { return t.getId() == tractor.getId(); }) != tractors.end()) {
        throw std::runtime_error("Tractor already exists");
    }
    tractors.push_back(tractor);
    saveToFile();
}

std::vector<Tractor> repo_tractor::get_all_tractors() const {
    return tractors;
}