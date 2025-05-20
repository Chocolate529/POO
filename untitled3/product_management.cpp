// product_management.h


// product_management.cpp
#include "product_management.h"
#include <QHeaderView>
#include <algorithm>
#include <QFileDialog>
#include <QDir>

ProductManagement::ProductManagement(QWidget* parent)
    : QMainWindow(parent) {
    setupUI();
    loadProductsFromFile();
    displayProducts();
}

ProductManagement::~ProductManagement() {
    saveProductsToFile();
    // Închiderea ferestrelor pentru tipurile de produse
    for (auto window : typeWindows.values()) {
        if (window) {
            window->close();
            delete window;
        }
    }
}

void ProductManagement::setupUI() {
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);

    // Partea de tabel
    tableView = new QTableView();
    model = new QStandardItemModel(0, 5, this);
    model->setHorizontalHeaderLabels({"ID", "Nume", "Tip", "Preț", "Număr Vocale"});
    tableView->setModel(model);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    mainLayout->addWidget(tableView);

    // Partea de filtru cu slider
    QHBoxLayout* sliderLayout = new QHBoxLayout();
    QLabel* sliderLabel = new QLabel("Filtrare după preț:");
    sliderLayout->addWidget(sliderLabel);

    priceSlider = new QSlider(Qt::Horizontal);
    priceSlider->setRange(0, 100);
    priceSlider->setValue(100);
    sliderLayout->addWidget(priceSlider);

    sliderValueLabel = new QLabel("100");
    sliderLayout->addWidget(sliderValueLabel);

    mainLayout->addLayout(sliderLayout);

    // Formular pentru adăugare produs
    QFormLayout* formLayout = new QFormLayout();

    idLineEdit = new QLineEdit();
    formLayout->addRow("ID:", idLineEdit);

    nameLineEdit = new QLineEdit();
    formLayout->addRow("Nume:", nameLineEdit);

    typeLineEdit = new QLineEdit();
    formLayout->addRow("Tip:", typeLineEdit);

    priceLineEdit = new QLineEdit();
    formLayout->addRow("Preț:", priceLineEdit);

    mainLayout->addLayout(formLayout);

    // Buton de adăugare
    addButton = new QPushButton("Adaugă Produs");
    mainLayout->addWidget(addButton);

    // Conectarea semnalelor
    connect(addButton, &QPushButton::clicked, this, &ProductManagement::addProduct);
    connect(priceSlider, &QSlider::valueChanged, this, &ProductManagement::filterByPrice);

    setWindowTitle("Gestiune Produse");
    resize(800, 600);
}

void ProductManagement::addProduct() {
    bool ok;
    int id = idLineEdit->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Eroare", "ID-ul trebuie să fie un număr întreg.");
        return;
    }

    QString name = nameLineEdit->text();
    QString type = typeLineEdit->text();

    double price = priceLineEdit->text().toDouble(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Eroare", "Prețul trebuie să fie un număr real.");
        return;
    }

    if (validateProduct(id, name, type, price)) {
        Product newProduct(id, name, type, price);
        products.push_back(newProduct);

        // Actualizarea numărului de produse de fiecare tip
        productTypeCount[type]++;

        // Actualizarea ferestrelor pentru tipurile de produse
        updateTypeWindows();

        // Resetarea formularului
        idLineEdit->clear();
        nameLineEdit->clear();
        typeLineEdit->clear();
        priceLineEdit->clear();

        // Reafișarea produselor și aplicarea filtrului curent
        displayProducts();
        filterByPrice(priceSlider->value());

        // Salvarea produselor în fișier
        saveProductsToFile();
    }
}

bool ProductManagement::validateProduct(int id, const QString& name, const QString& type, double price) {
    // Verificarea ID-ului unic
    for (const Product& product : products) {
        if (product.id == id) {
            QMessageBox::warning(this, "Eroare", "ID-ul există deja. Folosiți un ID unic.");
            return false;
        }
    }

    // Verificarea numelui
    if (name.isEmpty()) {
        QMessageBox::warning(this, "Eroare", "Numele produsului nu poate fi vid.");
        return false;
    }

    // Verificarea tipului
    if (type.isEmpty()) {
        QMessageBox::warning(this, "Eroare", "Tipul produsului nu poate fi vid.");
        return false;
    }

    // Verificarea prețului
    if (price < 1.0 || price > 100.0) {
        QMessageBox::warning(this, "Eroare", "Prețul trebuie să fie între 1.0 și 100.0.");
        return false;
    }

    return true;
}

