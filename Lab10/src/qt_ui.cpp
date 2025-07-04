//
// Created by lupse on 5/2/2025.
//
#include "include/qt_ui.h"
#include <vector>
#include <string>
void QtMasinaUI::adaugaGUI() {
      QDialog* dialog = new QDialog();
      dialog->setWindowTitle("Adauga Masina");
      dialog->resize(DIALOG_WIDTH, DIALOG_HEIGHT);
      auto* layoutAdauga = new QVBoxLayout(dialog);
      auto* formLayout = new QFormLayout();

      auto* numarInmatriculareEdit = new QLineEdit();
      auto* producatorEdit = new QLineEdit();
      auto* modelEdit = new QLineEdit();
      auto* tipEdit = new QLineEdit();

      formLayout->addRow("Numar inmatriculare:", numarInmatriculareEdit);
      formLayout->addRow("Producator:", producatorEdit);
      formLayout->addRow("Model:", modelEdit);
      formLayout->addRow("Tip:", tipEdit);

      layoutAdauga->addLayout(formLayout);

      auto* btnAdauga = new QPushButton("Adauga");
      auto* btnCancel = new QPushButton("Cancel");
      auto* btnLayout = new QHBoxLayout();
      btnLayout->addWidget(btnAdauga);
      btnLayout->addWidget(btnCancel);
      layoutAdauga->addLayout(btnLayout);

      connect(btnAdauga, &QPushButton::clicked, [=] {
            QString numar = numarInmatriculareEdit->text();
            QString prod = producatorEdit->text();
            QString model = modelEdit->text();
            QString tip = tipEdit->text();

            if (numar.isEmpty() || prod.isEmpty() || model.isEmpty() || tip.isEmpty()) {
            QMessageBox::warning(dialog, "Eroare", "Toate câmpurile sunt obligatorii.");
            return;
            }
            try {
                  service.adaugaMasina(numar.toStdString(), prod.toStdString(), model.toStdString(), tip.toStdString());
                  QMessageBox::information(dialog, "Operation Completed", "Masina adaugata cu succes!");
                  refreshGUI(service.getAllMasini());
                  dialog->accept();
            } catch (const std::exception& e) {
                  QMessageBox::warning(dialog, "Errore", e.what());
            }
      });

      connect(btnCancel, &QPushButton::clicked, dialog, &QDialog::close);
      dialog->exec();
}
void QtMasinaUI::stergeGUI() {
      QDialog* dialog = new QDialog();
      dialog->setWindowTitle("Sterge Masina");
      dialog->resize(DIALOG_WIDTH, DIALOG_HEIGHT);

      auto* layoutSterge = new QVBoxLayout(dialog);
      auto* formLayout = new QFormLayout();

      auto* numarInmatriculareEdit = new QLineEdit();

      formLayout->addRow("Numar inmatriculare:", numarInmatriculareEdit);

      layoutSterge->addLayout(formLayout);

      auto* btnSterge = new QPushButton("Sterge");
      auto* btnCancel = new QPushButton("Cancel");
      auto* btnLayout = new QHBoxLayout();
      btnLayout->addWidget(btnSterge);
      btnLayout->addWidget(btnCancel);
      layoutSterge->addLayout(btnLayout);

      connect(btnSterge, &QPushButton::clicked, [=] {
            QString numar = numarInmatriculareEdit->text();
            if (numar.isEmpty()) {
                  QMessageBox::warning(dialog, "Eroare", "Campul este obligatoriu");
                  return;
            }
            try{
                  service.stergeMasina(numar.toStdString());
                  QMessageBox::information(dialog, "Operation Completed", "Masina stearsa cu succes");
                  refreshGUI(service.getAllMasini());
                  dialog->accept();
            } catch (const std::exception& e) {
                QMessageBox::warning(dialog, "Errore", e.what());
            }
      });

      connect(btnCancel, &QPushButton::clicked, dialog, &QDialog::close);
      dialog->exec();
}
void QtMasinaUI::cautaGUI() {
      QDialog* dialog = new QDialog();
      dialog->setWindowTitle("Cauta Masina");
      dialog->resize(DIALOG_WIDTH, DIALOG_HEIGHT);

      auto* layoutCauta = new QVBoxLayout(dialog);
      auto* formLayout = new QFormLayout();


      auto* numarInmatriculareEdit = new QLineEdit();
      formLayout->addRow("Numar inmatriculare:", numarInmatriculareEdit);

      layoutCauta->addLayout(formLayout);

      auto* foundTable = new QTableWidget(dialog);
      foundTable->setColumnCount(4);
      foundTable->setHorizontalHeaderLabels({"Numar \n Inmatriculare", "Producator", "Model", "Tip"});
      foundTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
      foundTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

      layoutCauta->addWidget(foundTable);

      auto* btnCauta = new QPushButton("Cauta");
      auto* btnCancel = new QPushButton("Cancel");
      auto* btnLayout = new QHBoxLayout();
      btnLayout->addWidget(btnCauta);
      btnLayout->addWidget(btnCancel);
      layoutCauta->addLayout(btnLayout);




      connect(btnCauta, &QPushButton::clicked, [=] {
            QString numar = numarInmatriculareEdit->text();
            if (numar.isEmpty()) {
                  QMessageBox::warning(dialog, "Error", "Campul este obligatoriu");
                  return;
            }
            try {
                  Masina m = service.cautaMasina(numar.toStdString());
                  QString nr = QString::fromStdString(m.getNrInmatriculare());
                  QString prod = QString::fromStdString(m.getProducator());
                  QString model = QString::fromStdString(m.getModel());
                  QString tip = QString::fromStdString(m.getTip());
                  int row = foundTable->rowCount();
                  foundTable->insertRow(row);
                  foundTable->setItem(row, 0, new QTableWidgetItem(nr));
                  foundTable->setItem(row, 1, new QTableWidgetItem(prod));
                  foundTable->setItem(row, 2, new QTableWidgetItem(model));
                  foundTable->setItem(row, 3, new QTableWidgetItem(tip));
                  QMessageBox::information(dialog, "Operation Completed", "Masina gasita cu succes");
            } catch (const std::exception& e) {
                QMessageBox::warning(dialog, "Errore", e.what());
            }
      });

      connect(btnCancel, &QPushButton::clicked, dialog, &QDialog::close);
      dialog->exec();
}
void QtMasinaUI::modificaGUI() {
      QDialog* dialog = new QDialog();
      dialog->setWindowTitle("Modifica Masina");
      dialog->resize(DIALOG_WIDTH, DIALOG_HEIGHT);

      auto* layoutModifica = new QVBoxLayout(dialog);
      auto* formLayout = new QFormLayout();

      auto* nrInmatriculareEdit = new QLineEdit();
      auto* producatorEdit = new QLineEdit();
      auto* modelEdit = new QLineEdit();
      auto* tipEdit = new QLineEdit();

      formLayout->addRow("Numar inmatriculare:", nrInmatriculareEdit);
      formLayout->addRow("Producator nou:", producatorEdit);
      formLayout->addRow("Model nou:", modelEdit);
      formLayout->addRow("Tip nou:", tipEdit);
      layoutModifica->addLayout(formLayout);

      auto* btnModifica = new QPushButton("Modifica");
      auto* btnCancel = new QPushButton("Cancel");
      auto* btnLayout = new QHBoxLayout();
      btnLayout->addWidget(btnModifica);
      btnLayout->addWidget(btnCancel);
      layoutModifica->addLayout(btnLayout);

      connect(btnModifica, &QPushButton::clicked, [=] {
            QString numar = nrInmatriculareEdit->text();
            QString prod = producatorEdit->text();
            QString model = modelEdit->text();
            QString tip = tipEdit->text();
            if (numar.isEmpty() || prod.isEmpty() || model.isEmpty() || tip.isEmpty()) {
                  QMessageBox::warning(dialog, "Error", "Toate campurile sunt obligatorii.");
                  return;
            }
            try{
                  service.modificaMasina(numar.toStdString(), prod.toStdString(), model.toStdString(), tip.toStdString());
                  QMessageBox::information(dialog, "Operation completed", "Modificare realizata cu succes");
                  refreshGUI(service.getAllMasini());
                  dialog->accept();
            } catch (const std::exception& e) {
             QMessageBox::warning(dialog, "Errore", e.what());
            }
      });

      connect(btnCancel, &QPushButton::clicked, dialog, &QDialog::close);
      dialog->exec();
}
void QtMasinaUI::filtrareGUI() {
      QDialog* dialog = new QDialog();
      dialog->setWindowTitle("Filtrare Masini");
      dialog->resize(DIALOG_WIDTH, DIALOG_HEIGHT);

      auto* layoutFiltrare = new QVBoxLayout(dialog);
      auto* formLayout = new QFormLayout();

      auto* filterTypeEdit = new QLineEdit();

      auto* radioProducator = new QRadioButton("Filtrare dupa Producator");
      auto* radioTip = new QRadioButton("Filtrare dupa Tip");
      radioProducator->setChecked(true);

      formLayout->addRow("Criteriu:", filterTypeEdit);
      layoutFiltrare->addLayout(formLayout);
      layoutFiltrare->addWidget(radioProducator);
      layoutFiltrare->addWidget(radioTip);

      auto* btnFiltrare = new QPushButton("Filtrare");
      auto* btnCancel = new QPushButton("Cancel");
      auto* btnLayout = new QHBoxLayout();
      btnLayout->addWidget(btnFiltrare);
      btnLayout->addWidget(btnCancel);
      layoutFiltrare->addLayout(btnLayout);

      auto* filterTable = new QTableWidget(dialog);
      filterTable->setColumnCount(4);
      filterTable->setHorizontalHeaderLabels({"Numar \n Inmatriculare", "Producator", "Model", "Tip"});
      filterTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
      filterTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

      layoutFiltrare->addWidget(filterTable);

      connect(btnFiltrare, &QPushButton::clicked, [=] {
            filterTable->clear();
            QString criteriu = filterTypeEdit->text();
            if (criteriu.isEmpty()) {
                  QMessageBox::warning(dialog, "Error", "Nici un criteiu de filtrare introdus.");
                  return;
            }
            std::vector<Masina> rezultatFiltrare;
            if ( radioProducator->isChecked() ) {
                  rezultatFiltrare = service.getFilteredMasiniByProducator(criteriu.toStdString());
            } else {
                  rezultatFiltrare = service.getFilteredMasiniByTip(criteriu.toStdString());
            }

            filterTable->setRowCount(rezultatFiltrare.size());
            if (filterTable->rowCount() == 0) {
                  QMessageBox::information(dialog, "Empty", "Nu exista masini de acest fel.");
                  return;
            }
            for (int row = 0; row < filterTable->rowCount(); row++) {
                  const auto& m = rezultatFiltrare[row];
                  QString numar = QString::fromStdString(m.getNrInmatriculare());
                  QString prod = QString::fromStdString(m.getProducator());
                  QString model = QString::fromStdString(m.getModel());
                  QString tip = QString::fromStdString(m.getTip());

                  filterTable->setItem(row, 0, new QTableWidgetItem(numar));
                  filterTable->setItem(row, 1, new QTableWidgetItem(prod));
                  filterTable->setItem(row, 2, new QTableWidgetItem(model));
                  filterTable->setItem(row, 3, new QTableWidgetItem(tip));
            }
            QMessageBox::information(dialog, "Operation Completed", "Filtrare realizata cu succes!");
      });

      connect(btnCancel, &QPushButton::clicked, dialog, &QDialog::close);
      dialog->exec();
}

