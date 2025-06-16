//
// Created by lupse on 6/14/2025.
//

#ifndef SERVICE_PRODUSE_H
#define SERVICE_PRODUSE_H

#include "observer.h"
#include "produs.h"
#include "repo_produs.h"
#include "validator_produs.h"
#include <map>
class ServiceProduse: public observable {
    private:
      RepoProdus& rp;
      ValidatorProdus& vp;

    public:

      ServiceProduse(RepoProdus& _rp, ValidatorProdus& _vp) : rp{_rp}, vp{_vp} {};
      vector<Produs> getAllProduse() ;
      void addProdus(int id, string name, string tip, double price);
      std::map<string, int> getProduseByTip();
};



#endif //SERVICE_PRODUSE_H
