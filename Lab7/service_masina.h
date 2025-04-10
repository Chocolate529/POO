//
// Created by lupse on 4/7/2025.
//
#pragma once
#include "repo_masina.h"

class MasinaService {
private:
    MasinaRepo& repo;

public:
    explicit MasinaService(MasinaRepo& r) : repo{r} {}

    void adaugaMasina(const std::string& nr, const std::string& prod,
                      const std::string& mod, const std::string& tip);

    void stergeMasina(const std::string& nr);
    void modificaMasina(const std::string& nr, const std::string& prod,
                        const std::string& mod, const std::string& tip);

    const Masina& cautaMasina(const std::string& nr) const;
    const List<Masina>& getAllMasini() const;
};

