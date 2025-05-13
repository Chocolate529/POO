//
// Created by lupse on 4/15/2025.
//

#ifndef SERVICE_SPALATORIE_H
#define SERVICE_SPALATORIE_H
#include <vector>
#include <fstream>
#include "service_masina.h"
class ServiceSpalatorie{
private:
    std::vector<Masina> masiniSpalatorie;
    MasinaService& srv;
public:
    explicit ServiceSpalatorie(MasinaService& srv) : srv(srv) {}

    void adaugaMasina(const std::string& nrInmatriculare);
    void golesteLista();
    void generareLista(int nrTotal);
    void exportCSV(const std::string& fileName) const;
    [[nodiscard]] int nrMasini() const;
};
#endif //SERVICE_SPALATORIE_H
