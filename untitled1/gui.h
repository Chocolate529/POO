// gui.h
#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include <QBoxLayout>
#include <QTableWidget>
#include <QHeaderView>
#include <QPushButton>
#include <QLineEdit>
#include <QSlider>
#include <QMessageBox>
#include <QPainter>
#include <array>
#include "melodie.h"
#include "service_melodie.h"
#include "observer.h"
// Widget to draw a histogram of ranks
class RankBarWidget : public QWidget {
    Q_OBJECT
public:
    explicit RankBarWidget(QWidget* parent = nullptr) : QWidget(parent) {}
    void setCounts(const std::array<int, 10>& c) { counts_ = c; update(); }
protected:
    void paintEvent(QPaintEvent*) override {
        QPainter p(this);
        int n = counts_.size();
        if (n == 0) return;
        int w = width()/n;
        int maxc = *std::max_element(counts_.begin(), counts_.end());
        for (int i=0;i<n;++i) {
            int h = maxc>0 ? counts_[i]*height()/maxc : 0;
            QRect r(i*w, height()-h, w-2, h);
            p.fillRect(r, Qt::blue);
            p.drawRect(r);
        }
    }
private:
    std::array<int,10> counts_{};
};

class GUI : public QWidget, public Observer {
    Q_OBJECT
public:
    explicit GUI(ServiceMelodie& srv, QWidget* parent = nullptr);

private:
    ServiceMelodie& srv;
    std::vector<Melodie> melodii_gui;

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QTableWidget* mainTable = new QTableWidget(this);
    QHBoxLayout* dataLayout = new QHBoxLayout();
    QLineEdit* titluEdit = new QLineEdit(this);
    QSlider* rankSlider = new QSlider(Qt::Horizontal, this);
    QPushButton* updateBtn = new QPushButton("Update", this);
    QPushButton* deleteBtn = new QPushButton("Delete", this);
    RankBarWidget* histogram = new RankBarWidget(this);

    void initGui();
    void initConnections();
    void loadData(const std::vector<Melodie>&);
    void update() override {
        loadData(srv.getAllMelodii());
    }
};

#endif // GUI_H