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
      auto dialog = new QDialog();

      dialog->setWindowTitle("Spalatorie");
      dialog->resize(DIALOG_WIDTH, DIALOG_HEIGHT);

      auto layoutWash = new QHBoxLayout(dialog);

      auto tableWash = new QTableWidget(dialog);
      tableWash->setColumnCount(4);
      tableWash->setHorizontalHeaderLabels({"Numar \n Inmatriculare", "Producator", "Model", "Tip"});
      tableWash->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
      tableWash->setEditTriggers(QAbstractItemView::NoEditTriggers);
      layoutWash->addWidget(tableWash);

      auto btnLayout = new QVBoxLayout();
      QPushButton*  btnAdaugaWash = new QPushButton("Adauga");
      QPushButton* btnGoleste = new QPushButton("Goleste");
      QPushButton* btnExport = new QPushButton("Export");
      QPushButton* btnFillRandom = new QPushButton("Fill Random");

      btnLayout->addWidget(btnAdaugaWash);
      btnLayout->addWidget(btnGoleste);
      btnLayout->addWidget(btnExport);
      btnLayout->addWidget(btnFillRandom);

      layoutWash->addLayout(btnLayout);

      auto updateTable = [=]() {
            tableWash->setRowCount(static_cast<int>(masini_spalatorie.size()));

            int row = 0;
            for (const auto& m : masini_spalatorie) {
                  tableWash->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(m.getNrInmatriculare())));
                  tableWash->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(m.getProducator())));
                  tableWash->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(m.getModel())));
                  tableWash->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(m.getTip())));
                  row++;
            }
      };

      connect(btnAdaugaWash, &QPushButton::clicked, [=] {
            auto dialogAdd = new QDialog();
            dialogAdd->setWindowTitle("Adauga");

            auto layoutAddWash = new QVBoxLayout(dialogAdd);

            auto formAdd = new QFormLayout();
            auto nrInmatriculare = new QLineEdit();
            formAdd->addRow("Numar Inmatriculare", nrInmatriculare);
            layoutAddWash->addLayout(formAdd);

            auto btnAdd = new QPushButton("Adauga");
            auto btnCancel = new QPushButton("Cancel");
            auto btnLayoutAdd = new QHBoxLayout();
            btnLayoutAdd->addWidget(btnAdd);
            btnLayoutAdd->addWidget(btnCancel);
            layoutAddWash->addLayout(btnLayoutAdd);
            connect(btnAdd, &QPushButton::clicked, [=]() {
            try {
                 if (nrInmatriculare->text().isEmpty()) {
                        QMessageBox::warning(dialogAdd, "Eroare", "Nici un numar de inmatriculare!");
                        return;
                 }
                std::string nr = nrInmatriculare->text().toStdString();
                spalatorie.adaugaMasina(nr);
                  masini_spalatorie = spalatorie.getAllMasini();
                updateTable();
                  QMessageBox::information(dialog, "Succes", "Masini adaugate in spalatorie!");
                dialogAdd->close();
            } catch (const std::exception& ex) {
                QMessageBox::warning(dialogAdd, "Eroare", ex.what());
            }
        });

            connect(btnCancel, &QPushButton::clicked, dialogAdd, &QDialog::close);
            dialogAdd->exec();

      });

      connect(btnGoleste, QPushButton::clicked, [=]() {
            masini_spalatorie.clear();
            spalatorie.golesteLista();
            updateTable();
            QMessageBox::information(dialog, "Succes", "Masini sterse din spalatorie!");
      });

      connect(btnExport, QPushButton::clicked, [=]() {
            auto dialogExport = new QDialog();
            dialogExport->setWindowTitle("Export");

            auto layoutExport = new QVBoxLayout(dialogExport);
            auto formExport = new QFormLayout();

            auto radioBtnLayout = new QHBoxLayout();
            auto radioCsv = new QRadioButton("Csv");
            auto radioHtml = new QRadioButton("Html");
            radioCsv->setChecked(true);
            radioBtnLayout->addWidget(radioCsv);
            radioBtnLayout->addWidget(radioHtml);
            layoutExport->addLayout(radioBtnLayout);

            auto fileName = new QLineEdit();
            formExport->addRow("Numele fisierului", fileName);
            layoutExport->addLayout(formExport);

            auto btnExportDialog = new QPushButton("Export");
            auto btnCancel = new QPushButton("Cancel");
            auto btnLayoutExport = new QHBoxLayout();
            btnLayoutExport->addWidget(btnExportDialog);
            btnLayoutExport->addWidget(btnCancel);
            layoutExport->addLayout(btnLayoutExport);

            connect(btnExportDialog, &QPushButton::clicked, [=]() {
                  if (fileName->text().isEmpty()) {
                        QMessageBox::warning(dialogExport, "Eroare", "Nici un nume de fisier!");
                        return;
                  }
                  std::string numeFisier = fileName->text().toStdString();
                  try {
                        if (radioCsv->isChecked()) {
                              spalatorie.exportCSV(numeFisier);
                        } else {
                              spalatorie.exportHTML(numeFisier);
                        }
                        QMessageBox::information(dialogExport, "Succes", "Export realizat cu succes");
                        dialogExport->close();
                  } catch (const std::exception& ex) {
                        QMessageBox::warning(dialogExport, "Eroare", ex.what());
                  }
            });
            connect(btnCancel, &QPushButton::clicked, dialogExport, &QDialog::close);
            dialogExport->exec();
      });

      connect(btnFillRandom, QPushButton::clicked, [=]() {
            auto dialogFillRandom = new QDialog();
            dialogFillRandom->setWindowTitle("Fill Random");

            auto layoutFill = new QVBoxLayout(dialogFillRandom);

            auto formFill = new QFormLayout();
            auto numar = new QLineEdit();
            formFill->addRow("Numar de masini", numar);
            layoutFill->addLayout(formFill);

            auto btnLayoutFill = new QHBoxLayout();
            auto btnFill = new QPushButton("Fill");
            auto btnCancel = new QPushButton("Cancel");
            btnLayoutFill->addWidget(btnFill);
            btnLayoutFill->addWidget(btnCancel);
            layoutFill->addLayout(btnLayoutFill);

            connect(btnFill, QPushButton::clicked, [=]() {
                  if (numar->text().isEmpty()) {
                        QMessageBox::warning(dialogFillRandom, "Error", "Introduceti un numar!");
                        return;
                  }
                  int nr = numar->text().toInt();
                  try {
                        spalatorie.generareLista(nr);
                        masini_spalatorie = spalatorie.getAllMasini();
                        updateTable();
                        QMessageBox::information(dialogFillRandom,"Succes","Masini generate cu succes!");
                        dialogFillRandom->close();
                  } catch (const std::exception& ex) {
                        QMessageBox::warning(dialogFillRandom, "Eroare", ex.what());
                  }
            });
            connect(btnCancel, QPushButton::clicked, dialogFillRandom, &QDialog::close);

            dialogFillRandom->exec();
      });

      dialog->exec();
}
void QtMasinaUI::loadData(std::vector<Masina> v) {
      masini_ui = v;
      tableWidget->clearContents();
      tableWidget->setRowCount(static_cast<int>(service.getAllMasini().size()));
      tableWidget->setColumnCount(4);
      tableWidget->setHorizontalHeaderLabels({"Numar \n Inmatriculare","Producator",
                                                      "Model",  "Tip"});
      tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
      tableWidget->resizeRowsToContents();
      int row = 0;
      for (const auto& masina: masini_ui) {
            QString numar = QString::fromStdString(masina.getNrInmatriculare());
            QString producator = QString::fromStdString(masina.getProducator());
            QString model = QString::fromStdString(masina.getModel());
            QString tip = QString::fromStdString(masina.getTip());
            tableWidget->setItem(row, 0, new QTableWidgetItem(numar));
            tableWidget->setItem(row, 1, new QTableWidgetItem(producator));
            tableWidget->setItem(row, 2, new QTableWidgetItem(model));
            tableWidget->setItem(row, 3, new QTableWidgetItem(tip));
            row++;
      }
}



void QtMasinaUI::initGUI() {

      setLayout(layoutMain);
      tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
      layoutMain->addWidget(tableWidget);
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
}

void QtMasinaUI::refreshGUI(std::vector<Masina> v) {

      loadData(v);
      sondajeGUI();

}