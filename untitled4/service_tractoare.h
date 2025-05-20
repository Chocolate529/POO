//
// Created by lupse on 5/20/2025.
//

#ifndef SERVICE_TRACTOARE_H
#define SERVICE_TRACTOARE_H

#include "repo_tractor.h"
#include "validator_tractor.h"
#include <unordered_map>
class service_tractoare  {
    private:
      repo_tractor& repo;
      validator_tractor& validator;
    public:
        service_tractoare(repo_tractor& repo, validator_tractor& vld) : repo(repo), validator(vld) {}
        void add_tractor(int id, const std::string& name, const std::string& type, int nr_of_wheels);
        std::vector<Tractor> get_all_tractors() const;
    std::unordered_map<std::string, int> get_types() const;

};



#endif //SERVICE_TRACTOARE_H
