// product_management.h
#ifndef PRODUCT_MANAGEMENT_H
#define PRODUCT_MANAGEMENT_H

#include <QMainWindow>
#include <QTableView>
#include <QStandardItemModel>
#include <QLineEdit>
#include <QPushButton>
#include <QSlider>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QMap>
#include <QDialog>
#include <vector>
#include <string>

struct Product {
    int id;
    QString name;
    QString type;
    double price;
    int vowelCount;

    Product(int _id, const QString& _name, const QString& _type, double _price)
        : id(_id), name(_name), type(_type), price(_price) {
        // Calcularea numărului de vocale
        vowelCount = 0;
        QString vowels = "aeiouAEIOU";
        for (const QChar& c : name) {
            if (vowels.contains(c)) {
                vowelCount++;
            }
        }
    }
};

class TypeInfoDialog : public QDialog {

public:
    TypeInfoDialog(const QString& type, int count, QWidget* parent = nullptr)
        : QDialog(parent) {
        setWindowTitle(type);
        QVBoxLayout* layout = new QVBoxLayout(this);
        QLabel* label = new QLabel(QString("Număr de produse de tip %1: %2").arg(type).arg(count));
        layout->addWidget(label);

        QPushButton* closeButton = new QPushButton("Închide");
        layout->addWidget(closeButton);

        connect(closeButton, &QPushButton::clicked, this, &QDialog::accept);
        setLayout(layout);
    }
};

class ProductManagement : public QMainWindow {

public:
    ProductManagement(QWidget* parent = nullptr);
    ~ProductManagement();

private slots:
    void addProduct();
    void filterByPrice(int value);
    void loadProductsFromFile();
    void saveProductsToFile();
    void updateTypeWindows();

private:
    QTableView* tableView;
    QStandardItemModel* model;
    QLineEdit* idLineEdit;
    QLineEdit* nameLineEdit;
    QLineEdit* typeLineEdit;
    QLineEdit* priceLineEdit;
    QPushButton* addButton;
    QSlider* priceSlider;
    QLabel* sliderValueLabel;

    std::vector<Product> products;
    QMap<QString, int> productTypeCount;
    QMap<QString, TypeInfoDialog*> typeWindows;

    void setupUI();
    void displayProducts();
    bool validateProduct(int id, const QString& name, const QString& type, double price);
    int countVowels(const QString& str);
    void colorRowsByPrice(int threshold);
};

#endif // PRODUCT_MANAGEMENT_H