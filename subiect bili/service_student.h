//
// Created by lupse on 6/15/2025.
//

#ifndef SERVICE_STUDENT_H
#define SERVICE_STUDENT_H

#include "student.h"
#include "repo_student.h"
#include <algorithm>
class service_student {
    private:
      repo_student& repo;
      vector<repo_student> undo;
      vector<repo_student> redo;
    public:
      /// Constrcutorul clasei service_student intializeaza repo cu o referinta la un repo
      /// student
      /// @param r referinta la repo_student
      explicit service_student(repo_student& r);

      /// Returneaza toti studentii din repo
      /// @return vector de studenti
      vector<student> getStudents();

      /// Returneaza toti studentii din repo sortati dupa varsta crescator
      /// @return vector de studenti
      vector<student> getStudentsSorted();
      /// Pentru fiecare student din repo scade varsta cu 1
      void intinerire();
    ///Pentru fiecare student din repo creste varsta cu 1
      void imbatranire();

      /// Sterge fiecare student care id in vectorul ids
      /// @param ids vector de id uri
      void delStudents(vector<int> ids);
     /// Reface ultima operatie
      void undoRepo();
     /// Intoarce ultima operatie
      void redoRepo();
};



#endif //SERVICE_STUDENT_H
