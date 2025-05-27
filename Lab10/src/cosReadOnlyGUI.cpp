//
// Created by lupse on 5/27/2025.
//

#include "cosReadOnlyGUI.h"
void cosReadOnlyGUI::paintEvent(QPaintEvent* ev) {
  QPainter painter(this);
  int i = 0;
  for(const auto& m : masini) {
        painter.fillRect(i*50, 0, 30, 50, QColor(Qt::white));
        i++;
  }
}
void cosReadOnlyGUI::update() {
  refreshGUI(srv.getAllMasini());
  repaint();
}
void cosReadOnlyGUI::refreshGUI(std::vector<Masina> v){
  masini = v;

}