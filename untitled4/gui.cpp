//
// Created by lupse on 5/20/2025.
//

#include "gui.h"
void gui::initGUI(){
    setWindowTitle("Tractor Management");
    setMinimumSize(800, 600);



    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    mainLayout->addWidget(table);

    formLayout->addRow("ID", id);
    formLayout->addRow("Name", nume);
    formLayout->addRow("Type", tip);
    formLayout->addRow("Number of Wheels", roti);
    controlsLayout->addLayout(formLayout);
    controlsLayout->addWidget(add);

    controlsLayout->addWidget(tipuri);
    mainLayout->addLayout(controlsLayout);
    controlsLayout->addWidget(wheelsWidget);
    setLayout(mainLayout);
}

void gui::initConnect(){
    connect(tipuri, &QComboBox::currentTextChanged, this, [this](const QString& text) {
        for (int i = 0; i < table->rowCount(); ++i) {
            bool match = (table->item(i, 2)->text() == text);
            for (int col = 0; col < table->columnCount(); ++col) {
                if (table->item(i, col))
                    table->item(i, col)->setBackground(match && text != "Select type" ? QBrush(QColor(Qt::red)) : QBrush());
            }
        }
    });
    connect(add, &QPushButton::clicked, this, [this](){
        if(id->text().isEmpty() || nume->text().isEmpty() || tip->text().isEmpty() || roti->text().isEmpty()){
            QMessageBox::warning(this, "Error", "All fields must be filled");
            return;
        }
        try {
            int id_value = id->text().toInt();
            std::string name_value = nume->text().toStdString();
            std::string type_value = tip->text().toStdString();
            int nr_of_wheels_value = roti->text().toInt();
            srv.add_tractor(id_value, name_value, type_value, nr_of_wheels_value);
            refresh(srv.get_all_tractors());
        } catch (const std::exception& e) {
            QMessageBox::warning(this, "Error", e.what());
        }

    });
    connect(table, &QTableWidget::itemClicked, this, [this](QTableWidgetItem* item) {
        if (item) {
            int row = item->row();
            id->setText(table->item(row, 0)->text());
            nume->setText(table->item(row, 1)->text());
            tip->setText(table->item(row, 2)->text());
            roti->setText(table->item(row, 3)->text());
            wheelsWidget->setWheels(table->item(row, 3)->text().toInt());
            update();
        }
    });
}


void gui::refresh(std::vector<Tractor> tractors){
    id->clear();
    nume->clear();
    tip->clear();
    roti->clear();
  tractors_gui = tractors;
   std::sort(tractors_gui.begin(), tractors_gui.end(), [](const Tractor& a, const Tractor& b) {
        return a.getName() < b.getName();
    });
    table->clear();
    table->setColumnCount(5);
    table->setHorizontalHeaderLabels({"ID", "Name", "Type", "Number of Wheels", "Numar tractoare\n acelasi tip"});
    table->setRowCount(tractors.size());
    for (int i = 0; i < tractors.size(); ++i){
        table->setItem(i, 0, new QTableWidgetItem(QString::number(tractors_gui[i].getId())));
        table->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(tractors_gui[i].getName())));
        table->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(tractors_gui[i].getType())));
        table->setItem(i, 3, new QTableWidgetItem(QString::number(tractors_gui[i].getNrOfWheels())));
        table->setItem(i, 4, new QTableWidgetItem(QString::number(srv.get_types()[tractors_gui[i].getType()])));
    }
    tipuri->clear();
    tipuri->addItem("Select type");
    for(auto type : srv.get_types()){
        tipuri->addItem(QString::fromStdString(type.first));
    }
    update();
}