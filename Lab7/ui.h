//
// Created by lupse on 4/7/2025.
//
#pragma once
#include "service_masina.h"

class MasinaUI {
private:
    MasinaService& service;

    void adaugaUI();
    void stergeUI();
    void modificaUI();
    void cautaUI();
    void afiseazaToate() const;

public:
    explicit MasinaUI(MasinaService& srv): service{srv} {}
    void run();
};
