//
// Created by lupse on 6/15/2025.
//

#include "table_model.h"
int table_model::rowCount(const QModelIndex &parent) const{
  return static_cast<int>(students.size());
};
int table_model::columnCount(const QModelIndex &parent ) const {
  return 4;
};
QVariant table_model::data(const QModelIndex &index, int role) const {
      if(!index.isValid()) return QVariant();

      auto& student = students[index.row()];

      if(role == Qt::DisplayRole){
         switch(index.column()){
           case 0: return QString::number(student.getId());
           case 1: return QString::fromStdString(student.getNume());
           case 2: return QString::number(student.getVarsta());
           case 3: return QString::fromStdString(student.getFacultate());
           default: return QVariant();
         }
      }
      if(role == Qt::BackgroundRole){
        auto fac = student.getFacultate();
        if(fac == "mate") return QBrush(Qt::red);
        if(fac == "mate-info") return QBrush(Qt::green);
        if(fac == "info") return QBrush(Qt::blue);
        if(fac == "ai") return QBrush(Qt::cyan);
      }
      return QVariant();
}
QVariant table_model::headerData(int section, Qt::Orientation orientation, int role) const {
    if(orientation == Qt::Horizontal && role == Qt::DisplayRole){
      switch(section){
        case 0: return "NrMatricol";
        case 1: return "Nume";
        case 2: return "Varsta";
        case 3: return "Facultate";
      }
    }
    return QVariant();
};

void table_model::setData(vector<student> s){
  beginResetModel();
  students = s;
  endResetModel();
}