void ProductManagement::displayProducts() {
    model->setRowCount(0);

    // Sortarea produselor după preț
    std::sort(products.begin(), products.end(), [](const Product& a, const Product& b) {
        return a.price < b.price;
    });

    for (const Product& product : products) {
        QList<QStandardItem*> rowItems;
        rowItems << new QStandardItem(QString::number(product.id));
        rowItems << new QStandardItem(product.name);
        rowItems << new QStandardItem(product.type);
        rowItems << new QStandardItem(QString::number(product.price, 'f', 2));
        rowItems << new QStandardItem(QString::number(product.vowelCount));

        model->appendRow(rowItems);
    }

    // Aplicarea filtrului curent
    colorRowsByPrice(priceSlider->value());
}

void ProductManagement::filterByPrice(int value) {
    sliderValueLabel->setText(QString::number(value));
    colorRowsByPrice(value);
}

void ProductManagement::colorRowsByPrice(int threshold) {
    for (int row = 0; row < model->rowCount(); ++row) {
        double price = model->index(row, 3).data().toDouble();
        for (int col = 0; col < model->columnCount(); ++col) {
            QStandardItem* item = model->item(row, col);
            if (item) {
                if (price <= threshold) {
                    item->setBackground(QBrush(Qt::red));
                } else {
                    item->setBackground(QBrush());
                }
            }
        }
    }
}

void ProductManagement::loadProductsFromFile() {
    QFile file("products.txt");
    if (!file.exists()) {
        // Crearea unui fișier inițial cu minim 10 produse
        saveProductsToFile();
        return;
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Eroare", "Nu se poate deschide fișierul pentru citire.");
        return;
    }

    products.clear();
    productTypeCount.clear();

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(',');

        if (parts.size() >= 4) {
            int id = parts[0].toInt();
            QString name = parts[1];
            QString type = parts[2];
            double price = parts[3].toDouble();

            Product product(id, name, type, price);
            products.push_back(product);

            // Actualizarea numărului de produse de fiecare tip
            productTypeCount[type]++;
        }
    }

    file.close();

    // Dacă nu există produse în fișier, adăugarea de produse implicite
    if (products.empty()) {
        // Adăugarea a 10 produse implicite
        products.push_back(Product(1, "Laptop", "Electronice", 80.0));
        products.push_back(Product(2, "Telefon", "Electronice", 60.0));
        products.push_back(Product(3, "Cască", "Accesorii", 25.0));
        products.push_back(Product(4, "Tastatura", "Periferice", 40.0));
        products.push_back(Product(5, "Mouse", "Periferice", 20.0));
        products.push_back(Product(6, "Monitor", "Electronice", 90.0));
        products.push_back(Product(7, "Imprimantă", "Periferice", 70.0));
        products.push_back(Product(8, "Rucsac", "Accesorii", 35.0));
        products.push_back(Product(9, "Boxe", "Audio", 45.0));
        products.push_back(Product(10, "Cameră", "Foto", 75.0));

        // Actualizarea numărului de produse de fiecare tip
        for (const Product& product : products) {
            productTypeCount[product.type]++;
        }

        // Salvarea produselor în fișier
        saveProductsToFile();
    }

    // Actualizarea ferestrelor pentru tipurile de produse
    updateTypeWindows();
}

void ProductManagement::saveProductsToFile() {
    QFile file("products.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Eroare", "Nu se poate deschide fișierul pentru scriere.");
        return;
    }

    QTextStream out(&file);
    for (const Product& product : products) {
        out << product.id << "," << product.name << "," << product.type << "," << product.price << "\n";
    }

    file.close();
}

void ProductManagement::updateTypeWindows() {
    for (const QString& type : productTypeCount.keys()) {
        if (!typeWindows.contains(type)) {
            TypeInfoDialog* dialog = new TypeInfoDialog(type, productTypeCount[type], this);
            typeWindows[type] = dialog;
            dialog->show();
        } else {
            // Actualizarea ferestrelor existente
            if (typeWindows[type]) {
                typeWindows[type]->close();
                delete typeWindows[type];
            }
            typeWindows[type] = new TypeInfoDialog(type, productTypeCount[type], this);
            typeWindows[type]->show();
        }
    }
}

int ProductManagement::countVowels(const QString& str) {
    int count = 0;
    QString vowels = "aeiouAEIOU";
    for (const QChar& c : str) {
        if (vowels.contains(c)) {
            count++;
        }
    }
    return count;
}