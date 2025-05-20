#include <QApplication>
#include "gui.h"
#include "repo_tractor.h"
#include "service_tractoare.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    repo_tractor repo("../tractoare");
    validator_tractor validator;
    service_tractoare srv(repo, validator);
    gui w(srv);
    w.show();
    return a.exec();
}