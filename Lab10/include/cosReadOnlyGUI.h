//
// Created by lupse on 5/27/2025.
//

#ifndef COSREADONLYGUI_H
#define COSREADONLYGUI_H

#include <QWidget>
#include <QPainter>
#include <vector>
#include "domeniu_masina.h"
#include "observer.h"
#include "service_spalatorie.h"
class cosReadOnlyGUI: public QWidget , public Observer{
  private:
    ServiceSpalatorie& srv;
    std::vector<Masina> masini;
    void refreshGUI(std::vector<Masina> v);
  public:
    cosReadOnlyGUI(ServiceSpalatorie& srv):srv(srv) {
      srv.addObserver(this);
      refreshGUI(srv.getAllMasini());
    }
    void paintEvent(QPaintEvent* ev) override;
    void update() override;
};



#endif //COSREADONLYGUI_H
