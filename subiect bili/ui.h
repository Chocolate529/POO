//
// Created by lupse on 6/15/2025.
//

#ifndef UI_H
#define UI_H

#include "service_student.h"
#include "table_model.h"
#include "QWidget"
#include "QVBoxLayout"
#include "QPushButton"
class ui : public QWidget{
    private:
      service_student& srv;

      vector<int> selected;

      QVBoxLayout* main = new QVBoxLayout();

      QTableView* table = new QTableView();
      table_model* model = new table_model(this);

      QHBoxLayout* controls = new QHBoxLayout();
      QPushButton* young = new QPushButton("Intinerire");
      QPushButton* old = new QPushButton("Imbatranire");
      QPushButton* del = new QPushButton("Sterge Selectie");
      QPushButton* undo = new QPushButton("Undo");
      QPushButton* redo = new QPushButton("Redo");

      void loadData(vector<student> v);
      void initConnect();
      void initGUI();
    public:
      ui(service_student& srv): srv(srv){
          initGUI();
          initConnect();
          loadData(srv.getStudentsSorted());
      };
};



#endif //UI_H
