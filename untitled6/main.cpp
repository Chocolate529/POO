#include <QApplication>
#include <QPushButton>
#include "teste.h"
#include "ui.h"
int main(int argc, char *argv[]) {
    // std::filesystem::remove("../melodii");
    // std::filesystem::copy_file(
    //     std::filesystem::path("../base_melodii"),
    //     std::filesystem::path("../melodii"),
    //     std::filesystem::copy_options::overwrite_existing);
    teste t;
    t.runAllTests();
    QApplication a(argc, argv);
    repo_melodie rp{"../melodii"};
    service_melodii srv{rp};
    ui u{srv};
    u.show();
    return QApplication::exec();
}