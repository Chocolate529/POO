#include "gui.h"

GUI::GUI(ServiceMelodie& srv_, QWidget* parent)
    : QWidget(parent), srv(srv_) {
    initGui();
    initConnections();
    loadData(srv.getAllMelodii());
}

void GUI::initGui() {
    setWindowTitle("Melodii");
    setMinimumSize(1000, 800);
    srv.addObserver(this);
    // Slider settings: 0-9
    rankSlider->setRange(0,9);
    rankSlider->setTickPosition(QSlider::TicksBelow);
    rankSlider->setTickInterval(1);
    rankSlider->setSingleStep(1);

    // Table configuration
    mainTable->setColumnCount(5);
    mainTable->setHorizontalHeaderLabels({"ID","Titlu","Artist","Rank","Count by Rank"});
    mainTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    mainTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Data controls
    dataLayout->addWidget(titluEdit);
    dataLayout->addWidget(rankSlider);
    dataLayout->addWidget(updateBtn);
    dataLayout->addWidget(deleteBtn);

    // Histogram widget
    histogram->setMinimumHeight(150);
    histogram->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    mainTable->setStyleSheet(
            "QTableWidget::item:selected { background-color: lightgreen; color: black; }"
        );
    // Assemble layouts with stretch factors
    mainLayout->addWidget(mainTable, /*stretch=*/3);
    mainLayout->addLayout(dataLayout, /*stretch=*/0);
    mainLayout->addWidget(histogram, /*stretch=*/1);

    mainTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    mainTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Data controls
    dataLayout->addWidget(titluEdit);
    dataLayout->addWidget(rankSlider);
    dataLayout->addWidget(updateBtn);
    dataLayout->addWidget(deleteBtn);

    // Assemble layouts
    mainLayout->addWidget(mainTable);
    mainLayout->addLayout(dataLayout);
    mainLayout->addWidget(histogram);
}

void GUI::initConnections() {
    connect(mainTable, &QTableWidget::cellClicked, this,
            [this](int row,int){
        titluEdit->setText(mainTable->item(row,1)->text());
        rankSlider->setValue(mainTable->item(row,3)->text().toInt());
    });

    connect(updateBtn, &QPushButton::clicked, this, [this](){
        if (titluEdit->text().isEmpty()) {
            QMessageBox::warning(this,"Error","Select a row first"); return;
        }
        int id = mainTable->item(mainTable->currentRow(),0)->text().toInt();
        try {
            srv.updateMelodie(id, titluEdit->text().toStdString(), rankSlider->value());
            loadData(srv.getAllMelodii());
        } catch(const std::exception& e) {
            QMessageBox::warning(this,"Error",e.what());
        }
    });

    connect(deleteBtn, &QPushButton::clicked, this, [this](){
        if (titluEdit->text().isEmpty()) {
            QMessageBox::warning(this,"Error","Select a row first"); return;
        }
        int id = mainTable->item(mainTable->currentRow(),0)->text().toInt();
        try {
            srv.removeMeloide(id);
            loadData(srv.getAllMelodii());
        } catch(const std::exception& e) {
            QMessageBox::warning(this,"Error",e.what());
        }
    });
}

void GUI::loadData(const std::vector<Melodie>& melodii) {
    melodii_gui = melodii;
    std::ranges::sort(melodii_gui.begin(), melodii_gui.end(),
                      [](auto &a, auto &b){ return a.getRank()<b.getRank(); });

    mainTable->setRowCount(melodii_gui.size());
    for (int i=0;i<(int)melodii_gui.size();++i) {
        auto &m = melodii_gui[i];
        int r = m.getRank();
        int ct = std::count_if(melodii_gui.begin(), melodii_gui.end(),
                               [r](auto &x){ return x.getRank()==r; });
        mainTable->setItem(i,0,new QTableWidgetItem(QString::number(m.getId())));
        mainTable->setItem(i,1,new QTableWidgetItem(QString::fromStdString(m.getTitlu())));
        mainTable->setItem(i,2,new QTableWidgetItem(QString::fromStdString(m.getArtist())));
        mainTable->setItem(i,3,new QTableWidgetItem(QString::number(r)));
        mainTable->setItem(i,4,new QTableWidgetItem(QString::number(ct)));
    }

    // Build histogram data
    std::array<int,10> counts{};
    for (auto &m: melodii_gui) {
        int rr=m.getRank(); if(rr>=0&&rr<10) counts[rr]++;
    }
    histogram->setCounts(counts);
}
