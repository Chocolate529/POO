//
// Created by lupse on 4/7/2025.
//
#pragma once
#include "service_masina.h"
#include "service_spalatorie.h"
class MasinaUI {
private:
    MasinaService& service;
    ServiceSpalatorie& spalatorie;
    void adaugaUI();
    void stergeUI();
    void modificaUI();
    void cautaUI();
    void afiseazaToate() const;
    void filtrareUI() const;
    void sortareUI() const;
    void spalatorieUI() const;
public:
    explicit MasinaUI(MasinaService& srv, ServiceSpalatorie& spal): service{srv}, spalatorie{spal}{}
    void run();
};
