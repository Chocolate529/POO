//
// Created by lupse on 6/15/2025.
//

#include "repo_student.h"

#include <algorithm>

repo_student::repo_student(const string& fileName):
   fileName(fileName){};
void repo_student::loadFromFile(){
  students.clear();
  std::ifstream file(fileName);
  string line;
  while (std::getline(file, line)) {
    std::stringstream ss(line);
    string value;
    vector<string> tokens;
    while (std::getline(ss, value, ',')) {
      tokens.push_back(value);
    }
    int id = std::stoi(tokens[0]);
    string nume = tokens[1];
    int v = std::stoi(tokens[2]);
    string fac = tokens[3];
    students.emplace_back(id, nume, v, fac);
  }
}

void repo_student::saveToFile() {
    std::ofstream file(fileName);
   for (const auto& student : students) {
     file << student.getId() << ","
     << student.getNume() << ","
      << student.getVarsta() << ","
     <<student.getFacultate() << std::endl;
   }
}

vector<student> repo_student::getAll() {
  loadFromFile();
  return students;
}

void repo_student::updateAge(int id, int age) {
  loadFromFile();
  auto it = std::find_if(students.begin(), students.end(), [=](const student& s) {
    return s.getId() == id;
  });
  if (it != students.end()) {
    it->setVarsta(age);
    saveToFile();
  } else {
    throw::std::runtime_error("nu exista sudentul");
  }

}

void repo_student::del(int id) {
  loadFromFile();
  auto it =  std::find_if(students.begin(), students.end(), [=](const student& s) {
    return s.getId() == id;
  });
  if (it != students.end()) {
    students.erase(it);
    saveToFile();
  } else {
    throw::std::runtime_error("nu exista sudentul");
  }
}
