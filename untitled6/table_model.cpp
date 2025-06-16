//
// Created by lupse on 6/15/2025.
//

#include "table_model.h"
table_model::table_model(QObject *parent):QAbstractTableModel(parent){};
int table_model::rowCount(const QModelIndex &parent) const {
  return static_cast<int>(melodii.size());
}
int table_model::columnCount(const QModelIndex &parent) const {
  return 5;
}
QVariant table_model::data(const QModelIndex &index, int role  ) const {
  if(!index.isValid()) return QVariant();

  auto m = melodii[index.row()];
  auto times = ranks.at(m.getRank());
  if(role == Qt::DisplayRole){
    switch(index.column()){
      case 0: return QString::number(m.getId());
      case 1: return QString::fromStdString(m.getName());
      case 2: return QString::fromStdString(m.getArtist());
      case 3: return QString::number(m.getRank());
      case 4: return QString::number(times);
      default: return QVariant();
    }
  }
  return QVariant();
}
QVariant table_model::headerData(int section, Qt::Orientation orientation, int role) const {
  if(role == Qt::DisplayRole && orientation == Qt::Horizontal){
    switch(section){
      case 0: return "Id";
      case 1: return"Name";
      case 2:return "Artist";
      case 3:return "Rank";
      case 4: return "Same Rank";
    }
  }
  return QVariant();
}
void table_model::setData(vector<melodie> m, map<int,int> mp){
  beginResetModel();
  melodii = m;
  ranks = mp;
  endResetModel();
}