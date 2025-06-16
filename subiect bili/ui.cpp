//
// Created by lupse on 6/15/2025.
//

#include "ui.h"
void ui::loadData(vector<student> v){
  model->setData(v);
}
void ui::initConnect(){
  connect(young, QPushButton::clicked, this, [&]() {
    srv.intinerire();
    loadData(srv.getStudentsSorted());
  });
  connect(old, QPushButton::clicked, this, [&]() {
    srv.imbatranire();
    loadData(srv.getStudentsSorted());
  });
  connect(table->selectionModel(), QItemSelectionModel::selectionChanged, this, [&]() {
    if (table->selectionModel()->hasSelection()) {
      selected.clear();
        for (const auto& s : table->selectionModel()->selectedRows()) {
          auto idIndex = table->model()->index(s.row(),0);
          auto id =table->model()->data(idIndex).toInt();
          selected.push_back(id);

        }
    }
  });
  connect(del, QPushButton::clicked, this, [&]() {
    srv.delStudents(selected);
    selected.clear();
    loadData(srv.getStudentsSorted());
  });
  connect(undo, QPushButton::clicked, this, [&]() {
    srv.undoRepo();
    loadData(srv.getStudentsSorted());
  });
  connect(redo, QPushButton::clicked, this, [&]() {
    srv.redoRepo();
    loadData(srv.getStudentsSorted());
  });
}
void ui::initGUI(){
  setLayout(main);

  table->setModel(model);
  table->setSelectionBehavior(QAbstractItemView::SelectRows);
  main->addWidget(table);

  main->addLayout(controls);
  controls->addWidget(young);
  controls->addWidget(old);
  controls->addWidget(del);
  controls->addWidget(undo);
  controls->addWidget(redo);
}