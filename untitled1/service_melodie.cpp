//
// Created by lupse on 5/20/2025.
//

#include "service_melodie.h"

#include <stdexcept>

void ServiceMelodie::removeMeloide(int id) {
    updateArtistSongCount();
    auto melodii = repo.getAll();
    auto it = std::ranges::find_if(melodii.begin(), melodii.end(), [id](const Melodie& m) { return m.getId() == id; });
    if (it == melodii.end()) throw std::runtime_error("Melodie inexistenta");
    std::string artist = it->getArtist();
    if (artistSongCount[artist] == 1) throw std::runtime_error("Ultima melodie");
    repo.removeMelodie(id);
    updateArtistSongCount();
}
void ServiceMelodie::updateMelodie(int id, const std::string &titlu, int rank) {
    repo.updateMelodie(id, titlu, rank);
    notifyObservers();
}


std::vector<Melodie> ServiceMelodie::getAllMelodii() const {
    return repo.getAll();
}

void ServiceMelodie::updateArtistSongCount() {
    artistSongCount.clear();
    for (const auto& melodie : repo.getAll()) {
        artistSongCount[melodie.getArtist()]++;
    }
    notifyObservers();
}