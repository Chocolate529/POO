//
// Created by lupse on 6/15/2025.
//

#ifndef TABLE_MODEL_H
#define TABLE_MODEL_H

#include "QTableView"
#include "service_melodii.h"
class table_model: public QAbstractTableModel {
    private:
      vector<melodie> melodii;
      map<int,int> ranks;
    public:
      table_model(QObject *parent = nullptr);
      int rowCount(const QModelIndex &parent = QModelIndex()) const override;
      int columnCount(const QModelIndex &parent = QModelIndex()) const override;
      QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
      QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
      void setData(vector<melodie> m, map<int,int> mp);
};



#endif //TABLE_MODEL_H
