//
// Created by lupse on 6/15/2025.
//

#include "service_melodii.h"
service_melodii::service_melodii(repo_melodie& repo_melodie): repo(repo_melodie){
  for(auto const& m: repo.getAll()){
    artist_mel[m.getArtist()]++;
  }
}
vector<melodie> service_melodii::getMelodii(){
  return repo.getAll();
}
vector<melodie> service_melodii::getMelodiiSorted(){
  vector<melodie> m = repo.getAll();
  std::sort(m.begin(), m.end(), [](const melodie& x, const melodie& y){
    return x.getRank() < y.getRank();
  });
  return m;
}
map<int,int> service_melodii::getMelodiiMap(){
  std::map<int,int> m;
  for(const auto& e: repo.getAll()){
    m[e.getRank()]++;
  }
  return m;
}
void service_melodii::updateMelodie(int id, string a, int r){
  repo.update(id,a,r);
}
void service_melodii::delMelodie(int id,string artist){
  if(artist_mel[artist]-1>0){
  repo.del(id);
  artist_mel[artist]--;
  }else {
    throw std::runtime_error("Ultima Melodie a artistului"+artist);
  }

}
