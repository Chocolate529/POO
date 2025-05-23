#pragma once
#include "domeniu_masina.h"
#include "List.h"  // Include lista noastră dinamică
class MasinaRepo {
private:
    List<Masina> masini;  // Înlocuim std::vector cu List<Masina>

public:
    void adauga(const Masina& m);
    void sterge(const std::string& nrInmatriculare);
    void modifica(const Masina& m) const;
    [[nodiscard]] const Masina& cauta(const std::string& nrInmatriculare) const;
    [[nodiscard]] const List<Masina>& getAll() const;  // Adăugăm cuvântul cheie const
};
