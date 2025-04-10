//
// Created by lupse on 4/7/2025.
//
#pragma once
#include <string>

class Masina {
private:
    std::string nrInmatriculare;
    std::string producator;
    std::string model;
    std::string tip;

public:
    Masina(const std::string& nr, const std::string& prod,
           const std::string& mod, const std::string& t);

    const std::string& getNrInmatriculare() const;
    const std::string& getProducator() const;
    const std::string& getModel() const;
    const std::string& getTip() const;

    void setProducator(const std::string& prod);
    void setModel(const std::string& mod);
    void setTip(const std::string& t);

    bool operator==(const Masina& other) const;
};


