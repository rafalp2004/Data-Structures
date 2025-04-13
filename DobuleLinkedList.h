//
// Created by rafal on 10.04.2025.
//
#pragma once


#include <iostream>
#include <ostream>

template<typename T>
class DoubleLinkedList {
public:
    class Node {
    public:
        Node *prev;
        T data{};
        Node *next;

        Node(const T &data) : data(data), prev(nullptr), next(nullptr) {
        }
    };

    Node *head;
    Node *tail;

    DoubleLinkedList() : head(nullptr), tail(nullptr) {
    }

    ~DoubleLinkedList() {
        while (head != nullptr) {
            removeFromFirst();
        }
    }


    void addToFirst(T data) {
        Node *newNode = new Node(data);
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
    }

    void addToLast(T data) {
        Node *newNode = new Node(data);
        if (tail != nullptr) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } else {
            head = newNode;
            tail = newNode;
        }
    }

    void addToIndex(T data, const int index) {
        if (index < 0) return;
        if (index == 0) {
            addToFirst(data);
            return;
        }

        Node *current = head;
        for (int i = 0; i < index && current != nullptr; i++) {
            current = current->next;
        }
        if (current == nullptr) {
            addToLast(data);
            return;
        }


        Node *newNode = new Node(data);
        Node *tempPrev = current->prev;

        tempPrev->next = newNode;
        newNode->prev = tempPrev;

        current->prev = newNode;
        newNode->next = current;
    }

    void removeFromIndex(int index) {
        if (index < 0 || head == nullptr) return;
        if (index == 0) {
            removeFromFirst();
            return;
        }

        Node *current = head;
        for (int i = 0; i < index && current != nullptr; i++) {
            current = current->next;
        }

        if (current == nullptr) return; // Indeks poza zakresem
        if (current == tail) {
            removeFromLast();
            return;
        }

        Node *prevNode = current->prev;
        Node *nextNode = current->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        delete current;
    }


    void removeFromFirst() {
        if (head == nullptr) return;
        Node *temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    void removeFromLast() {
        if (tail == nullptr) return;
        Node *temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
    }

    int findElement(T element) {
        Node *current = head;
        int counter = 0;
        while (current->data != element) {
            if (current->next == nullptr) break;
            current = current->next;
            counter++;
        }
        if (current != nullptr && current->data == element) {
            return counter;
        }
        return -1;
    }

    void print() {
        Node *current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};
