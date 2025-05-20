//
// Created by lupse on 5/20/2025.
//

#include "validator_tractor.h"
std::string validator_tractor::validate(const std::string& name, const std::string& type, int nr_of_wheels) {
    std::string eror;
    if (name.empty() ) {
        eror += "Name cannot be empty\n";
    }
    if(type.empty()) {
        eror += "Type cannot be empty\n";
    }
    if(nr_of_wheels % 2 != 0 || nr_of_wheels < 2 || nr_of_wheels > 16) {
        eror += "Number of wheels must be positive\n";
    }
    return eror;
}