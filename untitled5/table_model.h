//
// Created by lupse on 6/14/2025.
//

#ifndef TABLE_MODEL_H
#define TABLE_MODEL_H

#include "QTableView"
#include "produs.h"
#include <vector>
using std::vector;

class TableModel: public QAbstractTableModel{
    private:
      vector<Produs> produse;
     QSlider* slider;
    public:
       explicit TableModel(QObject *parent, QSlider* slider = nullptr);
       int rowCount(const QModelIndex &parent = QModelIndex()) const override;
       int columnCount(const QModelIndex &parent = QModelIndex()) const override;
       [[nodiscard]] QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
       [[nodiscard]] QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
       void setData(vector<Produs> prod);
       void setSlider(QSlider* s);
};



#endif //TABLE_MODEL_H
