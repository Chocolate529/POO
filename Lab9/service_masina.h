//
// Created by lupse on 4/7/2025.
//
#pragma once
#include <memory>

#include "repo_masina.h"
#include "undo.h"
class MasinaService {
private:
    MasinaRepo& repo;
    std::vector<std::unique_ptr<ActiuneUndo>> undoActions;
    [[nodiscard]] static bool cmpNrInmatriculare(const Masina& masina1, const Masina& masina2);
    [[nodiscard]] static bool cmpTip(const Masina& masina1, const Masina& masina2);
    [[nodiscard]] static bool cmpProducatorModel(const Masina& masina1, const Masina& masina2);
    [[nodiscard]] std::vector<Masina> sorteazaMasini(bool (*cmp)(const Masina&, const Masina&)) const;
public:
    explicit MasinaService(MasinaRepo& r) : repo{r} {}
    MasinaService(const MasinaService&) = delete;
    void operator=(const MasinaService&) = delete;
    void adaugaMasina(const std::string& nr, const std::string& prod,
                      const std::string& mod, const std::string& tip) ;

    void stergeMasina(const std::string& nr) ;
    void modificaMasina(const std::string& nr, const std::string& prod,
                        const std::string& mod, const std::string& tip) ;

    [[nodiscard]] const Masina& cautaMasina(const std::string& nr) const;
    // [[nodiscard]] const Masina& cautaMasinaByIndex(int index) const;
    [[nodiscard]] const std::vector<Masina>& getAllMasini() const;
    [[nodiscard]] std::vector<Masina> getFilteredMasiniByProducator(const std::string& producator) const;
    [[nodiscard]] std::vector<Masina> getFilteredMasiniByTip(const std::string& tip) const;
    [[nodiscard]] std::vector<Masina> sorteazaMasiniNrInmatriculare() const;
    [[nodiscard]] std::vector<Masina> sorteazaMasiniTip() const;
    [[nodiscard]] std::vector<Masina> sorteazaMasiniProducatorModel() const;

    void undo();
    virtual ~MasinaService() = default;
    //inchiriere
};

