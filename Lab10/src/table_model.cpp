//
// Created by lupse on 6/3/2025.
//
#include "table_model.h"
#include <QString>
MyTableModel::MyTableModel(QObject *parent):
  QAbstractTableModel(parent){
}

void MyTableModel::setMasini(const std::vector<Masina>& v) {
  beginResetModel();
  masini = v;
  endResetModel();
}

int MyTableModel::rowCount(const QModelIndex &parent) const {
  return static_cast<int>(masini.size());
}

int MyTableModel::columnCount(const QModelIndex &parent) const {
  return 4;
}

QVariant MyTableModel::data(const QModelIndex &index, int role) const {
  qDebug() << index.row() << " " << index.column();

  if (!index.isValid() || role != Qt::DisplayRole)
    return {};
  const auto& m = masini[index.row()];
  switch (index.column()) {
    case 0: return QString::fromStdString(m.getNrInmatriculare());
    case 1: return QString::fromStdString(m.getProducator());
    case 2: return QString::fromStdString(m.getModel());
    case 3: return QString::fromStdString(m.getTip());
    default: return {};
  }
}
QVariant MyTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
  if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
    switch (section) {
      case 0: return "Numar Inmatriculare";
      case 1: return "Producator";
      case 2: return "Model";
      case 3: return "Tip";
    }
  }
  return QAbstractTableModel::headerData(section, orientation, role);
}
