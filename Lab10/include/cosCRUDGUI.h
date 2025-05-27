//
// Created by lupse on 5/27/2025.
//

#ifndef COSCRUDGUI_H
#define COSCRUDGUI_H
#include "domeniu_masina.h"
#include "service_spalatorie.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QListWidget>
#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QMessageBox>
class cosCRUDGUI : public QWidget, public Observer {
    private:
        std::vector<Masina> masini_cos;
        ServiceSpalatorie& srv;
        QVBoxLayout* mainLayout = new QVBoxLayout;;
        QHBoxLayout* buttonLayout = new QHBoxLayout;
        QPushButton* btnAdd = new QPushButton("Adauga");
        QPushButton* btnRandom = new QPushButton("Random");
        QPushButton* btnClear = new QPushButton("Goleste");
        QPushButton* btnExportCSV = new QPushButton("Export CSV");
        QPushButton* btnExportHTML = new QPushButton("Export HTML");
        QListWidget* listWidget = new QListWidget;

        QFormLayout* formLayout = new QFormLayout();
        QLineEdit* fileName = new QLineEdit;
        QLineEdit* randomToGenerate = new QLineEdit;

        void initGUI();
        void connectSignals();
        void refreshGUI(const std::vector<Masina>& masini);

        void add();
        void clear();
        void exportCSV();
        void exportHTML();
        void random();
        void update() override {
            refreshGUI(srv.getAllMasini());
        }
    public:
        explicit cosCRUDGUI(ServiceSpalatorie& srv): srv(srv) {
            srv.addObserver(this);
            initGUI();
            connectSignals();
            refreshGUI(srv.getAllMasini());
        }
};



#endif //COSCRUDGUI_H
