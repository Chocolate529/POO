//
// Created by lupse on 6/15/2025.
//

#ifndef REPO_STUDENT_H
#define REPO_STUDENT_H
#include <fstream>
#include <sstream>
#include "student.h"
#include <vector>
using std::vector;
class repo_student {
    private:
      vector<student> students;
      const string& fileName;

      /**
       * Citeste fiecare student dintr un fisier id,nume,varsta,facultate
       * Arunca runtime exception daca nu gaseste fisierul
       */
      void loadFromFile();
    /**
       *Scrie fiecare student intr un fisier id,nume,varsta,facultate
       * Arunca runtime exception daca nu gaseste fisierul
       */
      void saveToFile();
    public:
      /// Constructoreul clasei repo_student initializeaza fileName cu fileName
      /// @param fileName referinta constanta la un string - numele fisieruli
      explicit repo_student(const string& fileName);

      /// Assigment constructor pentru repo_student copiaza in this vectorul de studenti
      /// si updateaza continul fisierului
      /// @param ot instanta a clasei repo_student
      /// @return o referinta la repo_student
      repo_student& operator=(const repo_student& ot) {
          students = ot.students;
          saveToFile();
          return *this;
      }

      /// Returneaza toti studentii din repo
      /// @return vector de studenti
      vector<student> getAll();

      /// Updateaza varsta unui student cu id unic identificabil cu age
      /// @param id numar intreg unic fiecarui student
      /// @param age numar intreg
      void updateAge(int id, int age);

      /// Stege un student din repo in functie de id unic
      /// @param id numar intreg
      void del(int id);
};



#endif //REPO_STUDENT_H