void clearButtonsFromLayout(QLayout* layout) {
      for (int i = layout->count() - 1; i >= 0; --i) {
            QLayoutItem* item = layout->itemAt(i);
            QWidget* widget = item->widget();

            if (widget && qobject_cast<QPushButton*>(widget)) {
                  layout->takeAt(i);
                  delete widget;
                  delete item;
            }
      }
}

void QtMasinaUI::sondajeGUI() {
      const auto dictionar = service.multimapMasiniByTip();
      std::map<std::string, int> countMap;

      for (const auto& [tip, _] : dictionar) {
            countMap[tip]++;
      }
      clearButtonsFromLayout(sondajeLayout);
      for (const auto& [tip, count] : countMap) {
          //  std::cout << "Tip: " << tip << " -> " << count << " masini\n";
            QPushButton* tipBtn = new QPushButton(QString::fromStdString( tip));
            sondajeLayout->addWidget(tipBtn);
            connect(tipBtn, &QPushButton::clicked, [=] {
                  QMessageBox::information(this, "Sondaj " + tipBtn->text(), "Numarul de masini de acest este: " + QString::number(count));
            });
      }
}

void QtMasinaUI::sortareGUI() {
      QDialog* dialog = new QDialog();
      dialog->setWindowTitle("Sortare");
      dialog->resize(DIALOG_WIDTH, DIALOG_HEIGHT);

      QVBoxLayout* layoutSortare = new QVBoxLayout(dialog);

      QPushButton* btnSortNr = new QPushButton("Sortare dupa NrInmatriculare");
      QPushButton* btnSortTip = new QPushButton("Sortare dupa Tip");
      QPushButton* btnSortProdModel = new QPushButton("Sortare dupa Model");
      QPushButton* btnExit = new QPushButton("Exit");
      QVBoxLayout* btnSortLayout = new QVBoxLayout();
      btnSortLayout->addWidget(btnSortNr);
      btnSortLayout->addWidget(btnSortTip);
      btnSortLayout->addWidget(btnSortProdModel);
      btnSortLayout->addWidget(btnExit);
      layoutSortare->addLayout(btnSortLayout);

      connect(btnSortNr, &QPushButton::clicked, [=] {
            refreshGUI(service.sorteazaMasiniNrInmatriculare());
            dialog->accept();
      });
      connect(btnSortTip, &QPushButton::clicked, [=] {
            refreshGUI( service.sorteazaMasiniTip());
            dialog->accept();
      });
      connect(btnSortProdModel, &QPushButton::clicked, [=] {
            refreshGUI(service.sorteazaMasiniProducatorModel());
            dialog->accept();
      });
      connect(btnExit, &QPushButton::clicked, dialog, &QDialog::close);
      dialog->exec();
}
void QtMasinaUI::spalatorieGUI() {
     auto cos = new cosCRUDGUI(spalatorie);
      cos->show();
}
void QtMasinaUI::spalatorieHistogram() {
      auto histogram = new cosReadOnlyGUI(spalatorie);
      histogram->show();
}
// void QtMasinaUI::showCar(int i, int j) {
//       formLayout->addRow("i:", new QLineEdit(QString::number(i)));
//       formLayout->addRow("j:", new QLineEdit(QString::number(j)));
// }

