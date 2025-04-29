//
// Created by lupse on 4/7/2025.
//
#include "domeniu_masina.h"

Masina::Masina(const std::string& nr, const std::string& prod,
               const std::string& mod, const std::string& t)
    : nrInmatriculare{nr}, producator{prod}, model{mod}, tip{t} {}


const std::string& Masina::getNrInmatriculare() const {
    return nrInmatriculare;
}

const std::string& Masina::getProducator() const {
    return producator;
}

const std::string& Masina::getModel() const {
    return model;
}

const std::string& Masina::getTip() const {
    return tip;
}

void Masina::setProducator(const std::string& prod) {
    producator = prod;
}

void Masina::setModel(const std::string& mod) {
    model = mod;
}

void Masina::setTip(const std::string& t) {
    tip = t;
}

bool Masina::operator==(const Masina& other) const {
    return nrInmatriculare == other.nrInmatriculare;
}
