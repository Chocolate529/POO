//
// Created by lupse on 6/14/2025.
//

#include "ui.h"
void ui::initGUI(){
   setLayout(main);

   tableView->setModel(tableModel);
   main->addWidget(tableView);

   main->addLayout(updateLayout);


};
void ui::loadData(vector<Melodie> v, std::map<int,int> m) {
   tableModel->setData(v ,m);
};