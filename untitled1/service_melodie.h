//
// Created by lupse on 5/20/2025.
//

#ifndef SERVICE_MELODIE_H
#define SERVICE_MELODIE_H
#include "repo_melodie.h"
#include "observer.h"
#include <unordered_map>
class ServiceMelodie : public Observable {
    // Inherits from Observable to allow for observer pattern
    // This allows the service to notify observers when the data changes
 private:
    FileRepoMelodie& repo;
    std::unordered_map<std::string, int> artistSongCount;
    void updateArtistSongCount();
public:

    ServiceMelodie(FileRepoMelodie& repo): repo{repo} {
        updateArtistSongCount();
    }
    void removeMeloide(int id);
    void updateMelodie(int id, const std::string& titlu, int rank);

    std::vector<Melodie> getAllMelodii() const;
};



#endif //SERVICE_MELODIE_H
