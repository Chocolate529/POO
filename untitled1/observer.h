//
// Created by lupse on 5/20/2025.
//

#ifndef OBSERVER_H
#define OBSERVER_H
#include <vector>
#include <algorithm>
class Observer {
public:
    virtual void update() = 0;
    virtual ~Observer() = default;
};

class Observable {
private:
    std::vector<Observer*> observers;
public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    };
    void removeObserver(Observer* observer){
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    };

protected:
    void notifyObservers() {
        for (auto observer : observers) {
            observer->update();
        }
    };
};
#endif //OBSERVER_H
