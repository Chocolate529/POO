//
// Created by lupse on 6/14/2025.
//

#include "service_produse.h"
vector<Produs> ServiceProduse::getAllProduse(){
  return rp.getAll();
}
void ServiceProduse::addProdus(int id, string name, string tip, double price){
  Produs produs{id, name, tip, price};
  vp.valideaza(produs);
  rp.add(produs);
  notifyObservers();
}
std::map<string, int> ServiceProduse::getProduseByTip() {
  std::map<string, int> ProduseByTip;
  for (const auto &produs : rp.getAll()) {
    ProduseByTip[produs.getTip()] ++;
  }
  return ProduseByTip;
}

