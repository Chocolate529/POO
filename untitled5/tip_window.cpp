//
// Created by lupse on 6/14/2025.
//

#include "tip_window.h"
tip_window::tip_window(const QString& type, int value, QWidget *parent):
    type(type), QWidget(parent) {
  label = new QLabel("Count: " + QString::number(value), this);
  auto* layout = new QVBoxLayout(this);
  layout->addWidget(label);
  setLayout(layout);
  setWindowTitle("Type: " + type);

}

void tip_window::setCount(int count) {
  label->setText("Count: " + QString::number(count));
}
