//
// Created by lupse on 6/15/2025.
//

#include "teste.h"


void teste::testStudent(){
  student s{1,"Marius",14,"mate"};
  assert(s.getId() == 1);
  assert(s.getNume() == "Marius");
  assert(s.getVarsta() == 14);
  assert(s.getFacultate() == "mate");
  s.setVarsta(1);
  assert(s.getVarsta() == 1);
}

void teste::testRepo() {
  std::filesystem::remove("../test_repo");
  std::filesystem::copy_file(
      std::filesystem::path("../test_base"),
      std::filesystem::path("../test_repo"),
      std::filesystem::copy_options::overwrite_existing
  );
  repo_student rp{"../test_repo"};
  auto s = rp.getAll();
  assert(s.size() == 10);
  assert(s[0].getId() == 1);
  assert(s[0].getNume() == "Marius");
  assert(s[0].getVarsta() == 19);
  assert(s[0].getFacultate() == "mate");

  rp.updateAge(1, 25);
  s = rp.getAll();
  assert(s[0].getVarsta() == 25);
  rp.updateAge(1, 19);

  s = rp.getAll();
  rp.del(1);
  s = rp.getAll();
  auto it = std::find_if(s.begin(), s.end(), [](const student& s) {
    return s.getId() == 1;
  });
  assert(it == s.end());
}

void teste::testSrv() {
  std::filesystem::remove("../test_service");
  std::filesystem::copy_file(
      std::filesystem::path("../test_base"),
      std::filesystem::path("../test_service"),
      std::filesystem::copy_options::overwrite_existing
  );
  repo_student rp{"../test_service"};
  service_student srv{rp};
  auto s = srv.getStudents();
  assert(s.size() == 10);
  assert(s[0].getId() == 1);
  assert(s[0].getNume() == "Marius");
  assert(s[0].getVarsta() == 19);
  assert(s[0].getFacultate() == "mate");

  s = srv.getStudentsSorted();
  for (int i = 1; i < static_cast<int>(s.size()); i++) {
    assert(s[i-1].getVarsta() <= s[i].getVarsta());
  }
  s = srv.getStudents();
  srv.intinerire();
  int i = 0;
  for (const auto& student: srv.getStudents()) {
    assert(student.getVarsta() == s[i].getVarsta()-1);
    i++;
  }
  srv.imbatranire();
  i= 0;
  for (const auto& student: srv.getStudents()) {
    assert(student.getVarsta() == s[i].getVarsta());
    i++;

  }
  srv.delStudents({1});
  s = rp.getAll();
  auto it = std::find_if(s.begin(), s.end(), [](const student& s) {
    return s.getId() == 1;
  });
  assert(it == s.end());
  srv.delStudents({2,3,4});
  s = rp.getAll();
  it = std::find_if(s.begin(), s.end(), [](const student& s) {
    return s.getId() == 2;
  });
  assert(it == s.end());
  s = rp.getAll();
  it = std::find_if(s.begin(), s.end(), [](const student& s) {
    return s.getId() == 3;

  });
  assert(it == s.end());
  s = rp.getAll();
  it = std::find_if(s.begin(), s.end(), [](const student& s) {
    return s.getId() == 4;
  });
  assert(it == s.end());
}

void teste::runAllTests(){
  testStudent();
  testRepo();
  testSrv();
  std::cout << "Teste rulate cu succes" << std::endl;
}

