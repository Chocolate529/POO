#include "list.h"
#include <stdexcept>
#include "domeniu_masina.h"
// Constructor - Inițializează lista cu dimensiunea 0 și capacitatea 0
template <typename T>
List<T>::List() : data(nullptr), capacity(0), size(0) {}

// Destructor - Eliberează memoria alocată dinamic
template <typename T>
List<T>::~List() {
    delete[] data;
}

// Redimensionează lista (împinge capacitatea)
template <typename T>
void List<T>::resize() {
    capacity = (capacity == 0) ? 1 : capacity * 2;
    T* newData = new T[capacity];

    for (size_t i = 0; i < size; ++i) {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
}

// Adaugă un element în listă
template <typename T>
void List<T>::add(const T& value) {
    if (size == capacity) {
        resize();
    }
    data[size++] = value;
}

// Șterge un element din listă
template <typename T>
void List<T>::remove(const T& value) {
    for (size_t i = 0; i < size; ++i) {
        if (data[i] == value) {
            for (size_t j = i; j < size - 1; ++j) {
                data[j] = data[j + 1];
            }
            --size;
            return;
        }
    }
    throw std::runtime_error("Elementul nu a fost găsit în listă.");
}

// Returnează elementul de la un anumit index
template <typename T>
T& List<T>::get(size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Indexul este în afara limitelor.");
    }
    return data[index];
}

// Returnează dimensiunea actuală a listei
template <typename T>
size_t List<T>::getSize() const {
    return size;
}

// Explicităm instanțierea template-ului pentru tipul `Masina`
template class List<Masina>;
