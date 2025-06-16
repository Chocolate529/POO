//
// Created by lupse on 6/15/2025.
//

#include "teste.h"

void teste::testMelodie(){
  melodie m{1,"m1","a1",2};
  assert(m.getId() == 1);
  assert(m.getName() == "m1");
  assert(m.getArtist() == "a1");
  assert(m.getRank() == 2);
  m.setRank(3);
  assert(m.getRank() == 3);
  m.setArtist("a2");
  assert(m.getArtist() == "a2");
}

void teste::testRepo(){
  std::filesystem::remove("../test_repo");
  std::filesystem::copy_file(
      std::filesystem::path("../base_melodii"),
      std::filesystem::path("../test_repo"),
      std::filesystem::copy_options::overwrite_existing);
  repo_melodie rp{"../test_repo"};
  auto m = rp.getAll();
  assert(m.size() == 10);
  assert(m[0].getId() == 1);
  assert(m[0].getName() == "M1");
  assert(m[0].getArtist() == "A1");
  assert(m[0].getRank() == 0);

  rp.update(1,"A2",5);
  m = rp.getAll();
  assert(m.size() == 10);
  assert(m[0].getId() == 1);
  assert(m[0].getName() == "M1");
  assert(m[0].getArtist() == "A2");
  assert(m[0].getRank() == 5);

  int i= 1;
  for(const auto &it : m){
    rp.del(it.getId());
    auto m1 = rp.getAll();
    assert(m1.size() == m.size()-i);
    i++;
  }
}

void teste::testSrv(){
  std::filesystem::remove("../test_srv");
  std::filesystem::copy_file(
      std::filesystem::path("../base_melodii"),
      std::filesystem::path("../test_srv"),
      std::filesystem::copy_options::overwrite_existing);
  repo_melodie rp{"../test_srv"};
  service_melodii sr{rp};
  auto m = sr.getMelodii();
  assert(m.size() == 10);
  assert(m[0].getId() == 1);
  assert(m[0].getName() == "M1");
  assert(m[0].getArtist() == "A1");
  assert(m[0].getRank() == 0);

  m = sr.getMelodiiSorted();
  for(int i = 1; i < m.size(); i++){
    assert(m[i-1].getRank() < m[i].getRank());
  }

  auto map = sr.getMelodiiMap();
  for(auto [rank,times] : map){
    assert(times == 1);
  }

  sr.updateMelodie(1,"A2",5);
  m = sr.getMelodii();
  assert(m.size() == 10);
  assert(m[0].getId() == 1);
  assert(m[0].getName() == "M1");
  assert(m[0].getArtist() == "A2");
  assert(m[0].getRank() == 5);

  int i= 1;

  for(const auto &it : m){
    try{
    sr.delMelodie(it.getId(),it.getArtist());
    auto m1 = sr.getMelodii();
    assert(m1.size() == m.size()-i);
    i++;
    } catch(std::runtime_error& e){
      assert(true);
    }
  }

}

void teste::runAllTests(){
  testMelodie();
  testRepo();
  testSrv();
  cout << "All tests have passed!" << endl;
}