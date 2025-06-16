//
// Created by lupse on 6/14/2025.
//

#ifndef UI_H
#define UI_H

#include "service_produse.h"
#include "tip_window.h"

#include "QWidget"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include "QTableWidget"
#include "QTableView"
#include "QFormLayout"
#include "QLineEdit"
#include "QPushButton"
#include "table_model.h"
#include "QMessageBox"
#include "QSlider"
class Ui : public QWidget, public observer{
  private:
    ServiceProduse& srv;
    std::map<string, tip_window*> tips;
    QVBoxLayout* mainLayout = new QVBoxLayout();
    QTableView* table = new QTableView(this);
    TableModel* model = new TableModel(this,slider);

    QLineEdit* id = new QLineEdit();
    QLineEdit* nume = new QLineEdit();
    QLineEdit* tip = new QLineEdit();
    QLineEdit* pret = new QLineEdit();
    QFormLayout* layoutForm = new QFormLayout();

    QSlider* slider = new QSlider(Qt::Horizontal);
    QPushButton* btnAdd = new QPushButton("Add");
    QHBoxLayout* controlLayout = new QHBoxLayout();

    void initGUI();
    void loadData(vector<Produs> data);
    void initConnect();
    void initTypeWindows(std::map<string,int> mp);
    void updateTypeWindows(std::map<string,int> mp);
    void update() override;
    public:
    Ui(ServiceProduse &_serviceProdus): srv(_serviceProdus) {
        srv.addObserver(this);
        initGUI();
        initConnect();
        loadData(srv.getAllProduse());
        initTypeWindows(srv.getProduseByTip());
    }
};



#endif //UI_H
