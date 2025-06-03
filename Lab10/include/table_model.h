//
// Created by lupse on 6/3/2025.
//

#ifndef TABLE_MODEL_H
#define TABLE_MODEL_H
#include <QTableView>
#include <QString>
#include "domeniu_masina.h"
class MyTableModel : public QAbstractTableModel{
private:
    std::vector<Masina> masini;
public:
    void setMasini(const std::vector<Masina>& v);
    explicit MyTableModel(QObject *parent);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    [[nodiscard]] QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    [[nodiscard]] QVariant headerData(int section, Qt::Orientation orientation, int role) const override ;

};

#endif //TABLE_MODEL_H
