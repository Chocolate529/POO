//
// Created by lupse on 4/7/2025.
//
#pragma once
#include "repo_masina.h"

class MasinaService {
private:
    MasinaRepo& repo;
    [[nodiscard]] static bool cmpNrInmatriculare(const Masina& masina1, const Masina& masina2);
    [[nodiscard]] static bool cmpTip(const Masina& masina1, const Masina& masina2);
    [[nodiscard]] static bool cmpProducatorModel(const Masina& masina1, const Masina& masina2);
    [[nodiscard]] List<Masina> sorteazaMasini(bool (*cmp)(const Masina&, const Masina&)) const;
public:
    explicit MasinaService(MasinaRepo& r) : repo{r} {}

    void adaugaMasina(const std::string& nr, const std::string& prod,
                      const std::string& mod, const std::string& tip) const;

    void stergeMasina(const std::string& nr) const;
    void modificaMasina(const std::string& nr, const std::string& prod,
                        const std::string& mod, const std::string& tip) const;

    [[nodiscard]] const Masina& cautaMasina(const std::string& nr) const;
    [[nodiscard]] const List<Masina>& getAllMasini() const;
    [[nodiscard]] List<Masina> getFilteredMasiniByProducator(const std::string& producator) const;
    [[nodiscard]] List<Masina> getFilteredMasiniByTip(const std::string& tip) const;
    [[nodiscard]] List<Masina> sorteazaMasiniNrInmatriculare() const;
    [[nodiscard]] List<Masina> sorteazaMasiniTip() const;
    [[nodiscard]] List<Masina> sorteazaMasiniProducatorModel() const;
};

