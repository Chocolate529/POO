//
// Created by lupse on 6/15/2025.
//

#ifndef TABLE_MODEL_H
#define TABLE_MODEL_H

#include "service_student.h"
#include "QTableView"
class table_model : public QAbstractTableModel {
    private:
      vector<student> students;

    public:
      table_model(QObject *parent) : QAbstractTableModel(parent) {}
      int rowCount(const QModelIndex &parent = QModelIndex()) const override;
      int columnCount(const QModelIndex &parent = QModelIndex()) const override;
      QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
      QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
      void setData(vector<student> s);
};



#endif //TABLE_MODEL_H
