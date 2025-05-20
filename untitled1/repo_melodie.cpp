//
// Created by lupse on 5/20/2025.
//

#include "repo_melodie.h"
#include <fstream>
#include <sstream>
void FileRepoMelodie::saveToFile() {
    std::ofstream file("../melodii");
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    for (const auto& melodie : melodii) {
        file << melodie.getId() << "," << melodie.getTitlu() << "," << melodie.getArtist() << "," << melodie.getRank() << "\n";
    }
}void FileRepoMelodie::loadFromFile() {
    melodii.clear();
    std::ifstream file("../melodii");
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string idStr, titlu, artist, rankStr;
        if (!std::getline(iss, idStr, ',') ||
            !std::getline(iss, titlu, ',') ||
            !std::getline(iss, artist, ',') ||
            !std::getline(iss, rankStr, ',')) {
            throw std::runtime_error("Error reading line");
        }
        int id = std::stoi(idStr);
        int rank = std::stoi(rankStr);
        melodii.push_back({id, titlu, artist, rank});
    }
}

void FileRepoMelodie::removeMelodie(int id) {
    loadFromFile();
    auto melodie = std::ranges::find_if(melodii.begin(), melodii.end(), [id](const Melodie& melodie) {
        return melodie.getId() == id;
    });
    if (melodie != melodii.end()) {
        melodii.erase(melodie);
    } else {
        throw std::runtime_error("Melodie inexistenta");
    }
    saveToFile();
}

void FileRepoMelodie::updateMelodie(int id,const std::string& titlu, int rank) {
    loadFromFile();
    auto melodieToUpdate = std::ranges::find_if(melodii.begin(), melodii.end(), [id](const Melodie& melodie) {
        return melodie.getId() == id;
    });
    if (melodieToUpdate != melodii.end()) {
        melodieToUpdate->setTitlu(titlu);
        melodieToUpdate->setRank(rank);
    } else {
        throw std::runtime_error("Melodie inexistenta");
    }
    saveToFile();
}

[[nodiscard]] std::vector<Melodie> FileRepoMelodie::getAll() {
    loadFromFile();
    return melodii;
};
