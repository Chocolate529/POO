#include <QApplication>
#include <QPushButton>
#include "teste.h"
#include "ui.h"
int main(int argc, char *argv[]) {
    std::filesystem::remove("../studenti");
    std::filesystem::copy_file(
        std::filesystem::path("../test_base"),
        std::filesystem::path("../studenti"),
            std::filesystem::copy_options::overwrite_existing);
    teste t;
    t.runAllTests();
    QApplication a(argc, argv);
    repo_student rp{"../studenti"};
    service_student srv{rp};
    ui u {srv};
    u.show();
    return QApplication::exec();
}