//
// Created by lupse on 6/14/2025.
//

#include "validator_produs.h"

#include <stdexcept>

void ValidatorProdus::valideaza(const Produs& produs) {
    string err;
    if(produs.getName().empty()){
        err = "Produs name is empty\n";
    }
    if(produs.getTip().empty()){
        err = "Produs tip is empty\n";
    }
    if(produs.getPret() > 100.0 || produs.getPret() < 1.0){
        err = "Produs pret is invalid(must be between 1 and 100)\n";
    }
    if (!err.empty()) {
        throw std::invalid_argument(err);
    }
}