void QtMasinaUI::loadData(std::vector<Masina> v) {
      masini_ui = v;
      model->setMasini(masini_ui);
}



void QtMasinaUI::initGUI() {

      setLayout(layoutMain);
      // viewLayout->addWidget(tableWidget);
      // viewLayout->addLayout(formLayout);
      tableView->setModel(model);
      layoutMain->addWidget(tableView);
      layoutMain->addWidget(btnRefresh);
      connect(btnRefresh, &QPushButton::clicked, [=] {

            refreshGUI(service.getAllMasini());
      });
      layoutBtns->addWidget(btnAdauga);
      layoutBtns->addWidget(btnSterge);
      layoutBtns->addWidget(btnModifica);
      layoutBtns->addWidget(btnCauta);
      layoutBtns->addWidget(btnFiltrare);
      layoutBtns->addWidget(btnSortare);
      layoutBtns->addWidget(btnWash);
      layoutBtns->addWidget(btnWash2);
      layoutMain->addLayout(layoutBtns);

      layoutMain->addLayout(sondajeLayout);

      resize(WINDOW_WIDTH, WINDOW_HEIGHT);
      move((SCREEN_WIDTH-WINDOW_WIDTH)/2, (SCREEN_HEIGHT-WINDOW_HEIGHT)/2);
      masini_ui = service.getAllMasini();

}

void QtMasinaUI::initConnect() {
      connect(btnAdauga, QPushButton::clicked, this, &QtMasinaUI::adaugaGUI);
      connect(btnSterge, QPushButton::clicked, this, &QtMasinaUI::stergeGUI);
      connect(btnCauta, QPushButton::clicked, this, &QtMasinaUI::cautaGUI);
      connect(btnModifica, QPushButton::clicked, this, &QtMasinaUI::modificaGUI);
      connect(btnFiltrare, QPushButton::clicked, this, &QtMasinaUI::filtrareGUI);
      connect(btnSortare, QPushButton::clicked, this, &QtMasinaUI::sortareGUI);
      connect(btnWash, QPushButton::clicked, this, &QtMasinaUI::spalatorieGUI);
      connect(btnWash2, QPushButton::clicked, this, &QtMasinaUI::spalatorieHistogram);
      // connect(tableWidget, QTableWidget::cellClicked, this, &QtMasinaUI::showCar);
}

void QtMasinaUI::refreshGUI(std::vector<Masina> v) {

      loadData(v);
      sondajeGUI();

}