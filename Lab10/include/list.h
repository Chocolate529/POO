//
// Created by lupse on 4/8/2025.
//

#ifndef LIST_H
#define LIST_H
#include <stdexcept>
// #include "iterator_list.h"
template<typename T>
class IteratorList;
template <typename T>
class List {
    friend class IteratorList<T>;
private:
    T* data;
    size_t capacity;
    size_t size;

    void resize();

public:
    List();
    List(const List& other);
    List(List&& other) noexcept;
    ~List();

    void add(const T& value);
    void remove(const T& value);
    T& get(size_t index) const;
    void set(size_t index, const T& value);
    [[nodiscard]] size_t getSize() const;


    List& operator=(const List& other);
    List& operator=(List&& other) noexcept;
    bool operator==(const List& other) const;

    IteratorList<T> begin();
    IteratorList<T> end();
};


// Constructor - Inițializează lista cu dimensiunea 0 și capacitatea 0
template <typename T>
List<T>::List() : data(nullptr), capacity(0), size(0) {}

template <typename T>
List<T>::List(const List<T>& other) {
    data = new T[other.capacity];
    for (size_t i = 0; i < other.size; i++) {
        data[i] = other.data[i];
    }
    size = other.size;
    capacity = other.capacity;
}

template <typename T>
List<T>::List(List<T>&& other) noexcept{
    data = other.data;
    capacity = other.capacity;
    size = other.size;

    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

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

template <typename T>
void List<T>::set(size_t index, const T& value) {
    if (index >= size) {
        throw std::out_of_range("Indexul este în afara limitelor.");
    }
    data[index] = value;
}

// Returnează dimensiunea actuală a listei
template <typename T>
size_t List<T>::getSize() const {
    return size;
}

template<typename T>
List<T>& List<T>::operator=(const List& other) {
    if (this == &other) {
        return *this;
    }
    delete[] data;
    data = new T[other.size];
    this->size = other.size;
    this->capacity = other.capacity;
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
    return *this;
}

template<typename T>
List<T>& List<T>::operator=(List&& other) noexcept{
    if (this == &other) {
        return *this;
    }
    delete[] data;
    data = other.data;
    capacity = other.capacity;
    size = other.size;

    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
    return *this;
}

template<typename T>
bool List<T>::operator==(const List& other) const {
    if (this.size != other.size) {
        return false;
    }
    if (this.capacity != other.capacity) {
        return false;
    }
    for (size_t i = 0; i < size; ++i) {
        if (data[i] == data[i]) {
            return false;
        }
    }
    return true;
}

template<typename T>
IteratorList<T> List<T>::begin() {
    return IteratorList<T>(*this);
}
template<typename T>
IteratorList<T> List<T>::end() {
    return IteratorList<T>(*this, size);
}
template<typename T>
class IteratorList {
    friend class List<T>;
private:
    const List<T>& list;
    int poz=0;

public:
    explicit IteratorList(const List<T>& list) noexcept;
    IteratorList(const List<T>& list, int poz) noexcept;

    void urmator();
    [[nodiscard]] bool valid() const;
    T& element() const;
    void prim();
    T& operator*() const;
    IteratorList& operator++();
    bool operator==(const IteratorList& other) const;
    bool operator!=(const IteratorList& other) const;

};

template<typename T>
IteratorList<T> :: IteratorList(const List<T>& list) noexcept: list{ list } {}

template<typename T>
IteratorList<T> :: IteratorList(const List<T>& list, int poz) noexcept: list{ list }, poz{ poz }{}

template<typename T>
void IteratorList<T>::urmator() {
    poz++;
}

template<typename T>
bool IteratorList<T>::valid() const {
    return poz < list.size;
}

template<typename T>
T &IteratorList<T>::element() const {
    return list.data[poz];
}

template<typename T>
void IteratorList<T>::prim() {
    poz = 0;
}

template<typename T>
T& IteratorList<T>::operator*() const {
    return element();
}

template<typename T>
IteratorList<T>& IteratorList<T>::operator++() {
    poz++;
    return *this;
}

template<typename T>
bool IteratorList<T>::operator==(const IteratorList &other) const {
    return poz == other.poz;
}

template<typename T>
bool IteratorList<T>::operator!=(const IteratorList &other) const {
    return !(*this == other);
}




#endif //LIST_H
