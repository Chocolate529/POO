//
// Created by lupse on 5/20/2025.
//
#include <stdexcept>
#include "service_tractoare.h"
void service_tractoare::add_tractor(int id, const std::string& name, const std::string& type, int nr_of_wheels){
   std::string err = validator.validate(name, type, nr_of_wheels);
   if(!err.empty()){
       throw std::runtime_error(err);
   }
   repo.add_tractor(Tractor(id, name, type, nr_of_wheels));
}
std::vector<Tractor> service_tractoare::get_all_tractors() const {
    return repo.get_all_tractors();
}
std::unordered_map<std::string, int> service_tractoare::get_types() const{
    std::unordered_map<std::string, int> types_count;
    for (const auto& tractor : repo.get_all_tractors()) {
        types_count[tractor.getType()]++;
    }
    return types_count;
};
