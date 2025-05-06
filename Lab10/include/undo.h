//
// Created by lupse on 4/28/2025.
//

#ifndef UNDO_H
#define UNDO_H
class ActiuneUndo {
public:
    virtual void doUndo() = 0;
    virtual ~ActiuneUndo() = default;
};

class UndoAdauga : public ActiuneUndo {
    Masina masinaAdaugata;
    MasinaRepo& repo;
public:
    UndoAdauga(MasinaRepo& masinaRepo, Masina& masina): repo {masinaRepo}, masinaAdaugata {masina} {}

    void doUndo() override {
        repo.sterge(masinaAdaugata.getNrInmatriculare());
    };
};

class UndoSterge : public ActiuneUndo {
    Masina masinaStearsa;
    MasinaRepo& repo;
public:
    UndoSterge(MasinaRepo& masinaRepo, Masina& masina): repo {masinaRepo}, masinaStearsa {masina} {}

    void doUndo() override {
        repo.adauga(masinaStearsa);
    }
};

class UndoModifica : public ActiuneUndo {
    Masina masinaVeche;
    MasinaRepo& repo;
public:
    UndoModifica(MasinaRepo& masinaRepo, Masina& masina): repo {masinaRepo}, masinaVeche {masina} {}

    void doUndo() override {
        repo.modifica(masinaVeche);
    }
};
#endif //UNDO_H
