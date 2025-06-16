//
// Created by lupse on 6/15/2025.
//

#include "service_student.h"
service_student::service_student(repo_student& r) : repo(r) {}
vector<student> service_student::getStudents() {
  return repo.getAll();
}
vector<student> service_student::getStudentsSorted() {
  vector<student> s = repo.getAll();
  std::sort(s.begin(), s.end(), [](const student& s1, const student& s2) {
    return s1.getVarsta() < s2.getVarsta();
  });
  return s;
}
void service_student::intinerire() {
  undo.push_back(repo);
  for (const auto& s : repo.getAll()) {
    repo.updateAge(s.getId(), s.getVarsta()-1);
  }
}
void service_student::imbatranire() {
  undo.push_back(repo);
  for (const auto& s : repo.getAll()) {
    repo.updateAge(s.getId(), s.getVarsta()+1);
  }
};

void service_student::delStudents(vector<int> ids) {
  undo.push_back(repo);
  for (const auto& i: ids) {
    repo.del(i);
  }
}
void service_student::undoRepo() {
  if (undo.size() > 0) {
    redo.push_back(repo);
    repo = undo.back();
    undo.pop_back();
  }
}
void service_student::redoRepo() {
   if (redo.size() > 0) {
     undo.push_back(repo);
     repo = redo.back();
     redo.pop_back();
   }
}