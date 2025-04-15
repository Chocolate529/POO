//
// Created by lupse on 4/15/2025.
//

#ifndef SERVICE_SPALATORIE_H
#define SERVICE_SPALATORIE_H
#include <vector>
#include <fstream>
#include "service_masina.h"
class ServiceSpalatorie: public MasinaService {
private:
    std::vector<Masina> masiniSpalatorie;
public:
    explicit ServiceSpalatorie(MasinaService& srv) : MasinaService(srv) {}

    void adaugaMasina(const std::string& nrInmatriculare);
    void golesteLista();
    void generareLista(int nrTotal);
    void exportCSV(const std::string& fileName) const;
    int nrMasini() const;
};
#endif //SERVICE_SPALATORIE_H
