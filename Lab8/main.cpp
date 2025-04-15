#include "ui.h"
#include "teste.h"
int main() {
    Teste::runTests();
    MasinaRepo repo;
    MasinaService service{repo};
    ServiceSpalatorie spalatorie{service};
    MasinaUI ui{service, spalatorie};
    ui.run();
}
