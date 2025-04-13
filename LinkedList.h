//
// Created by rafal on 12.04.2025.
//
#include <iostream>
#include <ostream>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template<typename T>

class LinkedList {
public:
    class Node {
    public:
        Node *next;
        T data{};

        Node(const T &data): data(data), next(nullptr) {
        }
    };

    Node *head;
    Node *tail;

    LinkedList(): head(nullptr), tail(nullptr) {
    };

    ~LinkedList() {
        while (head != nullptr) {
            removeFromFirst();
        }
    }


    void addToFirst(T data) {
        Node *newNode = new Node(data);
        newNode->next = head;
        if (head == nullptr) {
            tail = newNode;
        }
        head = newNode;
    }

    void addToLast(T data) {
        Node *newNode = new Node(data);
        if (tail != nullptr) {
            tail->next = newNode;
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
        for (int i = 0; i < index - 1 && current != nullptr; i++) {
            current = current->next;
        }
        if (current == nullptr) {
            addToLast(data);
            return;
        }

        Node *newNode = new Node(data);
        Node *tempNext = current->next;

        current->next = newNode;
        newNode->next = tempNext;
    }

    void removeFromFirst() {
        if (head == nullptr) return;
        Node *temp = head;
        head = head->next;
        if (head == nullptr) tail = nullptr;
        delete temp;
    }

    void removeFromLast() {
        if (head == nullptr) return;

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node *current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;
        tail = current;
    }

    void removeFromIndex(int index) {
        if (index < 0 || head == nullptr) return;
        if (index == 0) {
            removeFromFirst();
            return;
        }

        Node *current = head;
        for (int i = 0; i < index - 1 && current != nullptr; i++) {
            current = current->next;
        }

        if (current->next == nullptr) return; // Indeks poza zakresem

        Node *temp = current->next;
        current->next = temp->next;
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

#endif //LINKEDLIST_H
