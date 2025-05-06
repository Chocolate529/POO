#pragma once
#include "domeniu_masina.h"
#include <vector>

class MasinaRepo {
private:
    std::vector<Masina> masini;  // Înlocuim std::vector cu List<Masina>

public:
    virtual void adauga(const Masina& m);
    virtual void sterge(const std::string& nrInmatriculare);
    virtual void modifica(const Masina& m);
    [[nodiscard]] virtual const Masina& cauta(const std::string& nrInmatriculare) const;
    // [[nodiscard]] const Masina& cautaIndex(int index) const;
    [[nodiscard]] virtual const std::vector<Masina>& getAll() const;  // Adăugăm cuvântul cheie const
    virtual ~MasinaRepo() = default;
};


class MasinaRepoFile: public MasinaRepo {
private:
    std::string& fileName;
    void writeToFile();
    void readFromFile();
public:
    explicit MasinaRepoFile(std::string& fileName):MasinaRepo() ,  fileName(fileName) {
        readFromFile();
    }
    void adauga(const Masina& m) override;
    void sterge(const std::string& nrInmatriculare) override;
    void modifica(const Masina& m) override;

};