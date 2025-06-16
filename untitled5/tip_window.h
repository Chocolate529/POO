//
// Created by lupse on 6/14/2025.
//

#ifndef TIP_WINDOW_H
#define TIP_WINDOW_H

#include "QLabel"
#include "QWidget"
#include "QVBoxLayout"
class tip_window : public QWidget{
  private:
    QLabel *label;
    QString type;

  public:
    tip_window(const QString& type,int value, QWidget *parent = Q_NULLPTR);
    void setCount(int count);
};



#endif //TIP_WINDOW_H
