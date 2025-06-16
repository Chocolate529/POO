//
// Created by lupse on 6/14/2025.
//

#include "service_melodie.h"
service_melodie::service_melodie(repo_melodie& r) : rp(r) {}

vector<Melodie> service_melodie::getAllMelodii(){
  return rp.getAll();
}

std::map<int, int> service_melodie::getAllByRank() {
  std::map<int, int> ret;
  for (const auto& e: rp.getAll()) {
    ret[e.getRank()]++;
  }
  return ret;
}
