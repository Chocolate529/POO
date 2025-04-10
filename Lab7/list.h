//
// Created by lupse on 4/8/2025.
//

#ifndef LIST_H
#define LIST_H

template <typename T>

class List {
private:
    T* data;
    size_t capacity;
    size_t size;

    void resize();

public:
    List();
    ~List();

    void add(const T& value);
    void remove(const T& value);
    T& get(size_t index) const;
    size_t getSize() const;
};

#endif //LIST_H
