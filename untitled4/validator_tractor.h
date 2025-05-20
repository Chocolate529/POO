//
// Created by lupse on 5/20/2025.
//

#ifndef VALIDATOR_TRACTOR_H
#define VALIDATOR_TRACTOR_H

#include <string>

class validator_tractor {
    std::string eror="";

    public:
      std::string validate(const std::string& name, const std::string& type, int nr_of_wheels) ;
};



#endif //VALIDATOR_TRACTOR_H
