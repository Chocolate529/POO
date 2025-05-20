//
// Created by lupse on 5/20/2025.
//

#ifndef GUI_H
#define GUI_H
#include "service_tractoare.h"
#include "tractor.h"
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QMessageBox>
#include <QPainter>
#include <QMouseEvent>
class WheelsWidget : public QWidget {
    Q_OBJECT
    int selected_wheels = 0;
public:
    explicit WheelsWidget(QWidget* parent = nullptr) : QWidget(parent) {}
    void setWheels(int n) { selected_wheels = n; update(); }
protected:
    void paintEvent(QPaintEvent*) override {
        QPainter painter(this);
        painter.setPen(Qt::black);
        painter.setBrush(Qt::red);
        int radius = 20, spacing = 10;
        int startX = 10, y = height() / 2 - radius;
        for (int i = 0; i < selected_wheels; ++i) {
            int x = startX + i * (2 * radius + spacing);
            painter.drawEllipse(x, y, 2 * radius, 2 * radius);

        }
    }
    void mousePressEvent(QMouseEvent* event) override {
        int radius = 20, spacing = 10;
        int startX = 10, y = height() / 2 - radius;
        for (int i = 0; i < selected_wheels; ++i) {
            int x = startX + i * (2 * radius + spacing);
            QRect circleRect(x, y, 2 * radius, 2 * radius);
            if (circleRect.contains(event->pos())) {
                selected_wheels = std::max(0, selected_wheels - 2);
                update();
                break;
            }
        }
    }
};
class gui :public QWidget{
    private:
    std::vector<Tractor> tractors_gui;
    service_tractoare& srv;
      QTableWidget* table = new QTableWidget();
      QHBoxLayout* mainLayout = new QHBoxLayout();
        QVBoxLayout* controlsLayout = new QVBoxLayout();
      QFormLayout* formLayout = new QFormLayout();
      QLineEdit* id = new QLineEdit( );
      QLineEdit* nume = new QLineEdit( );
      QLineEdit* tip = new QLineEdit( );
      QLineEdit* roti = new QLineEdit( );
      QComboBox* tipuri = new QComboBox();
        QPushButton* add = new QPushButton("Add");
    WheelsWidget* wheelsWidget = new WheelsWidget();
      void initGUI();
      void initConnect();
      void refresh(std::vector<Tractor> tractors);
    public:
      gui(service_tractoare& service): srv(service){
            initGUI();
            initConnect();
            refresh(srv.get_all_tractors());
      }
};



#endif //GUI_H
