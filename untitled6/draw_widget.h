//
// Created by lupse on 6/15/2025.
//

#ifndef DRAW_WIDGET_H
#define DRAW_WIDGET_H

#include "QPainter"
#include "QWidget"
#include "service_melodii.h"
class draw_widget: public QWidget {
private:
    map<int,int> ranks;

public:
    void setRanks(map<int,int> r){
        ranks = r;
        update();
    }
    void paintEvent(QPaintEvent *) override{
        QPainter painter(this);
        int margin = 30;
        int radiusStep = 12;
        struct Corner { int x, y; };
        std::map<int, Corner> corners = {
            {1, {margin, margin}}, // top-left
            {2, {width() - margin, margin}}, // top-right
            {3, {margin, height() - margin}}, // bottom-left
            {4, {width() - margin, height() - margin}} // bottom-right
        };
        for (int rank = 1; rank <= 4; ++rank) {
            int count = ranks.count(rank) ? ranks.at(rank) : 0;
            auto [cx, cy] = corners[rank];
            for (int i = 1; i <= count; ++i) {
                int r = i * radiusStep;
                painter.drawEllipse(QPoint(cx, cy), r, r);
            }
            painter.drawText(cx - 8, cy + 5, QString::number(rank));
        }




      }
};



#endif //DRAW_WIDGET_H
