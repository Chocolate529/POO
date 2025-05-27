//
// Created by lupse on 5/27/2025.
//

#include "cosCRUDGUI.h"
void cosCRUDGUI::add() {
    auto dialog = new QDialog;
    dialog->setWindowTitle("Adaugare in cos");
    auto dialogLayout = new QVBoxLayout();
    dialog->setLayout(dialogLayout);
    auto dialogBtnLayout = new QHBoxLayout();
    auto form = new QFormLayout();

    dialogLayout->addLayout(form);
    dialogLayout->addLayout(dialogBtnLayout);

    auto nrInmatriculare = new QLineEdit;
    form->addRow("Numar inmatriculare:", nrInmatriculare);

    auto dialogBtnAdd = new QPushButton("Add");
    auto dialogBtnCancel = new QPushButton("Cancel");
    dialogBtnLayout->addWidget(dialogBtnAdd);
    dialogBtnLayout->addWidget(dialogBtnCancel);

    connect(dialogBtnAdd, &QPushButton::clicked, [&]() {
        if (nrInmatriculare->text().isEmpty()) {
            QMessageBox::warning(dialog, "Eroare", "Field is empty!");
            return;
        }
        try {
            std::string nr = nrInmatriculare->text().toStdString();
            srv.adaugaMasina(nr);
            refreshGUI(srv.getAllMasini());
            dialog->accept();
        } catch (const std::exception& e) {
            QMessageBox::warning(dialog, "Eroare", e.what());
        }

    });

    connect(dialogBtnCancel, &QPushButton::clicked, dialog, &QDialog::close);

    dialog->exec();

}
void cosCRUDGUI::clear() {
    srv.golesteLista();
    refreshGUI(srv.getAllMasini());
}
void cosCRUDGUI::exportCSV() {
    srv.exportCSV(fileName->text().toStdString());
    QMessageBox::information(this, "Succes", "Export realizat cu succes!");
}
void cosCRUDGUI::exportHTML() {
    srv.exportHTML(fileName->text().toStdString());
    QMessageBox::information(this, "Succes", "Export realizat cu succes!");

}
void cosCRUDGUI::random() {
    if (randomToGenerate->text().isEmpty()) {
        QMessageBox::warning(this, "Eroare", "Field is empty!");
        return;
    }
    try {
        srv.generareLista(randomToGenerate->text().toInt());
        refreshGUI(srv.getAllMasini());
        QMessageBox::information(this, "Succes", "Generare realizata cu succes!");

    } catch (const std::exception& e) {
        QMessageBox::warning(this, "Eroare", e.what());
    }
}
void cosCRUDGUI::initGUI(){
    setLayout(mainLayout);
    mainLayout->addWidget(listWidget);
    mainLayout->addLayout(formLayout);
    mainLayout->addLayout(buttonLayout);

    formLayout->addRow("Nume fisier export:", fileName);
    formLayout->addRow("Numar pentru generare random:", randomToGenerate);

    buttonLayout->addWidget(btnAdd);
    buttonLayout->addWidget(btnRandom);
    buttonLayout->addWidget(btnClear);
    buttonLayout->addWidget(btnExportCSV);
    buttonLayout->addWidget(btnExportHTML);

    listWidget->setSelectionMode(QAbstractItemView::SingleSelection);
}
void cosCRUDGUI::connectSignals(){
  connect(btnAdd, &QPushButton::clicked, this, &cosCRUDGUI::add);
  connect(btnClear, &QPushButton::clicked, this, &cosCRUDGUI::clear);
  connect(btnExportCSV, &QPushButton::clicked, this, &cosCRUDGUI::exportCSV);
  connect(btnExportHTML, &QPushButton::clicked, this, &cosCRUDGUI::exportHTML);
  connect(btnRandom, &QPushButton::clicked, this, &cosCRUDGUI::random);
}
void cosCRUDGUI::refreshGUI(const std::vector<Masina>& masini){
    masini_cos = masini;
    listWidget->clear();
    listWidget->addItem("Numar Inmatriculare | Producator | Model | Tip");
    for (const auto& masina : masini_cos) {
        QString itemText = QString::fromStdString(masina.getNrInmatriculare() + " | " +
                                                  masina.getProducator() + " | " +
                                                  masina.getModel() + " | " +
                                                  masina.getTip());
        listWidget->addItem(itemText);
    }
}