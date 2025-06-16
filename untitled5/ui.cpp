//
// Created by lupse on 6/14/2025.
//

#include "ui.h"
void Ui::initGUI() {
    setLayout(mainLayout);

    table->setModel(model);
    model->setSlider(slider);
    mainLayout->addWidget(table);

    mainLayout->addLayout(layoutForm);
    layoutForm->addRow("Id:", id);
    layoutForm->addRow("Nume:", nume);
    layoutForm->addRow("Tip:", tip);
    layoutForm->addRow("Pret:", pret);

    mainLayout->addLayout(controlLayout);
    controlLayout->addWidget(btnAdd);
    controlLayout->addWidget(slider);
    slider->setTickInterval(100);
    slider->setTickPosition(QSlider::TicksBelow);

    slider->setValue(0);

}
void Ui::loadData(vector<Produs> data) {
    model->setData(data);

}
void Ui::initConnect() {
    connect(btnAdd, QPushButton::clicked, this, [&]() {
         if (id->text().isEmpty() || nume->text().isEmpty() || tip->text().isEmpty() || pret->text().isEmpty()) {
             QMessageBox::warning(this,"Eroare","Toate campurile sunt obligatorii");
             return;
         }
         int i = id->text().toInt();
         string n = nume->text().toStdString();
         string t = tip->text().toStdString();
         double p = pret->text().toDouble();

         try {
             srv.addProdus(i, n, t, p);
             loadData(srv.getAllProduse());

             QMessageBox::information(this, "Succes", "Produs adaugat cu secces");
         } catch (std::exception& e) {
             QMessageBox::warning(this, "Eroare", e.what());
         }

    });
}
void Ui::initTypeWindows(std::map<string,int> mp) {
    for (auto [_,win] : tips) {
        win->close();
        delete win;
    }
    tips.clear();
    for (const auto& [type, count] : mp) {
        auto* win = new tip_window(QString::fromStdString(type), count);
        win->show();
        tips[type] = win;
    }
}
void Ui::updateTypeWindows(std::map<string,int> mp) {
    for (auto it = tips.begin(); it != tips.end(); ) {
        if (mp.find(it->first) == mp.end() || mp[it->first] == 0) {
            it->second->close();
            delete it->second;
            it = tips.erase(it);
        } else {
            ++it;
        }
    }
    // Update existing windows and create new ones if needed
    for (const auto& [type, count] : mp) {
        if (tips.find(type) == tips.end()) {
            auto* win = new tip_window(QString::fromStdString(type), count);
            win->show();
            tips[type] = win;
        } else {
            tips[type]->setCount(count);
        }
    }
}
void Ui::update() {
    updateTypeWindows(srv.getProduseByTip());
};