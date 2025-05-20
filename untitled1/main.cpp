#include <QtWidgets/QApplication>
#include "gui.h"
#include "repo_melodie.h"
#include "service_melodie.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    FileRepoMelodie repo;
    ServiceMelodie srv{repo};
    GUI w{srv};
    w.show();
    GUI w2{srv};
    w2.show();
    return app.exec();
}