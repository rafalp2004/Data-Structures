//
// Created by rafal on 14.04.2025.
//
#include <iostream>

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

template<typename T>
class DynamicArray {
public:
    T *pointer;
    int size;
    int capacity;

    DynamicArray() : size(0), capacity(4), pointer(new T[4]) {
    }

    ~DynamicArray() {
        delete[] pointer;
    }

    void resize() {
        T *newPointer = new T[capacity * 2];
        for (int i = 0; i < size; i++) {
            newPointer[i] = pointer[i];
        }
        delete[] pointer;
        pointer = newPointer;
        capacity *= 2;
    }

    void addToFirst(T data) {
         if (size == capacity) {
                resize();
            }
        for (int i = size; i > 0; i--) {
            pointer[i] = pointer[i - 1];
        }
        pointer[0] = data;
        size++;
    }

    void addToLast(T data) {
        if (size == capacity) {
            resize();
        }
        pointer[size] = data;
        size++;
    }

    void addToIndex(T data, const int index) {
        if (index < 0 || index > size) return;
        if (index == 0) {
            addToFirst(data);
            return;
        }
        if (size == capacity) {
            resize();
        }
        for (int i = size; i > index; i--) {
            pointer[i] = pointer[i - 1];
        }
        pointer[index] = data;
        size++;
    }

    void removeFromFirst() {
        for (int i = 1; i < size; i++) {
            pointer[i - 1] = pointer[i];
        }
        size--;
    }

    void removeFromLast() {
        if (size > 0) {
            size--;
        }
    }

    void removeFromIndex(int index) {
        if (index < 0 || index >= size) return;
        for (int i = index; i < size - 1; i++) {
            pointer[i] = pointer[i + 1];
        }
        size--;
    }

    int findElement(T element) {
        for (int i = 0; i < size; i++) {
            if (pointer[i] == element) {
                return i;
            }
        }
        return -1;
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            std::cout << pointer[i] << " ";
        }
        std::cout << "\n";
    }
};

#endif //DYNAMICARRAY_H
