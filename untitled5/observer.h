//
// Created by lupse on 6/14/2025.
//

#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>
#include <algorithm>

class observer {
    public:
       virtual void update() = 0;
  virtual ~observer() = default;
};

class observable {
  private:
    std::vector<observer*> observers;
  protected:
    void notifyObservers() {
       for(auto& obs: observers) {
         obs->update();
       }
    }
  public:
    void addObserver(observer* obs) {
      observers.push_back(obs);
    }
    void removeObserver(observer* obs) {
      observers.erase(std::remove(observers.begin(), observers.end(), obs),observers.end());
    }

};

#endif //OBSERVER_H
