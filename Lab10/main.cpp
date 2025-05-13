#include <QApplication>

#include "include/console_ui.h"
#include "include/teste.h"
#include "include/qt_ui.h"

int main(int argc, char** argv) {
    Teste::runTests();
    MasinaRepo repo;
    std::string fileName = "../masinute";
    MasinaRepoFile repoFile {fileName};
    // MasinaService service{repo};
    MasinaService service{repoFile};
    ServiceSpalatorie spalatorie{service};
    MasinaUI ui{service, spalatorie};
    QApplication app(argc, argv);
    QtMasinaUI qt{service, spalatorie};
    qt.show();
    app.exec();
    // ui.run();
}
