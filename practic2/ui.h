//
// Created by lupse on 6/14/2025.
//

#ifndef UI_H
#define UI_H

#include "QWidget"
#include "QVBoxLayout"

#include "QLineEdit"
#include "QPushButton"
#include "QSlider"
#include "table_model.h"
#include "service_melodie.h"
class ui: public QWidget {
    private:
      service_melodie& service;
      QVBoxLayout* main = new QVBoxLayout();
      QTableView* tableView = new QTableView;
      table_model* tableModel = new table_model(this);

      QVBoxLayout* updateLayout = new QVBoxLayout();
      QLineEdit* titlu = new QLineEdit();
      QSlider* sliderRank = new QSlider();
      QPushButton* btnUpdate = new QPushButton("Update");

      void initGUI();
      void loadData(vector<Melodie> v, std::map<int,int> m);
      void initConnect();
    public:
      explicit ui(service_melodie& service): service(service) {
        initGUI();
        loadData(service.getAllMelodii(), service.getAllByRank());
      };
};



#endif //UI_H
