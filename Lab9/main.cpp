#include "ui.h"
#include "teste.h"
int main() {
    Teste::runTests();
    MasinaRepo repo;
    std::string fileName = "../masinute";
    MasinaRepoFile repoFile {fileName};
    // MasinaService service{repo};
    MasinaService service{repoFile};
    ServiceSpalatorie spalatorie{repo};
    MasinaUI ui{service, spalatorie};
    ui.run();
}
