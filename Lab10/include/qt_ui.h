//
// Created by lupse on 5/2/2025.
//

#ifndef QT_UI_H
#define QT_UI_H
#include <qlistwidget.h>
#include <QtWidgets/QApplication>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qformlayout.h>
#include <QtWidgets/qlistwidget.h>
#include <QTWidgets/QDialog>
#include <QTWidgets/qmessagebox.h>
#include <QTWidgets/qradiobutton.h>
#include <QHeaderView>
#include <QScreen>
#include <QTWidgets/qtablewidget.h>
#include "service_masina.h"
#include "include/domeniu_masina.h"
#include "service_spalatorie.h"
#include "cosCRUDGUI.h"
#include "cosReadOnlyGUI.h"
#include "table_model.h"
#define ALPHA 0.5
#define BETA 0.25
class QtMasinaUI: public QWidget {
private:
    std::vector<Masina> masini_ui;
    std::vector<Masina> masini_spalatorie;

    MasinaService& service;
    ServiceSpalatorie& spalatorie;
    QTableView* tableView = new QTableView(this);
    MyTableModel* model = new MyTableModel(this);
    QScreen* screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();

    const int SCREEN_WIDTH = screenGeometry.width();
    const int SCREEN_HEIGHT = screenGeometry.height();
    const int WINDOW_WIDTH = static_cast<int>(SCREEN_WIDTH * ALPHA);
    const int WINDOW_HEIGHT = static_cast<int>(SCREEN_HEIGHT * ALPHA);
    const int DIALOG_WIDTH = static_cast<int>(SCREEN_WIDTH * BETA);
    const int DIALOG_HEIGHT = static_cast<int>(SCREEN_HEIGHT * BETA);


    QHBoxLayout* layoutMain = new QHBoxLayout();

    QVBoxLayout* sondajeLayout = new QVBoxLayout();
    QVBoxLayout* layoutBtns = new QVBoxLayout();
    QPushButton* btnRefresh = new QPushButton("Refresh");
    QPushButton* btnAdauga = new QPushButton("Adauga");
    QPushButton* btnSterge = new QPushButton("Sterge");
    QPushButton* btnCauta = new QPushButton("Cauta");
    QPushButton* btnModifica = new QPushButton("Modifica");
    QPushButton* btnFiltrare = new QPushButton("Filtrare");
    QPushButton* btnSortare = new QPushButton("Sortare");
    QPushButton* btnWash = new QPushButton("Spalatorie CRUD");
    QPushButton* btnWash2 = new QPushButton("SPalatorie Histogram");
    void adaugaGUI();
    void stergeGUI();
    void modificaGUI();
    void cautaGUI();
    void filtrareGUI();
    void sortareGUI() ;
    void spalatorieGUI();
    void spalatorieHistogram();
    void sondajeGUI();
    void initGUI();
    void loadData(std::vector<Masina> v);
    void initConnect();
    void refreshGUI(std::vector<Masina> v);
    // void showCar(int i, int j);
public:
    explicit QtMasinaUI(MasinaService& srv, ServiceSpalatorie& spal): service{srv}, spalatorie{spal} {
        initGUI();
        refreshGUI(service.getAllMasini());
        initConnect();
    }
};
#endif //QT_UI_H
