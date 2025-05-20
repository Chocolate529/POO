#include "product_management.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    ProductManagement window;
    window.show();
    return app.exec();
}