//
// Created by lupse on 6/14/2025.
//

#include "table_model.h"
 TableModel::TableModel(QObject *parent,QSlider* slider): QAbstractTableModel(parent) ,
slider(slider) {}
int TableModel::rowCount(const QModelIndex &parent) const {
  return static_cast<int>(produse.size());
}
int TableModel::columnCount(const QModelIndex &parent ) const {
  return 5;
}
QVariant TableModel::data(const QModelIndex &index, int role ) const {
  if(!index.isValid() || index.row() >= produse.size()) return QVariant();

  const Produs &p = produse[index.row()];
  if(role == Qt::DisplayRole){

      switch (index.column()) {
        case 0: return QString::number(p.getId());
        case 1: return QString::fromStdString(p.getName());
        case 2: return QString::fromStdString(p.getTip());
        case 3: return QString::number(p.getPret());
        case 4: return QString::number(p.getNrVocale());
        default: return QVariant();
      }
   }
   if(role == Qt::BackgroundRole && slider){
       if(p.getPret() <= slider->value()){
         return QBrush(Qt::red);
       }
   }
   return QVariant();
};
QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role ) const {
  if(orientation == Qt::Horizontal && role == Qt::DisplayRole){
    switch (section) {
      case 0: return "Id";
      case 1: return "Name";
      case 2: return "Tip";
      case 3: return "Pret";
      case 4: return "Nr Vocale";

    }
  }
  return QAbstractTableModel::headerData(section, orientation, role);
};
void TableModel::setData(vector<Produs> prod){
    beginResetModel();
    produse = prod;
    endResetModel();
}
void TableModel::setSlider(QSlider* s){
  slider=s;
}
