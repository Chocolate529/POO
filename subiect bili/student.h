//
// Created by lupse on 6/15/2025.
//

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using std::string;

class student {
    private:
      int id, varsta;
      string nume,facultate;

    public:
      /// Constructorul clasei student intializeaza campurile id cu id
      /// varsta cu varsta, nume cu nume, facultate cu facultate
      /// @param id numar intreg unic
      /// @param nume string nevid
      /// @param varsta numar intreg > 0
      /// @param facultate string nevid
      student(int id,  string nume ,int varsta, string facultate);

      /// Returneaza id-ul unui student
      /// @return numar intreg
      int getId() const;

      /// Returneaza varsta unui student
      /// @return numar intreg
      int getVarsta() const;

      /// Returneaza numele unui student
      /// @return string
      string getNume() const;
     ///Returneaza facultate unui student
     /// @return string
      string getFacultate() const;

      /// Steeaza varsta unui student
      /// @param varsta numar intreg > 0
      void setVarsta(int varsta);
};



#endif //STUDENT_H
