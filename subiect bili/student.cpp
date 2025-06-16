//
// Created by lupse on 6/15/2025.
//

#include "student.h"
student::student(int id,  string nume ,int varsta, string facultate):
     id(id),varsta(varsta),nume(nume),facultate(facultate){};
int student::getId() const{
  return id;
};
int student::getVarsta() const{
  return varsta;
};
string student::getNume() const{
  return nume;
};
string student::getFacultate() const{
  return facultate;
};
void student::setVarsta(int varsta) {
  this->varsta = varsta;
}
