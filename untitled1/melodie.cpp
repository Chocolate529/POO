//
// Created by lupse on 5/20/2025.
//

#include "melodie.h"


int Melodie::getId() const {
    return id;
}

std::string Melodie::getTitlu() const {
    return titlu;
}

std::string Melodie::getArtist() const {
    return artist;
}

int Melodie::getRank() const {
    return rank;
}

void Melodie::setTitlu(std::string titlu_nou) {
    titlu = std::move(titlu_nou);
}

void Melodie::setRank(int rank_nou) {
    rank = rank_nou;
}