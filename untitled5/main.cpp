#include <QApplication>
#include <QPushButton>
#include "teste.h"
#include "ui.h"
int main(int argc, char *argv[]) {
    Teste t;
    t.runAllTests();
    QApplication a(argc, argv);
    ValidatorProdus validator;
    RepoProdus rp{"../produse"};
    ServiceProduse srv(rp, validator);
    Ui u{srv};
    u.show();
    return QApplication::exec();
}