//
// Created by lupse on 6/15/2025.
//

#include "ui.h"

void ui::initGUI(){
   setLayout(main);
    main->addWidget(draw);
    draw->setMinimumHeight(100);
   table->setModel(model);
   table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
   main->addWidget(table);

   form->addRow("Artist",artist);
   form->addRow("Rank",rank);
   form->addRow(update);
   form->addRow(del);

   rank->setOrientation(Qt::Horizontal);
   rank->setRange(0,9);


   main->addLayout(form);



}
void ui::loadData(vector<melodie>v, map<int,int> map){
  model->setData(v,map);
    ranks = map;
    repaint();
}
void ui::initConnect(){
    connect(table->selectionModel(), &QItemSelectionModel::selectionChanged, [&](){
        auto index = table->currentIndex();
        if(!index.isValid()) return;
        auto idIndex = table->model()->index(index.row(),0);
        auto ArtistIndex = table->model()->index(index.row(),2);
        auto rankIndex = table->model()->index(index.row(),3);
        auto id =table->model()->data(idIndex).toInt();
        auto artistName = table->model()->data(ArtistIndex).toString();
        auto rankValue = table->model()->data(rankIndex).toInt();
        id_curent = id;
        artist->setText(artistName);
        rank->setValue(rankValue);
    });
    connect(update, &QPushButton::clicked, [&](){
        if(id_curent == -1) return;
        srv.updateMelodie(id_curent, artist->text().toStdString(), rank->value());
        loadData(srv.getMelodiiSorted(), srv.getMelodiiMap());
        id_curent = -1;
        artist->clear();
        rank->setValue(0);
    });
    connect(del, &QPushButton::clicked, [&](){
        if(id_curent == -1) return;
        try{
            srv.delMelodie(id_curent,artist->text().toStdString());
            loadData(srv.getMelodiiSorted(), srv.getMelodiiMap());
            id_curent = -1;
            artist->clear();
            rank->setValue(0);
         } catch (std::runtime_error& e){
           QMessageBox::warning(this,"Eror",e.what());
         }
    });
}
