#include <QApplication>
#include <QPushButton>
#include "teste.h"
#include "ui.h"
int main(int argc, char *argv[]) {
    teste t;
    t.runAllTeste();
    QApplication a(argc, argv);
    repo_melodie rp{"../melodii"};
    service_melodie srv{rp};
    ui u{srv};
    u.show();
    return QApplication::exec();
}