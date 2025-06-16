//
// Created by lupse on 6/14/2025.
//

#ifndef TABLE_MODEL_H
#define TABLE_MODEL_H

#include "QWidget"
#include "QTableView"
#include "service_melodie.h"
class table_model: public QAbstractTableModel {
    private:
      vector<Melodie> melodii;
      std::map<int,int> ranks;
    public:
      explicit table_model(QObject* parent = nullptr);
      int rowCount(const QModelIndex &parent = QModelIndex()) const override;
      int columnCount(const QModelIndex &parent = QModelIndex()) const override;
      QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
      QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
      void setData(vector<Melodie> v, std::map<int,int> m);
};



#endif //TABLE_MODEL_H
