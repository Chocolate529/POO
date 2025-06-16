//
// Created by lupse on 6/15/2025.
//

#ifndef UI_H
#define UI_H

#include "QWidget"
#include "service_melodii.h"
#include "table_model.h"
#include "draw_widget.h"
#include "QVBoxLayout"
#include "QLineEdit"
#include "QFormLayout"
#include "QPushButton"
#include "QSlider"
#include "QMessageBox"
class ui : public QWidget{
    private:
  map<int,int> ranks;
      service_melodii& srv;
      int id_curent = -1;
      QVBoxLayout* main = new QVBoxLayout();

      QTableView* table = new QTableView();
      table_model* model = new table_model();

      QFormLayout* form = new QFormLayout();
      QLineEdit* artist = new QLineEdit();
      QSlider* rank = new QSlider();

      draw_widget* draw = new draw_widget();

      QPushButton* update = new QPushButton("Modifica");
      QPushButton* del = new QPushButton("Sterge");

      void initGUI();
      void loadData(vector<melodie> v, map<int,int> map);
      void initConnect();

    public:
      ui(service_melodii& srv): srv(srv){
        initGUI();
        initConnect();
        loadData(srv.getMelodiiSorted(),srv.getMelodiiMap());
      }
  void paintEvent(QPaintEvent *) override{
        QPainter painter(this);
        int margin = 30;
        int radiusStep = 12;
        struct Corner { int x, y; };
        std::map<int, Corner> corners = {
          {1, {margin, margin}}, // top-left
          {2, {width() - margin, margin}}, // top-right
          {3, {margin, height() - margin}}, // bottom-left
          {4, {width() - margin, height() - margin}} // bottom-right
        };
        for (int rank = 1; rank <= 4; ++rank) {
          int count = ranks.count(rank) ? ranks.at(rank) : 0;
          auto [cx, cy] = corners[rank];
          for (int i = 1; i <= count; ++i) {
            int r = i * radiusStep;
            painter.drawEllipse(QPoint(cx, cy), r, r);
          }
          painter.drawText(cx - 8, cy + 5, QString::number(rank));
        }




      }
};



#endif //UI_H
