//
// Created by lupse on 5/20/2025.
//

#ifndef JOC_H
#define JOC_H

#include <vector>
#include <string>

class Tractor {
private:
     int id;
     std::string name;
     std::string type;
     int nr_of_wheels;
public:
  Tractor(int id, const std::string& name, const std::string& type, int nr_of_wheels)
      : id(id), name(name), type(type), nr_of_wheels(nr_of_wheels) {}
     std::string getName() const;
     int getId() const;
     std::string getType() const;
     int getNrOfWheels() const;
};



#endif //JOC_H
