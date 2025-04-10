//
// Created by lupse on 4/7/2025.
//
#pragma once
#include "domeniu_masina.h"
#include <vector>
#include <stdexcept>

class MasinaRepo {
private:
    std::vector<Masina> masini;

public:
    void adauga(const Masina& m);
    void sterge(const std::string& nrInmatriculare);
    void modifica(const Masina& m);
    const Masina& cauta(const std::string& nrInmatriculare) const;
    const std::vector<Masina>& getAll() const;
};
